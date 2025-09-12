#ifndef DATABASEUSERMANAGER_H
#define DATABASEUSERMANAGER_H

#include <QDir>
#include <QSqlQuery>
#include <QSqlError>
#include "Utils/TimeUtil.h"
#include "UserModel.h"
#include "Managers/DataBaseFileManager.h"
#include "MediaHelpers/FileWriter.h"
#include "MediaHelpers/FileReader.h"

class DataBaseUserManager
{
private:
    QByteArray      photoData;
    TimeUtil        timeUtil;
    DataBaseFileManager dbFileManager;

public:
    UserModel GetUserInId(const qint16 &idUser, const QSqlDatabase &dataBase)
    {
        UserModel       tempUserModel;
        QSqlQuery       query(dataBase);

        query.prepare("SELECT * FROM users WHERE id_user = :id_user;");
        query.bindValue(":id_user", idUser);

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
        }
        if (query.next())
        {
            tempUserModel.SetIdUser(query.value(0).toInt());
            tempUserModel.SetLogin(query.value(1).toString());
            tempUserModel.SetPhone(query.value(3).toString());
            tempUserModel.SetEmail(query.value(4).toString());
            tempUserModel.SetDateBithday(query.value(6).toString());
        }

        return tempUserModel;
    }

    bool RegUser(UserModel &userModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("INSERT INTO users (login, password, phone, entry_time) VALUES (?, ?, ?, ?);");

        userModel.SetEntryTime(timeUtil.GetDateTime());

        query.addBindValue(userModel.GetLogin());
        query.addBindValue(userModel.GetPassword());
        query.addBindValue(userModel.GetPhone());
        query.addBindValue(userModel.GetEntryTime());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }

        return true;
    }

    bool AuthUser(UserModel &userModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("SELECT * FROM users WHERE login = :login AND password = :password AND phone = :phone;");
        query.bindValue(":login", userModel.GetLogin());
        query.bindValue(":password", userModel.GetPassword());
        query.bindValue(":phone", userModel.GetPhone());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }
        if (query.next())
        {
            if (userModel.GetLogin() == query.value(1).toString() && userModel.GetPassword() == query.value(2).toString()
                && userModel.GetPhone() == query.value(3).toString())
            {
                userModel.SetIdUser(query.value(0).toInt());
                userModel.SetEmail(query.value(4).toString());
                userModel.SetEntryTime(timeUtil.GetDateTime());
                userModel.SetDateBithday(query.value(7).toString());
                userModel.SetCountNotifications(GetCountNotifications(userModel, dataBase));
                userModel.SetCountFriends(GetCountFriends(userModel, dataBase));
                userModel.SetStatus(true);
                userModel.SetFileModel(dbFileManager.GetFileInUser(userModel, dataBase));

                return true;
            }
        }
        return false;
    }

    bool CheckUserLogin(const UserModel &userModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("SELECT COUNT(*) FROM users WHERE login = :login;");

        if (userModel.GetIdUser() != 0)
        {
            query.prepare("SELECT COUNT(*) FROM users WHERE login = :login AND id_user != :id_user;");
            query.bindValue(":id_user", userModel.GetIdUser());
        }
        else
        {
            query.prepare("SELECT COUNT(*) FROM users WHERE login = :login;");
        }

        query.bindValue(":login", userModel.GetLogin());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }

        if (query.next())
        {
            return (query.value(0).toInt() == 0);
        }

        return false;
    }

    bool CheckUserLoginUpdate(const UserModel &userModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("SELECT COUNT(*) FROM users WHERE login = :login;");

        if (userModel.GetIdUser() != 0)
        {
            query.prepare("SELECT COUNT(*) FROM users WHERE login = :login AND id_user != :id_user;");
            query.bindValue(":login", userModel.GetIdUser());
        }
        else
        {
            query.prepare("SELECT COUNT(*) FROM users WHERE login = :login;");
        }

        query.bindValue(":login", userModel.GetLogin());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }

        if (query.next())
        {
            return (query.value(0).toInt() == 0);
        }

        return false;
    }

    bool UpdateDataUser(const UserModel &userModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("UPDATE users SET login = ?, password = ?, phone = ?, email = ?, date_birthday = ? WHERE id_user = ?;");

        query.addBindValue(userModel.GetLogin());
        query.addBindValue(userModel.GetPassword());
        query.addBindValue(userModel.GetPhone());
        query.addBindValue(userModel.GetEmail());
        query.addBindValue(userModel.GetDateBithday());
        query.addBindValue(userModel.GetIdUser());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }
        return true;
    }

    bool UpdateTimeUser(const UserModel &userModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("UPDATE users SET entry_time = ? WHERE id_user = ?;");

        query.addBindValue(userModel.GetEntryTime());
        query.addBindValue(userModel.GetIdUser());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }
        return true;
    }

    bool UpdatePhotoUser(const UserModel &userModel, const QSqlDatabase &dataBase)
    {
        return dbFileManager.AddFileInUser(userModel, dataBase);
    }

    qint32 GetCountNotifications(const UserModel &userModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("SELECT COUNT(*) FROM notification WHERE id_user_accepter = :id_user");
        query.bindValue(":id_user", userModel.GetIdUser());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
        }
        if (query.next())
        {
            return query.value(0).toInt();
        }
        return 0;
    }

    qint32 GetCountFriends(const UserModel &userModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery   query(dataBase);
        qint32      sum = 0;

        query.prepare("SELECT COUNT(*) FROM friends WHERE id_first_user = :id_user");
        query.bindValue(":id_user", userModel.GetIdUser());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
        }
        if (query.next())
        {
            sum += query.value(0).toInt();
        }

        query.prepare("SELECT COUNT(*) FROM friends WHERE id_second_user = :id_user");
        query.bindValue(":id_user", userModel.GetIdUser());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
        }
        if (query.next())
        {
            sum += query.value(0).toInt();
        }

        return sum;
    }
};

#endif // DATABASEUSERMANAGER_H
