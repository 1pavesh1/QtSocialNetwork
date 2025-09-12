#ifndef FILEREADER_H
#define FILEREADER_H

#include <QByteArray>
#include <QDir>
#include "Models/UserModel.h"
#include "Models/PostModel.h"

class MediaManager
{
private:
    QString     filePath;
    QByteArray  mediaData;
    qint64      bytesWritten;

public:
    QByteArray GetMediaDataPost(const PostModel &postModel)
    {
        filePath = postModel.GetFilePath();

        QFile file(filePath);
        if (!file.exists())
        {
            qDebug() << "Файл поста не найден:" << filePath;
            return QByteArray();
        }

        if (!file.open(QIODevice::ReadOnly))
        {
            qDebug() << "Не удалось открыть файл поста:" << file.errorString();
            return QByteArray();
        }

        mediaData = file.readAll();
        file.close();

        return mediaData;
    }

    QByteArray GetPhotoUser(const UserModel &userModel)
    {
        filePath = userModel.GetPhotoPath();

        QFile file(filePath);
        if (!file.exists())
        {
            qDebug() << "Фото пользователя не найдено:" << filePath;
            return QByteArray();
        }

        if (!file.open(QIODevice::ReadOnly))
        {
            qDebug() << "Не удалось открыть фото:" << file.errorString();
            return QByteArray();
        }

        mediaData = file.readAll();
        file.close();

        return mediaData;
    }
};

#endif // FILEREADER_H
