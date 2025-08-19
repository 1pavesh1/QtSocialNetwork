#ifndef MEDIAMANAGER_H
#define MEDIAMANAGER_H

#include <QByteArray>
#include <QDir>
#include <QPainter>
#include "Models/UserModel.h"
#include "Models/PostModel.h"

class MediaManager
{
private:
    QString     filePath;
    QByteArray  mediaData;
    qint64      bytesWritten;

public:
    QPixmap GetHandlerPhoto(const QByteArray &photo, const QSize &sizePhoto)
    {
        QPixmap pixmap;
        pixmap.loadFromData(photo);

        QSize buttonSize = sizePhoto;
        QPixmap scaledPixmap(buttonSize);
        scaledPixmap.fill(Qt::transparent);

        QPainter painter(&scaledPixmap);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setBrush(QBrush(pixmap.scaled(buttonSize, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
        painter.drawEllipse(0, 0, buttonSize.width(), buttonSize.height());
        painter.end();

        return scaledPixmap;
    }

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
            qDebug() << "Файл поста не найден:" << filePath;
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

    bool SaveMediaDataPostOnServer(PostModel &postModel)
    {
        mediaData = postModel.GetMediaData();

        CreateDirectory("MediaDataPosts");

        postModel.SetFilePath(GetFilePath("MediaDataPosts", postModel.GetIdPost()));

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

        userModel.SetPhotoPath(GetFilePath("PhotoUsers", userModel.GetIdUser()));

        QFile file(userModel.GetPhotoPath());
        if (file.open(QIODevice::WriteOnly))
        {
            bytesWritten = file.write(mediaData);
            file.close();
            return true;
        }
        return false;
    }

    void CreateDirectory(const QString &directoryName)
    {
        QDir().mkpath(directoryName);
    }

    QString GetFilePath(QString dirName, qint32 idModel)
    {
        return QString("%1/%2.png").arg(dirName).arg(idModel);
    }
};

#endif // MEDIAMANAGER_H
