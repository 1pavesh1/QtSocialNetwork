#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <QByteArray>
#include <QDir>
#include "DirectoryHelper.h"
#include "FileModel.h"

class FileWriter
{
private:
    DirectoryHelper dirHelper;

public:
    bool SaveFileOnServer(const FileModel &fileModel)
    {
        dirHelper.CreateDirectory(fileModel.GetDirectoryName());

        QFile file(fileModel.GetPath());
        if (file.open(QIODevice::WriteOnly))
        {
            file.write(fileModel.GetFileData());
            file.close();
            return true;
        }
        return false;
    }

    bool DeleteFile(const FileModel &fileModel)
    {
        QFile file(fileModel.GetPath());
        if (file.exists())
        {
            if (file.remove())
            {
                qDebug() << "Файл удален: " << fileModel.GetName();
                return true;
            }
            else
            {
                qDebug() << "Ошибка удаления файла: " << file.errorString();
                return false;
            }
        }
        else
        {
            qDebug() << "Файл для удаления не найден: " << fileModel.GetName();
            return false;
        }
    }
};

#endif // FILEWRITER_H
