#ifndef VALIDATIONMANAGER_H
#define VALIDATIONMANAGER_H

#include <QDebug>
#include <QString>

class ValidationManager
{
public:
    bool LoginIsValidation(const QString &login)                       { return CheckLoginValidation(login);                       }
    bool PasswordIsValidation(const QString &password)                 { return CheckPasswordValidation(password);                 }
    bool PhoneIsValidation(const QString &phone)                       { return CheckPhoneValidation(phone);                       }
    bool DataSize(const QString &tempText)                             { return CheckDataSize(tempText);                           }
    bool EmailIsValidation(const QString &email)                       { return CheckEmailValidation(email);                       }

private:
    bool CheckLoginValidation(const QString &login)
    {
        for (int i = 0; i < login.size(); ++i)
        {
            if (!((login[i] >= 'A' && login[i] <= 'Z') || (login[i] >= 'a' && login[i] <= 'z')))
                return false;
        }
        return true;
    }

    bool CheckPasswordValidation(const QString &password)
    {
        for (int i = 0; i < password.size(); ++i)
        {
            if (!((password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= 'a' && password[i] <= 'z')))
                return false;
        }
        return true;
    }

    bool CheckPhoneValidation(const QString &phone)
    {
        if (phone.size() != 17)
            return false;
        else
            return true;
    }

    bool CheckDataSize(const QString &tempText)
    {
        if (tempText.size() < 5)
            return false;
        else
            return true;
    }

    bool CheckEmailValidation(const QString &email)
    {
        if (!email.isEmpty() && email.count('@') != 1)
            return false;
        else
            return true;
    }
};

#endif // VALIDATIONMANAGER_H
