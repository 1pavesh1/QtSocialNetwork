#ifndef DATABASECOMMENTMANAGER_H
#define DATABASECOMMENTMANAGER_H

#include <QList>
#include <QString>
#include <QByteArray>
#include <QSqlQuery>
#include <QSqlError>
#include "CommentModel.h"
#include "PostModel.h"
#include "Managers/DataBaseUserManager.h"

class DataBaseCommentManager
{
public:
    QList <CommentModel> GetComments(const PostModel &postModel, const QSqlDatabase &dataBase)
    {
        CommentModel                    tempCommentModel;
        DataBaseUserManager             dbUserManager;
        QList <CommentModel>            commentList;
        QSqlQuery                       query(dataBase);

        query.prepare("SELECT * FROM comment WHERE id_post = :id_post;");
        query.bindValue(":id_post", postModel.GetIdPost());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
        }
        while (query.next())
        {
            tempCommentModel.SetIdComment(query.value(0).toInt());
            tempCommentModel.SetIdPost(query.value(1).toInt());
            tempCommentModel.SetIdUser(query.value(2).toInt());
            tempCommentModel.SetTextContent(query.value(3).toString());
            tempCommentModel.SetCreatedDate(query.value(4).toString());
            tempCommentModel.SetIsEdited(query.value(5).toBool());
            tempCommentModel.SetUserModel(dbUserManager.GetUserInId(tempCommentModel.GetIdUser(), dataBase));

            commentList.push_back(tempCommentModel);
        }
        return commentList;
    }

    bool AddComment(const CommentModel &commentModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery    query(dataBase);

        query.prepare("INSERT INTO comment (id_post, id_user, text_content, created_date, is_edited) VALUES (?, ?, ?, ?, ?);");
        query.addBindValue(commentModel.GetIdPost());
        query.addBindValue(commentModel.GetIdUser());
        query.addBindValue(commentModel.GetTextContent());
        query.addBindValue(commentModel.GetCreatedDate());
        query.addBindValue(commentModel.IsEdited());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }
        return true;
    }

    bool DeleteComment(const CommentModel &commentModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("DELETE FROM comment WHERE id_comment = :id_comment;");
        query.bindValue(":id_comment", commentModel.GetIdComment());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }
        return true;
    }

    bool DeleteAllCommentsPost(const PostModel &postModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("DELETE FROM comment WHERE id_post = :id_post;");
        query.bindValue(":id_post", postModel.GetIdPost());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }
        return true;
    }

    bool EditComment(const CommentModel &commentModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("UPDATE comment SET text_content = ?, is_edited = ? WHERE id_comment = ?;");

        query.addBindValue(commentModel.GetTextContent());
        query.addBindValue(true);
        query.addBindValue(commentModel.GetIdComment());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }
        return true;
    }
};

#endif // DATABASECOMMENTMANAGER_H
