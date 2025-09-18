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

    bool DeleteAllLikesPost(const PostModel &postModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);
        qDebug() << "dbLikeManager: " << postModel.GetFileModel().GetIdFile() << " " << postModel.GetIdPost();

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
