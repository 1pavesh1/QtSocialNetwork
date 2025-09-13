/****************************************************************************
** Meta object code from reading C++ file 'PostItemWidget.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../CustomWidgets/PostItemWidget.h"
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
        "ClickOnLikeButton",
        "",
        "PostModel",
        "postModel",
        "ClickOnCommentButton",
        "ClickOnDownload",
        "ClickOnEdit",
        "ClickOnDelete"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'ClickOnLikeButton'
        QtMocHelpers::SignalData<void(const PostModel &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'ClickOnCommentButton'
        QtMocHelpers::SignalData<void(const PostModel &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'ClickOnDownload'
        QtMocHelpers::SignalData<void(const PostModel &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'ClickOnEdit'
        QtMocHelpers::SignalData<void(const PostModel &)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'ClickOnDelete'
        QtMocHelpers::SignalData<void(const PostModel &)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
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
        case 0: _t->ClickOnLikeButton((*reinterpret_cast< std::add_pointer_t<PostModel>>(_a[1]))); break;
        case 1: _t->ClickOnCommentButton((*reinterpret_cast< std::add_pointer_t<PostModel>>(_a[1]))); break;
        case 2: _t->ClickOnDownload((*reinterpret_cast< std::add_pointer_t<PostModel>>(_a[1]))); break;
        case 3: _t->ClickOnEdit((*reinterpret_cast< std::add_pointer_t<PostModel>>(_a[1]))); break;
        case 4: _t->ClickOnDelete((*reinterpret_cast< std::add_pointer_t<PostModel>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (PostItemWidget::*)(const PostModel & )>(_a, &PostItemWidget::ClickOnLikeButton, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (PostItemWidget::*)(const PostModel & )>(_a, &PostItemWidget::ClickOnCommentButton, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (PostItemWidget::*)(const PostModel & )>(_a, &PostItemWidget::ClickOnDownload, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (PostItemWidget::*)(const PostModel & )>(_a, &PostItemWidget::ClickOnEdit, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (PostItemWidget::*)(const PostModel & )>(_a, &PostItemWidget::ClickOnDelete, 4))
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
    if (!strcmp(_clname, "CustomWidget"))
        return static_cast< CustomWidget*>(this);
    return QWidget::qt_metacast(_clname);
}

int PostItemWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void PostItemWidget::ClickOnLikeButton(const PostModel & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void PostItemWidget::ClickOnCommentButton(const PostModel & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void PostItemWidget::ClickOnDownload(const PostModel & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void PostItemWidget::ClickOnEdit(const PostModel & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void PostItemWidget::ClickOnDelete(const PostModel & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}
QT_WARNING_POP
