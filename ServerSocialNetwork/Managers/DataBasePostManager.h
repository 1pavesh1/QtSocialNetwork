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

        query.prepare("SELECT TOP 5 * FROM post ORDER BY created_date DESC;");

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
            tempPostModel.SetLikesList(GetLikesList(tempPostModel, dataBase));
            tempPostModel.SetCommentsList(GetCommentsList(tempPostModel, dataBase));
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

        query.prepare("SELECT TOP 5 * FROM post WHERE id_user = :id_user ORDER BY created_date DESC;");
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
            tempPostModel.SetLikesList(GetLikesList(tempPostModel, dataBase));
            tempPostModel.SetCommentsList(GetCommentsList(tempPostModel, dataBase));
            tempPostModel.SetFileModel(dbFileManager.GetFileInPost(tempPostModel, dataBase));

            postList.push_back(tempPostModel);
        }

        return postList;
    }

    QList<PostModel> GetPostsInName(const PostModel &postModel, const QSqlDatabase &dataBase)
    {
        DataBaseUserManager dbUserManager;
        QSqlQuery           query(dataBase);

        if (!postList.isEmpty())
            postList.clear();

        query.prepare("SELECT * FROM post WHERE name = :name ORDER BY created_date DESC;");
        query.bindValue(":name", postModel.GetName());

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
            tempPostModel.SetLikesList(GetLikesList(tempPostModel, dataBase));
            tempPostModel.SetCommentsList(GetCommentsList(tempPostModel, dataBase));
            tempPostModel.SetUserModel(dbUserManager.GetUserInId(tempPostModel.GetIdUser(), dataBase));
            tempPostModel.SetFileModel(dbFileManager.GetFileInPost(tempPostModel, dataBase));

            postList.push_back(tempPostModel);
        }

        return postList;
    }

    QList <LikeModel> GetLikesList(const PostModel &postModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery           query(dataBase);
        LikeModel           likeModel;
        QList <LikeModel>   likesList;

        query.prepare("SELECT * FROM likes WHERE id_post = :id_post;");
        query.bindValue(":id_post", postModel.GetIdPost());

        if (!query.exec())
            qDebug() << query.lastError().text();

        while (query.next())
        {
            likeModel.SetIdLike(query.value(0).toInt());
            likeModel.SetIdUser(query.value(1).toInt());
            likeModel.SetIdPost(query.value(2).toInt());

            likesList.push_back(likeModel);
        }

        return likesList;
    }

    QList <CommentModel> GetCommentsList(const PostModel &postModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery               query(dataBase);
        CommentModel            commentModel;
        QList <CommentModel>    commentList;

        query.prepare("SELECT * FROM comment WHERE id_post = :id_post;");
        query.bindValue(":id_post", postModel.GetIdPost());

        if (!query.exec())
            qDebug() << query.lastError().text();

        while (query.next())
        {
            commentModel.SetIdComment(query.value(0).toInt());
            commentModel.SetIdPost(query.value(1).toInt());
            commentModel.SetIdUser(query.value(2).toInt());
            commentModel.SetTextContent(query.value(3).toString());
            commentModel.SetCreatedDate(query.value(4).toString());
            commentModel.SetIsEdited(query.value(5).toBool());

            commentList.push_back(commentModel);
        }

        return commentList;
    }

    bool EditPost(const PostModel &postModel, const QSqlDatabase &dataBase)
    {
        if (postModel.GetFileModel().GetFileData().isEmpty())
        {
            if (!fileWriter.DeleteFile(postModel.GetFileModel()) || !dbFileManager.DeleteFileInPost(postModel, dataBase))
                return false;
        }
        else
        {
            if (!fileWriter.DeleteFile(postModel.GetFileModel()) || !fileWriter.SaveFileOnServer(postModel.GetFileModel()) || !dbFileManager.UpdateFilePathInPost(postModel, dataBase))
                return false;
        }

        QSqlQuery query(dataBase);

        query.prepare("UPDATE post SET name = ?, text_content = ? WHERE id_post = ?;");

        query.addBindValue(postModel.GetName());
        query.addBindValue(postModel.GetTextContent());
        query.addBindValue(postModel.GetIdPost());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }

        return true;
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

        query.prepare("SELECT * FROM post WHERE id_user = :id_user AND created_date = :created_date AND name = :name");

        query.bindValue(":id_user", tempPostModel.GetIdUser());
        query.bindValue(":created_date", tempPostModel.GetCreatedDate());
        query.bindValue(":name", tempPostModel.GetName());

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
            if (!fileWriter.DeleteFile(postModel.GetFileModel()) || !dbFileManager.DeleteFileInPost(postModel, dataBase))
                return false;
        }

        if (!dbCommentManager.DeleteAllCommentsPost(postModel, dataBase) || !dbLikeManager.DeleteAllLikesPost(postModel, dataBase))
            return false;


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
};

#endif // DATABASEPOSTMANAGER_H
