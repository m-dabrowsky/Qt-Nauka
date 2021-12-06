#include <QtGui>
#include <QtNetwork>
#include "ui_window.h"

#ifndef __MYWINDOW_H__
#define __MYWINDOW_H__

class MyWindow: public QWidget, private Ui::Form
{
    Q_OBJECT
public:
    MyWindow ();
    ~MyWindow () {}
protected slots:
    void GetFile ();
    void httpRequestFinished (int requestId, bool error);
    void httpResponseHeaderReceived(const QHttpResponseHeader & header);
    void httpDataReadProgress (int bytesRead, int totalBytes);
    void CancelGetFile ();
    void Quit ();
private:
    QHttp *http;
    QFile *file;
    QProgressDialog *progressDialog;
};        

#endif // __MYWINDOW_H__
