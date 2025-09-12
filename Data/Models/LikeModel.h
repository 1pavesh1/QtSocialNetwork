#ifndef LIKEMODEL_H
#define LIKEMODEL_H

#include "Data.h"

class LikeModel : public Data
{
private:
    qint32  idLike;
    qint32  idUser;
    qint32  idPost;

    void serialize(QDataStream &out) const override
    {
        out << idLike << idUser << idPost;
    }

    void deserialize(QDataStream &in) override
    {
        in >> idLike >> idUser >> idPost;
    }

public:
    LikeModel() : idLike(0), idUser(0), idPost(0)
    {

    }

    qint32    GetIdLike()       const { return idLike; }
    qint32    GetIdUser()       const { return idUser; }
    qint32    GetIdPost()       const { return idPost; }

    void SetIdLike(const qint32 &idLike)  { this->idLike  = idLike; }
    void SetIdUser(const qint32 &idUser)  { this->idUser  = idUser; }
    void SetIdPost(const qint32 &idPost)  { this->idPost  = idPost; }
};

#endif // LIKEMODEL_H
