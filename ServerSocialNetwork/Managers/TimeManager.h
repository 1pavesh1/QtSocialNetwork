#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <QDateTime>
#include <QDebug>

class TimeManager
{
public:
    QString GetDateTime()
    {
        return QDateTime::currentDateTime().toString("HH:mm dd.MM.yyyy");
    }
};

#endif // TIMEMANAGER_H
