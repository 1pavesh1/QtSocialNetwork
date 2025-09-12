#ifndef DATABASENOTIFICATIONMANAGER_H
#define DATABASENOTIFICATIONMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "NotificationModel.h"
#include "UserModel.h"
#include "Utils/TimeUtil.h"
#include "Managers/DataBaseUserManager.h"

class DataBaseNotificationManager
{
public:
    QList <NotificationModel> GetNotifications(const UserModel &userModel, const QSqlDatabase &dataBase)
    {
        DataBaseUserManager             dataBaseUserManager;
        NotificationModel               tempNotificationModel;
        QList <NotificationModel>       notificationList;
        QSqlQuery                       query(dataBase);

        if (!notificationList.isEmpty())
            notificationList.clear();

        query.prepare("SELECT * FROM notification WHERE id_user_accepter = :id_user;");
        query.bindValue(":id_user", userModel.GetIdUser());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
        }
        while (query.next())
        {
            tempNotificationModel.SetIdNotification(query.value(0).toInt());
            tempNotificationModel.SetIdUserSender(query.value(1).toInt());
            tempNotificationModel.SetIdUserAccepter(query.value(2).toInt());
            tempNotificationModel.SetQuery(query.value(3).toString());
            tempNotificationModel.SetDateSending(query.value(4).toString());

            tempNotificationModel.SetUserModel(dataBaseUserManager.GetUserInId(tempNotificationModel.GetIdUserSender(), dataBase));

            notificationList.push_back(tempNotificationModel);
        }

        return notificationList;
    }

    bool AddNotification(const UserModel &mainUserModel, const UserModel &tempUserModel, const QSqlDatabase &dataBase)
    {
        TimeUtil    timeUtil;
        QSqlQuery   query(dataBase);

        query.prepare("INSERT INTO notification (id_user_sender, id_user_accepter, query, date_sending) VALUES (?, ?, ?, ?);");
        query.addBindValue(mainUserModel.GetIdUser());
        query.addBindValue(tempUserModel.GetIdUser());
        query.addBindValue("ADD_USER");
        query.addBindValue(timeUtil.GetDateTime());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }
        return true;
    }

    void DeleteNotificationInUser(const UserModel &mainUserModel, const UserModel &tempUserModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("DELETE FROM notification WHERE id_user_sender = :id_user_sender AND id_user_accepter = :id_user_accepter;");
        query.bindValue(":id_user_sender", mainUserModel.GetIdUser());
        query.bindValue(":id_user_accepter", tempUserModel.GetIdUser());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
        }

        query.prepare("DELETE FROM notification WHERE id_user_sender = :id_user_sender AND id_user_accepter = :id_user_accepter;");
        query.bindValue(":id_user_sender", tempUserModel.GetIdUser());
        query.bindValue(":id_user_accepter", mainUserModel.GetIdUser());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
        }
    }

    void DeleteNotificationInModel(const NotificationModel &notificationModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("DELETE FROM notification WHERE id_user_sender = :id_user_sender AND id_user_accepter = :id_user_accepter;");
        query.bindValue(":id_user_sender", notificationModel.GetIdUserSender());
        query.bindValue(":id_user_accepter", notificationModel.GetIdUserAccepter());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
        }

        query.prepare("DELETE FROM notification WHERE id_user_sender = :id_user_sender AND id_user_accepter = :id_user_accepter;");
        query.bindValue(":id_user_sender", notificationModel.GetIdUserAccepter());
        query.bindValue(":id_user_accepter", notificationModel.GetIdUserSender());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
        }
    }

    void AcceptNotifciation(const NotificationModel &notificationModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("INSERT INTO friends (id_first_user, id_second_user) VALUES (?, ?);");
        query.addBindValue(notificationModel.GetIdUserSender());
        query.addBindValue(notificationModel.GetIdUserAccepter());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
        }

        DeleteNotificationInModel(notificationModel, dataBase);
    }
};

#endif // DATABASENOTIFICATIONMANAGER_H
