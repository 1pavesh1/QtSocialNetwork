#ifndef COMMENTMODEL_H
#define COMMENTMODEL_H

#include "Data.h"
#include "UserModel.h"

class CommentModel : public Data
{
private:
    qint32      idComment;
    qint32      idPost;
    qint32      idUser;
    QString     textContent;
    QString     createdDate;
    bool        isEdited;

    UserModel   userModel;

    void serialize(QDataStream &out) const override
    {
        out << idComment << idPost << idUser << textContent << createdDate << isEdited << userModel;
    }

    void deserialize(QDataStream &in) override
    {
        in >> idComment >> idPost >> idUser >> textContent >> createdDate >> isEdited >> userModel;
    }
public:
    CommentModel() : idComment(0), idPost(0), idUser(0), textContent(""), createdDate(""), isEdited(false)
    {

    }

    qint32      GetIdComment()      const    { return idComment;    }
    qint32      GetIdUser()         const    { return idUser;       }
    qint32      GetIdPost()         const    { return idPost;       }
    QString     GetTextContent()    const    { return textContent;  }
    QString     GetCreatedDate()    const    { return createdDate;  }
    bool        IsEdited()          const    { return isEdited;     }
    UserModel   GetUserModel()      const    { return userModel;    }

    void SetIdComment(const qint32 &idComment)          { this->idComment   = idComment;    }
    void SetIdPost(const qint32 &idPost)                { this->idPost      = idPost;       }
    void SetIdUser(const qint32 &idUser)                { this->idUser      = idUser;       }
    void SetTextContent(const QString &textContent)     { this->textContent = textContent;  }
    void SetCreatedDate(const QString &createdDate)     { this->createdDate = createdDate;  }
    void SetIsEdited(const bool &isEdited)              { this->isEdited    = isEdited;     }
    void SetUserModel(const UserModel &userModel)       { this->userModel   = userModel;    }
};

#endif // COMMENTMODEL_H
