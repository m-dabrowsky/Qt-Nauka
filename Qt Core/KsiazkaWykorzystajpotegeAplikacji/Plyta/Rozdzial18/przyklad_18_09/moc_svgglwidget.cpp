/****************************************************************************
** Meta object code from reading C++ file 'svgglwidget.h'
**
** Created: Wed 16. Jan 21:48:58 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "svgglwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'svgglwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_SvgGLWidget[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      25,   13,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SvgGLWidget[] = {
    "SvgGLWidget\0\0antialiased\0setAntialiased(bool)\0"
};

const QMetaObject SvgGLWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_SvgGLWidget,
      qt_meta_data_SvgGLWidget, 0 }
};

const QMetaObject *SvgGLWidget::metaObject() const
{
    return &staticMetaObject;
}

void *SvgGLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SvgGLWidget))
	return static_cast<void*>(const_cast< SvgGLWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int SvgGLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setAntialiased((*reinterpret_cast< bool(*)>(_a[1]))); break;
        }
        _id -= 1;
    }
    return _id;
}
