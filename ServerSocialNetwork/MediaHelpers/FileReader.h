#ifndef FILEREADER_H
#define FILEREADER_H

#include <QByteArray>
#include <QDir>

class FileReader
{
private:
    QByteArray fileData;

public:
    QByteArray GetFileData(const QString &filePath)
    {
        QFile file(filePath);
        if (!file.exists())
        {
            qDebug() << "Файл не найден";
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
