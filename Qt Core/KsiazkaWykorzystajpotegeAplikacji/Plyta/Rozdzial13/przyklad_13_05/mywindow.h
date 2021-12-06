#include <QtGui>        

#ifndef __MYWINDOW_H__
#define __MYWINDOW_H__

class MyWindow: public QMainWindow
{
    Q_OBJECT
public:
    MyWindow ();
    ~MyWindow ();
private:
    QString fileName;
    QTextEdit *textEdit;
    QMenu *fileMenu;
    QAction *fileMenuNew;
    QAction *fileMenuOpen;
    QAction *fileMenuSave;
    QAction *fileMenuSaveAs;
    QAction *fileMenuQuit;
    QToolBar *fileToolBar;
private slots:
    void New ();
    void Open ();
    void Save ();
    void SaveAs ();
};        

#endif // __MYWINDOW_H__
