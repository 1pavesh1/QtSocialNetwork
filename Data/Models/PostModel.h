#ifndef POSTMODEL_H
#define POSTMODEL_H

#include "Data.h"
#include "LikeModel.h"
#include "CommentModel.h"
#include "UserModel.h"
#include "FileModel.h"

class PostModel : public Data
{
private:
    qint32                  idPost;
    qint32                  idUser;
    QString                 textContent;
    QString                 createdDate;
    QString                 name;

    QList <LikeModel>       likesList;
    QList <CommentModel>    commentsList;

    UserModel               userModel;
    FileModel               fileModel;

    void serialize(QDataStream &out) const override
    {
        out << idPost << idUser << textContent
            << createdDate << name
            << likesList << commentsList << userModel << fileModel;
    }

    void deserialize(QDataStream &in) override
    {
        in  >> idPost >> idUser >> textContent
            >> createdDate >> name
            >> likesList >> commentsList >> userModel >> fileModel;
    }

public:
    PostModel() : idPost(0), idUser(0), textContent(""), createdDate(""), name(""),
        likesList(0), commentsList(0), userModel(), fileModel()
    {

    }

    qint32                      GetIdPost()         const           { return idPost;            }
    qint32                      GetIdUser()         const           { return idUser;            }
    QString                     GetTextContent()    const           { return textContent;       }
    QString                     GetCreatedDate()    const           { return createdDate;       }
    QString                     GetName()           const           { return name;              }
    QList <LikeModel>           GetLikesList()      const           { return likesList;         }
    QList <CommentModel>        GetCommentsList()   const           { return commentsList;      }
    UserModel                   GetUserModel()      const           { return userModel;         }
    FileModel                   GetFileModel()      const           { return fileModel;         }

    void SetIdPost(const qint32 &idPost)                                { this->idPost          = idPost;           }
    void SetIdUser(const qint32 &idUser)                                { this->idUser          = idUser;           }
    void SetTextContent(const QString &textContent)                     { this->textContent     = textContent;      }
    void SetCreatedDate(const QString &createdDate)                     { this->createdDate     = createdDate;      }
    void SetName(const QString &name)                                   { this->name            = name;             }
    void SetLikesList(const QList <LikeModel> &likesList)               { this->likesList       = likesList;        }
    void SetCommentsList(const QList <CommentModel> &commentsList)      { this->commentsList    = commentsList;     }
    void SetUserModel(const UserModel &userModel)                       { this->userModel       = userModel;        }
    void SetFileModel(const FileModel &fileModel)                       { this->fileModel       = fileModel;        }
};

#endif // POSTMODEL_H
