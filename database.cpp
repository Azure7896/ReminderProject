#include "database.h"

#include "user.h"


DataBase::DataBase() {}

bool DataBase::createConnection() {
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("C:/Users/Azure/Desktop/Reminder/reminderdatabase.sqlite");
  return db.open();
}

bool DataBase::login(User user) {
  QSqlQuery query;
  query.prepare("SELECT username, password FROM Users WHERE username= ? AND password = ?");
  query.addBindValue(user.getName());
  query.addBindValue(encryptor.encryptPassword(user.getPassword()));
  query.exec();
  return query.first();
}

bool DataBase::isRegistered(User user) {
    QSqlQuery query;
    query.prepare("SELECT username FROM Users WHERE username= ?");
    query.addBindValue(user.getName());
    query.exec();
    return query.first();
}

void DataBase::updateActiveUser(int userId) {
  QSqlQuery query;
  query.prepare("UPDATE ActiveUser SET user_id = ? WHERE id = 1");
  query.addBindValue(userId);
  query.exec();
}

int DataBase::getActiveUserId() {
    int id = 0;
     QSqlQuery query;
     query.prepare("SELECT user_id FROM ActiveUser WHERE id = 1");
     query.exec();
     while (query.next()) {
       id = query.value(0).toInt();
     }
     return id;
}

int DataBase::getUserId(User user) {
    int id = 0;
     QSqlQuery query;
     query.prepare("SELECT user_id FROM Users WHERE username = ?");
     query.addBindValue(user.getName());
     query.exec();
     while (query.next()) {
       id = query.value(0).toInt();
     }
     return id;
}

void DataBase::registerAccount(User user) {
  QSqlQuery query;
  query.prepare("INSERT INTO Users (username, password) "
    "VALUES (?, ?);");
  query.addBindValue(user.getName());
  query.addBindValue(encryptor.encryptPassword(user.getPassword()));
  query.exec();
}

QSqlQuery DataBase::loadFromDatabase() {
  QSqlQuery query;
  query.prepare("SELECT Name, Date, Priority, Time FROM UserEntries WHERE user_id = ?");
  query.addBindValue(getActiveUserId());
  query.exec();
  return query;
}

QSqlQuery DataBase::loadFromDatabaseByDesc() {
  QSqlQuery query;
  query.prepare("SELECT Name, Date, Priority, Time FROM UserEntries WHERE user_id = ? ORDER BY Name desc");
  query.addBindValue(getActiveUserId());
  query.exec();
  return query;
}

QSqlQuery DataBase::loadFromDatabaseByAscend() {
  QSqlQuery query;
  query.prepare("SELECT Name, Date, Priority, Time FROM UserEntries WHERE user_id = ? ORDER BY Name");
  query.addBindValue(getActiveUserId());
  query.exec();
  return query;
}

QSqlQuery DataBase::loadFromDatabaseByItem(QString item) {
  QSqlQuery query;
  query.prepare("SELECT Name, Date, Priority, Time FROM UserEntries WHERE user_id = ? AND"
                " name LIKE ? ");
  query.addBindValue(getActiveUserId());
  query.addBindValue("%%" + item + "%");
  query.exec();
  return query;
}

QSqlQuery DataBase::loadFromDatabaseByPriority() {
  QSqlQuery query;
  query.prepare("SELECT Name, Date, Priority, Time FROM UserEntries WHERE user_id = ? ORDER BY Priority desc");
  query.addBindValue(getActiveUserId());
  query.exec();
  return query;
}

int DataBase::returnQueriesCount() {

  QSqlQuery query("SELECT id FROM UserEntries ORDER BY id DESC LIMIT 1;");
  query.next();
  int queriesCount = query.value(0).toInt();
  return queriesCount;
}

void DataBase::queriesCountToOne() {
  queriesCount = 1;
}

void DataBase::addToDatabase(QString nameVar, QString dateVar, QString time, bool checkboxVar, bool withActualDate) {
  if (withActualDate) {
    dateVar = date.createDate();
  }
  if (checkboxVar) {
    QSqlQuery query;
    query.prepare("INSERT INTO UserEntries (Name, Date, Priority, Time, user_id) "
      "VALUES (?, ?, ?, ?, ?);");
    query.addBindValue(nameVar);
    query.addBindValue(dateVar);
    query.addBindValue(priority);
    query.addBindValue(time);
    query.addBindValue(getActiveUserId());
    query.exec();
  } else {
    QSqlQuery query;
    query.prepare("INSERT INTO UserEntries (Name, Date, Priority, Time, user_id) "
      "VALUES (?, ?, '-', ?, ?);");
    query.addBindValue(nameVar);
    query.addBindValue(dateVar);
    query.addBindValue(time);
    query.addBindValue(getActiveUserId());
    query.exec();
  }
}

void DataBase::deleteAll() {
  QSqlQuery query;
  query.prepare("DELETE FROM UserEntries WHERE user_id = ?");
  query.addBindValue(getActiveUserId());
  query.exec();
  query.clear();
}
