/****************************************************************************
** Meta object code from reading C++ file 'mywindow.h'
**
** Created: Sat 22. Dec 22:29:33 2007
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mywindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mywindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_MyWindow[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x09,
      20,    9,    9,    9, 0x09,
      33,    9,    9,    9, 0x09,
      43,    9,    9,    9, 0x09,
      71,   59,    9,    9, 0x09,
     105,    9,    9,    9, 0x09,
     112,    9,    9,    9, 0x09,
     128,  119,    9,    9, 0x09,
     165,  157,    9,    9, 0x09,
     198,  187,    9,    9, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_MyWindow[] = {
    "MyWindow\0\0Connect()\0Disconnect()\0"
    "GetFile()\0CancelGetFile()\0item,column\0"
    "ProcessItem(QTreeWidgetItem*,int)\0"
    "CdUp()\0Quit()\0id,error\0"
    "ftpCommandFinished(int,bool)\0urlInfo\0"
    "ftpListInfo(QUrlInfo)\0done,total\0"
    "ftpDataTransferProgress(qint64,qint64)\0"
};

const QMetaObject MyWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyWindow,
      qt_meta_data_MyWindow, 0 }
};

const QMetaObject *MyWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MyWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyWindow))
	return static_cast<void*>(const_cast< MyWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Connect(); break;
        case 1: Disconnect(); break;
        case 2: GetFile(); break;
        case 3: CancelGetFile(); break;
        case 4: ProcessItem((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: CdUp(); break;
        case 6: Quit(); break;
        case 7: ftpCommandFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 8: ftpListInfo((*reinterpret_cast< const QUrlInfo(*)>(_a[1]))); break;
        case 9: ftpDataTransferProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        }
        _id -= 10;
    }
    return _id;
}
