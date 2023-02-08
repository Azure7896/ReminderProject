#ifndef DATABASE_H
#define DATABASE_H

#include "date.h"
#include "encryptor.h"
#include "user.h"

#include <QtSql>

#include <QSqlDatabase>

class DataBase {
  public:
  DataBase();
  bool createConnection();
  bool login(User user);
  void registerAccount(User user);
  void addToDatabase(QString nameVar, QString dateVar, QString time, bool checkboxVar, bool withActualDate);
  bool isRegistered(User user);

  QSqlQuery loadFromDatabase();
  QSqlQuery loadFromDatabaseByDesc();
  QSqlQuery loadFromDatabaseByAscend();
  QSqlQuery loadFromDatabaseByItem(QString item);
  QSqlQuery loadFromDatabaseByPriority();

  void deleteAll();
  void queriesCountToOne();
  int returnQueriesCount();

  int getUserId(User user);
  int getActiveUserId();
  void updateActiveUser(int userId);
  QString nextRecord();
  QString previousRecord();

  private:
  const QString priority = "Ważne";
  QSqlQuery query;
  QString time;
  QString nameFromDatabase;
  QString dateFromDatabase;
  QString priorityFromDatabase;
  QString hoursFromDatabase;
  QString minutesFromDatabase;
  QString encryptedPassword;
  int queriesCount = 1;
  QString result;
  date date;
  Encryptor encryptor;


};

#endif // DATABASE_H
