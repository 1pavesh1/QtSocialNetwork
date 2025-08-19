#ifndef USERVECTOR_H
#define USERVECTOR_H

#include <QVector>
#include "Data.h"
#include "Models/UserModel.h"

class UserVector : public Data
{
private:
    QVector <UserModel> userModelVector;

    void serialize(QDataStream &out) const override
    {
        out << userModelVector;
    }

    void deserialize(QDataStream &in) override
    {
        in >> userModelVector;
    }

public:
    QVector <UserModel> GetUserModelVector() const
    {
        return userModelVector;
    }

    void SetUserModelVector(const QVector <UserModel> &userModelVector)
    {
        this->userModelVector = userModelVector;
    }
};

#endif // USERVECTOR_H
