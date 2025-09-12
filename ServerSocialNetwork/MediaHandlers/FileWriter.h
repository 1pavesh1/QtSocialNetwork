#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <QByteArray>
#include <QDir>
#include "Data.h"
#include "UserModel.h"
#include "PostModel.h"

class FileWriter
{
private:
    QString     filePath;
    QByteArray  fileData;
    qint64      bytesWritten;

public:
    bool SaveFileOnServer(Data &dataSave)
    {

    }

    bool SaveMediaDataPostOnServer(PostModel &postModel)
    {
        mediaData = postModel.GetMediaData();

        CreateDirectory("MediaDataPosts");

        postModel.SetFilePath(GetFilePath("MediaDataPosts", postModel.GetName(), postModel.GetFileType()));

        QFile file(postModel.GetFilePath());
        if (file.open(QIODevice::WriteOnly))
        {
            bytesWritten = file.write(mediaData);
            file.close();
            return true;
        }
        return false;
    }

    bool SavePhotoUserOnServer(UserModel &userModel)
    {
        mediaData = userModel.GetPhoto();

        CreateDirectory("PhotoUsers");

        userModel.SetPhotoPath(GetFilePath("PhotoUsers", userModel.GetLogin(), "png"));

        QFile file(userModel.GetPhotoPath());
        if (file.open(QIODevice::WriteOnly))
        {
            bytesWritten = file.write(mediaData);
            file.close();
            return true;
        }
        return false;
    }

    bool DeleteFile(const QString &filePath)
    {
        QFile file(filePath);
        if (file.exists()) {
            if (file.remove()) {
                qDebug() << "Файл удален:" << filePath;
                return true;
            } else {
                qDebug() << "Ошибка удаления файла:" << file.errorString();
                return false;
            }
        } else {
            qDebug() << "Файл для удаления не найден:" << filePath;
            return false;
        }
    }

    void CreateDirectory(const QString &directoryName)
    {
        QDir().mkpath(directoryName);
    }

    QString GetFilePath(const QString dirName, const QString nameModel, const QString fileFormat)
    {
        return QString("%1/%2.%3").arg(dirName).arg(nameModel).arg(fileFormat);
    }
};

#endif // FILEWRITER_H
