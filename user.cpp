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
