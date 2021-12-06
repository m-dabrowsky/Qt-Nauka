#include "mywindow.h"

MyWindow::MyWindow ()
{
    setupUi (this);
    
    // utworzenie obiektu klasy QHttp
    http = new QHttp (this);
    
    // ustawnie warto�ci pocz�tkowej file jest wa�ne dla
    // poprawnego tworzenia i usuwania obiektu tej klasy
    file = NULL;

    // utworzenie element�w interfejsu, kt�re nie s� zapisane w pliku UI
    progressDialog = new QProgressDialog (this);
    progressDialog -> setWindowTitle ("Pobieranie pliku");
    
    // po��czenia sygna�-gniazdo
    connect (pushButtonGet,SIGNAL(clicked()),this,SLOT(GetFile()));
    connect (lineEdit,SIGNAL(returnPressed()),this,SLOT(GetFile()));
    connect (http,SIGNAL(requestFinished(int,bool)),this,SLOT(httpRequestFinished(int,bool)));
    connect (http,SIGNAL(responseHeaderReceived(const QHttpResponseHeader &)),this,SLOT(httpResponseHeaderReceived(const QHttpResponseHeader &)));
    connect (http,SIGNAL(dataReadProgress(int,int)),this,SLOT(httpDataReadProgress(int,int)));
    connect (progressDialog,SIGNAL(canceled()),this,SLOT(CancelGetFile()));
    connect (pushButtonQuit,SIGNAL(clicked()),this,SLOT(Quit()));
}

// po��czenie z serwerem HTTP i pobranie pliku

void MyWindow::GetFile ()
{
    // sprawdzenie poprawno�ci adresu
    QUrl url (lineEdit -> text ().toLower ());
    if (!url.isValid () || url.scheme() != "http")
    {
        QMessageBox::critical (this,"B��d","Niepoprawny adres URL");
        return;
    }
    
    // wydzielenie nazwy pliku z adresu URL 
    QFileInfo fileInfo (url.path());
    QString fileName = fileInfo.fileName();
    if (fileName.isEmpty())
        fileName = "index.html";

    // sprawdzenie, czy plik o takiej nazwie znajduje 
    // si� w bie��cym folderze lokalnego komputera
    if (QFile::exists (fileName))
    {
        if (QMessageBox::question (this,"Pytanie","Plik o takiej nazwie istnieje w bie��cym folderze.<BR>Nadpisa� istniej�cy plik?",QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
            return;
    }
        
    // utworzenie pliku  
    file = new QFile (fileName);
    
    // otwarcie pliku do zapisu i obs�uga ewentualnego b��du
    if (!file -> open (QFile::WriteOnly)) 
    {
         QMessageBox::critical (this,"B��d","Nie mo�na utworzy� pliku:<BR>" + fileName);
         delete file;
         file = NULL;
         return;
    }
    
    // po��czenie z serwerem i pobranie wybranego pliku
    http -> setHost (url.host());
    http -> get (url.path(),file);

    // wy�wietlenie okna z informacj� o post�pie w pobieraniu pliku
    progressDialog -> setLabelText ("Pobieranie pliku: " + fileName);
    progressDialog -> exec ();
}

void MyWindow::httpRequestFinished (int requestId, bool error)
{
    // obs�uga b��du po��czenia z serwerem
    if (error && (http -> state () == QHttp::Connecting || http -> state () == QHttp::HostLookup))
    {
        // ukrycie okna z informacj� o post�pie w pobieraniu pliku
        progressDialog -> hide ();
              
        // pobranie adresu URL 
        QUrl url (lineEdit -> text ().toLower ());

        // komunikat
        QMessageBox::critical (this,"B��d","B��d po��czenia z serwerem:<BR>" + url.host());
        
        // zamkni�cie i usuni�cie pliku
        if (file)
        {
            file -> close();
            file -> remove();
            delete file;
            file = NULL;
        }
    }
    
    // zako�czenie pobierania pliku
    if (http -> state () == QHttp::Connected)
    {
        // ukrycie okna z informacj� o post�pie w pobieraniu pliku
        progressDialog -> hide();
        
        // zamkni�cie pliku
        if (file)
        {
            file -> close();
            delete file;
            file = NULL;
        }
    }
}

// przetwarzanie pobranego nag��wka HTML

void MyWindow::httpResponseHeaderReceived (const QHttpResponseHeader & header)
{
    if (header.statusCode() != 200) 
    {
        // ukrycie okna z informacj� o post�pie w pobieraniu pliku
        progressDialog -> hide ();

        // komunikat
        QMessageBox::critical (this,"B��d","B��d pobrania pliku");
        
        // zamkni�cie i usuni�cie pliku
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

// aktualizacja danych okna z paskiem post�pu przy pobieraniu pliku

void MyWindow::httpDataReadProgress (int bytesRead, int totalBytes)
{
    progressDialog -> setMaximum (totalBytes);
    progressDialog -> setValue (bytesRead);
}

// przerwanie pobierania pliku z serwera 

void MyWindow::CancelGetFile()
{
    // zamkni�cie i usuni�cie pliku
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

// wyj�cie z programu

void MyWindow::Quit ()
{
    delete file;
    qApp -> quit ();
}
