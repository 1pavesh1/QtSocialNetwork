#ifndef VALIDATIONMANAGER_H
#define VALIDATIONMANAGER_H

#include <QDebug>
#include <QString>
#include "Managers/MessageManager.h"

class ValidationManager
{
public:
    bool LoginIsValidation(const QString &login)                       { return CheckLoginValidation(login);                       }
    bool PasswordIsValidation(const QString &password)                 { return CheckPasswordValidation(password);                 }
    bool PhoneIsValidation(const QString &phone)                       { return CheckPhoneValidation(phone);                       }
    bool DataSize(const QString &tempText)                             { return CheckDataSize(tempText);                           }
private:
    bool CheckLoginValidation(const QString &login)                    // Проверка логина
    {
        for (int i = 0; i < login.size(); ++i)
        {
            if (!((login[i] >= 'A' && login[i] <= 'Z') || (login[i] >= 'a' && login[i] <= 'z')))
            {
                messageManager.LoginIsCorrect();
                return false;
            }
        }
        return true;
    }
    bool CheckPasswordValidation(const QString &password)
    {
        for (int i = 0; i < password.size(); ++i)
        {
            if (!((password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= 'a' && password[i] <= 'z')))
            {
                messageManager.PasswordIsCorrect();
                return false;
            }
        }
        return true;
    }
    bool CheckPhoneValidation(const QString &phone)
    {
        if (phone.size() != 17)
        {
            messageManager.PhoneSize();
            return false;
        }
        return true;
    }
    bool CheckDataSize(const QString &tempText)
    {
        if (tempText.size() < 5)
        {
            messageManager.DataSize();
            return false;
        }
        return true;
    }

    MessageManager messageManager;
};

#endif // VALIDATIONMANAGER_H
