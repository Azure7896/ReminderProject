#include "user.h"

User::User()
{

}

int User::getUserId() {
      return this->idUser;
    }

QString User::getName() {
      return this->name;
    }

QString User::getPassword() {
      return this->password;
}

void User::setName(QString name) {
    this->name = name;
}

void User::setPassword(QString password) {
    this->password = password;
}




