#ifndef POSTVECTOR_H
#define POSTVECTOR_H

#include <QVector>
#include "Data.h"
#include "Models/PostModel.h"

class PostVector : public Data
{
private:
    QVector <PostModel> postModelVector;

    void serialize(QDataStream &out) const override
    {
        out << postModelVector;
    }

    void deserialize(QDataStream &in) override
    {
        in >> postModelVector;
    }
public:
    QVector <PostModel> GetPostModelVector() const
    {
        return postModelVector;
    }

    void SetPostModelVector(const QVector <PostModel> &postModelVector)
    {
        this->postModelVector = postModelVector;
    }
};

#endif // POSTVECTOR_H
