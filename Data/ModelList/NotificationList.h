#ifndef NOTIFICATIONLIST_H
#define NOTIFICATIONLIST_H

#include <QList>
#include "Data.h"
#include "Models/NotificationModel.h"

class NotificationList : public Data
{
private:
    QList <NotificationModel> notificationList;

    void serialize(QDataStream &out) const override
    {
        out << notificationList;
    }

    void deserialize(QDataStream &in) override
    {
        in >> notificationList;
    }

public:
    QList <NotificationModel> GetNotificationList() const
    {
        return notificationList;
    }

    void SetNotificationList(const QVector <NotificationModel> &notificationList)
    {
        this->notificationList = notificationList;
    }
};

#endif // NOTIFICATIONLIST_H
