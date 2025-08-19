#ifndef DATABASECONNECTMANAGER_H
#define DATABASECONNECTMANAGER_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QString>

class DataBaseConnectManager
{
private:
    const QString   connectStr = "DRIVER={ODBC Driver 17 for SQL Server};SERVER=PAVESH;DATABASE=SocialNetworkDataBase;Trusted_Connection=yes;";
    QSqlDatabase    dataBase;

public:
    DataBaseConnectManager()
    {
        if (ConnectToDataBase())
        {
            qDebug() << "Успешное подключение к DataBaseSocialNetwork";
        }
        else
        {
            qDebug() << "Ошибка подключения к DataBaseSocialNetwork:" << dataBase.lastError().text();
        }
    }

    ~DataBaseConnectManager()
    {
        if (dataBase.isOpen())
        {
            dataBase.close();
        }
    }

    bool ConnectToDataBase()
    {
        dataBase = QSqlDatabase::addDatabase("QODBC");
        dataBase.setDatabaseName(connectStr);
        return dataBase.open();
    }

    QSqlDatabase GetDataBase() const
    {
        return dataBase;
    }
};

#endif // DATABASECONNECTMANAGER_H
