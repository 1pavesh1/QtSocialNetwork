#ifndef NOTIFICATIONMODEL_H
#define NOTIFICATIONMODEL_H

#include "Data.h"
#include "UserModel.h"

class NotificationModel : public Data
{
private:
    qint32  idNotification;
    qint32  idUserSender;
    qint32  idUserAccepter;
    QString query;
    QString dateSending;

    UserModel userModel;

    void serialize(QDataStream &out) const override
    {
        out << idNotification << idUserSender
            << idUserAccepter << query << dateSending << userModel;
    }

    void deserialize(QDataStream &in) override
    {
        in >> idNotification >> idUserSender
            >> idUserAccepter >> query >> dateSending >> userModel;
    }

public:
    NotificationModel() : idNotification(0), idUserSender(0), idUserAccepter(0),
        query(""), dateSending("")
    {

    }

    qint32    GetIdNotification()     const { return idNotification;  }
    qint32    GetIdUserSender()       const { return idUserSender;    }
    qint32    GetIdUserAccepter()     const { return idUserAccepter;  }
    QString   GetQuery()              const { return query;           }
    QString   GetDateSending()        const { return dateSending;     }
    UserModel GetUserModel()          const { return userModel;       }

    void SetIdNotification(const qint32 &idNotification)    { this->idNotification  = idNotification;   }
    void SetIdUserSender(const qint32 &idUserSender)        { this->idUserSender    = idUserSender;     }
    void SetIdUserAccepter(const qint32 &idUserAccepter)    { this->idUserAccepter  = idUserAccepter;   }
    void SetQuery(const QString &query)                     { this->query           = query;            }
    void SetDateSending(const QString &dateSending)         { this->dateSending     = dateSending;      }
    void SetUserModel(const UserModel &userModel)           { this->userModel       = userModel;        }
};

#endif // NOTIFICATIONMODEL_H
