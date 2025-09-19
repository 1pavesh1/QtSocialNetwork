#ifndef DATABASELIKEMANAGER_H
#define DATABASELIKEMANAGER_H

#include <QVector>
#include <QString>
#include <QByteArray>
#include <QSqlQuery>
#include <QSqlError>
#include "LikeModel.h"
#include "PostModel.h"

class DataBaseLikeManager
{
public:
    bool CheckLikePost(const LikeModel &likeModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery    query(dataBase);

        query.prepare("SELECT * FROM likes WHERE id_user = :id_user AND id_post = :id_post;");
        query.bindValue(":id_user", likeModel.GetIdUser());
        query.bindValue(":id_post", likeModel.GetIdPost());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }
        if (query.next())
        {
            if (likeModel.GetIdUser() == query.value(1).toInt() && likeModel.GetIdPost() == query.value(2).toInt())
            {
                return true;
            }
        }

        return false;
    }

    bool AddLikePost(const LikeModel &likeModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery    query(dataBase);

        query.prepare("INSERT INTO likes (id_user, id_post) VALUES (?, ?);");
        query.addBindValue(likeModel.GetIdUser());
        query.addBindValue(likeModel.GetIdPost());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }
        return true;
    }

    bool DeleteLikePost(const LikeModel &likeModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery    query(dataBase);

        query.prepare("DELETE FROM likes WHERE id_user = :id_user AND id_post = :id_post;");
        query.bindValue(":id_user", likeModel.GetIdUser());
        query.bindValue(":id_post", likeModel.GetIdPost());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }
        return true;
    }

    bool DeleteAllLikesPost(const PostModel &postModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("DELETE FROM likes WHERE id_post = :id_post;");
        query.bindValue(":id_post", postModel.GetIdPost());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }
        return true;
    }
};

#endif // DATABASELIKEMANAGER_H
