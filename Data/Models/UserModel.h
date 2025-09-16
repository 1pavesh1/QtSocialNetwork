#ifndef USERMODEL_H
#define USERMODEL_H

#include "Data.h"
#include "FileModel.h"

class UserModel : public Data
{
private:
    qint32      idUser;
    QString     login;
    QString     password;
    QString     phone;
    QString     email;
    QString     entryTime;
    QString     dateBithday;

    qint32      countFriends;
    qint32      countNotifications;
    bool        isOnline;
    FileModel   fileModel;

    void serialize(QDataStream &out) const override
    {
        out << idUser << login << password << phone << email
            << entryTime << dateBithday
            << countFriends << countNotifications << isOnline << fileModel;
    }

    void deserialize(QDataStream &in) override
    {
        in  >> idUser >> login >> password >> phone >> email
            >> entryTime >> dateBithday
            >> countFriends >> countNotifications >> isOnline >> fileModel;
    }

public:
    UserModel() : idUser(0), login(""), password(""), phone(""), email(""),
        entryTime(""), dateBithday(""),
        countFriends(0), countNotifications(0), isOnline(false), fileModel()
    {

    }

    qint32      GetIdUser()              const              { return idUser;               }
    QString     GetLogin()               const              { return login;                }
    QString     GetPassword()            const              { return password;             }
    QString     GetPhone()               const              { return phone;                }
    QString     GetEmail()               const              { return email;                }
    QString     GetEntryTime()           const              { return entryTime;            }
    QString     GetDateBithday()         const              { return dateBithday;          }
    qint32      GetCountFriends()        const              { return countFriends;         }
    qint32      GetCountNotifications()  const              { return countNotifications;   }
    bool        GetStatusOnline()        const              { return isOnline;             }
    FileModel   GetFileModel()           const              { return fileModel;            }

    void SetIdUser(const qint32 &idUser)                                    { this->idUser              = idUser;               }
    void SetLogin(const QString &login)                                     { this->login               = login;                }
    void SetPassword(const QString &password)                               { this->password            = password;             }
    void SetPhone(const QString &phone)                                     { this->phone               = phone;                }
    void SetEmail(const QString &email)                                     { this->email               = email;                }
    void SetEntryTime(const QString &entryTime)                             { this->entryTime           = entryTime;            }
    void SetDateBithday(const QString &dateBithday)                         { this->dateBithday         = dateBithday;          }
    void SetCountFriends(const qint32 &countFriends)                        { this->countFriends        = countFriends;         }
    void SetCountNotifications(const qint32 &countNotifications)            { this->countNotifications  = countNotifications;   }
    void SetStatus(const bool &isOnline)                                    { this->isOnline            = isOnline;             }
    void SetFileModel(const FileModel &fileModel)                           { this->fileModel           = fileModel;            }
};

#endif // USERMODEL_H
