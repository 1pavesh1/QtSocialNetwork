#ifndef USERSERVERMANAGER_H
#define USERSERVERMANAGER_H

#include <QTcpSocket>
#include <QMap>
#include <QVector>
#include "UserModel.h"

class UserServerManager
{
public:
    UserModel GetUserInSocket(QMap <QTcpSocket*, UserModel> &userServerMap, QTcpSocket *socket)
    {
        return userServerMap[socket];
    }

    void AddSocketServerToMap(QMap <QTcpSocket*, UserModel> &userServerMap, QTcpSocket *socket)
    {
        UserModel tempModel;
        userServerMap.insert(socket, tempModel);
    }

    void AddUserServerToMap(QMap <QTcpSocket*, UserModel> &userServerMap, QTcpSocket *socket, UserModel &userModel)
    {
        userServerMap.find(socket).value() = userModel;
    }

    void RemoveUserServerFromMap(QMap <QTcpSocket*, UserModel> &userServerMap, QTcpSocket *socket)
    {
        userServerMap.remove(socket);
    }

    void ReplaceUser(QMap <QTcpSocket*, UserModel> &userServerMap, QTcpSocket *socket, UserModel &userModel)
    {
        userServerMap[socket] = userModel;
    }

    void DeleteDataUserServerFromMap(QMap <QTcpSocket*, UserModel> &userServerMap, QTcpSocket *socket)
    {
        qDebug() << "Пользователь вышел из аккаунта: " << userServerMap[socket].GetLogin();
        UserModel tempModel;
        userServerMap[socket] = tempModel;
    }

    bool CheckUserOnServer(QMap <QTcpSocket*, UserModel> &userServerMap, QTcpSocket *socket)
    {
        if (userServerMap.count(socket))
        {
            return true;
        }
        return false;
    }

    bool CheckUserMain(QMap <QTcpSocket*, UserModel> &userServerMap, QTcpSocket *socket, UserModel &userModel)
    {
        if (userServerMap.value(socket).GetIdUser() == userModel.GetIdUser())
            return true;
        else
            return false;
    }
};

#endif // USERSERVERMANAGER_H
