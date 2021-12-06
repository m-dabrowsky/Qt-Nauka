#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QFileDialog>

class MyWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MyWindow(QWidget *parent = nullptr);

private:
    QString fileName;               // Nazwa pliku
    QTextEdit *textEdit;            // Główny widget w którym będzie się pisało
    QMenu *fileMenu;                // do stworzenia menu
    QAction *fileMenuNew;           // opcja Nowy
    QAction *fileMenuOpen;          // opcja Otwórz
    QAction *fileMenuSave;          // opcja Zapisz
    QAction *fileMenuSaveAs;        // opcja Zapisz jako
    QAction *fileMenuQuit;          // opcja wyjdź
    QToolBar *fileToolBar;          // do Tool Baru
signals:
private slots:
    // Działania na plikach
    void New();
    void Open();
    void Save();
    void SaveAs();

};

#endif // MYWINDOW_H
