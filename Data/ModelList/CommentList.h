#ifndef COMMENTLIST_H
#define COMMENTLIST_H

#include <QList>
#include "Data.h"
#include "Models/CommentModel.h"

class CommentList : public Data
{
private:
    QList <CommentModel> commentList;

    void serialize(QDataStream &out) const override
    {
        out << commentList;
    }

    void deserialize(QDataStream &in) override
    {
        in >> commentList;
    }

public:
    QList <CommentModel> GetCommentList() const
    {
        return commentList;
    }

    void SetCommentList(const QVector <CommentModel> &commentList)
    {
        this->commentList = commentList;
    }
};

#endif // COMMENTLIST_H
