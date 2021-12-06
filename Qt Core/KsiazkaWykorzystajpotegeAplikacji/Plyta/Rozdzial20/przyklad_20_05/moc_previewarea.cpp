/****************************************************************************
** Meta object code from reading C++ file 'previewarea.h'
**
** Created: Sun 27. Jan 06:18:29 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "previewarea.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'previewarea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_PreviewArea[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      22,   12,   12,   12, 0x0a,
      32,   12,   12,   12, 0x0a,
      47,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PreviewArea[] = {
    "PreviewArea\0\0zoomIn()\0zoomOut()\0"
    "previousPage()\0nextPage()\0"
};

const QMetaObject PreviewArea::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PreviewArea,
      qt_meta_data_PreviewArea, 0 }
};

const QMetaObject *PreviewArea::metaObject() const
{
    return &staticMetaObject;
}

void *PreviewArea::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PreviewArea))
	return static_cast<void*>(const_cast< PreviewArea*>(this));
    return QWidget::qt_metacast(_clname);
}

int PreviewArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: zoomIn(); break;
        case 1: zoomOut(); break;
        case 2: previousPage(); break;
        case 3: nextPage(); break;
        }
        _id -= 4;
    }
    return _id;
}
