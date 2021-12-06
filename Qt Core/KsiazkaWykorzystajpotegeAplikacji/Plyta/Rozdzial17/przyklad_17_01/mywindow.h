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
    void Connect ();
    void Disconnect ();
    void GetFile ();
    void CancelGetFile ();
    void ProcessItem (QTreeWidgetItem *item, int column);
    void CdUp();
    void Quit ();
    void ftpCommandFinished (int id, bool error);
    void ftpListInfo (const QUrlInfo & urlInfo);
    void ftpDataTransferProgress (qint64 done, qint64 total);
private:
    QFtp *ftp;
    QFile *file;
    QProgressDialog *progressDialog;
};        

#endif // __MYWINDOW_H__
