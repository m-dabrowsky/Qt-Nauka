#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)         // definicja konstruktora
    : QMainWindow(parent)                       // wywołuje konstruktor
    , ui(new Ui::MainWindow)                    // tworzy instancje klasy UI
{
    ui->setupUi(this);                          // konfiguruje UI
    this->setCentralWidget(ui->textEdit);



}

MainWindow::~MainWindow()
{
    delete ui; // destruktor usuwa UI
}

void MainWindow::on_actionNew_triggered()
{
    currentFile.clear();                // Czyści bufor, ale nie ekran tekstu
    ui->textEdit->setText(QString());   // powoduje nie wyświetlenie żadnego tekstu
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the File"); // otwiera okno umożliwiające wybór pliku
    QFile file(fileName);                                                   // plik przechowywany do wykonania działań na plikach
    currentFile = fileName;                                                 // currentFile jest QString
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString() );
        return;
    }

    setWindowTitle(fileName);
    QTextStream in(&file);                                                  // przesłanie danych do in
    QString text = in.readAll();                                            // odczyt danych z in
    ui->textEdit->setText(text);                                            // wyświetlenie zawartości tekstu
    file.close();
}




void MainWindow::on_actionSave_triggered()
{
    QString fileName;
    // If we don't have a filename from before, get one.
    if (currentFile.isEmpty()) {
        fileName = QFileDialog::getSaveFileName(this, "Save");
        currentFile = fileName;
    } else {
        fileName = currentFile;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }

    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();


}


void MainWindow::on_actionSaveAs_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}


void MainWindow::on_actionPrint_triggered()
{

    QPrinter printer;
    printer.setPrinterName("Printer Name");
    QPrintDialog dialog(&printer, this);
    if (dialog.exec() == QDialog::Rejected)
        return;

    ui->textEdit->print(&printer);


}


void MainWindow::on_actionExit_triggered()
{
    QCoreApplication::quit();
}





void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionFont_triggered()
{
    bool fontSelected;
    QFont font = QFontDialog::getFont(&fontSelected, this);
    if (fontSelected)
        ui->textEdit->setFont(font);
}

