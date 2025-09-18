#ifndef DATABASEPOSTMANAGER_H
#define DATABASEPOSTMANAGER_H

#include <QDir>
#include <QSqlQuery>
#include <QSqlError>
#include <QList>
#include "PostModel.h"
#include "Managers/DataBaseUserManager.h"
#include "Managers/DataBaseFileManager.h"
#include "Managers/DataBaseLikeManager.h"
#include "Managers/DataBaseCommentManager.h"
#include "MediaHelpers/FileWriter.h"
#include "MediaHelpers/FileReader.h"

class DataBasePostManager
{
private:
    QList <PostModel>       postList;
    DataBaseFileManager     dbFileManager;
    DataBaseLikeManager     dbLikeManager;
    DataBaseCommentManager  dbCommentManager;
    FileWriter              fileWriter;
    PostModel               tempPostModel;
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
        tempPostModel = postModel;

        QSqlQuery query(dataBase);

        query.prepare("INSERT INTO post (id_user, name, text_content, created_date) VALUES (?, ?, ?, ?);");

        query.addBindValue(tempPostModel.GetIdUser());
        query.addBindValue(tempPostModel.GetName());
        query.addBindValue(tempPostModel.GetTextContent());
        query.addBindValue(tempPostModel.GetCreatedDate());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }

        query.prepare("SELECT * FROM post WHERE id_user = :id_user AND created_date = :created_date");

        query.bindValue(":id_user", tempPostModel.GetIdUser());
        query.bindValue(":created_date", tempPostModel.GetCreatedDate());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }
        if (query.next())
        {
            tempPostModel.SetIdPost(query.value(0).toInt());
        }

        if (!tempPostModel.GetFileModel().GetFileData().isEmpty())
        {
            if (!fileWriter.SaveFileOnServer(tempPostModel.GetFileModel()) || !dbFileManager.AddFileInPost(tempPostModel, dataBase))
                return false;
        }

        return true;
    }

    bool DeletePost(const PostModel &postModel, const QSqlDatabase &dataBase)
    {
        if (!postModel.GetFileModel().GetFileData().isEmpty())
        {
            fileWriter.DeleteFile(postModel.GetFileModel());
            dbFileManager.DeleteFileInPost(postModel, dataBase);
        }

        dbCommentManager.DeleteAllCommentsPost(postModel, dataBase);
        dbLikeManager.DeleteAllLikesPost(postModel, dataBase);

        QSqlQuery query(dataBase);

        query.prepare("DELETE FROM post WHERE id_post = :id_post;");
        query.bindValue(":id_post", postModel.GetIdPost());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }

        return true;
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
