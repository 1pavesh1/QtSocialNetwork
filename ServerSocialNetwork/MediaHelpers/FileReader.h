#ifndef FILEREADER_H
#define FILEREADER_H

#include <QByteArray>
#include <QDir>
#include "FileModel.h"

class FileReader
{
private:
    QByteArray fileData;

public:
    QByteArray GetFileData(const FileModel &fileModel)
    {
        QFile file(fileModel.GetPath());
        if (!file.exists())
        {
            qDebug() << "Файл не найден:" << fileModel.GetName();
            return QByteArray();
        }

        if (!file.open(QIODevice::ReadOnly))
        {
            qDebug() << "Не удалось открыть файл:" << file.errorString();
            return QByteArray();
        }

        fileData = file.readAll();
        file.close();

        return fileData;
    }
};

#endif // FILEREADER_H
