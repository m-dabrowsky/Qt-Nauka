#include <QtGui>
#include "ui_preview_window.h"
#include "previewarea.h"

#ifndef __PREVIEWWINDOW_H__
#define __PREVIEWWINDOW_H__

class PreviewWindow: public QMainWindow, private Ui::PrevWindow
{
    Q_OBJECT
public:
    PreviewWindow (QWidget *parent, QTextDocument *document, QPrinter *print);
    virtual ~PreviewWindow ();
private slots:
    void Print ();
    void PageSetup ();
private:
    QTextDocument *textDocument;
    PreviewArea *previewArea;
    QPrinter *printer;
};

#endif // __PREVIEWWINDOW_H__
