#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H
#include <QString>


class Encryptor
{
public:
    Encryptor();
    QString encryptPassword(QString password);
private:
    QString encryptedPassword;
};

#endif // ENCRYPTOR_H
