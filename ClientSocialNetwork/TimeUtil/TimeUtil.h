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
    QString FormatDateForDisplay(const QString &sqlDate)
    {
        if (sqlDate.length() < 16) return sqlDate;

        QString datePart = sqlDate.left(10);
        QString timePart = sqlDate.mid(11, 5);

        return timePart + " " + datePart;
    }
};

#endif // TIMEUTIL_H
