#ifndef FILEMODEL_H
#define FILEMODEL_H

#include <QBuffer>
#include "Data.h"

class FileModel : public Data
{
private:
    qint32      idFile;
    QString     directoryName;
    QString     name;
    QString     path;
    QString     type;
    QString     format;

    QByteArray  fileData;

    void serialize(QDataStream &out) const override
    {
        out << idFile << directoryName << name << path << type << format << fileData;
    }

    void deserialize(QDataStream &in) override
    {
        in >> idFile >> directoryName >> name >> path >> type >> format >> fileData;
    }
public:
    FileModel() : idFile(0), directoryName(""), name(""), path(""), type(""), format(""), fileData(0)
    {

    }

    qint32      GetIdFile()         const    { return idFile;           }
    QString     GetDirectoryName()  const    { return directoryName;    }
    QString     GetName()           const    { return name;             }
    QString     GetPath()           const    { return path;             }
    QString     GetType()           const    { return type;             }
    QString     GetFormat()         const    { return format;           }
    QByteArray  GetFileData()       const    { return fileData;         }

    void SetIdFile(const qint32 &idFile)                { this->idFile          = idFile;        }
    void SetDirectoryName(const QString &directoryName) { this->directoryName   = directoryName; }
    void SetName(const QString &name)                   { this->name            = name;          }
    void SetPath(const QString &path)                   { this->path            = path;          }
    void SetType(const QString &type)                   { this->type            = type;          }
    void SetFormat(const QString &format)               { this->format          = format;        }
    void SetFileData(const QByteArray &fileData)        { this->fileData        = fileData;      }
};

#endif // FILEMODEL_H
