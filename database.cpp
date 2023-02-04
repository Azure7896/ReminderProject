#include "database.h"

#include "user.h"


DataBase::DataBase() {}

bool DataBase::createConnection() {
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("C:/Users/Azure/Desktop/Reminder/reminderdatabase.sqlite");
  return db.open();
}

bool DataBase::login(User user) {
  QByteArray bytes = QCryptographicHash::hash(user.getPassword().toUtf8(), QCryptographicHash::Md5);
  encryptedPassword = QString(bytes.toHex());
  QSqlQuery query;
  query.prepare("SELECT username, password FROM Users WHERE username= ? AND password = ?");
  query.addBindValue(user.getName());
  query.addBindValue(encryptedPassword);
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

int DataBase::getUserId(User user) {
  int id = 0;
  QSqlQuery query;
  query.prepare("SELECT user_id FROM Users WHERE username = ?");
  query.addBindValue(user.getName());
  while (query.next()) {
    id = query.value(0).toInt();
  }
  return id;
}

void DataBase::registerAccount(User user) {
  QByteArray bytes = QCryptographicHash::hash(user.getPassword().toUtf8(), QCryptographicHash::Md5);
  encryptedPassword = QString(bytes.toHex());
  QSqlQuery query;
  query.prepare("INSERT INTO Users (username, password) "
    "VALUES (?, ?);");
  query.addBindValue(user.getName());
  query.addBindValue(encryptedPassword);
  query.exec();
}

QSqlQuery DataBase::loadFromDatabase() {
  QString q = QString("SELECT Name, Date, Priority, Time FROM UserEntries");
  QSqlQuery query(q);
  query.exec();
  return query;
}

QSqlQuery DataBase::loadFromDatabaseByDesc() {
  QString q = QString("SELECT Name, Date, Priority, Time FROM UserEntries ORDER BY Name desc");
  QSqlQuery query(q);
  query.exec();
  return query;
}

QSqlQuery DataBase::loadFromDatabaseByAscend() {
  QString q = QString("SELECT Name, Date, Priority, Time FROM UserEntries ORDER BY Name");
  QSqlQuery query(q);
  query.exec();
  return query;
}

QSqlQuery DataBase::loadFromDatabaseByItem(QString item) {
  QSqlQuery query;
  query.prepare("SELECT Name, Date, Priority, Time FROM UserEntries WHERE name LIKE ?");
  query.addBindValue("%%" + item + "%");
  query.exec();
  return query;
}

QSqlQuery DataBase::loadFromDatabaseByPriority() {
  QString q = QString("SELECT Name, Date, Priority, Time FROM UserEntries ORDER BY Priority desc");
  QSqlQuery query(q);
  query.exec();
  return query;
}

void DataBase::refreshIDs() {
  QSqlQuery query;
  query.prepare("UPDATE UserEntries SET id = id - 1 WHERE id > ?;");
  //query.addBindValue(idNumber);
  query.exec();
  query.clear();
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
    query.prepare("INSERT INTO UserEntries (Name, Date, Priority, Time) "
      "VALUES (?, ?, ?, ?);");
    query.addBindValue(nameVar);
    query.addBindValue(dateVar);
    query.addBindValue(priority);
    query.addBindValue(time);
    query.exec();
  } else {
    QSqlQuery query;
    query.prepare("INSERT INTO UserEntries (Name, Date, Priority, Time) "
      "VALUES (?, ?, '-', ?);");
    query.addBindValue(nameVar);
    query.addBindValue(dateVar);
    query.addBindValue(time);
    query.exec();
  }
}

/*void DataBase::deleteCurrent() {
      QSqlQuery query;
       query.prepare("DELETE FROM UserEntries WHERE id= ?;");
       query.addBindValue(idNumber);
       query.exec();
       query.clear();
}*/

void DataBase::deleteAll() {
  QSqlQuery query;
  query.prepare("DELETE FROM UserEntries;");
  query.exec();
  query.clear();
}
