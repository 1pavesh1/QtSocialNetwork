#ifndef DATABASEFILEMANAGER_H
#define DATABASEFILEMANAGER_H

#include <QSqlQuery>
#include <QSqlError>
#include "PostModel.h"
#include "UserModel.h"
#include "FileModel.h"

class DataBaseFileManager
{
private:
    FileModel   fileModel;
public:
    bool AddFileInPost(const PostModel &postModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("INSERT INTO file (name, path, type, format) VALUES (?, ?, ?, ?);");

        query.addBindValue(postModel.GetFileModel().GetName());
        query.addBindValue(postModel.GetFileModel().GetPath());
        query.addBindValue(postModel.GetFileModel().GetType());
        query.addBindValue(postModel.GetFileModel().GetFormat());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }

        postModel.GetFileModel().SetIdFile(query.lastInsertId().toInt());

        query.prepare("INSERT INTO post-file (id_file, id_post) VALUES (?, ?);");

        query.addBindValue(postModel.GetFileModel().GetIdFile());
        query.addBindValue(postModel.GetIdPost());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }
        return true;
    }

    bool AddFileInUser(const UserModel &userModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("INSERT INTO file (name, path, type, format) VALUES (?, ?, ?, ?);");

        query.addBindValue(userModel.GetFileModel().GetName());
        query.addBindValue(userModel.GetFileModel().GetPath());
        query.addBindValue(userModel.GetFileModel().GetType());
        query.addBindValue(userModel.GetFileModel().GetFormat());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }

        userModel.GetFileModel().SetIdFile(query.lastInsertId().toInt());

        query.prepare("INSERT INTO user-file (id_file, id_user) VALUES (?, ?);");

        query.addBindValue(userModel.GetFileModel().GetIdFile());
        query.addBindValue(userModel.GetIdUser());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }
        return true;
    }

    bool DeleteFileInPost(const PostModel &postModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("DELETE FROM file WHERE id_file = :id_file;");
        query.bindValue(":id_file", postModel.GetFileModel().GetIdFile());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }

        query.prepare("DELETE FROM post-file WHERE id_post = :id_post;");
        query.bindValue(":id_post", postModel.GetIdPost());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }
        return true;
    }

    bool DeleteFileInUser(const UserModel &userModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("DELETE FROM file WHERE id_file = :id_file;");
        query.bindValue(":id_file", userModel.GetFileModel().GetIdFile());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }

        query.prepare("DELETE FROM user-file WHERE id_post = :id_user;");
        query.bindValue(":id_user", userModel.GetIdUser());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }
        return true;
    }

    FileModel GetFileInPost(const PostModel &postModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("SELECT f.* FROM file f INNER JOIN post-file pf ON f.id_file = pf.id_file WHERE pf.id_post = :id_post");

        query.bindValue(":id_post", postModel.GetIdPost());

        if (!query.exec())
            qDebug() << query.lastError().text();

        if (query.next())
        {
            fileModel.SetIdFile(query.value(0).toInt());
            fileModel.SetName(query.value(1).toString());
            fileModel.SetPath(query.value(2).toString());
            fileModel.SetType(query.value(3).toString());
            fileModel.SetFormat(query.value(4).toString());
        }
        return fileModel;
    }

    FileModel GetFileInUser(const UserModel &userModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("SELECT f.* FROM file f INNER JOIN user-file pf ON f.id_file = pf.id_file WHERE pf.id_user = :id_user");

        query.bindValue(":id_user", userModel.GetIdUser());

        if (!query.exec())
            qDebug() << query.lastError().text();

        if (query.next())
        {
            fileModel.SetIdFile(query.value(0).toInt());
            fileModel.SetName(query.value(1).toString());
            fileModel.SetPath(query.value(2).toString());
            fileModel.SetType(query.value(3).toString());
            fileModel.SetFormat(query.value(4).toString());
        }
        return fileModel;
    }
};

#endif // DATABASEFILEMANAGER_H
