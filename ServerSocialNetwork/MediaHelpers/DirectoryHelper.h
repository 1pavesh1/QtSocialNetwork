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
};

#endif // DIRECTORYHELPER_H
