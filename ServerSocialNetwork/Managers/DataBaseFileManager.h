#ifndef DATABASEFILEMANAGER_H
#define DATABASEFILEMANAGER_H

#include <QSqlQuery>
#include <QSqlError>
#include "MediaHelpers/FileReader.h"
#include "PostModel.h"
#include "UserModel.h"
#include "FileModel.h"

class DataBaseFileManager
{
private:
    FileReader  fileReader;
    FileModel   fileModel;
    qint32      idFile;

public:
    bool AddFileInPost(const PostModel &postModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("INSERT INTO [file] (name, path, type, format) VALUES (?, ?, ?, ?);");

        query.addBindValue(postModel.GetFileModel().GetName());
        query.addBindValue(postModel.GetFileModel().GetPath());
        query.addBindValue(postModel.GetFileModel().GetType());
        query.addBindValue(postModel.GetFileModel().GetFormat());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }

        query.prepare("SELECT * FROM [file] WHERE path = :path");

        query.bindValue(":path", postModel.GetFileModel().GetPath());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }
        if (query.next())
        {
            idFile = query.value(0).toInt();
        }

        query.prepare("INSERT INTO [post_file] (id_file, id_post) VALUES (?, ?);");
        query.addBindValue(idFile);
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

        query.prepare("INSERT INTO [file] (name, path, type, format) VALUES (?, ?, ?, ?);");

        query.addBindValue(userModel.GetFileModel().GetName());
        query.addBindValue(userModel.GetFileModel().GetPath());
        query.addBindValue(userModel.GetFileModel().GetType());
        query.addBindValue(userModel.GetFileModel().GetFormat());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }

        query.prepare("SELECT * FROM [file] WHERE path = :path");

        query.bindValue(":path", userModel.GetFileModel().GetPath());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }
        if (query.next())
        {
            idFile = query.value(0).toInt();
        }

        query.prepare("INSERT INTO [user_file] (id_file, id_user) VALUES (?, ?);");
        query.addBindValue(idFile);
        query.addBindValue(userModel.GetIdUser());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }
        return true;
    }

    bool UpdateFilePathInPost(const PostModel &postModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("UPDATE [file] SET path = ? WHERE id_file = ?;");

        query.addBindValue(postModel.GetFileModel().GetPath());
        query.addBindValue(postModel.GetFileModel().GetIdFile());

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

        query.prepare("DELETE FROM [post_file] WHERE id_post = :id_post AND id_file = :id_file;");
        query.bindValue(":id_post", postModel.GetIdPost());
        query.bindValue(":id_file", postModel.GetFileModel().GetIdFile());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }

        query.prepare("DELETE FROM [file] WHERE id_file = :id_file;");
        query.bindValue(":id_file", postModel.GetFileModel().GetIdFile());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }

        return true;
    }

    bool CheckFileRecordInPost(const PostModel &postModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("SELECT * FROM [file] WHERE path = :path");

        query.bindValue(":path", postModel.GetFileModel().GetPath());

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
            return false;
        }
        return true;
    }

    bool CheckFileRecordInUser(const UserModel &userModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("SELECT * FROM [file] WHERE path = :path");

        query.bindValue(":path", userModel.GetFileModel().GetPath());

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

        query.prepare("SELECT f.* FROM [file] f INNER JOIN [post_file] pf ON f.id_file = pf.id_file WHERE pf.id_post = :id_post");

        query.bindValue(":id_post", postModel.GetIdPost());

        if (!query.exec())
            qDebug() << query.lastError().text();

        FileModel fileModel;

        if (query.next())
        {
            fileModel.SetIdFile(query.value(0).toInt());
            fileModel.SetName(query.value(1).toString());
            fileModel.SetPath(query.value(2).toString());
            fileModel.SetType(query.value(3).toString());
            fileModel.SetFormat(query.value(4).toString());
            fileModel.SetFileData(fileReader.GetFileData(fileModel.GetPath()));
        }

        return fileModel;
    }

    FileModel GetFileInUser(const UserModel &userModel, const QSqlDatabase &dataBase)
    {
        QSqlQuery query(dataBase);

        query.prepare("SELECT f.* FROM [file] f INNER JOIN [user_file] pf ON f.id_file = pf.id_file WHERE pf.id_user = :id_user");

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
            fileModel.SetFileData(fileReader.GetFileData(fileModel.GetPath()));
        }
        return fileModel;
    }
};

#endif // DATABASEFILEMANAGER_H
