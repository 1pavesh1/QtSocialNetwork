#ifndef POSTMODEL_H
#define POSTMODEL_H

#include "Data.h"
#include "Models/UserModel.h"

class PostModel : public Data
{
private:
    qint32  idPost;
    qint32  idUser;
    QString name;
    QString textContent;
    QString createdDate;
    QString filePath;
    QString fileType;
    QString fileName;

    QByteArray mediaData;
    qint32  countLikes;
    qint32  countComments;

    UserModel userModel;

    void serialize(QDataStream &out) const override
    {
        out << idPost << idUser << name
            << textContent << createdDate << mediaData
            << countLikes << countComments << filePath << fileType << fileName << userModel;
    }

    void deserialize(QDataStream &in) override
    {
        in >> idPost >> idUser >> name
            >> textContent >> createdDate >> mediaData
            >> countLikes >> countComments >> filePath >> fileType >> fileName >> userModel;

    }

public:
    PostModel() : idPost(0), idUser(0), name(""), textContent(""), createdDate(""),
        mediaData(0), countLikes(0), countComments(0), filePath(""), fileType(""), fileName(""), userModel()
    {

    }

    PostModel(const qint32 &idPost, const qint32 &idUser, const QString &name, const QString &textContent,
              const QString &createdDate, const QByteArray &mediaData, const qint32 &countLikes, const qint32 &countComments,
              const QString &filePath, const QString &fileType, const QString &fileName, const UserModel &userModel) :
        idPost(idPost), idUser(idUser), name(name), textContent(textContent), createdDate(createdDate),
        mediaData(mediaData), countLikes(countLikes), countComments(countComments),
        filePath(filePath), fileType(fileType), fileName(fileName), userModel(userModel)
    {

    }

    qint32      GetIdPost()         const    { return idPost;        }
    qint32      GetIdUser()         const    { return idUser;        }
    QString     GetName()           const    { return name;          }
    QString     GetTextContent()    const    { return textContent;   }
    QString     GetCreatedDate()    const    { return createdDate;   }
    QString     GetFilePath()       const    { return filePath;      }
    QString     GetFileType()       const    { return fileType;      }
    QString     GetFileName()       const    { return fileName;      }
    QByteArray  GetMediaData()      const    { return mediaData;     }
    qint32      GetCountLikes()     const    { return countLikes;    }
    qint32      GetCountComments()  const    { return countComments; }
    UserModel   GetUserModel()      const    { return userModel;     }

    void SetIdPost(const qint32 &idPost)               { this->idPost           = idPost;          }
    void SetIdUser(const qint32 &idUser)               { this->idUser           = idUser;          }
    void SetName(const QString &name)                  { this->name             = name;            }
    void SetTextContent(const QString &textContent)    { this->textContent      = textContent;     }
    void SetCreatedDate(const QString &createdDate)    { this->createdDate      = createdDate;     }
    void SetFilePath(const QString &filePath)          { this->filePath         = filePath;        }
    void SetFileType(const QString &fileType)          { this->fileType         = fileType;        }
    void SetFileName(const QString &fileName)          { this->fileName         = fileName;        }
    void SetMediaData(const QByteArray &mediaData)     { this->mediaData        = mediaData;       }
    void SetCountLikes(const qint32 &countLikes)       { this->countLikes       = countLikes;      }
    void SetCountComments(const qint32 &countComments) { this->countComments    = countComments;   }
    void SetUserModel(const UserModel &userModel)      { this->userModel        = userModel;       }
};

#endif // POSTMODEL_H
