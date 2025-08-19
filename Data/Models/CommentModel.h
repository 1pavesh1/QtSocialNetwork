#ifndef COMMENTMODEL_H
#define COMMENTMODEL_H

#include "Data.h"

class CommentModel : public Data
{
private:
    qint32  idComment;
    qint32  idUser;
    QString textContent;
    QString createdDate;

    void serialize(QDataStream &out) const override
    {
        out << idComment << idUser << textContent << createdDate;
    }

    void deserialize(QDataStream &in) override
    {
        in >> idComment >> idUser >> textContent >> createdDate;
    }
public:
    CommentModel() : idComment(0), idUser(0), textContent(""), createdDate("")
    {

    }

    CommentModel(const qint32 &idComment, const qint32 &idUser, const QString &textContent, const QString &createdDate) :
        idComment(idComment), idUser(idUser), textContent(textContent), createdDate(createdDate)
    {

    }

    qint32  GetIdComment()      const    { return idComment;    }
    qint32  GetIdUser()         const    { return idUser;       }
    QString GetTextContent()    const    { return textContent;  }
    QString GetCreatedDate()    const    { return createdDate;  }

    void SetIdComment(const qint32 &idComment)          { this->idComment   = idComment;    }
    void SetIdUser(const qint32 &idUser)                { this->idUser      = idUser;       }
    void SetTextContent(const QString &textContent)     { this->textContent = textContent;  }
    void SetCreatedDate(const QString &createdDate)     { this->createdDate = createdDate;  }
};

#endif // COMMENTMODEL_H
