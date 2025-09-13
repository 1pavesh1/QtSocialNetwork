#ifndef DAOINTERFACE_H
#define DAOINTERFACE_H

#include <QList>
#include <QString>
#include <QByteArray>
#include <QSqlQuery>
#include <QSqlError>
#include "CommentModel.h"
#include "FileModel.h"
#include "LikeModel.h"
#include "NotificationModel.h"
#include "PostModel.h"
#include "UserModel.h"
#include "Utils/TimeUtil.h"

class DAOInterface
{
public:
    virtual bool AddItem(const Data &data, const QSqlDatabase &dataBase);
    virtual bool UpdateItem(const Data &data, const QSqlDatabase &dataBase);
    virtual bool DeleteItem(const Data &data, const QSqlDatabase &dataBase);
    virtual bool GetItemInId(const qint32 &idModel, const QSqlDatabase &dataBase);
    virtual Data GetItem(const Data &data, const QSqlDatabase &dataBase);
};

#endif // DAOINTERFACE_H
