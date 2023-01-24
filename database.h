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
  bool registerAccount(QString name, QString password);
  void addToDatabase(QString latestIDVar, QString nameVar, QString dateVar, QString time, bool checkboxVar);
  QSqlQuery loadFromDatabase();
  QSqlQuery loadFromDatabaseByDesc();
  QSqlQuery loadFromDatabaseByAscend();
  QSqlQuery loadFromDatabaseByItem(QString item);
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
  QString latestIDVar;
  int latestIDVarInt;
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
  QString passwordToCheck;
  QString Variable;
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
