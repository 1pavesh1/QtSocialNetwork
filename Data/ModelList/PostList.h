#ifndef POSTLIST_H
#define POSTLIST_H

#include <QList>
#include "Data.h"
#include "Models/PostModel.h"

class PostList : public Data
{
private:
    QList <PostModel> postList;

    void serialize(QDataStream &out) const override
    {
        out << postList;
    }

    void deserialize(QDataStream &in) override
    {
        in >> postList;
    }

public:
    QList <PostModel> GetPostList() const
    {
        return postList;
    }

    void SetPostList(const QVector <PostModel> &postList)
    {
        this->postList = postList;
    }
};

#endif // POSTLIST_H
