/****************************************************************************
** Meta object code from reading C++ file 'SocketManager.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Managers/SocketManager.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SocketManager.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13SocketManagerE_t {};
} // unnamed namespace

template <> constexpr inline auto SocketManager::qt_create_metaobjectdata<qt_meta_tag_ZN13SocketManagerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "SocketManager",
        "UserReg",
        "",
        "UserModel",
        "userModel",
        "UserRegFailed",
        "UserRegRepeat",
        "UserAuth",
        "UserAuthServer",
        "UserAuthFailed",
        "UserUpdateData",
        "UserUpdateName",
        "UserUpdateFailed",
        "UserChangePhoto",
        "UserChangePhotoFailed",
        "UserIsMain",
        "UserNotMain",
        "GetUsers",
        "UserList",
        "userList",
        "GetUsersFailed",
        "GetFriends",
        "GetFriendsFailed",
        "CheckRelationship",
        "TypeQuery",
        "relationship",
        "GetNotifications",
        "NotificationList",
        "notificationList",
        "GetNotificationsFailed",
        "AcceptNotification",
        "NotificationModel",
        "notificationModel",
        "CancelNotification",
        "AddFriend",
        "typeQuery",
        "CancelFriend",
        "DeleteFriend",
        "AddPost",
        "AddPostFailed",
        "GetPost",
        "PostList",
        "postList",
        "GetPostFailed",
        "GetUserPost",
        "GetUserPostFailed",
        "DeletePost",
        "PostModel",
        "postModel",
        "DeletePostFailed",
        "EditPost",
        "EditPostFailed",
        "LikePost",
        "LikeModel",
        "likeModel",
        "LikePostFailed",
        "AddCommentPost",
        "CommentModel",
        "commentModel",
        "AddCommentPostFailed",
        "EditCommentPost",
        "EditCommentPostFailed",
        "DeleteCommentPost",
        "DeleteCommentPostFailed",
        "GetCommentPost",
        "CommentList",
        "commentList",
        "GetCommentPostFailed"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'UserReg'
        QtMocHelpers::SignalData<void(const UserModel &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'UserRegFailed'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'UserRegRepeat'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'UserAuth'
        QtMocHelpers::SignalData<void(const UserModel &)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'UserAuthServer'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'UserAuthFailed'
        QtMocHelpers::SignalData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'UserUpdateData'
        QtMocHelpers::SignalData<void(const UserModel &)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'UserUpdateName'
        QtMocHelpers::SignalData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'UserUpdateFailed'
        QtMocHelpers::SignalData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'UserChangePhoto'
        QtMocHelpers::SignalData<void(const UserModel &)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'UserChangePhotoFailed'
        QtMocHelpers::SignalData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'UserIsMain'
        QtMocHelpers::SignalData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'UserNotMain'
        QtMocHelpers::SignalData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'GetUsers'
        QtMocHelpers::SignalData<void(const UserList &)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 18, 19 },
        }}),
        // Signal 'GetUsersFailed'
        QtMocHelpers::SignalData<void()>(20, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'GetFriends'
        QtMocHelpers::SignalData<void(const UserList &)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 18, 19 },
        }}),
        // Signal 'GetFriendsFailed'
        QtMocHelpers::SignalData<void()>(22, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'CheckRelationship'
        QtMocHelpers::SignalData<void(const TypeQuery &)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 24, 25 },
        }}),
        // Signal 'GetNotifications'
        QtMocHelpers::SignalData<void(const NotificationList &)>(26, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 27, 28 },
        }}),
        // Signal 'GetNotificationsFailed'
        QtMocHelpers::SignalData<void()>(29, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'AcceptNotification'
        QtMocHelpers::SignalData<void(const NotificationModel &)>(30, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 31, 32 },
        }}),
        // Signal 'CancelNotification'
        QtMocHelpers::SignalData<void(const NotificationModel &)>(33, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 31, 32 },
        }}),
        // Signal 'AddFriend'
        QtMocHelpers::SignalData<void(const TypeQuery &)>(34, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 24, 35 },
        }}),
        // Signal 'CancelFriend'
        QtMocHelpers::SignalData<void(const TypeQuery &)>(36, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 24, 35 },
        }}),
        // Signal 'DeleteFriend'
        QtMocHelpers::SignalData<void(const TypeQuery &)>(37, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 24, 35 },
        }}),
        // Signal 'AddPost'
        QtMocHelpers::SignalData<void()>(38, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'AddPostFailed'
        QtMocHelpers::SignalData<void()>(39, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'GetPost'
        QtMocHelpers::SignalData<void(const PostList &)>(40, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 41, 42 },
        }}),
        // Signal 'GetPostFailed'
        QtMocHelpers::SignalData<void()>(43, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'GetUserPost'
        QtMocHelpers::SignalData<void(const PostList &)>(44, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 41, 42 },
        }}),
        // Signal 'GetUserPostFailed'
        QtMocHelpers::SignalData<void()>(45, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'DeletePost'
        QtMocHelpers::SignalData<void(const PostModel &)>(46, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 47, 48 },
        }}),
        // Signal 'DeletePostFailed'
        QtMocHelpers::SignalData<void()>(49, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'EditPost'
        QtMocHelpers::SignalData<void(const PostModel &)>(50, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 47, 48 },
        }}),
        // Signal 'EditPostFailed'
        QtMocHelpers::SignalData<void()>(51, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'LikePost'
        QtMocHelpers::SignalData<void(const LikeModel &)>(52, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 53, 54 },
        }}),
        // Signal 'LikePostFailed'
        QtMocHelpers::SignalData<void()>(55, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'AddCommentPost'
        QtMocHelpers::SignalData<void(const CommentModel &)>(56, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 57, 58 },
        }}),
        // Signal 'AddCommentPostFailed'
        QtMocHelpers::SignalData<void()>(59, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'EditCommentPost'
        QtMocHelpers::SignalData<void(const CommentModel &)>(60, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 57, 58 },
        }}),
        // Signal 'EditCommentPostFailed'
        QtMocHelpers::SignalData<void()>(61, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'DeleteCommentPost'
        QtMocHelpers::SignalData<void(const CommentModel &)>(62, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 57, 58 },
        }}),
        // Signal 'DeleteCommentPostFailed'
        QtMocHelpers::SignalData<void()>(63, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'GetCommentPost'
        QtMocHelpers::SignalData<void(const CommentList &)>(64, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 65, 66 },
        }}),
        // Signal 'GetCommentPostFailed'
        QtMocHelpers::SignalData<void()>(67, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<SocketManager, qt_meta_tag_ZN13SocketManagerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject SocketManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QTcpSocket::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13SocketManagerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13SocketManagerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13SocketManagerE_t>.metaTypes,
    nullptr
} };

void SocketManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SocketManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->UserReg((*reinterpret_cast< std::add_pointer_t<UserModel>>(_a[1]))); break;
        case 1: _t->UserRegFailed(); break;
        case 2: _t->UserRegRepeat(); break;
        case 3: _t->UserAuth((*reinterpret_cast< std::add_pointer_t<UserModel>>(_a[1]))); break;
        case 4: _t->UserAuthServer(); break;
        case 5: _t->UserAuthFailed(); break;
        case 6: _t->UserUpdateData((*reinterpret_cast< std::add_pointer_t<UserModel>>(_a[1]))); break;
        case 7: _t->UserUpdateName(); break;
        case 8: _t->UserUpdateFailed(); break;
        case 9: _t->UserChangePhoto((*reinterpret_cast< std::add_pointer_t<UserModel>>(_a[1]))); break;
        case 10: _t->UserChangePhotoFailed(); break;
        case 11: _t->UserIsMain(); break;
        case 12: _t->UserNotMain(); break;
        case 13: _t->GetUsers((*reinterpret_cast< std::add_pointer_t<UserList>>(_a[1]))); break;
        case 14: _t->GetUsersFailed(); break;
        case 15: _t->GetFriends((*reinterpret_cast< std::add_pointer_t<UserList>>(_a[1]))); break;
        case 16: _t->GetFriendsFailed(); break;
        case 17: _t->CheckRelationship((*reinterpret_cast< std::add_pointer_t<TypeQuery>>(_a[1]))); break;
        case 18: _t->GetNotifications((*reinterpret_cast< std::add_pointer_t<NotificationList>>(_a[1]))); break;
        case 19: _t->GetNotificationsFailed(); break;
        case 20: _t->AcceptNotification((*reinterpret_cast< std::add_pointer_t<NotificationModel>>(_a[1]))); break;
        case 21: _t->CancelNotification((*reinterpret_cast< std::add_pointer_t<NotificationModel>>(_a[1]))); break;
        case 22: _t->AddFriend((*reinterpret_cast< std::add_pointer_t<TypeQuery>>(_a[1]))); break;
        case 23: _t->CancelFriend((*reinterpret_cast< std::add_pointer_t<TypeQuery>>(_a[1]))); break;
        case 24: _t->DeleteFriend((*reinterpret_cast< std::add_pointer_t<TypeQuery>>(_a[1]))); break;
        case 25: _t->AddPost(); break;
        case 26: _t->AddPostFailed(); break;
        case 27: _t->GetPost((*reinterpret_cast< std::add_pointer_t<PostList>>(_a[1]))); break;
        case 28: _t->GetPostFailed(); break;
        case 29: _t->GetUserPost((*reinterpret_cast< std::add_pointer_t<PostList>>(_a[1]))); break;
        case 30: _t->GetUserPostFailed(); break;
        case 31: _t->DeletePost((*reinterpret_cast< std::add_pointer_t<PostModel>>(_a[1]))); break;
        case 32: _t->DeletePostFailed(); break;
        case 33: _t->EditPost((*reinterpret_cast< std::add_pointer_t<PostModel>>(_a[1]))); break;
        case 34: _t->EditPostFailed(); break;
        case 35: _t->LikePost((*reinterpret_cast< std::add_pointer_t<LikeModel>>(_a[1]))); break;
        case 36: _t->LikePostFailed(); break;
        case 37: _t->AddCommentPost((*reinterpret_cast< std::add_pointer_t<CommentModel>>(_a[1]))); break;
        case 38: _t->AddCommentPostFailed(); break;
        case 39: _t->EditCommentPost((*reinterpret_cast< std::add_pointer_t<CommentModel>>(_a[1]))); break;
        case 40: _t->EditCommentPostFailed(); break;
        case 41: _t->DeleteCommentPost((*reinterpret_cast< std::add_pointer_t<CommentModel>>(_a[1]))); break;
        case 42: _t->DeleteCommentPostFailed(); break;
        case 43: _t->GetCommentPost((*reinterpret_cast< std::add_pointer_t<CommentList>>(_a[1]))); break;
        case 44: _t->GetCommentPostFailed(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)(const UserModel & )>(_a, &SocketManager::UserReg, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)()>(_a, &SocketManager::UserRegFailed, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)()>(_a, &SocketManager::UserRegRepeat, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)(const UserModel & )>(_a, &SocketManager::UserAuth, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)()>(_a, &SocketManager::UserAuthServer, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)()>(_a, &SocketManager::UserAuthFailed, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)(const UserModel & )>(_a, &SocketManager::UserUpdateData, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)()>(_a, &SocketManager::UserUpdateName, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)()>(_a, &SocketManager::UserUpdateFailed, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)(const UserModel & )>(_a, &SocketManager::UserChangePhoto, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)()>(_a, &SocketManager::UserChangePhotoFailed, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)()>(_a, &SocketManager::UserIsMain, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)()>(_a, &SocketManager::UserNotMain, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)(const UserList & )>(_a, &SocketManager::GetUsers, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)()>(_a, &SocketManager::GetUsersFailed, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)(const UserList & )>(_a, &SocketManager::GetFriends, 15))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)()>(_a, &SocketManager::GetFriendsFailed, 16))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)(const TypeQuery & )>(_a, &SocketManager::CheckRelationship, 17))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)(const NotificationList & )>(_a, &SocketManager::GetNotifications, 18))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)()>(_a, &SocketManager::GetNotificationsFailed, 19))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)(const NotificationModel & )>(_a, &SocketManager::AcceptNotification, 20))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)(const NotificationModel & )>(_a, &SocketManager::CancelNotification, 21))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)(const TypeQuery & )>(_a, &SocketManager::AddFriend, 22))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)(const TypeQuery & )>(_a, &SocketManager::CancelFriend, 23))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)(const TypeQuery & )>(_a, &SocketManager::DeleteFriend, 24))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)()>(_a, &SocketManager::AddPost, 25))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)()>(_a, &SocketManager::AddPostFailed, 26))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)(const PostList & )>(_a, &SocketManager::GetPost, 27))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)()>(_a, &SocketManager::GetPostFailed, 28))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)(const PostList & )>(_a, &SocketManager::GetUserPost, 29))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)()>(_a, &SocketManager::GetUserPostFailed, 30))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)(const PostModel & )>(_a, &SocketManager::DeletePost, 31))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)()>(_a, &SocketManager::DeletePostFailed, 32))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)(const PostModel & )>(_a, &SocketManager::EditPost, 33))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)()>(_a, &SocketManager::EditPostFailed, 34))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)(const LikeModel & )>(_a, &SocketManager::LikePost, 35))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)()>(_a, &SocketManager::LikePostFailed, 36))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)(const CommentModel & )>(_a, &SocketManager::AddCommentPost, 37))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)()>(_a, &SocketManager::AddCommentPostFailed, 38))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)(const CommentModel & )>(_a, &SocketManager::EditCommentPost, 39))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)()>(_a, &SocketManager::EditCommentPostFailed, 40))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)(const CommentModel & )>(_a, &SocketManager::DeleteCommentPost, 41))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)()>(_a, &SocketManager::DeleteCommentPostFailed, 42))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)(const CommentList & )>(_a, &SocketManager::GetCommentPost, 43))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocketManager::*)()>(_a, &SocketManager::GetCommentPostFailed, 44))
            return;
    }
}

const QMetaObject *SocketManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SocketManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13SocketManagerE_t>.strings))
        return static_cast<void*>(this);
    return QTcpSocket::qt_metacast(_clname);
}

int SocketManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 45)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 45;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 45)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 45;
    }
    return _id;
}

// SIGNAL 0
void SocketManager::UserReg(const UserModel & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void SocketManager::UserRegFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SocketManager::UserRegRepeat()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SocketManager::UserAuth(const UserModel & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void SocketManager::UserAuthServer()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void SocketManager::UserAuthFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void SocketManager::UserUpdateData(const UserModel & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void SocketManager::UserUpdateName()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void SocketManager::UserUpdateFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void SocketManager::UserChangePhoto(const UserModel & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1);
}

// SIGNAL 10
void SocketManager::UserChangePhotoFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void SocketManager::UserIsMain()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void SocketManager::UserNotMain()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void SocketManager::GetUsers(const UserList & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 13, nullptr, _t1);
}

// SIGNAL 14
void SocketManager::GetUsersFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void SocketManager::GetFriends(const UserList & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 15, nullptr, _t1);
}

// SIGNAL 16
void SocketManager::GetFriendsFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void SocketManager::CheckRelationship(const TypeQuery & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 17, nullptr, _t1);
}

// SIGNAL 18
void SocketManager::GetNotifications(const NotificationList & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 18, nullptr, _t1);
}

// SIGNAL 19
void SocketManager::GetNotificationsFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 19, nullptr);
}

// SIGNAL 20
void SocketManager::AcceptNotification(const NotificationModel & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 20, nullptr, _t1);
}

// SIGNAL 21
void SocketManager::CancelNotification(const NotificationModel & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 21, nullptr, _t1);
}

// SIGNAL 22
void SocketManager::AddFriend(const TypeQuery & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 22, nullptr, _t1);
}

// SIGNAL 23
void SocketManager::CancelFriend(const TypeQuery & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 23, nullptr, _t1);
}

// SIGNAL 24
void SocketManager::DeleteFriend(const TypeQuery & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 24, nullptr, _t1);
}

// SIGNAL 25
void SocketManager::AddPost()
{
    QMetaObject::activate(this, &staticMetaObject, 25, nullptr);
}

// SIGNAL 26
void SocketManager::AddPostFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 26, nullptr);
}

// SIGNAL 27
void SocketManager::GetPost(const PostList & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 27, nullptr, _t1);
}

// SIGNAL 28
void SocketManager::GetPostFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 28, nullptr);
}

// SIGNAL 29
void SocketManager::GetUserPost(const PostList & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 29, nullptr, _t1);
}

// SIGNAL 30
void SocketManager::GetUserPostFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 30, nullptr);
}

// SIGNAL 31
void SocketManager::DeletePost(const PostModel & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 31, nullptr, _t1);
}

// SIGNAL 32
void SocketManager::DeletePostFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 32, nullptr);
}

// SIGNAL 33
void SocketManager::EditPost(const PostModel & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 33, nullptr, _t1);
}

// SIGNAL 34
void SocketManager::EditPostFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 34, nullptr);
}

// SIGNAL 35
void SocketManager::LikePost(const LikeModel & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 35, nullptr, _t1);
}

// SIGNAL 36
void SocketManager::LikePostFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 36, nullptr);
}

// SIGNAL 37
void SocketManager::AddCommentPost(const CommentModel & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 37, nullptr, _t1);
}

// SIGNAL 38
void SocketManager::AddCommentPostFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 38, nullptr);
}

// SIGNAL 39
void SocketManager::EditCommentPost(const CommentModel & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 39, nullptr, _t1);
}

// SIGNAL 40
void SocketManager::EditCommentPostFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 40, nullptr);
}

// SIGNAL 41
void SocketManager::DeleteCommentPost(const CommentModel & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 41, nullptr, _t1);
}

// SIGNAL 42
void SocketManager::DeleteCommentPostFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 42, nullptr);
}

// SIGNAL 43
void SocketManager::GetCommentPost(const CommentList & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 43, nullptr, _t1);
}

// SIGNAL 44
void SocketManager::GetCommentPostFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 44, nullptr);
}
QT_WARNING_POP
