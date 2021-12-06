#include "mywindow.h"
#include "previewwindow.h"

MyWindow::MyWindow ():
    QMainWindow (0,Qt::Window)
{
    // utworzenie interfejsu okna
    setupUi (this);

    // domyœlna nazwa pliku
    fileName = "dokument1.txt";

    // tytu³ okna
    setWindowTitle("Edytor tekstu - QtDesigner - " + fileName);

    // pasek statusu
    Ui::Window::statusBar -> showMessage ("Gotowy");

    // sygna³y i gniazda
    connect (fileMenuNew,SIGNAL (triggered()),this,SLOT (New()));
    connect (fileMenuOpen,SIGNAL (triggered()),this,SLOT (Open()));
    connect (fileMenuSave,SIGNAL (triggered()),this,SLOT (Save()));
    connect (fileMenuSaveAs,SIGNAL (triggered()),this,SLOT (SaveAs()));
    connect (fileMenuSavePDF,SIGNAL (triggered()),this,SLOT (SavePDF()));
    connect (fileMenuPrintPreview,SIGNAL (triggered()),this,SLOT (PrintPreview()));    
    connect (fileMenuPrint,SIGNAL (triggered()),this,SLOT (Print()));
    connect (fileMenuQuit,SIGNAL (triggered()),qApp,SLOT (quit()));
}

// nowy plik

void MyWindow::New ()
{
     textEdit -> clear ();
}

// odczyt pliku

void MyWindow::Open ()
{
     QString newFileName = QFileDialog::getOpenFileName (this);
     if (!newFileName.isEmpty ())
     {
         QFile file (newFileName);
         if (file.open (QFile::ReadOnly | QFile::Text))
         {
             QTextStream in (&file);
             textEdit -> setPlainText (in.readAll ());
             fileName = newFileName;
             setWindowTitle ("Edytor tekstu - QtDesigner - " + fileName);
             Ui::Window::statusBar -> showMessage ("Plik odczytany",2000);
         }
     }
}

// zapis pliku

void MyWindow::Save ()
{
    QFile file (fileName);
    if (file.open (QFile::WriteOnly | QFile::Text))
    {
        QTextStream out (&file);
        out << textEdit -> toPlainText ();
        Ui::Window::statusBar -> showMessage ("Plik zapisany",2000);
    }
}

// zapis pliku pod now¹ nazw¹

void MyWindow::SaveAs ()
{
    QString newFileName = QFileDialog::getSaveFileName (this);
    if (!newFileName.isEmpty ())
    {
        QFile file (newFileName);
        if (file.open (QFile::WriteOnly | QFile::Text))
        {
            QTextStream out (&file);
            out << textEdit -> toPlainText ();
            fileName = newFileName;
            setWindowTitle ("Edytor tekstu - QtDesigner - " + fileName);
            Ui::Window::statusBar -> showMessage ("Plik zapisany",2000);
        }
    }
}

// zapis (drukowanie) do pliku PDF

void MyWindow::SavePDF ()
{
    // wybór nazwy pliku
    QString filter ("Portable Document Format (*.pdf);;wszystkie pliki (*.*)");
    QString newFileName = QFileDialog::getSaveFileName (this,"Zapisywanie jako",".",filter);
    if (!newFileName.isEmpty ())
    {
        // konfiguracja urz¹dzenia drukuj¹cego
        printer.setResolution (600);
        printer.setOutputFileName (newFileName);
        printer.setOutputFormat (QPrinter::PdfFormat);

        // drukowanie do pliku i komunikat
        textEdit -> print (&printer);
        Ui::Window::statusBar -> showMessage ("Plik PDF zapisany",2000);
    }
}

// drukowanie pliku

void MyWindow::Print()
{
    QPrintDialog printDlg (&printer,this);
    if (printDlg.exec() == QDialog::Accepted)
    {
        textEdit -> print (&printer);
        Ui::Window::statusBar -> showMessage ("Plik wydrukowany",2000);
    }
}

// podgl¹d wydruku pliku

void MyWindow::PrintPreview ()
{
    PreviewWindow *preview = new PreviewWindow (this,textEdit->document(),&printer);
    preview -> setWindowModality (Qt::WindowModal);
    preview -> setAttribute (Qt::WA_DeleteOnClose);
    preview -> show ();
}

