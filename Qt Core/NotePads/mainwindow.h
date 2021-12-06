#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>      // udostępnia główne okno aplikacji
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QFontDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; } // deklaracja klasy MainWindow w namespace UI
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // deklaracja konstruktora który ma domyślany parametr parent.
    // Nullptr wskazuje że widzet nie ma elementu nadrzędnego (jest to widget najwyższego poziomu)
    MainWindow(QWidget *parent = nullptr);
    // deklaracja destruktora który zwalnia zasoby nabyte przez obiekt podczas jeg cyklu życia
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSaveAs_triggered();

    void on_actionPrint_triggered();

    void on_actionExit_triggered();

    void on_actionPaste_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionFont_triggered();

private:
    Ui::MainWindow *ui; // wskaźnik do klasy MainWindow
    QString currentFile;
};
#endif // MAINWINDOW_H
