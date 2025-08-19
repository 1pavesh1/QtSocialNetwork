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
#include "UserVector.h"
#include "NotificationVector.h"
#include "PostVector.h"

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
    UserVector                      userModelVector;

    NotificationModel               notificationModel;
    NotificationVector              notificationModelVector;

    PostModel                       postModel;
    PostVector                      postModelVector;

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
    void GetUsers(const UserVector &userModelVector);
    void GetUsersFailed();
    // Получение друзей
    void GetFriends(const UserVector &userModelVector);
    void GetFriendsFailed();
    // Получение статуса отношений пользователя
    void CheckRelationship(const TypeQuery &relationship);
    // Получение уведомлений
    void GetNotifications(const NotificationVector &notificationModelVector);
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
    void GetPost(const PostVector &postModelVector);
    void GetPostFailed();
    void GetUserPost(const PostVector &postModelVector);
    void GetUserPostFailed();
};

#endif // SOCKETMANAGER_H
