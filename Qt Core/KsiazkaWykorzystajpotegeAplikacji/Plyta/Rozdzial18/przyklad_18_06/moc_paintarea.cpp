/****************************************************************************
** Meta object code from reading C++ file 'paintarea.h'
**
** Created: Tue 15. Jan 20:58:57 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "paintarea.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paintarea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_PaintArea[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      27,   24,   10,   10, 0x0a,
      43,   24,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PaintArea[] = {
    "PaintArea\0\0clearImage()\0on\0setPolyAA(bool)\0"
    "setTextAA(bool)\0"
};

const QMetaObject PaintArea::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PaintArea,
      qt_meta_data_PaintArea, 0 }
};

const QMetaObject *PaintArea::metaObject() const
{
    return &staticMetaObject;
}

void *PaintArea::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PaintArea))
	return static_cast<void*>(const_cast< PaintArea*>(this));
    return QWidget::qt_metacast(_clname);
}

int PaintArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: clearImage(); break;
        case 1: setPolyAA((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: setTextAA((*reinterpret_cast< bool(*)>(_a[1]))); break;
        }
        _id -= 3;
    }
    return _id;
}
