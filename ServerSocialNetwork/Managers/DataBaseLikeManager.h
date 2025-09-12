#ifndef DATABASELIKEMANAGER_H
#define DATABASELIKEMANAGER_H

#include <QVector>
#include <QString>
#include <QByteArray>
#include <QSqlQuery>
#include <QSqlError>
#include "LikeModel.h"

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
};

#endif // DATABASELIKEMANAGER_H
