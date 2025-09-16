#include "Managers/SocketManager.h"

SocketManager::SocketManager() { connectSocket(); }

SocketManager &SocketManager::instance()
{
    static SocketManager socketManager;
    return socketManager;
}

void SocketManager::connectSocket()
{
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &SocketManager::SlotReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &SocketManager::SlotDisconnected);
    socket->connectToHost("127.0.0.1", 2323);
    this->nextBlockSize = 0;
}

void SocketManager::SlotDisconnected()
{

}

void SocketManager::SlotReadyRead()
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
            ReadQuery(in);
            this->nextBlockSize = 0;
        }
    }
    else
    {
        qDebug() << "Ошибка передачи сообщения...";
    }
}

void SocketManager::SendDataToServer(const TypeQuery &typeQuery, const Data& data)
{
    arrayData.clear();
    QDataStream out(&arrayData, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_9);
    out << qint32(0) << typeQuery << data;
    out.device()->seek(0);
    out << qint32(arrayData.size() - sizeof(qint32));
    socket->write(arrayData);
}

void SocketManager::ReadQuery(QDataStream &dataFromServer)
{
    dataFromServer >> typeQuery;
    qDebug() << typeQuery;
    switch (typeQuery)
    {
    case REG_USER_QUERY: case REG_USER_REPEAT_ANSWER: case REG_USER_FAILED_ANSWER:
        dataFromServer >> userModel;
        ReadRegAnswer(typeQuery);
        break;
    case AUTH_USER_QUERY: case AUTH_USER_ON_SERVER_ANSWER: case AUTH_USER_DATA_ANSWER:
        dataFromServer >> userModel;
        ReadAuthAnswer(typeQuery);
        break;
    case UPDATE_USER_QUERY: case UPDATE_USER_NAME_ANSWER: case UPDATE_USER_FAILED_ANSWER:
        dataFromServer >> userModel;
        ReadUpdateAnswer(typeQuery);
        break;
    case USER_IS_MAIN_ANSWER: case USER_NOT_MAIN_ANSWER:
        dataFromServer >> userModel;
        ReadCheckUserProfileAnswer(typeQuery);
        break;
    case CHANGE_PHOTO_USER_QUERY: case CHANGE_PHOTO_FAILED_ANSWER:
        dataFromServer >> userModel;
        ReadChangePhotoAnswer(typeQuery);
        break;
    case GET_USERS_QUERY: case GET_USERS_FAILED_ANSWER:
        dataFromServer >> userList;
        ReadGetUsers(typeQuery);
        break;
    case GET_FRIENDS_QUERY: case GET_FRIENDS_FAILED_ANSWER:
        dataFromServer >> userList;
        ReadGetFriends(typeQuery);
        break;
    case RELATIONSHIP_FRIEND_ANSWER: case RELATIONSHIP_NOT_FRIEND_ANSWER: case RELATIONSHIP_WAIT_NOTIFICATION_ANSWER:
        dataFromServer >> tempUser;
        ReadGetRelationship(typeQuery);
        break;
    case GET_NOTIFICATIONS_QUERY:
        dataFromServer >> notificationList;
        ReadGetNotification(typeQuery);
        break;
    case ACCEPT_NOTIIFICATION_QUERY: case CANCEL_NOTIIFICATION_QUERY:
        dataFromServer >> notificationModel;
        ReadNotificationAnswer(typeQuery);
        break;
    case ADD_FRIEND_ANSWER: case CANCEL_FRIEND_ANSWER: case DELETE_FRIEND_ANSWER:
        dataFromServer >> tempUser;
        ReadFriendAnswer(typeQuery);
        break;
    case ADD_POST_QUERY: case ADD_POST_FAILED_ANSWER:
        dataFromServer >> postModel;
        ReadAddPostAnswer(typeQuery);
        break;
    case GET_POSTS_QUERY: case GET_POSTS_FAILED_ANSWER:
        dataFromServer >> postModelVector;
        ReadGetPostAnswer(typeQuery);
        break;
    case GET_USER_POSTS_QUERY: case GET_USER_POSTS_FAILED:
        dataFromServer >> postModelVector;
        ReadGetUserPostAnswer(typeQuery);
        break;
    case DELETE_USER_POST_QUERY: case DELETE_USER_POST_FAILED:
        dataFromServer >> postModel;
        ReadDeletePostAnswer(typeQuery);
        break;
    case EDIT_POST_QUERY: case EDIT_POST_FAILED:
        dataFromServer >> postModel;
        ReadEditPostAnswer(typeQuery);
        break;
    case LIKE_POST_QUERY: case LIKE_POST_FAILED:
        dataFromServer >> postModel;
        ReadLikePostAnswer(typeQuery);
        break;
    case ADD_COMMENT_QUERY: case ADD_COMMENT_FAILED:
        dataFromServer >> commentModel;
        ReadAddCommentPostAnswer(typeQuery);
        break;
    case DELETE_COMMENT_QUERY: case DELETE_COMMENT_FAILED:
        dataFromServer >> commentModel;
        ReadDeleteCommentPostAnswer(typeQuery);
        break;
    case EDIT_COMMENT_QUERY: case EDIT_COMMENT_FAILED:
        dataFromServer >> commentModel;
        ReadEditCommentPostAnswer(typeQuery);
        break;
    case GET_COMMENTS_QUERY: case GET_COMMENTS_FAILED:
        dataFromServer >> commentList;
        ReadGetCommentPostAnswer(typeQuery);
        break;
    default:
        break;
    }
}

void SocketManager::RegistrationUserQuery(const UserModel &userModel)
{
    SendDataToServer(REG_USER_QUERY, userModel);
}

void SocketManager::AuthorizationUserQuery(const UserModel &userModel)
{
    SendDataToServer(AUTH_USER_QUERY, userModel);
}

void SocketManager::UpdateDataQuery(const UserModel &userModel)
{
    SendDataToServer(UPDATE_USER_QUERY, userModel);
}

void SocketManager::LogoutUserQuery(const UserModel &userModel)
{
    SendDataToServer(LOGOUT_USER_QUERY, userModel);
}

void SocketManager::ChangePhotoQuery(const UserModel &userModel)
{
    SendDataToServer(CHANGE_PHOTO_USER_QUERY, userModel);
}

void SocketManager::GetUsersQuery(const UserModel &userModel)
{
    SendDataToServer(GET_USERS_QUERY, userModel);
}

void SocketManager::GetFriendsQuery(const UserModel &userModel)
{
    SendDataToServer(GET_FRIENDS_QUERY, userModel);
}

void SocketManager::GetRelationshipQuery(const UserModel &userModel)
{
    SendDataToServer(GET_RELATIONSHIP_USER_QUERY, userModel);
}

void SocketManager::GetNotificationQuery(const UserModel &userModel)
{
    SendDataToServer(GET_NOTIFICATIONS_QUERY, userModel);
}

void SocketManager::AcceptNotificationQuery(const NotificationModel &notificationModel)
{
    SendDataToServer(ACCEPT_NOTIIFICATION_QUERY, notificationModel);
}

void SocketManager::CancelNotificationQuery(const NotificationModel &notificationModel)
{
    SendDataToServer(CANCEL_NOTIIFICATION_QUERY, notificationModel);
}

void SocketManager::AddFriendQuery(const UserModel &userModel)
{
    SendDataToServer(ADD_USER_QUERY, userModel);
}

void SocketManager::CancelFriendQuery(const UserModel &userModel)
{
    SendDataToServer(CANCEL_USER_QUERY, userModel);
}

void SocketManager::DeleteFriendQuery(const UserModel &userModel)
{
    SendDataToServer(DELETE_USER_QUERY, userModel);
}

void SocketManager::CheckUserProfileQuery(const UserModel &userModel)
{
    SendDataToServer(CHECK_USER_QUERY, userModel);
}

void SocketManager::AddPostQuery(const PostModel &postModel)
{
    SendDataToServer(ADD_POST_QUERY, postModel);
}

void SocketManager::GetPostQuery(const UserModel &userModel)
{
    SendDataToServer(GET_POSTS_QUERY, userModel);
}

void SocketManager::GetUserPostQuery(const UserModel &userModel)
{
    SendDataToServer(GET_USER_POSTS_QUERY, userModel);
}

void SocketManager::DeletePostQuery(const PostModel &postModel)
{
    SendDataToServer(DELETE_USER_POST_QUERY, postModel);
}

void SocketManager::EditPostQuery(const PostModel &postModel)
{
    SendDataToServer(EDIT_POST_QUERY, postModel);
}

void SocketManager::LikePostQuery(const LikeModel &likeModel)
{
    SendDataToServer(LIKE_POST_QUERY, likeModel);
}

void SocketManager::AddCommentPostQuery(const CommentModel &commentModel)
{
    SendDataToServer(ADD_COMMENT_QUERY, commentModel);
}

void SocketManager::DeleteCommentPostQuery(const CommentModel &commentModel)
{
    SendDataToServer(DELETE_COMMENT_QUERY, commentModel);
}

void SocketManager::EditCommentPostQuery(const CommentModel &commentModel)
{
    SendDataToServer(EDIT_COMMENT_QUERY, commentModel);
}

void SocketManager::GetCommentPostQuery(const PostModel &postModel)
{
    SendDataToServer(GET_COMMENTS_QUERY, postModel);
}

void SocketManager::ReadRegAnswer(const TypeQuery &typeQuery)
{
    if (typeQuery == REG_USER_QUERY)
        emit UserReg(userModel);
    else if (typeQuery == REG_USER_REPEAT_ANSWER)
        emit UserRegRepeat();
    else
        emit UserRegFailed();
}

void SocketManager::ReadAuthAnswer(const TypeQuery &typeQuery)
{
    if (typeQuery == AUTH_USER_QUERY)
        emit UserAuth(userModel);
    else if (typeQuery == AUTH_USER_ON_SERVER_ANSWER)
        emit UserAuthServer();
    else
        emit UserAuthFailed();
}

void SocketManager::ReadUpdateAnswer(const TypeQuery &typeQuery)
{
    if (typeQuery == UPDATE_USER_QUERY)
        emit UserUpdateData(userModel);
    else if (typeQuery == UPDATE_USER_NAME_ANSWER)
        emit UserUpdateName();
    else
        emit UserUpdateFailed();
}

void SocketManager::ReadChangePhotoAnswer(const TypeQuery &typeQuery)
{
    if (typeQuery == CHANGE_PHOTO_USER_QUERY)
        emit UserChangePhoto(userModel);
    else
        emit UserChangePhotoFailed();
}

void SocketManager::ReadCheckUserProfileAnswer(const TypeQuery &typeQuery)
{
    if (typeQuery == USER_IS_MAIN_ANSWER)
        emit UserIsMain();
    else
        emit UserNotMain();
}

void SocketManager::ReadGetUsers(const TypeQuery &typeQuery)
{
    if (typeQuery == GET_USERS_QUERY)
        emit GetUsers(userList);
    else
        emit GetUsersFailed();
}

void SocketManager::ReadGetFriends(const TypeQuery &typeQuery)
{
    if (typeQuery == GET_FRIENDS_QUERY)
        emit GetUsers(userList);
    else
        emit GetUsersFailed();
}

void SocketManager::ReadGetRelationship(const TypeQuery &typeQuery)
{
    emit CheckRelationship(typeQuery);
}

void SocketManager::ReadGetNotification(const TypeQuery &typeQuery)
{
    if (typeQuery == GET_NOTIFICATIONS_QUERY)
        emit GetNotifications(notificationList);
    else
        emit GetNotificationsFailed();
}

void SocketManager::ReadNotificationAnswer(const TypeQuery &typeQuery)
{
    if (typeQuery == ACCEPT_NOTIIFICATION_QUERY)
        emit AcceptNotification(notificationModel);
    else
        emit CancelNotification(notificationModel);
}

void SocketManager::ReadFriendAnswer(const TypeQuery &typeQuery)
{
    emit CheckRelationship(typeQuery);
}

void SocketManager::ReadAddPostAnswer(const TypeQuery &typeQuery)
{
    if (typeQuery == ADD_POST_QUERY)
        emit AddPost();
    else
        emit AddPostFailed();
}

void SocketManager::ReadGetPostAnswer(const TypeQuery &typeQuery)
{
    if (typeQuery == GET_POSTS_QUERY)
        emit GetPost(postModelVector);
    else
        emit GetPostFailed();
}

void SocketManager::ReadGetUserPostAnswer(const TypeQuery &typeQuery)
{
    if (typeQuery == GET_USER_POSTS_QUERY)
        emit GetUserPost(postModelVector);
    else
        emit GetUserPostFailed();
}

void SocketManager::ReadDeletePostAnswer(const TypeQuery &typeQuery)
{
    if (typeQuery == DELETE_USER_POST_QUERY)
        emit DeletePost(postModel);
    else
        emit DeletePostFailed();
}

void SocketManager::ReadEditPostAnswer(const TypeQuery &typeQuery)
{
    if (typeQuery == EDIT_POST_QUERY)
        emit EditPost(postModel);
    else
        emit EditPostFailed();
}

void SocketManager::ReadLikePostAnswer(const TypeQuery &typeQuery)
{
    if (typeQuery == LIKE_POST_QUERY)
        emit LikePost(likeModel);
    else
        emit LikePostFailed();
}

void SocketManager::ReadAddCommentPostAnswer(const TypeQuery &typeQuery)
{
    if (typeQuery == ADD_COMMENT_QUERY)
        emit AddCommentPost(commentModel);
    else
        emit AddCommentPostFailed();
}

void SocketManager::ReadDeleteCommentPostAnswer(const TypeQuery &typeQuery)
{
    if (typeQuery == DELETE_COMMENT_QUERY)
        emit DeleteCommentPost(commentModel);
    else
        emit DeleteCommentPostFailed();
}

void SocketManager::ReadEditCommentPostAnswer(const TypeQuery &typeQuery)
{
    if (typeQuery == EDIT_COMMENT_QUERY)
        emit EditCommentPost(commentModel);
    else
        emit EditCommentPostFailed();
}

void SocketManager::ReadGetCommentPostAnswer(const TypeQuery &typeQuery)
{
    if (typeQuery == GET_COMMENTS_QUERY)
        emit GetCommentPost(commentList);
    else
        emit GetCommentPostFailed();
}
