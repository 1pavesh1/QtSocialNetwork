/****************************************************************************
** Meta object code from reading C++ file 'FeedWindow.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../FeedWindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FeedWindow.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10FeedWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto FeedWindow::qt_create_metaobjectdata<qt_meta_tag_ZN10FeedWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "FeedWindow",
        "on_openMenuButton_clicked",
        "",
        "on_profilePinButton_clicked",
        "on_myPostPinButton_clicked",
        "on_usersPinButton_clicked",
        "on_settingsPinButton_clicked",
        "on_exitPinButton_clicked",
        "on_addPostButton_clicked",
        "on_notificationButton_clicked",
        "on_searchButton_clicked",
        "OnLikeClicked",
        "PostModel",
        "postModel",
        "OnCommentClicked",
        "OnEditComment",
        "CommentModel",
        "commentModel",
        "OnDeleteComment",
        "on_updateFeedButton_clicked",
        "on_backButton_clicked",
        "on_sendCommentButton_clicked",
        "on_cancelEditComment_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_openMenuButton_clicked'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_profilePinButton_clicked'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_myPostPinButton_clicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_usersPinButton_clicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_settingsPinButton_clicked'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_exitPinButton_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_addPostButton_clicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_notificationButton_clicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_searchButton_clicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'OnLikeClicked'
        QtMocHelpers::SlotData<void(const PostModel &)>(11, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 12, 13 },
        }}),
        // Slot 'OnCommentClicked'
        QtMocHelpers::SlotData<void(const PostModel &)>(14, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 12, 13 },
        }}),
        // Slot 'OnEditComment'
        QtMocHelpers::SlotData<void(const CommentModel &)>(15, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 16, 17 },
        }}),
        // Slot 'OnDeleteComment'
        QtMocHelpers::SlotData<void(const CommentModel &)>(18, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 16, 17 },
        }}),
        // Slot 'on_updateFeedButton_clicked'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_backButton_clicked'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_sendCommentButton_clicked'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_cancelEditComment_clicked'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<FeedWindow, qt_meta_tag_ZN10FeedWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject FeedWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10FeedWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10FeedWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10FeedWindowE_t>.metaTypes,
    nullptr
} };

void FeedWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<FeedWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_openMenuButton_clicked(); break;
        case 1: _t->on_profilePinButton_clicked(); break;
        case 2: _t->on_myPostPinButton_clicked(); break;
        case 3: _t->on_usersPinButton_clicked(); break;
        case 4: _t->on_settingsPinButton_clicked(); break;
        case 5: _t->on_exitPinButton_clicked(); break;
        case 6: _t->on_addPostButton_clicked(); break;
        case 7: _t->on_notificationButton_clicked(); break;
        case 8: _t->on_searchButton_clicked(); break;
        case 9: _t->OnLikeClicked((*reinterpret_cast< std::add_pointer_t<PostModel>>(_a[1]))); break;
        case 10: _t->OnCommentClicked((*reinterpret_cast< std::add_pointer_t<PostModel>>(_a[1]))); break;
        case 11: _t->OnEditComment((*reinterpret_cast< std::add_pointer_t<CommentModel>>(_a[1]))); break;
        case 12: _t->OnDeleteComment((*reinterpret_cast< std::add_pointer_t<CommentModel>>(_a[1]))); break;
        case 13: _t->on_updateFeedButton_clicked(); break;
        case 14: _t->on_backButton_clicked(); break;
        case 15: _t->on_sendCommentButton_clicked(); break;
        case 16: _t->on_cancelEditComment_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *FeedWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FeedWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10FeedWindowE_t>.strings))
        return static_cast<void*>(this);
    return BaseWindow::qt_metacast(_clname);
}

int FeedWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
