#include <QtGui>
#include "ui_window.h"

#ifndef __MYWINDOW_H__
#define __MYWINDOW_H__

class MyWindow: public QMainWindow, private Ui::Window
{
    Q_OBJECT
public:
    MyWindow ();
    ~MyWindow () {};
private:
    QString fileName;
private slots:
    void New ();
    void Open ();
    void Save ();
    void SaveAs ();
    void SavePDF ();
    void PenWidth ();
    void PenColor ();
    void PenStyle (QAction *action);
    void PenCapStyle (QAction *action);
    void PenJoinStyle (QAction *action);
    void DrawingTool (QAction *action);
    void BrushColor ();
    void BrushStyle (QAction *action);
    void Font ();
    void Text ();
    void Print ();
};

#endif // __MYWINDOW_H__
