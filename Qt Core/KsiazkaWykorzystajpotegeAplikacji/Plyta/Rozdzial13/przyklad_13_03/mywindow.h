#include <QtGui>        

#ifndef __MYWINDOW_H__
#define __MYWINDOW_H__

class MyWindow: public QMainWindow
{
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
};        

#endif // __MYWINDOW_H__
