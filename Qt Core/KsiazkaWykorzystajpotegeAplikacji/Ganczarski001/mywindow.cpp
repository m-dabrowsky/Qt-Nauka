#include "mywindow.h"

MyWindow::MyWindow(QWidget *parent) : QMainWindow(0,Qt::Window)
{
    fileName = "dokument1.txt";                         // Określenie domyślnej nazyw pliku
    setGeometry(300,300,600,400);                       // ustawienie wielkości okna
    setWindowTitle("Edytor część 1 - " + fileName);     // ustawienie tytułu
    setWindowIcon(QIcon (":/images/exit.png"));         // ustawienie ikony obok tytułu
    textEdit = new QTextEdit();                         // Pole do pisania
    setCentralWidget(textEdit);                         // ustawienie pola do pisania jako główny widget

    // menu Plik - menuBar jest już w QMainWindow - zwraca wskaźnik na obiket paska menu
    fileMenu = menuBar()->addMenu("&Plik");           // Dodanie zakładki Plik - &oznacza że P będzię skrótem
    // menu Plik/Nowy
    fileMenuNew = new QAction (QIcon (":/images/new.png"), "&Nowy", this); // utworzenie dynamicznie obiektu  New
    fileMenuNew->setShortcut(QString ("Ctrl+N"));                          // Określenie skrótu
    fileMenuNew->setStatusTip("Tworzy nowy plik");                         // określenie opisu po najechaniu myszką lub w pasku statusu
    fileMenu->addAction(fileMenuNew);                                      // dodanie obiektu do zakładki Plik
    // menu Plik/Otworz
    fileMenuOpen = new QAction (QIcon (":/images/open.png"), "&Otwórz", this);
    fileMenuOpen->setShortcut(Qt::Key_0 | Qt::ControlModifier);
    fileMenuOpen->setStatusTip("Otwiera plik");
    fileMenu->addAction(fileMenuOpen);
    // menu Plik/Zapisz
    fileMenuSave = new QAction ("&Zapisz", this);
    fileMenuSave->setIcon(QIcon (":/images/save.png"));
    fileMenuSave->setShortcut(Qt::Key_0 | Qt::ControlModifier);
    fileMenuSave->setStatusTip("Zapisuje plik");
    fileMenu->addAction(fileMenuSave);
    // menu Plik/Zapisz jako
    fileMenuSaveAs = new QAction ("&Zapisz jako", this);
    fileMenuSaveAs->setStatusTip("Zapisuje plik jako");
    fileMenu->addAction(fileMenuSaveAs);
    fileMenu->addSeparator();
    // menu Plik/Zapisz jako
    fileMenuQuit = new QAction ("&Wyjście", this);
    fileMenuQuit->setStatusTip("Zakończenie działania programu");
    fileMenuQuit->setShortcut(Qt::Key_F4 | Qt::AltModifier);
    fileMenu->addAction(fileMenuQuit);


    // Status Bar
    statusBar() -> showMessage("Gotowy");   //Status Bar jest już w QMainWindow
    // Tool Bar
    fileToolBar = new QToolBar(this);
    fileToolBar -> addAction(fileMenuNew);
    fileToolBar -> addAction(fileMenuOpen);
    fileToolBar -> addAction(fileMenuSave);
    addToolBar(fileToolBar);

    connect(fileMenuNew, SIGNAL(triggered()), this, SLOT(New()));
    connect(fileMenuOpen, SIGNAL(triggered()), this, SLOT(Open()));
    connect(fileMenuSave, SIGNAL(triggered()), this, SLOT(Save()));
    connect(fileMenuSaveAs, SIGNAL(triggered()), this, SLOT(SaveAs()));

}

void MyWindow::New(){
    textEdit->clear();
}

void MyWindow::Open(){
    QString newFile = QFileDialog::getOpenFileName(this);
    if(!newFile.isEmpty()){
        QFile file(newFile);
        if(file.open (QFile::ReadOnly | QFile::Text)){
            QTextStream in(&file);
            textEdit->setPlainText(in.readAll());
            fileName = newFile;
            statusBar()->showMessage("Plik odczytany",2000);
        }
    }
}

void MyWindow::Save(){
    QFile file(fileName);
    if(file.open(QFile::WriteOnly | QFile::Text)){
        QTextStream out (&file);
        out << textEdit -> toPlainText();
        statusBar() -> showMessage("Plik zapisany", 2000);
    }
}

void MyWindow::SaveAs(){
    QString newFileName = QFileDialog::getSaveFileName(this);
    if(!newFileName.isEmpty()){
        QFile file(newFileName);
        if(file.open(QFile::WriteOnly | QFile::Text)){
            QTextStream out (&file);
            out << textEdit -> toPlainText();
            fileName = newFileName;
            statusBar() -> showMessage("Plik zapisany", 2000);
        }
    }
}
