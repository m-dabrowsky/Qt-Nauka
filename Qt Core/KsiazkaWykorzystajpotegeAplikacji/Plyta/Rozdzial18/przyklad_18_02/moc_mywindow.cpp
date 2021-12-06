/****************************************************************************
** Meta object code from reading C++ file 'mywindow.h'
**
** Created: Thu 10. Jan 18:43:34 2008
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
       9,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      16,    9,    9,    9, 0x08,
      23,    9,    9,    9, 0x08,
      30,    9,    9,    9, 0x08,
      39,    9,    9,    9, 0x08,
      50,    9,    9,    9, 0x08,
      68,   61,    9,    9, 0x08,
      87,   61,    9,    9, 0x08,
     109,   61,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MyWindow[] = {
    "MyWindow\0\0New()\0Open()\0Save()\0SaveAs()\0"
    "PenWidth()\0PenColor()\0action\0"
    "PenStyle(QAction*)\0PenCapStyle(QAction*)\0"
    "PenJoinStyle(QAction*)\0"
};

const QMetaObject MyWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MyWindow,
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
    return QMainWindow::qt_metacast(_clname);
}

int MyWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: New(); break;
        case 1: Open(); break;
        case 2: Save(); break;
        case 3: SaveAs(); break;
        case 4: PenWidth(); break;
        case 5: PenColor(); break;
        case 6: PenStyle((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 7: PenCapStyle((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 8: PenJoinStyle((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        }
        _id -= 9;
    }
    return _id;
}
