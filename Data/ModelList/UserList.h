#ifndef USERLIST_H
#define USERLIST_H

#include <QList>
#include "Data.h"
#include "Models/UserModel.h"

class UserList : public Data
{
private:
    QList <UserModel> userList;

    void serialize(QDataStream &out) const override
    {
        out << userList;
    }

    void deserialize(QDataStream &in) override
    {
        in >> userList;
    }

public:
    QList <UserModel> GetUserList() const
    {
        return userList;
    }

    void SetUserList(const QVector <UserModel> &userList)
    {
        this->userList = userList;
    }
};

#endif // USERLIST_H
