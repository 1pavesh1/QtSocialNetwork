#ifndef POSTMODEL_H
#define POSTMODEL_H

#include "Data.h"
#include "UserModel.h"
#include "FileModel.h"

class PostModel : public Data
{
private:
    qint32      idPost;
    qint32      idUser;
    QString     textContent;
    QString     createdDate;
    QString     name;

    qint32      countLikes;
    qint32      countComments;

    UserModel   userModel;
    FileModel   fileModel;

    void serialize(QDataStream &out) const override
    {
        out << idPost << idUser << textContent
            << createdDate << name
            << countLikes << countComments << userModel << fileModel;
    }

    void deserialize(QDataStream &in) override
    {
        in  >> idPost >> idUser >> textContent
            >> createdDate >> name
            >> countLikes >> countComments >> userModel >> fileModel;
    }

public:
    PostModel() : idPost(0), idUser(0), textContent(""), createdDate(""), name(""),
        countLikes(0), countComments(0), userModel(), fileModel()
    {

    }

    qint32      GetIdPost()         const           { return idPost;            }
    qint32      GetIdUser()         const           { return idUser;            }
    QString     GetTextContent()    const           { return textContent;       }
    QString     GetCreatedDate()    const           { return createdDate;       }
    QString     GetName()           const           { return name;              }
    qint32      GetCountLikes()     const           { return countLikes;        }
    qint32      GetCountComments()  const           { return countComments;     }
    UserModel   GetUserModel()      const           { return userModel;         }
    FileModel   GetFileModel()      const           { return fileModel;         }

    void SetIdPost(const qint32 &idPost)                        { this->idPost           = idPost;          }
    void SetIdUser(const qint32 &idUser)                        { this->idUser           = idUser;          }
    void SetTextContent(const QString &textContent)             { this->textContent      = textContent;     }
    void SetCreatedDate(const QString &createdDate)             { this->createdDate      = createdDate;     }
    void SetName(const QString &name)                           { this->name             = name;            }
    void SetCountLikes(const qint32 &countLikes)                { this->countLikes       = countLikes;      }
    void SetCountComments(const qint32 &countComments)          { this->countComments    = countComments;   }
    void SetUserModel(const UserModel &userModel)               { this->userModel        = userModel;       }
    void SetFileModel(const FileModel &fileModel)               { this->fileModel        = fileModel;       }
};

#endif // POSTMODEL_H
