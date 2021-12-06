#include "mywindow.h"

MyWindow::MyWindow ()
{
    setupUi (this);
    
    // utworzenie obiektu klasy QHttp
    http = new QHttp (this);
    
    // ustawnie wartoœci pocz¹tkowej file jest wa¿ne dla
    // poprawnego tworzenia i usuwania obiektu tej klasy
    file = NULL;

    // utworzenie elementów interfejsu, które nie s¹ zapisane w pliku UI
    progressDialog = new QProgressDialog (this);
    progressDialog -> setWindowTitle ("Pobieranie pliku");
    
    // po³¹czenia sygna³-gniazdo
    connect (pushButtonGet,SIGNAL(clicked()),this,SLOT(GetFile()));
    connect (lineEdit,SIGNAL(returnPressed()),this,SLOT(GetFile()));
    connect (http,SIGNAL(requestFinished(int,bool)),this,SLOT(httpRequestFinished(int,bool)));
    connect (http,SIGNAL(responseHeaderReceived(const QHttpResponseHeader &)),this,SLOT(httpResponseHeaderReceived(const QHttpResponseHeader &)));
    connect (http,SIGNAL(dataReadProgress(int,int)),this,SLOT(httpDataReadProgress(int,int)));
    connect (progressDialog,SIGNAL(canceled()),this,SLOT(CancelGetFile()));
    connect (pushButtonQuit,SIGNAL(clicked()),this,SLOT(Quit()));
}

// po³¹czenie z serwerem HTTP i pobranie pliku

void MyWindow::GetFile ()
{
    // sprawdzenie poprawnoœci adresu
    QUrl url (lineEdit -> text ().toLower ());
    if (!url.isValid () || url.scheme() != "http")
    {
        QMessageBox::critical (this,"B³¹d","Niepoprawny adres URL");
        return;
    }
    
    // wydzielenie nazwy pliku z adresu URL 
    QFileInfo fileInfo (url.path());
    QString fileName = fileInfo.fileName();
    if (fileName.isEmpty())
        fileName = "index.html";

    // sprawdzenie, czy plik o takiej nazwie znajduje 
    // siê w bie¿¹cym folderze lokalnego komputera
    if (QFile::exists (fileName))
    {
        if (QMessageBox::question (this,"Pytanie","Plik o takiej nazwie istnieje w bie¿¹cym folderze.<BR>Nadpisaæ istniej¹cy plik?",QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
            return;
    }
        
    // utworzenie pliku  
    file = new QFile (fileName);
    
    // otwarcie pliku do zapisu i obs³uga ewentualnego b³êdu
    if (!file -> open (QFile::WriteOnly)) 
    {
         QMessageBox::critical (this,"B³¹d","Nie mo¿na utworzyæ pliku:<BR>" + fileName);
         delete file;
         file = NULL;
         return;
    }
    
    // po³¹czenie z serwerem i pobranie wybranego pliku
    http -> setHost (url.host());
    http -> get (url.path(),file);

    // wyœwietlenie okna z informacj¹ o postêpie w pobieraniu pliku
    progressDialog -> setLabelText ("Pobieranie pliku: " + fileName);
    progressDialog -> exec ();
}

void MyWindow::httpRequestFinished (int requestId, bool error)
{
    // obs³uga b³êdu po³¹czenia z serwerem
    if (error && (http -> state () == QHttp::Connecting || http -> state () == QHttp::HostLookup))
    {
        // ukrycie okna z informacj¹ o postêpie w pobieraniu pliku
        progressDialog -> hide ();
              
        // pobranie adresu URL 
        QUrl url (lineEdit -> text ().toLower ());

        // komunikat
        QMessageBox::critical (this,"B³¹d","B³¹d po³¹czenia z serwerem:<BR>" + url.host());
        
        // zamkniêcie i usuniêcie pliku
        if (file)
        {
            file -> close();
            file -> remove();
            delete file;
            file = NULL;
        }
    }
    
    // zakoñczenie pobierania pliku
    if (http -> state () == QHttp::Connected)
    {
        // ukrycie okna z informacj¹ o postêpie w pobieraniu pliku
        progressDialog -> hide();
        
        // zamkniêcie pliku
        if (file)
        {
            file -> close();
            delete file;
            file = NULL;
        }
    }
}

// przetwarzanie pobranego nag³ówka HTML

void MyWindow::httpResponseHeaderReceived (const QHttpResponseHeader & header)
{
    if (header.statusCode() != 200) 
    {
        // ukrycie okna z informacj¹ o postêpie w pobieraniu pliku
        progressDialog -> hide ();

        // komunikat
        QMessageBox::critical (this,"B³¹d","B³¹d pobrania pliku");
        
        // zamkniêcie i usuniêcie pliku
        if (file)
        {
            file -> close();
            file -> remove();
            delete file;
            file = NULL;
        }
        
        // zaniechanie operacji na serwerze HTTP
        http -> abort();
    }
}

// aktualizacja danych okna z paskiem postêpu przy pobieraniu pliku

void MyWindow::httpDataReadProgress (int bytesRead, int totalBytes)
{
    progressDialog -> setMaximum (totalBytes);
    progressDialog -> setValue (bytesRead);
}

// przerwanie pobierania pliku z serwera 

void MyWindow::CancelGetFile()
{
    // zamkniêcie i usuniêcie pliku
    if (file)
    {
        file -> close ();
        file -> remove ();
        delete file;
        file = NULL;
    }
    
    // przerwanie operacji na serwerze HTTP
    http -> abort ();
}

// wyjœcie z programu

void MyWindow::Quit ()
{
    delete file;
    qApp -> quit ();
}
