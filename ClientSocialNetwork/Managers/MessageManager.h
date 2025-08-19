#ifndef MESSAGEMANAGER_H
#define MESSAGEMANAGER_H

#include <QDebug>
#include <QString>
#include <QMessageBox>

class MessageManager
{
public:
    // Логин
    void LoginIsCorrect()
    {
        message.information(0, "Логин неправильный", "Логин должен состоять из английских символов !");
    }
    // Пароль
    void PasswordIsCorrect()
    {
        message.information(0, "Пароль неправильный", "Пароль должен состоять из английских символов !");
    }
    // Телефонный номер
    void PhoneSize()
    {
        message.information(0, "Номер телефона", "Поле номер телефона не заполнено !");
    }
    // Регистрация
    void RegUserLoginRepeat()
    {
        message.critical(0, "Регистрация", "Пользователь с таким логином уже существует !");
    }
    void RegFailed()
    {
        message.critical(0, "Регистрация", "Ошибка регистрации !");
    }
    // Авторизация
    void AuthUserOnServer()
    {
        message.critical(0, "Авторизация", "Такой пользователь уже авторизован !");
    }
    void AuthFailed()
    {
        message.critical(0, "Авторизация", "Неверно введены данные !");
    }
    // Обновление данных
    void UpdateData()
    {
        message.information(0, "Обновление данных", "Данные успешно обновлены !");
    }
    void UpdateDataFailed()
    {
        message.critical(0, "Обновление данных", "Данные не были обновлены !");
    }
    void UpdateDataNameFailed()
    {
        message.critical(0, "Обновление данных", "Такой логин уже зарезервирован !");
    }
    void UpdatePhoto()
    {
        message.information(0, "Обновление фото", "Фотография изменена !");
    }
    void UpdatePhotoFailed()
    {
        message.critical(0, "Обновление фото", "Ошибка при изменении фотографии !");
    }
    // Остальное
    void DataSize()
    {
        message.information(0, "Размер логина и пароля", "Размер пароля и логина не должен быть меньше 5 символов !");
    }
    void LineIsClear()
    {
        message.warning(0, "Пустые поля", "Поля данных не заполнены !");
    }
    void FileFailed()
    {
        message.critical(0, "Ошибка загрузки", "Файл не был загружен !");
    }
    void GetDataFailed()
    {
        message.critical(0, "Получение данных", "Не получилось доставить данные !");
    }
private:
    QMessageBox message;
};

#endif // MESSAGEMANAGER_H
