#ifndef PATHUTIL_H
#define PATHUTIL_H

#include <QString>
#include "FileModel.h"

class PathUtil
{
public:
    QString GetFilePath(const FileModel &fileModel)
    {
        return QString("%1/%2.%3").arg(fileModel.GetDirectoryName()).arg(fileModel.GetName()).arg(fileModel.GetFormat());
    }
};

#endif // PATHUTIL_H
