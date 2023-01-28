#ifndef DATABASE_H
#define DATABASE_H

#include "user.h"

#include <QtSql>

#include <QSqlDatabase>

class DataBase {
  public:
  DataBase();
  bool createConnection();
  bool login(User user);
  void registerAccount(User user);
  void addToDatabase(QString nameVar, QString dateVar, QString time, bool checkboxVar); //QString latestIDVar,
  QSqlQuery loadFromDatabase();
  QSqlQuery loadFromDatabaseByDesc();
  QSqlQuery loadFromDatabaseByAscend();
  QSqlQuery loadFromDatabaseByItem(QString item);
  QSqlQuery loadFromDatabaseByPriority();
  void deleteCurrent();
  void deleteAll();
  void refreshIDs();
  void queriesCountToOne();
  int count(int count);
  int returnQueriesCount();
  QString nextRecord();
  QString previousRecord();
  QSqlQuery query;

  private:
  QString time;
  QString latestIDFinal;
  QString idFromDatabase;
  QString resultVar;
  QString nameFromDatabase;
  QString dateFromDatabase;
  QString priorityFromDatabase;
  QString hoursFromDatabase;
  QString minutesFromDatabase;
  int hoursFromDatabaseInt;
  int minutesFromDatabaseInt;
  QString encryptedPassword;
  QString nameFromDatabaseToRemove;
  QString dateFromDatabaseToRemove;
  QString priorityFromDatabaseToRemove;
  QString hoursFromDatabaseToRemove;
  QString minutesFromDatabaseToRemove;
  int hoursFromDatabaseIntToRemove;
  int minutesFromDatabaseIntToRemove;
  int numberOfRowFromDatabaseIntToRemove;
  QString numberOfRowsFromDatabaseToRemove;
  int nCount;
  int idNumber = 0;
  int queriesCount = 1;
  QString result;

};

#endif // DATABASE_H
