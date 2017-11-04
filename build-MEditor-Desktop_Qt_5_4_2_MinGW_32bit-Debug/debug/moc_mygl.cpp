/****************************************************************************
** Meta object code from reading C++ file 'mygl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MEditor/src/mygl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mygl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyGL_t {
    QByteArrayData data[38];
    char stringdata[408];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyGL_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyGL_t qt_meta_stringdata_MyGL = {
    {
QT_MOC_LITERAL(0, 0, 4), // "MyGL"
QT_MOC_LITERAL(1, 5, 12), // "setClickFace"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 5), // "Face*"
QT_MOC_LITERAL(4, 25, 1), // "f"
QT_MOC_LITERAL(5, 27, 16), // "setClickHalfEdge"
QT_MOC_LITERAL(6, 44, 9), // "HalfEdge*"
QT_MOC_LITERAL(7, 54, 1), // "h"
QT_MOC_LITERAL(8, 56, 14), // "setClickVertex"
QT_MOC_LITERAL(9, 71, 7), // "Vertex*"
QT_MOC_LITERAL(10, 79, 1), // "v"
QT_MOC_LITERAL(11, 81, 10), // "updateList"
QT_MOC_LITERAL(12, 92, 21), // "std::vector<Vertex*>&"
QT_MOC_LITERAL(13, 114, 2), // "vV"
QT_MOC_LITERAL(14, 117, 23), // "std::vector<HalfEdge*>&"
QT_MOC_LITERAL(15, 141, 2), // "hV"
QT_MOC_LITERAL(16, 144, 19), // "std::vector<Face*>&"
QT_MOC_LITERAL(17, 164, 2), // "fV"
QT_MOC_LITERAL(18, 167, 19), // "slot_setCurrentFace"
QT_MOC_LITERAL(19, 187, 23), // "slot_setCurrentHalfEdge"
QT_MOC_LITERAL(20, 211, 21), // "slot_setCurrentVertex"
QT_MOC_LITERAL(21, 233, 14), // "slot_spiltEdge"
QT_MOC_LITERAL(22, 248, 20), // "slot_triangulateFace"
QT_MOC_LITERAL(23, 269, 14), // "slot_subdivide"
QT_MOC_LITERAL(24, 284, 12), // "slot_extrude"
QT_MOC_LITERAL(25, 297, 14), // "slot_bevelEdge"
QT_MOC_LITERAL(26, 312, 13), // "slot_changeFR"
QT_MOC_LITERAL(27, 326, 1), // "r"
QT_MOC_LITERAL(28, 328, 13), // "slot_changeFG"
QT_MOC_LITERAL(29, 342, 1), // "g"
QT_MOC_LITERAL(30, 344, 13), // "slot_changeFB"
QT_MOC_LITERAL(31, 358, 1), // "b"
QT_MOC_LITERAL(32, 360, 13), // "slot_changeVX"
QT_MOC_LITERAL(33, 374, 1), // "x"
QT_MOC_LITERAL(34, 376, 13), // "slot_changeVY"
QT_MOC_LITERAL(35, 390, 1), // "y"
QT_MOC_LITERAL(36, 392, 13), // "slot_changeVZ"
QT_MOC_LITERAL(37, 406, 1) // "z"

    },
    "MyGL\0setClickFace\0\0Face*\0f\0setClickHalfEdge\0"
    "HalfEdge*\0h\0setClickVertex\0Vertex*\0v\0"
    "updateList\0std::vector<Vertex*>&\0vV\0"
    "std::vector<HalfEdge*>&\0hV\0"
    "std::vector<Face*>&\0fV\0slot_setCurrentFace\0"
    "slot_setCurrentHalfEdge\0slot_setCurrentVertex\0"
    "slot_spiltEdge\0slot_triangulateFace\0"
    "slot_subdivide\0slot_extrude\0slot_bevelEdge\0"
    "slot_changeFR\0r\0slot_changeFG\0g\0"
    "slot_changeFB\0b\0slot_changeVX\0x\0"
    "slot_changeVY\0y\0slot_changeVZ\0z"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGL[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x06 /* Public */,
       5,    1,  107,    2, 0x06 /* Public */,
       8,    1,  110,    2, 0x06 /* Public */,
      11,    3,  113,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    1,  120,    2, 0x0a /* Public */,
      19,    1,  123,    2, 0x0a /* Public */,
      20,    1,  126,    2, 0x0a /* Public */,
      21,    0,  129,    2, 0x0a /* Public */,
      22,    0,  130,    2, 0x0a /* Public */,
      23,    0,  131,    2, 0x0a /* Public */,
      24,    0,  132,    2, 0x0a /* Public */,
      25,    0,  133,    2, 0x0a /* Public */,
      26,    1,  134,    2, 0x0a /* Public */,
      28,    1,  137,    2, 0x0a /* Public */,
      30,    1,  140,    2, 0x0a /* Public */,
      32,    1,  143,    2, 0x0a /* Public */,
      34,    1,  146,    2, 0x0a /* Public */,
      36,    1,  149,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 14, 0x80000000 | 16,   13,   15,   17,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   27,
    QMetaType::Void, QMetaType::Double,   29,
    QMetaType::Void, QMetaType::Double,   31,
    QMetaType::Void, QMetaType::Double,   33,
    QMetaType::Void, QMetaType::Double,   35,
    QMetaType::Void, QMetaType::Double,   37,

       0        // eod
};

void MyGL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyGL *_t = static_cast<MyGL *>(_o);
        switch (_id) {
        case 0: _t->setClickFace((*reinterpret_cast< Face*(*)>(_a[1]))); break;
        case 1: _t->setClickHalfEdge((*reinterpret_cast< HalfEdge*(*)>(_a[1]))); break;
        case 2: _t->setClickVertex((*reinterpret_cast< Vertex*(*)>(_a[1]))); break;
        case 3: _t->updateList((*reinterpret_cast< std::vector<Vertex*>(*)>(_a[1])),(*reinterpret_cast< std::vector<HalfEdge*>(*)>(_a[2])),(*reinterpret_cast< std::vector<Face*>(*)>(_a[3]))); break;
        case 4: _t->slot_setCurrentFace((*reinterpret_cast< Face*(*)>(_a[1]))); break;
        case 5: _t->slot_setCurrentHalfEdge((*reinterpret_cast< HalfEdge*(*)>(_a[1]))); break;
        case 6: _t->slot_setCurrentVertex((*reinterpret_cast< Vertex*(*)>(_a[1]))); break;
        case 7: _t->slot_spiltEdge(); break;
        case 8: _t->slot_triangulateFace(); break;
        case 9: _t->slot_subdivide(); break;
        case 10: _t->slot_extrude(); break;
        case 11: _t->slot_bevelEdge(); break;
        case 12: _t->slot_changeFR((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->slot_changeFG((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->slot_changeFB((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->slot_changeVX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->slot_changeVY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->slot_changeVZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyGL::*_t)(Face * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::setClickFace)) {
                *result = 0;
            }
        }
        {
            typedef void (MyGL::*_t)(HalfEdge * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::setClickHalfEdge)) {
                *result = 1;
            }
        }
        {
            typedef void (MyGL::*_t)(Vertex * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::setClickVertex)) {
                *result = 2;
            }
        }
        {
            typedef void (MyGL::*_t)(std::vector<Vertex*> & , std::vector<HalfEdge*> & , std::vector<Face*> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::updateList)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject MyGL::staticMetaObject = {
    { &GLWidget277::staticMetaObject, qt_meta_stringdata_MyGL.data,
      qt_meta_data_MyGL,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyGL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyGL::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyGL.stringdata))
        return static_cast<void*>(const_cast< MyGL*>(this));
    return GLWidget277::qt_metacast(_clname);
}

int MyGL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GLWidget277::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void MyGL::setClickFace(Face * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyGL::setClickHalfEdge(HalfEdge * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyGL::setClickVertex(Vertex * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyGL::updateList(std::vector<Vertex*> & _t1, std::vector<HalfEdge*> & _t2, std::vector<Face*> & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
