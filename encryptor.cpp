#include "encryptor.h"
#include <QString>
#include <QCryptographicHash>

Encryptor::Encryptor()
{

}

QString Encryptor::encryptPassword(QString password) {
    QByteArray bytes = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5);
    return encryptedPassword = QString(bytes.toHex());
}
