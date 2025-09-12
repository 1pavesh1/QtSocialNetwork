#ifndef DIRECTORYHELPER_H
#define DIRECTORYHELPER_H

#include <QString>
#include <QDir>
#include "FileModel.h"

class DirectoryHelper
{
public:
    void CreateDirectory(const QString &directoryName)
    {
        QDir().mkpath(directoryName);
    }

    QString GetFilePath(const FileModel &fileModel)
    {
        return QString("%1/%2.%3").arg(fileModel.GetDirectoryName()).arg(fileModel.GetName()).arg(fileModel.GetFormat());
    }
};

#endif // DIRECTORYHELPER_H
