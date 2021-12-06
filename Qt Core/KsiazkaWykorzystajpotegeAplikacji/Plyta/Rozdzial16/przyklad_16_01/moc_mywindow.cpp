/****************************************************************************
** Meta object code from reading C++ file 'mywindow.h'
**
** Created: Tue 11. Dec 05:09:30 2007
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
       7,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x09,
      28,    9,    9,    9, 0x09,
      49,    9,    9,    9, 0x09,
      73,    9,    9,    9, 0x09,
      94,    9,    9,    9, 0x09,
     114,    9,    9,    9, 0x09,
     134,    9,    9,    9, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_MyWindow[] = {
    "MyWindow\0\0MessageBoxAbout()\0"
    "MessageBoxCritical()\0MessageBoxInformation()\0"
    "MessageBoxQuestion()\0MessageBoxWarning()\0"
    "MessageBoxAboutQt()\0ErrorMessage()\0"
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
        case 0: MessageBoxAbout(); break;
        case 1: MessageBoxCritical(); break;
        case 2: MessageBoxInformation(); break;
        case 3: MessageBoxQuestion(); break;
        case 4: MessageBoxWarning(); break;
        case 5: MessageBoxAboutQt(); break;
        case 6: ErrorMessage(); break;
        }
        _id -= 7;
    }
    return _id;
}
