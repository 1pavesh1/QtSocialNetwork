#ifndef DATABASEPOSTMANAGER_H
#define DATABASEPOSTMANAGER_H

#include <QDir>
#include <QSqlQuery>
#include <QSqlError>
#include <QVector>
#include "TimeManager.h"
#include "MediaManager.h"
#include "PostModel.h"
#include "Managers/DataBaseUserManager.h"

class DataBasePostManager
{
private:
    QVector <PostModel> vectorPost;
    TimeManager     timeManger;
    MediaManager    mediaManager;

public:
    QVector<PostModel> GetPosts(const QSqlDatabase &dataBase)
    {
        DataBaseUserManager dbUserManager;
        QSqlQuery           query(dataBase);

        if (!vectorPost.isEmpty())
            vectorPost.clear();

        query.prepare("SELECT * FROM post;");

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
        }
        while (query.next())
        {
            PostModel tempPostModel;

            tempPostModel.SetIdPost(query.value(0).toInt());
            tempPostModel.SetIdUser(query.value(1).toInt());
            tempPostModel.SetName(query.value(5).toString());
            tempPostModel.SetTextContent(query.value(2).toString());
            tempPostModel.SetCreatedDate(query.value(4).toString());
            tempPostModel.SetFileName(query.value(7).toString());
            tempPostModel.SetFileType(query.value(6).toString());
            tempPostModel.SetFilePath(query.value(3).toString());
            tempPostModel.SetUserModel(dbUserManager.GetUserInId(tempPostModel.GetIdUser(), dataBase));

            if (!tempPostModel.GetFilePath().isEmpty())
                tempPostModel.SetMediaData(mediaManager.GetMediaDataPost(tempPostModel));

            vectorPost.push_back(tempPostModel);
        }

        return vectorPost;
    }

    QVector<PostModel> GetUserPosts(const UserModel &userModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery           query(dataBase);

        if (!vectorPost.isEmpty())
            vectorPost.clear();

        query.prepare("SELECT * FROM post WHERE id_user = :id_user;");
        query.bindValue(":id_user", userModel.GetIdUser());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
        }
        while (query.next())
        {
            PostModel tempPostModel;

            tempPostModel.SetIdPost(query.value(0).toInt());
            tempPostModel.SetIdUser(query.value(1).toInt());
            tempPostModel.SetName(query.value(5).toString());
            tempPostModel.SetTextContent(query.value(2).toString());
            tempPostModel.SetCreatedDate(query.value(4).toString());
            tempPostModel.SetFileName(query.value(7).toString());
            tempPostModel.SetFileType(query.value(6).toString());
            tempPostModel.SetFilePath(query.value(3).toString());

            if (!tempPostModel.GetFilePath().isEmpty())
                tempPostModel.SetMediaData(mediaManager.GetMediaDataPost(tempPostModel));

            vectorPost.push_back(tempPostModel);
        }

        return vectorPost;
    }

    bool AddPost(const PostModel &postModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("INSERT INTO post (id_user, text_content, file_path, created_date, name, file_type, file_name) VALUES (?, ?, ?, ?, ?, ?, ?);");

        query.addBindValue(postModel.GetIdUser());
        query.addBindValue(postModel.GetTextContent());
        query.addBindValue(postModel.GetFilePath());
        query.addBindValue(timeManger.GetDateTime());
        query.addBindValue(postModel.GetName());
        query.addBindValue(postModel.GetFileType());
        query.addBindValue(postModel.GetFileName());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }

        return true;
    }
};

#endif // DATABASEPOSTMANAGER_H
