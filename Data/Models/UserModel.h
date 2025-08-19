#ifndef USERMODEL_H
#define USERMODEL_H

#include "Data.h"

class UserModel : public Data
{
private:
    qint32      idUser;
    QString     login;
    QString     password;
    QString     phone;
    QString     email;
    QString     dateBithday;
    QString     entryTime;
    QString     photoPath;

    QByteArray  photo;
    qint32      countFriends;
    qint32      countNotifications;
    bool        isOnline;

    void serialize(QDataStream &out) const override
    {
        out << idUser << login << password << phone << email
            << dateBithday << entryTime << photoPath << photo
            << countFriends << countNotifications << isOnline;
    }

    void deserialize(QDataStream &in) override
    {
        in >> idUser >> login >> password >> phone >> email
            >> dateBithday >> entryTime >> photoPath >> photo
            >> countFriends >> countNotifications >> isOnline;
    }

public:
    UserModel() : idUser(0), login(""), password(""), phone(""), email(""),
        dateBithday(""), entryTime(""), photoPath(""), photo(NULL),
        countFriends(0), countNotifications(0), isOnline(false)
    {

    }

    UserModel(const qint32 &idUser, const QString &login, const QString &password, const QString &phone, const QString &email,
              const QString &dateBithday, const QString &entryTime,
              const QString &photoPath, const QByteArray &photo, const qint32 &countFriends,
              const qint32 &countNotifications, const bool &isOnline) :
        idUser(idUser), login(login), password(password), phone(phone), email(email),
        dateBithday(dateBithday), entryTime(entryTime), photoPath(photoPath), photo(photo),
        countFriends(countFriends), countNotifications(countNotifications), isOnline(isOnline)
    {

    }

    qint32      GetIdUser()              const   { return idUser;               }
    QString     GetLogin()               const   { return login;                }
    QString     GetPassword()            const   { return password;             }
    QString     GetPhone()               const   { return phone;                }
    QString     GetEmail()               const   { return email;                }
    QString     GetDateBithday()         const   { return dateBithday;          }
    QString     GetEntryTime()           const   { return entryTime;            }
    QString     GetPhotoPath()           const   { return photoPath;            }
    QByteArray  GetPhoto()               const   { return photo;                }
    qint32      GetCountFriends()        const   { return countFriends;         }
    qint32      GetCountNotifications()  const   { return countNotifications;   }
    bool        GetStatusOnline()        const   { return isOnline;             }

    void SetIdUser(const qint32 &idUser)                            { this->idUser              = idUser;               }
    void SetLogin(const QString &login)                             { this->login               = login;                }
    void SetPassword(const QString &password)                       { this->password            = password;             }
    void SetPhone(const QString &phone)                             { this->phone               = phone;                }
    void SetEmail(const QString &email)                             { this->email               = email;                }
    void SetDateBithday(const QString &dateBithday)                 { this->dateBithday         = dateBithday;          }
    void SetEntryTime(const QString &entryTime)                     { this->entryTime           = entryTime;            }
    void SetPhotoPath(const QString &photoPath)                     { this->photoPath           = photoPath;            }
    void SetPhoto(const QByteArray &photo)                          { this->photo               = photo;                }
    void SetCountFriends(const qint32 &countFriends)                { this->countFriends        = countFriends;         }
    void SetCountNotifications(const qint32 &countNotifications)    { this->countNotifications  = countNotifications;   }
    void SetStatus(const bool &isOnline)                            { this->isOnline            = isOnline;             }
};

#endif // USERMODEL_H
