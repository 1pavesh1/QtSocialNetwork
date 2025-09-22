#include "ServerSocialNetwork.h"

ServerSocialNetwork::ServerSocialNetwork()
{
    if (this->listen(QHostAddress::Any, 2323))
    {
        qDebug("Сервер работает");
        connect(this, &QTcpServer::newConnection, this, &ServerSocialNetwork::IncomingConnection);
    }
    else
    {
        qDebug("Сервер не работает");
    }
    this->nextBlockSize = 0;
}

void ServerSocialNetwork::IncomingConnection()
{
    socket = this->nextPendingConnection();
    if (socket)
    {
        connect(socket, &QTcpSocket::readyRead, this, &ServerSocialNetwork::SlotReadyRead);
        connect(socket, &QTcpSocket::disconnected, this, [this]() { SlotDisconnected(socket); });

        userServerManager.AddSocketServerToMap(userServerMap, socket);

        qDebug() << "Новое подключение";
    }
}

void ServerSocialNetwork::SlotDisconnected(QTcpSocket *socket)
{
    dbUserManager.UpdateTimeUser(userModel, dbConnectManager.GetDataBase());
    userServerManager.RemoveUserServerFromMap(userServerMap, socket);

    qDebug() << "Пользователь отключен";

    socket->deleteLater();
}

void ServerSocialNetwork::SlotReadyRead()
{
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_9);
    if (in.status() == QDataStream::Ok)
    {
        while (1)
        {
            if (this->nextBlockSize == 0)
            {
                if (socket->bytesAvailable() < 2)
                {
                    break;
                }
                in >> this->nextBlockSize;
            }
            if (socket->bytesAvailable() < this->nextBlockSize)
            {
                break;
            }
            ReadQuery(in, socket);
            this->nextBlockSize = 0;
        }
    }
    else
    {
        qDebug() << "Ошибка передачи сообщения...";
    }
}

void ServerSocialNetwork::ReadQuery(QDataStream &query, QTcpSocket *socket)
{
    query >> typeQuery;
    qDebug() << "Вход " << typeQuery;
    switch (typeQuery)
    {
    case REG_USER_QUERY:
        query >> userModel;
        RegUser(userModel, socket);
        break;
    case AUTH_USER_QUERY:
        query >> userModel;
        AuthUser(userModel, socket);
        break;
    case UPDATE_USER_QUERY:
        query >> userModel;
        UpdateDataUser(userModel, socket);
        break;
    case LOGOUT_USER_QUERY:
        query >> userModel;
        LogoutUser(userModel, socket);
        break;
    case CHECK_USER_QUERY:
        query >> userModel;
        CheckUser(userModel, socket);
        break;
    case CHANGE_PHOTO_USER_QUERY:
        query >> userModel;
        ChangePhotoUser(userModel, socket);
        break;
    case GET_USERS_QUERY:
        query >> userModel;
        GetUsers(userModel, socket);
        break;
    case GET_FRIENDS_QUERY:
        query >> userModel;
        GetFriends(userModel, socket);
        break;
    case GET_RELATIONSHIP_USER_QUERY:
        query >> userModel;
        GetRelationShipUser(userModel, socket);
        break;
    case ADD_USER_QUERY:
        query >> userModel;
        AddUser(userModel, socket);
        break;
    case CANCEL_USER_QUERY:
        query >> userModel;
        CancelUser(userModel, socket);
        break;
    case DELETE_USER_QUERY:
        query >> userModel;
        DeleteUser(userModel, socket);
        break;
    case GET_NOTIFICATIONS_QUERY:
        query >> userModel;
        GetNotifications(userModel, socket);
        break;
    case ACCEPT_NOTIIFICATION_QUERY:
        query >> notificationModel;
        AcceptNotification(notificationModel, socket);
        break;
    case CANCEL_NOTIIFICATION_QUERY:
        query >> notificationModel;
        CancelNotification(notificationModel, socket);
        break;
    case ADD_POST_QUERY:
        query >> postModel;
        AddPost(postModel, socket);
        break;
    case GET_POSTS_QUERY:
        query >> userModel;
        GetPosts(socket);
        break;
    case GET_USER_POSTS_QUERY:
        query >> userModel;
        GetUserPosts(userModel, socket);
        break;
    case DELETE_USER_POST_QUERY:
        query >> postModel;
        DeletePost(postModel, socket);
        break;
    case EDIT_POST_QUERY:
        query >> postModel;
        EditPost(postModel, socket);
        break;
    case LIKE_POST_QUERY:
        query >> likeModel;
        LikePost(likeModel, socket);
        break;
    case ADD_COMMENT_QUERY:
        query >> commentModel;
        AddCommentPost(commentModel, socket);
        break;
    case DELETE_COMMENT_QUERY:
        query >> commentModel;
        DeleteCommentPost(commentModel, socket);
        break;
    case EDIT_COMMENT_QUERY:
        query >> commentModel;
        EditCommentPost(commentModel, socket);
        break;
    case GET_COMMENTS_QUERY:
        query >> postModel;
        GetCommentsPost(postModel, socket);
        break;
    case SEARCH_POSTS_QUERY:
        query >> postModel;
        SearchPostsInName(postModel, socket);
        break;
    case SEARCH_USERS_QUERY:
        query >> userModel;
        SearchUsersInLogin(userModel, socket);
        break;
    default:
        break;
    }
}

void ServerSocialNetwork::RegUser(UserModel &userModel, QTcpSocket *socket)
{
    if (dbUserManager.CheckUserLogin(userModel, dbConnectManager.GetDataBase()))
    {
        if (dbUserManager.RegUser(userModel, dbConnectManager.GetDataBase()))
        {
            userServerManager.AddUserServerToMap(userServerMap, socket, userModel);
            SendDataToClient(REG_USER_QUERY, userModel, socket);
        }
        else
        {
            SendDataToClient(REG_USER_FAILED_ANSWER, userModel, socket);
        }
    }
    else
    {
        SendDataToClient(REG_USER_REPEAT_ANSWER, userModel, socket);
    }
}

void ServerSocialNetwork::AuthUser(UserModel &userModel, QTcpSocket *socket)
{
    if (userServerManager.CheckUserOnServer(userServerMap, socket))
    {
        if (dbUserManager.AuthUser(userModel, dbConnectManager.GetDataBase()))
        {
            userServerManager.AddUserServerToMap(userServerMap, socket, userModel);
            SendDataToClient(AUTH_USER_QUERY, userModel, socket);
        }
        else
        {
            SendDataToClient(AUTH_USER_DATA_ANSWER, userModel, socket);
        }
    }
    else
    {
        SendDataToClient(AUTH_USER_ON_SERVER_ANSWER, userModel, socket);
    }
}

void ServerSocialNetwork::UpdateDataUser(UserModel &userModel, QTcpSocket *socket)
{
    if (dbUserManager.CheckUserLogin(userModel, dbConnectManager.GetDataBase()))
    {
        if (dbUserManager.UpdateDataUser(userModel, dbConnectManager.GetDataBase()))
        {
            userServerManager.ReplaceUser(userServerMap, socket, userModel);
            SendDataToClient(UPDATE_USER_QUERY, userModel, socket);
        }
        else
        {
            SendDataToClient(UPDATE_USER_FAILED_ANSWER, userModel, socket);
        }
    }
    else
    {
        SendDataToClient(UPDATE_USER_NAME_ANSWER, userModel, socket);
    }
}

void ServerSocialNetwork::LogoutUser(const UserModel &userModel, QTcpSocket *socket)
{
    dbUserManager.UpdateTimeUser(userModel, dbConnectManager.GetDataBase());
    userServerManager.DeleteDataUserServerFromMap(userServerMap, socket);
}

void ServerSocialNetwork::CheckUser(UserModel &userModel, QTcpSocket *socket)
{
    if (userServerManager.CheckUserMain(userServerMap, socket, userModel))
        SendDataToClient(USER_IS_MAIN_ANSWER, userModel, socket);
    else
        SendDataToClient(USER_NOT_MAIN_ANSWER, userModel, socket);
}

void ServerSocialNetwork::ChangePhotoUser(UserModel &userModel, QTcpSocket *socket)
{
    if (dbUserManager.UpdatePhotoUser(userModel, dbConnectManager.GetDataBase()))
        SendDataToClient(CHANGE_PHOTO_USER_QUERY, userModel, socket);
    else
        SendDataToClient(CHANGE_PHOTO_FAILED_ANSWER, userModel, socket);
}

void ServerSocialNetwork::GetUsers(const UserModel &userModel, QTcpSocket *socket)
{
    userList.SetUserList(dbFriendsManager.GetUsers(userModel, dbConnectManager.GetDataBase()));
    for (auto userModel : userList.GetUserList())
    {
        if (userServerManager.CheckUserOnServer(userServerMap, socket))
            userModel.SetStatus(true);
    }
    if (userList.GetUserList().isEmpty())
        SendDataToClient(GET_USERS_FAILED_ANSWER, userList, socket);
    else
        SendDataToClient(GET_USERS_QUERY, userList, socket);
}

void ServerSocialNetwork::GetFriends(const UserModel &userModel, QTcpSocket *socket)
{
    userList.SetUserList(dbFriendsManager.GetFriends(userModel, dbConnectManager.GetDataBase()));
    for (auto userModel : userList.GetUserList())
    {
        if (userServerManager.CheckUserOnServer(userServerMap, socket))
            userModel.SetStatus(true);
    }
    if (userList.GetUserList().isEmpty())
        SendDataToClient(GET_FRIENDS_FAILED_ANSWER, userList, socket);
    else
        SendDataToClient(GET_FRIENDS_QUERY, userList, socket);
}

void ServerSocialNetwork::GetRelationShipUser(const UserModel &userModel, QTcpSocket *socket)
{
    SendDataToClient(dbFriendsManager.GetRelationship(userServerManager.GetUserInSocket(userServerMap, socket),
                                                      userModel,
                                                      dbConnectManager.GetDataBase()), userModel, socket);
}

void ServerSocialNetwork::AddUser(const UserModel &userModel, QTcpSocket *socket)
{
    dbNotificationManager.AddNotification(userServerManager.GetUserInSocket(userServerMap, socket),
                                          userModel,
                                          dbConnectManager.GetDataBase());
    SendDataToClient(dbFriendsManager.GetRelationship(userServerManager.GetUserInSocket(userServerMap, socket),
                                                      userModel,
                                                      dbConnectManager.GetDataBase()), userModel, socket);
}

void ServerSocialNetwork::CancelUser(const UserModel &userModel, QTcpSocket *socket)
{
    dbNotificationManager.DeleteNotificationInUser(userServerManager.GetUserInSocket(userServerMap, socket),
                                                   userModel,
                                                   dbConnectManager.GetDataBase());
    SendDataToClient(dbFriendsManager.GetRelationship(userServerManager.GetUserInSocket(userServerMap, socket),
                                                      userModel,
                                                      dbConnectManager.GetDataBase()), userModel, socket);
}

void ServerSocialNetwork::DeleteUser(const UserModel &userModel, QTcpSocket *socket)
{
    dbFriendsManager.DeleteFriend(userServerManager.GetUserInSocket(userServerMap, socket),
                                  userModel,
                                  dbConnectManager.GetDataBase());
    SendDataToClient(dbFriendsManager.GetRelationship(userServerManager.GetUserInSocket(userServerMap, socket),
                                                      userModel,
                                                      dbConnectManager.GetDataBase()), userModel, socket);
}

void ServerSocialNetwork::GetNotifications(const UserModel &userModel, QTcpSocket *socket)
{
    notificationList.SetNotificationList(
        dbNotificationManager.GetNotifications(userModel, dbConnectManager.GetDataBase()));
    SendDataToClient(GET_NOTIFICATIONS_QUERY, notificationList, socket);
}

void ServerSocialNetwork::AcceptNotification(const NotificationModel &notificationModel, QTcpSocket *socket)
{
    dbNotificationManager.AcceptNotifciation(notificationModel, dbConnectManager.GetDataBase());
    SendDataToClient(ACCEPT_NOTIIFICATION_QUERY, notificationModel, socket);
}

void ServerSocialNetwork::CancelNotification(const NotificationModel &notificationModel, QTcpSocket *socket)
{
    dbNotificationManager.DeleteNotificationInModel(notificationModel, dbConnectManager.GetDataBase());
    SendDataToClient(CANCEL_NOTIIFICATION_QUERY, notificationModel, socket);
}

void ServerSocialNetwork::AddPost(PostModel &postModel, QTcpSocket *socket)
{
    if (dbPostManager.AddPost(postModel, dbConnectManager.GetDataBase()))
        SendDataToClient(ADD_POST_QUERY, postModel, socket);
    else
        SendDataToClient(ADD_POST_FAILED_ANSWER, postModel, socket);
}

void ServerSocialNetwork::GetPosts(QTcpSocket *socket)
{
    postList.SetPostList(dbPostManager.GetPosts(dbConnectManager.GetDataBase()));
    SendDataToClient(GET_POSTS_QUERY, postList, socket);
}

void ServerSocialNetwork::GetUserPosts(const UserModel &userModel, QTcpSocket *socket)
{
    postList.SetPostList(dbPostManager.GetUserPosts(userModel, dbConnectManager.GetDataBase()));
    SendDataToClient(GET_USER_POSTS_QUERY, postList, socket);
}

void ServerSocialNetwork::DeletePost(const PostModel &postModel, QTcpSocket *socket)
{
    if (dbPostManager.DeletePost(postModel, dbConnectManager.GetDataBase()))
        SendDataToClient(DELETE_USER_POST_QUERY, postModel, socket);
    else
        SendDataToClient(DELETE_USER_POST_FAILED, postModel, socket);
}

void ServerSocialNetwork::EditPost(const PostModel &postModel, QTcpSocket *socket)
{
    if (dbPostManager.EditPost(postModel, dbConnectManager.GetDataBase()))
        SendDataToClient(EDIT_POST_QUERY, postModel, socket);
    else
        SendDataToClient(EDIT_POST_FAILED, postModel, socket);
}

void ServerSocialNetwork::LikePost(const LikeModel &likeModel, QTcpSocket *socket)
{
    if (!dbLikeManager.CheckLikePost(likeModel, dbConnectManager.GetDataBase()))
    {
        if (dbLikeManager.AddLikePost(likeModel, dbConnectManager.GetDataBase()))
            SendDataToClient(LIKE_POST_QUERY, postModel, socket);
        else
            SendDataToClient(LIKE_POST_FAILED, postModel, socket);
    }
    else
    {
        if (dbLikeManager.DeleteLikePost(likeModel, dbConnectManager.GetDataBase()))
            SendDataToClient(LIKE_POST_QUERY, postModel, socket);
        else
            SendDataToClient(LIKE_POST_FAILED, postModel, socket);
    }
}

void ServerSocialNetwork::AddCommentPost(const CommentModel &commentModel, QTcpSocket *socket)
{
    if (dbCommentManager.AddComment(commentModel, dbConnectManager.GetDataBase()))
        SendDataToClient(ADD_COMMENT_QUERY, commentModel, socket);
    else
        SendDataToClient(ADD_COMMENT_FAILED, commentModel, socket);
}

void ServerSocialNetwork::GetCommentsPost(const PostModel &postModel, QTcpSocket *socket)
{
    commentList.SetCommentList(
        dbCommentManager.GetComments(postModel, dbConnectManager.GetDataBase()));
    SendDataToClient(GET_COMMENTS_QUERY, commentList, socket);
}

void ServerSocialNetwork::DeleteCommentPost(const CommentModel &commentModel, QTcpSocket *socket)
{
    if (dbCommentManager.DeleteComment(commentModel, dbConnectManager.GetDataBase()))
        SendDataToClient(DELETE_COMMENT_QUERY, commentModel, socket);
    else
        SendDataToClient(DELETE_COMMENT_FAILED, commentModel, socket);
}

void ServerSocialNetwork::EditCommentPost(const CommentModel &commentModel, QTcpSocket *socket)
{
    if (dbCommentManager.EditComment(commentModel, dbConnectManager.GetDataBase()))
        SendDataToClient(EDIT_COMMENT_QUERY, commentModel, socket);
    else
        SendDataToClient(EDIT_COMMENT_FAILED, commentModel, socket);
}

void ServerSocialNetwork::SearchPostsInName(const PostModel &postModel, QTcpSocket *socket)
{
    postList.SetPostList(dbPostManager.GetPostsInName(postModel, dbConnectManager.GetDataBase()));
    if (postList.GetPostList().isEmpty())
        SendDataToClient(SEARCH_POSTS_FAILED, postList, socket);
    else
        SendDataToClient(SEARCH_POSTS_QUERY, postList, socket);
}

void ServerSocialNetwork::SearchUsersInLogin(const UserModel &userModel, QTcpSocket *socket)
{
    userList.SetUserList(dbFriendsManager.GetUsersInLogin(userModel, dbConnectManager.GetDataBase()));
    if (userList.GetUserList().isEmpty())
        SendDataToClient(SEARCH_USERS_FAILED, userList, socket);
    else
        SendDataToClient(SEARCH_USERS_QUERY, userList, socket);
}

void ServerSocialNetwork::SendDataToClient(const TypeQuery &typeQuery, const Data &data, QTcpSocket *socket)
{
    qDebug() << "Выход " << typeQuery;
    auto it = userServerMap.find(socket);
    arrayData.clear();
    QDataStream out(&arrayData, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_9);
    out << qint32(0) << typeQuery << data;
    out.device()->seek(0);
    out << qint32(arrayData.size() - sizeof(qint32));
    it.key()->write(arrayData);
    qDebug() << "Сообщение отправлено пользователю: " << it.value().GetLogin();
}
