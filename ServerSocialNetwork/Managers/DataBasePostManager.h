#ifndef DATABASEPOSTMANAGER_H
#define DATABASEPOSTMANAGER_H

#include <QDir>
#include <QSqlQuery>
#include <QSqlError>
#include <QList>
#include "Utils/TimeUtil.h"
#include "PostModel.h"
#include "Managers/DataBaseUserManager.h"
#include "Managers/DataBaseFileManager.h"
#include "Managers/DataBaseFileManager.h"
#include "MediaHelpers/FileWriter.h"
#include "MediaHelpers/FileReader.h"

class DataBasePostManager
{
private:
    QList <PostModel>   postList;
    TimeUtil            timeUtil;
    DataBaseFileManager dbFileManager;
    FileWriter          fileWriter;

public:
    QList<PostModel> GetPosts(const QSqlDatabase &dataBase)
    {
        DataBaseUserManager dbUserManager;
        QSqlQuery           query(dataBase);

        if (!postList.isEmpty())
            postList.clear();

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
            tempPostModel.SetName(query.value(2).toString());
            tempPostModel.SetTextContent(query.value(3).toString());
            tempPostModel.SetCreatedDate(query.value(4).toString());
            tempPostModel.SetCountLikes(GetCountLikes(tempPostModel, dataBase));
            tempPostModel.SetCountComments(GetCountComments(tempPostModel, dataBase));
            tempPostModel.SetUserModel(dbUserManager.GetUserInId(tempPostModel.GetIdUser(), dataBase));
            tempPostModel.SetFileModel(dbFileManager.GetFileInPost(tempPostModel, dataBase));

            postList.push_back(tempPostModel);
        }

        return postList;
    }

    QList<PostModel> GetUserPosts(const UserModel &userModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery           query(dataBase);

        if (!postList.isEmpty())
            postList.clear();

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
            tempPostModel.SetName(query.value(2).toString());
            tempPostModel.SetTextContent(query.value(3).toString());
            tempPostModel.SetCreatedDate(query.value(4).toString());
            tempPostModel.SetCountLikes(GetCountLikes(tempPostModel, dataBase));
            tempPostModel.SetCountComments(GetCountComments(tempPostModel, dataBase));
            tempPostModel.SetFileModel(dbFileManager.GetFileInPost(tempPostModel, dataBase));

            postList.push_back(tempPostModel);
        }

        return postList;
    }

    bool EditPost(const PostModel &postModel, const QSqlDatabase &dataBase)
    {

    }

    bool AddPost(const PostModel &postModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("INSERT INTO post (id_user, name, text_content, created_date) VALUES (?, ?, ?, ?);");

        query.addBindValue(postModel.GetIdUser());
        query.addBindValue(postModel.GetName());
        query.addBindValue(postModel.GetTextContent());
        query.addBindValue(timeUtil.GetDateTime());
        dbFileManager.AddFileInPost(postModel, dataBase);

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }

        return true;
    }

    bool DeletePost(const PostModel &postModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("DELETE FROM post WHERE id_post = :id_post;");
        query.bindValue(":id_post", postModel.GetIdPost());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }
        if (!dbFileManager.DeleteFileInPost(postModel, dataBase))
            return false;

        return fileWriter.DeleteFile(postModel.GetFileModel());
    }

    qint32 GetCountLikes(const PostModel &postModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("SELECT COUNT(*) FROM likes WHERE id_post = :id_post");
        query.bindValue(":id_post", postModel.GetIdPost());

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

    qint32 GetCountComments(const PostModel &postModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("SELECT COUNT(*) FROM comment WHERE id_post = :id_post");
        query.bindValue(":id_post", postModel.GetIdPost());

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
};

#endif // DATABASEPOSTMANAGER_H
