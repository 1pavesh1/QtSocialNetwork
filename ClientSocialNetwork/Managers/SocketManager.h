#ifndef SOCKETMANAGER_H
#define SOCKETMANAGER_H

#include <QTcpSocket>
#include <QString>
#include "Data.h"
#include "TypeQuery.h"
#include "CommentModel.h"
#include "NotificationModel.h"
#include "PostModel.h"
#include "UserModel.h"
#include "UserList.h"
#include "NotificationList.h"
#include "PostList.h"
#include "LikeModel.h"
#include "CommentModel.h"
#include "CommentList.h"

class SocketManager : public QTcpSocket
{
    Q_OBJECT

private:
    QTcpSocket                      *socket;
    QByteArray                      arrayData;
    qint32                          nextBlockSize;
    TypeQuery                       typeQuery;

    UserModel                       userModel;
    UserModel                       tempUser;
    UserList                        userModelList;

    NotificationModel               notificationModel;
    NotificationList                notificationList;

    PostModel                       postModel;
    PostList                        postModelList;

    LikeModel                       likeModel;

    CommentModel                    commentModel;
    CommentList                     commentList;

public:
    static SocketManager& instance();
    SocketManager();
    void connectSocket();

    void SlotDisconnected();
    void SlotReadyRead();
    void SendDataToServer(const TypeQuery &typeQuery, const Data& data);
    void ReadQuery(QDataStream &answerServer);

    void RegistrationUserQuery(const UserModel &userModel);
    void AuthorizationUserQuery(const UserModel &userModel);
    void CheckUserProfileQuery(const UserModel &userModel);
    void UpdateDataQuery(const UserModel &userModel);
    void ChangePhotoQuery(const UserModel &userModel);
    void GetUsersQuery(const UserModel &userModel);
    void GetFriendsQuery(const UserModel &userModel);
    void GetRelationshipQuery(const UserModel &userModel);
    void LogoutUserQuery(const UserModel &userModel);
    void GetNotificationQuery(const UserModel &userModel);
    void AcceptNotificationQuery(const NotificationModel &notificationModel);
    void CancelNotificationQuery(const NotificationModel &notificationModel);
    void AddFriendQuery(const UserModel &userModel);
    void CancelFriendQuery(const UserModel &userModel);
    void DeleteFriendQuery(const UserModel &userModel);
    void AddPostQuery(const PostModel &postModel);
    void GetPostQuery(const UserModel &userModel);
    void GetUserPostQuery(const UserModel &userModel);
    void DeletePostQuery(const PostModel &postModel);
    void EditPostQuery(const PostModel &postModel);
    void LikePostQuery(const LikeModel &likeModel);
    void AddCommentPostQuery(const CommentModel &commentModel);
    void EditCommentPostQuery(const CommentModel &commentModel);
    void DeleteCommentPostQuery(const CommentModel &commentModel);
    void GetCommentPostQuery(const PostModel &postModel);
    void SearchPostsQuery(const PostModel &postModel);
    void SearchUsersQuery(const UserModel &userModel);

    void ReadRegAnswer(const TypeQuery &typeQuery);
    void ReadAuthAnswer(const TypeQuery &typeQuery);
    void ReadUpdateAnswer(const TypeQuery &typeQuery);
    void ReadChangePhotoAnswer(const TypeQuery &typeQuery);
    void ReadCheckUserProfileAnswer(const TypeQuery &typeQuery);
    void ReadGetUsers(const TypeQuery &typeQuery);
    void ReadGetFriends(const TypeQuery &typeQuery);
    void ReadGetRelationship(const TypeQuery &typeQuery);
    void ReadGetNotification(const TypeQuery &typeQuery);
    void ReadNotificationAnswer(const TypeQuery &typeQuery);
    void ReadFriendAnswer(const TypeQuery &typeQuery);
    void ReadAddPostAnswer(const TypeQuery &typeQuery);
    void ReadGetPostAnswer(const TypeQuery &typeQuery);
    void ReadGetUserPostAnswer(const TypeQuery &typeQuery);
    void ReadDeletePostAnswer(const TypeQuery &typeQuery);
    void ReadEditPostAnswer(const TypeQuery &typeQuery);
    void ReadLikePostAnswer(const TypeQuery &typeQuery);
    void ReadAddCommentPostAnswer(const TypeQuery &typeQuery);
    void ReadEditCommentPostAnswer(const TypeQuery &typeQuery);
    void ReadDeleteCommentPostAnswer(const TypeQuery &typeQuery);
    void ReadGetCommentPostAnswer(const TypeQuery &typeQuery);
    void ReadSearchPostsAnswer(const TypeQuery &typeQuery);
    void ReadSearchUsersAnswer(const TypeQuery &typeQuery);

signals:
    // Регистрация
    void UserReg(const UserModel &userModel);
    void UserRegFailed();
    void UserRegRepeat();
    // Авторизация
    void UserAuth(const UserModel &userModel);
    void UserAuthServer();
    void UserAuthFailed();
    // Обновление данных
    void UserUpdateData(const UserModel &userModel);
    void UserUpdateName();
    void UserUpdateFailed();
    void UserChangePhoto(const UserModel &userModel);
    void UserChangePhotoFailed();
    // Проверка профиля пользователя
    void UserIsMain();
    void UserNotMain();
    // Получение пользователей
    void GetUsers(const UserList &userList);
    void GetUsersFailed();
    // Получение друзей
    void GetFriends(const UserList &userList);
    void GetFriendsFailed();
    // Получение статуса отношений пользователя
    void CheckRelationship(const TypeQuery &relationship);
    // Получение уведомлений
    void GetNotifications(const NotificationList &notificationList);
    void GetNotificationsFailed();
    // Принятие и отказ от уведомлений
    void AcceptNotification(const NotificationModel &notificationModel);
    void CancelNotification(const NotificationModel &notificationModel);
    // Удаление, добавлений и отмена запроса в друзья
    void AddFriend(const TypeQuery &typeQuery);
    void CancelFriend(const TypeQuery &typeQuery);
    void DeleteFriend(const TypeQuery &typeQuery);
    // Удаление, добавление, редактирование, получение постов
    void AddPost();
    void AddPostFailed();
    void GetPost(const PostList &postList);
    void GetPostFailed();
    void GetUserPost(const PostList &postList);
    void GetUserPostFailed();
    void DeletePost(const PostModel &postModel);
    void DeletePostFailed();
    void EditPost(const PostModel &postModel);
    void EditPostFailed();
    // Лайки и комментарии поста
    void LikePost(const LikeModel &likeModel);
    void LikePostFailed();
    void AddCommentPost(const CommentModel &commentModel);
    void AddCommentPostFailed();
    void EditCommentPost(const CommentModel &commentModel);
    void EditCommentPostFailed();
    void DeleteCommentPost(const CommentModel &commentModel);
    void DeleteCommentPostFailed();
    void GetCommentPost(const CommentList &commentList);
    void GetCommentPostFailed();
    // Поиск
    void SearchPosts(const PostList &postList);
    void SearchPostsFailed();
    void SearchUsers(const UserList &userList);
    void SearchUsersFailed();
};

#endif // SOCKETMANAGER_H
