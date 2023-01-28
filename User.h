#ifndef USER_H
#define USER_H
#include<QString>


class User
{
public:
    User();
    int getUserId();
    QString getName();
    QString getPassword();
    void setName(QString name);
    void setPassword(QString password);
private:
    int idUser;
    QString name;
    QString password;
};

#endif // USER_H
