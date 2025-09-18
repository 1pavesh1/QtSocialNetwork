#ifndef TIMEUTIL_H
#define TIMEUTIL_H

#include <QDateTime>
#include <QDebug>

class TimeUtil
{
public:
    QString GetDateTime()
    {
        return QDateTime::currentDateTime().toString("HH:mm dd.MM.yyyy");
    }
};

#endif // TIMEUTIL_H
