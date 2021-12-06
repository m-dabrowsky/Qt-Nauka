#include "mywindow.h"

MyWindow::MyWindow ()
{
    setupUi (this);
    
    // ustawnie wartoœci pocz¹tkowej ftp jest wa¿ne dla 
    // poprawnego tworzenia i usuwania obiektu tej klasy
    ftp = NULL;
    
    // utworzenie elementów interfejsu, które nie s¹ zapisane w pliku UI
    progressDialog = new QProgressDialog (this);
    progressDialog -> setWindowTitle ("Pobieranie pliku");
    
    // powi¹zania sygna³-gniazdo
    connect (pushButtonConnect,SIGNAL(clicked()),this,SLOT(Connect()));
    connect (lineEdit,SIGNAL(returnPressed ()),this,SLOT(Connect()));
    connect (pushButtonDisconnect,SIGNAL(clicked()),this,SLOT(Disconnect()));
    connect (pushButtonGet,SIGNAL(clicked()),this,SLOT(GetFile()));
    connect (progressDialog,SIGNAL(canceled()),this,SLOT(CancelGetFile()));
    connect (pushButtonQuit,SIGNAL(clicked()),this,SLOT(Quit()));
    connect (treeWidget,SIGNAL(itemActivated(QTreeWidgetItem *, int)),this,SLOT(ProcessItem(QTreeWidgetItem *, int)));
    connect (pushButtonCdUp,SIGNAL(clicked()), this, SLOT(CdUp()));
}

// po³¹czenie z serwerem FTP

void MyWindow::Connect ()
{
    if (!ftp)
    {
        // sprawdzenie poprawnoœci adresu
        QUrl url (lineEdit -> text ().toLower ());
        if (!url.isValid () || url.scheme() != "ftp")
        {
            QMessageBox::critical (this,"B³¹d","Niepoprawny adres URL");
            return;
        }
         
        // kursor - klepsydra
        setCursor (Qt::WaitCursor);
        
        // utworzenie obiektu klasy QFtp
        ftp = new QFtp (this);
        
        // utworzenie po³¹czeñ sygna³-gniazdo
        connect (ftp,SIGNAL(commandFinished(int,bool)),this,SLOT(ftpCommandFinished(int,bool)));
        connect (ftp,SIGNAL(listInfo(const QUrlInfo &)),this,SLOT(ftpListInfo(const QUrlInfo &)));
        connect (ftp,SIGNAL(dataTransferProgress(qint64,qint64)),this,SLOT(ftpDataTransferProgress(qint64,qint64)));

        // po³¹czenie z serwerem
        ftp -> connectToHost (url.host(),url.port(21));
        
        // zalogowanie siê na zdalnym komputerze
        if (!url.userName().isEmpty())
            ftp -> login (url.userName(),url.password());
        else
            ftp->login();
        
        // w razie potrzeby przejœcie do wybranego folderu na zdalnym komputerze
        if (!url.path().isEmpty())
            ftp -> cd (url.path());
     }
}

// zerwanie po³¹czenia z serwerem FTP

void MyWindow::Disconnect ()
{
    if (ftp)
    { 
        // kursor - klepsydra
        setCursor (Qt::WaitCursor);

        // roz³¹czenie po³¹czenia i usuniêcie obiektu
        ftp -> abort();
        ftp -> deleteLater();
        ftp = NULL;

        // usuniêcie i dezaktywacja listy folderów/plików
        treeWidget -> clear ();
        treeWidget -> setEnabled (false);
    
        // pocz¹tkowe stany dostêpnoœci przycisków 
        pushButtonDisconnect -> setEnabled (false);
        pushButtonConnect -> setEnabled (true);
        pushButtonCdUp -> setEnabled (false);
        pushButtonGet -> setEnabled (false);
     
        // ustawienie normalnego kursora
        setCursor (Qt::ArrowCursor);
    }
}

// zakoñczenie pojedynczej operacji na zdalnym komputerze

void MyWindow::ftpCommandFinished (int id, bool error)
{
    // ustawienie normalnego kursora
    setCursor (Qt::ArrowCursor);
    
    // po³¹czenie ze zdalnym komputerem
    if (ftp -> currentCommand() == QFtp::ConnectToHost) 
    {
        // obs³uga b³êdu po³¹czenia z serwerem
        if (error)
        {
            // komunikat i roz³¹czenie 
            QMessageBox::critical (this,"B³¹d","B³¹d po³¹czenia z serwerem:<BR>" + lineEdit -> text ());
            Disconnect ();
            return;
        }

        // zmiana statusu przycisków        
        pushButtonDisconnect -> setEnabled (true);
        pushButtonConnect -> setEnabled (false);
        pushButtonCdUp -> setEnabled (true);
        pushButtonGet -> setEnabled (true);
        
        // aktywacja listy folderów/plików 
        treeWidget -> setEnabled (true);
     }
     
     // zalogowanie na zdalnym komputerze i pobranie 
     // informacji o bie¿¹cym folderze zdalnego komputera
     if (ftp -> currentCommand() == QFtp::Login)
     {
         ftp -> list ();
     }
     
     // zakoñczenie pobierania informacji o bie¿¹cym folderze 
     // zdalnego komputera obs³uga przypadku, gdy folder jest pusty
     if (ftp -> currentCommand() == QFtp::List)
         if (treeWidget -> topLevelItemCount () == 0) 
         {
             treeWidget -> addTopLevelItem (new QTreeWidgetItem(QStringList() << "<pusty folder>"));
         }
         
     // zakoñczenie pobierania pliku ze zdalnego komputera
     if (ftp -> currentCommand() == QFtp::Get) 
     {
         // w przypadku b³êdu zamkniêcie i usuniêcie pliku,
         // w przeciwnym wypadku tylko zamkniêcie pliku
         file -> close();
         if (error) 
             file -> remove();

         // usuniêcie obiektu
         delete file;

         // zamkniêcie okna z informacj¹ o postêpie w pobieraniu pliku
         progressDialog -> hide();
     }
}

// pobranie informacji o nowym obiekcie zawartym w folderze zdalnego komputera

void MyWindow::ftpListInfo (const QUrlInfo & urlInfo)
{
    // utworzenie nowego elementu
    QTreeWidgetItem *item = new QTreeWidgetItem;
    item -> setText (0,urlInfo.name());
    item -> setText (1,QString::number(urlInfo.size()));
    item -> setText (2,urlInfo.owner());
    item -> setText (3,urlInfo.group());
    item -> setText (4,urlInfo.lastModified().toString ("MMM dd yyyy"));

    // wybór w³aœciwej ikony
    if (urlInfo.isSymLink())
        item -> setIcon (0,QIcon (":/images/symbolic_link.png"));
    else
    if (urlInfo.isDir())
        item -> setIcon (0,QIcon (":/images/dir.png"));
    else
    if (urlInfo.isFile())
        item -> setIcon (0,QIcon (":/images/file.png"));

    // zapis ukrytej informacji czy dany element listy jest folderem, czy te¿ plikiem
    if (urlInfo.isDir() && !urlInfo.isSymLink())
        item -> setStatusTip (5,"d");
    else
    if (urlInfo.isFile())
        item -> setStatusTip (5,"f");
        
    // dodanie elementu do drzewa
    treeWidget -> addTopLevelItem (item);

    // okreœlenie bie¿¹cego elementu drzewa
    if (!treeWidget -> currentItem()) 
        treeWidget -> setCurrentItem (treeWidget -> topLevelItem(0));
}

// pobieranie pliku ze zdalnego serwera

void MyWindow::GetFile ()
{
    // sprawdzenie, czy bie¿¹cy element jest plikiem
    if (treeWidget -> currentItem() -> statusTip (5) != "f")
        return;
    
    // nazwa pliku
    QString fileName = treeWidget -> currentItem() -> text(0);

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
         return;
    }

    // pobranie pliku ze zdalnego komputera
    ftp -> get (treeWidget -> currentItem() -> text(0),file);

    // wyœwietlenie okna z informacj¹ o postêpie w pobieraniu pliku
    progressDialog -> setLabelText ("Pobieranie pliku: " + fileName);
    progressDialog -> exec ();
}

// aktualizacja danych okna z paskiem postêpu przy pobieraniu pliku

void MyWindow::ftpDataTransferProgress (qint64 done, qint64 total)
{
    progressDialog -> setMaximum (total);
    progressDialog -> setValue (done);
}

// przerwanie pobierania pliku ze zdalnego komputera

void MyWindow::CancelGetFile()
{
    // zamkniêcie i usuniêcie pliku
    file -> close ();
    file -> remove ();
    
    // przerwanie operacji na serwerze FTP
    ftp -> abort ();
}

// przetwarzanie bie¿¹cego elementu listy plików i folderów - zmiana folderu

void MyWindow::ProcessItem (QTreeWidgetItem *item, int column)
{
    // sprawdzenie czy to jest folder
    if (item -> statusTip (5) == "d")
    {
        // kursor - klepsydra
        setCursor (Qt::WaitCursor);

        // nazwa folderu 
        QString name = item -> text(0);
    
        // wyczyszczenie listy plików/folderów
        treeWidget -> clear();
    
        // zmiana folderu i pobranie zawartoœci nowego folderu
        ftp -> cd (name);
        ftp -> list ();
    }
}

// przejœcie do folderu nadrzêdnego na zdalnym komputerze

void MyWindow::CdUp ()
{
    // kursor - klepsydra
    setCursor (Qt::WaitCursor);

    // wyczyszczenie listy plików/folderów
    treeWidget -> clear();

    // zmiana folderu i pobranie zawartoœci nowego folderu
    ftp -> cd ("..");
    ftp -> list ();
}

// wyjœcie z programu

void MyWindow::Quit ()
{
    Disconnect ();
    qApp -> quit ();
}

