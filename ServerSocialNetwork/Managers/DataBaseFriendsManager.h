#ifndef DATABASEFRIENDSMANAGER_H
#define DATABASEFRIENDSMANAGER_H

#include <QVector>
#include <QString>
#include <QByteArray>
#include <QSqlQuery>
#include <QSqlError>
#include "MediaManager.h"
#include "TypeQuery.h"
#include "UserModel.h"

class DataBaseFriendsManager
{
private:
    UserModel           tempUserModel;
    QVector <UserModel> usersVector;
    MediaManager mediaManager;

public:
    QVector <UserModel> GetUsers(const QSqlDatabase &dataBase)  // Функция получения массива пользователей
    {
        QSqlQuery query(dataBase);

        if (!usersVector.isEmpty())
            usersVector.clear();

        query.prepare("SELECT * FROM users;");

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
        }
        while (query.next())
        {
            tempUserModel.SetIdUser(query.value(0).toInt());
            tempUserModel.SetLogin(query.value(1).toString());
            tempUserModel.SetPhone(query.value(3).toString());
            tempUserModel.SetEmail(query.value(4).toString());
            tempUserModel.SetPhotoPath(query.value(5).toString());
            tempUserModel.SetEntryTime(query.value(6).toString());
            tempUserModel.SetDateBithday(query.value(7).toString());

            if (!tempUserModel.GetPhotoPath().isEmpty())
                tempUserModel.SetPhoto(mediaManager.GetPhotoUser(tempUserModel));

            usersVector.push_back(tempUserModel);
        }

        return usersVector;
    }

    QVector <UserModel> GetFriends(const UserModel &userModel, const QSqlDatabase &dataBase)
    {
        QVector <qint16>    indexUserVector;
        QSqlQuery           query(dataBase);

        if (!usersVector.isEmpty() || !indexUserVector.isEmpty())
        {
            usersVector.clear();
            indexUserVector.clear();
        }

        query.prepare("SELECT * FROM friends WHERE id_first_user = :id_user;");
        query.bindValue(":id_user", userModel.GetIdUser());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
        }
        while (query.next())
        {
            indexUserVector.push_back(query.value(1).toInt());
        }

        query.prepare("SELECT * FROM friends WHERE id_second_user = :id_user;");
        query.bindValue(":id_user", userModel.GetIdUser());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
        }
        while (query.next())
        {
            indexUserVector.push_back(query.value(1).toInt());
        }

        query.prepare("SELECT * FROM users WHERE id_user = :id_user;");

        for (int i = 0; i < indexUserVector.size(); ++i)
        {
            query.bindValue(":id_user", indexUserVector[i]);

            if (!query.exec())
            {
                qDebug() << query.lastError().text();
            }
            while (query.next())
            {
                tempUserModel.SetIdUser(query.value(0).toInt());
                tempUserModel.SetLogin(query.value(1).toString());
                tempUserModel.SetPhone(query.value(3).toString());
                tempUserModel.SetEmail(query.value(4).toString());
                tempUserModel.SetPhotoPath(query.value(5).toString());
                tempUserModel.SetEntryTime(query.value(6).toString());
                tempUserModel.SetDateBithday(query.value(7).toString());

                if (!tempUserModel.GetPhotoPath().isEmpty())
                    tempUserModel.SetPhoto(mediaManager.GetPhotoUser(tempUserModel));

                usersVector.push_back(tempUserModel);
            }
        }
        qDebug() << "Размер вектора друзей: " << usersVector.size();
        return usersVector;
    }

    TypeQuery GetRelationship(const UserModel &mainUserModel, const UserModel &tempUserModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("SELECT * FROM friends WHERE id_first_user = :id_first_user AND id_second_user = :id_second_user;");
        query.bindValue(":id_first_user", mainUserModel.GetIdUser());
        query.bindValue(":id_second_user", tempUserModel.GetIdUser());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
        }
        if (query.next())
        {
            if (mainUserModel.GetIdUser() == query.value(0).toInt() && tempUserModel.GetIdUser() == query.value(1).toInt())
                return RELATIONSHIP_FRIEND_ANSWER;
        }

        query.prepare("SELECT * FROM friends WHERE id_first_user = :id_first_user AND id_second_user = :id_second_user;");
        query.bindValue(":id_first_user", tempUserModel.GetIdUser());
        query.bindValue(":id_second_user", mainUserModel.GetIdUser());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
        }
        if (query.next())
        {
            if (tempUserModel.GetIdUser() == query.value(0).toInt() && mainUserModel.GetIdUser() == query.value(1).toInt())
                return RELATIONSHIP_FRIEND_ANSWER;
        }

        query.prepare("SELECT * FROM notification WHERE id_user_sender = :id_user_sender AND id_user_accepter = :id_user_accepter;");
        query.bindValue(":id_user_sender", mainUserModel.GetIdUser());
        query.bindValue(":id_user_accepter", tempUserModel.GetIdUser());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
        }
        if (query.next())
        {
            if ((mainUserModel.GetIdUser() == query.value(1).toInt() && tempUserModel.GetIdUser() == query.value(2).toInt()) ||
                (mainUserModel.GetIdUser() == query.value(2).toInt() && tempUserModel.GetIdUser() == query.value(1).toInt()))
                return RELATIONSHIP_WAIT_NOTIFICATION_ANSWER;
        }

        return RELATIONSHIP_NOT_FRIEND_ANSWER;
    }

    void DeleteFriend(const UserModel &mainUserModel, const UserModel &tempUserModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("DELETE FROM friends WHERE id_first_user = :id_first_user AND id_second_user = :id_second_user;");
        query.bindValue(":id_first_user", mainUserModel.GetIdUser());
        query.bindValue(":id_second_user", tempUserModel.GetIdUser());

        if (!query.exec())
            qDebug() << query.lastError().text();

        query.prepare("DELETE FROM friends WHERE id_first_user = :id_first_user AND id_second_user = :id_second_user;");
        query.bindValue(":id_first_user", tempUserModel.GetIdUser());
        query.bindValue(":id_second_user", mainUserModel.GetIdUser());

        if (!query.exec())
            qDebug() << query.lastError().text();
    }
};

#endif // DATABASEFRIENDSMANAGER_H
