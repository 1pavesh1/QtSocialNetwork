/****************************************************************************
** Meta object code from reading C++ file 'PostItemWidget.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../CustomWidgets/PostItemWidget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PostItemWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN14PostItemWidgetE_t {};
} // unnamed namespace

template <> constexpr inline auto PostItemWidget::qt_create_metaobjectdata<qt_meta_tag_ZN14PostItemWidgetE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "PostItemWidget",
        "likeClicked",
        "",
        "postId",
        "commentClicked",
        "downloadClicked",
        "editClicked",
        "deleteClicked",
        "downloadAllClicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'likeClicked'
        QtMocHelpers::SignalData<void(qint32)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'commentClicked'
        QtMocHelpers::SignalData<void(qint32)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'downloadClicked'
        QtMocHelpers::SignalData<void(qint32)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'editClicked'
        QtMocHelpers::SignalData<void(qint32)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'deleteClicked'
        QtMocHelpers::SignalData<void(qint32)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'downloadAllClicked'
        QtMocHelpers::SignalData<void(qint32)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<PostItemWidget, qt_meta_tag_ZN14PostItemWidgetE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject PostItemWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14PostItemWidgetE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14PostItemWidgetE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14PostItemWidgetE_t>.metaTypes,
    nullptr
} };

void PostItemWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<PostItemWidget *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->likeClicked((*reinterpret_cast< std::add_pointer_t<qint32>>(_a[1]))); break;
        case 1: _t->commentClicked((*reinterpret_cast< std::add_pointer_t<qint32>>(_a[1]))); break;
        case 2: _t->downloadClicked((*reinterpret_cast< std::add_pointer_t<qint32>>(_a[1]))); break;
        case 3: _t->editClicked((*reinterpret_cast< std::add_pointer_t<qint32>>(_a[1]))); break;
        case 4: _t->deleteClicked((*reinterpret_cast< std::add_pointer_t<qint32>>(_a[1]))); break;
        case 5: _t->downloadAllClicked((*reinterpret_cast< std::add_pointer_t<qint32>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (PostItemWidget::*)(qint32 )>(_a, &PostItemWidget::likeClicked, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (PostItemWidget::*)(qint32 )>(_a, &PostItemWidget::commentClicked, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (PostItemWidget::*)(qint32 )>(_a, &PostItemWidget::downloadClicked, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (PostItemWidget::*)(qint32 )>(_a, &PostItemWidget::editClicked, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (PostItemWidget::*)(qint32 )>(_a, &PostItemWidget::deleteClicked, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (PostItemWidget::*)(qint32 )>(_a, &PostItemWidget::downloadAllClicked, 5))
            return;
    }
}

const QMetaObject *PostItemWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PostItemWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14PostItemWidgetE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PostItemWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void PostItemWidget::likeClicked(qint32 _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void PostItemWidget::commentClicked(qint32 _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void PostItemWidget::downloadClicked(qint32 _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void PostItemWidget::editClicked(qint32 _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void PostItemWidget::deleteClicked(qint32 _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void PostItemWidget::downloadAllClicked(qint32 _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}
QT_WARNING_POP
