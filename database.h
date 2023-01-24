#ifndef DATABASE_H
#define DATABASE_H

#include "user.h"

#include <QtSql>

#include <QSqlDatabase>

class DataBase {
  public: DataBase();
  bool createConnection();
  bool login(User user);
  bool registerAccount(QString login, QString password);
  void addToDatabase(QString latestIDVar, QString nameVar, QString dateVar, QString hoursVar, QString minutesVar, bool checkboxVar);
  void deleteCurrent();
  void deleteAll();
  void refreshIDs();
  void queriesCountToOne();
  int count(int count);
  int returnQueriesCount();
  QString nextRecord();
  QString previousRecord();
  QSqlQuery loadFromDatabase();
  QString loadFromDatabaseByName();
  QString loadFromDatabaseByPriority();
  QString searchByRange();
  QSqlQuery query;

  private: int hoursVarInt;
  int minutesVarInt;
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
  QString nameFromDatabaseForRemove;
  QString dateFromDatabaseForRemove;
  QString priorityFromDatabaseForRemove;
  QString hoursFromDatabaseForRemove;
  QString minutesFromDatabaseForRemove;
  int hoursFromDatabaseIntForRemove;
  int minutesFromDatabaseIntForRemove;
  int numberOfRowFromDatabaseIntForRemove;
  QString numberOfRowFromDatabaseForRemove;
  int nCount;
  int idNumber = 0;
  int queriesCount = 1;
  QSqlDatabase db;
  QString result;

};

#endif // DATABASE_H
