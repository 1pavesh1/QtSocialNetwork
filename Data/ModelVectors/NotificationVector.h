#ifndef NOTIFICATIONVECTOR_H
#define NOTIFICATIONVECTOR_H

#include <QVector>
#include "Data.h"
#include "Models/NotificationModel.h"

class NotificationVector : public Data
{
private:
    QVector <NotificationModel> notificationModelVector;

    void serialize(QDataStream &out) const override
    {
        out << notificationModelVector;
    }

    void deserialize(QDataStream &in) override
    {
        in >> notificationModelVector;
    }

public:
    QVector <NotificationModel> GetNotificationModelVector() const
    {
        return notificationModelVector;
    }

    void SetNotificationModelVector(const QVector <NotificationModel> &notificationModelVector)
    {
        this->notificationModelVector = notificationModelVector;
    }
};

#endif // NOTIFICATIONVECTOR_H
