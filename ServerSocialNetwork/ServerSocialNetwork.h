#ifndef SERVERSOCIALNETWORK_H
#define SERVERSOCIALNETWORK_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include <QVector>
#include <QTime>
#include "Managers/DataBaseConnectManager.h"
#include "Managers/DataBaseCommentManager.h"
#include "Managers/DataBaseFriendsManager.h"
#include "Managers/DataBaseLikeManager.h"
#include "Managers/DataBaseNotificationManager.h"
#include "Managers/DataBasePostManager.h"
#include "Managers/DataBaseUserManager.h"
#include "Managers/UserServerManager.h"
#include "Data.h"
#include "TypeQuery.h"
#include "CommentModel.h"
#include "NotificationModel.h"
#include "PostModel.h"
#include "UserModel.h"
#include "UserList.h"
#include "NotificationList.h"
#include "PostList.h"
#include "CommentList.h"
#include "LikeModel.h"
#include "MediaHelpers/FileReader.h"
#include "MediaHelpers/FileWriter.h"
#include "MediaHelpers/DirectoryHelper.h"

class ServerSocialNetwork : public QTcpServer
{
    Q_OBJECT
private:
    QTcpSocket                      *socket;
    QByteArray                      arrayData;
    qint32                          nextBlockSize;
    QMap <QTcpSocket*, UserModel>   userServerMap;

    TypeQuery                       typeQuery;

    FileReader                      fileReader;
    FileWriter                      fileWriter;
    DirectoryHelper                 dirHelper;

    DataBaseConnectManager          dbConnectManager;
    DataBaseCommentManager          dbCommentManager;
    DataBaseFriendsManager          dbFriendsManager;
    DataBaseLikeManager             dbLikeManager;
    DataBaseNotificationManager     dbNotificationManager;
    DataBasePostManager             dbPostManager;
    DataBaseUserManager             dbUserManager;
    UserServerManager               userServerManager;

    UserModel                       userModel;
    UserList                        userList;

    NotificationModel               notificationModel;
    NotificationList                notificationList;

    PostModel                       postModel;
    PostList                        postList;

    LikeModel                       likeModel;

    CommentModel                    commentModel;
    CommentList                     commentList;

    void ReadQuery(QDataStream &query, QTcpSocket *socket);
    void RegUser(UserModel &userModel, QTcpSocket *socket);
    void AuthUser(UserModel &userModel, QTcpSocket *socket);
    void UpdateDataUser(UserModel &userModel, QTcpSocket *socket);
    void LogoutUser(const UserModel &userModel, QTcpSocket *socket);
    void CheckUser(UserModel &userModel, QTcpSocket *socket);
    void ChangePhotoUser(UserModel &userModel, QTcpSocket *socket);
    void GetUsers(const UserModel &userModel, QTcpSocket *socket);
    void GetFriends(const UserModel &userModel, QTcpSocket *socket);
    void GetRelationShipUser(const UserModel &userModel, QTcpSocket *socket);
    void AddUser(const UserModel &userModel, QTcpSocket *socket);
    void CancelUser(const UserModel &userModel, QTcpSocket *socket);
    void DeleteUser(const UserModel &userModel, QTcpSocket *socket);
    void GetNotifications(const UserModel &userModel, QTcpSocket *socket);
    void AcceptNotification(const NotificationModel &notificationModel, QTcpSocket *socket);
    void CancelNotification(const NotificationModel &notificationModel, QTcpSocket *socket);
    void AddPost(PostModel &postModel, QTcpSocket *socket);
    void GetPosts(QTcpSocket *socket);
    void GetUserPosts(const UserModel &userModel, QTcpSocket *socket);
    void DeletePost(const PostModel &postModel, QTcpSocket *socket);
    void EditPost(const PostModel &postModel, QTcpSocket *socket);
    void LikePost(const LikeModel &likeModel, QTcpSocket *socket);
    void AddCommentPost(const CommentModel &commentModel, QTcpSocket *socket);
    void DeleteCommentPost(const CommentModel &commentModel, QTcpSocket *socket);
    void EditCommentPost(const CommentModel &commentModel, QTcpSocket *socket);
    void GetCommentsPost(const PostModel &postModel, QTcpSocket *socket);
    void SearchPostsInName(const PostModel &postModel, QTcpSocket *socket);
    void SearchUsersInLogin(const UserModel &userModel, QTcpSocket *socket);
    void SendDataToClient(const TypeQuery &typeQuery, const Data &data, QTcpSocket *socket);
public:
    ServerSocialNetwork();
public slots:
    void IncomingConnection();
    void SlotReadyRead();
    void SlotDisconnected(QTcpSocket *socket);
};

#endif // SERVERSOCIALNETWORK_H
