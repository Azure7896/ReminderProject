#include "database.h"



database::database()
{
}


void database::createConnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName ("C:/Projects/Reminder/reminderdatabase.sqlite");
    db.open();
}

void database::refreshIDs() {
    QSqlQuery query;
    query.prepare("UPDATE UserEntries SET id = id - 1 WHERE id > ?;");
    query.addBindValue(idNumber);
    query.exec();
    query.clear();
}

int database::returnQueriesCount(){

    QSqlQuery query("SELECT id FROM UserEntries ORDER BY id DESC LIMIT 1;");
    query.next();
    int latestIdNumber = query.value(0).toInt();
    return latestIdNumber;
}

void database::queriesCountToOne(){
    queriesCount = 1;
}

void database::addToDatabase(QString latestIDVar, QString nameVar, QString dateVar, QString hoursVar, QString minutesVar, bool checkboxVar) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName ("C:/Projects/Reminder/reminderdatabase.sqlite");
    latestIDVarInt = latestIDVar.toInt();
    hoursVarInt = hoursVar.toInt();
    minutesVarInt = minutesVar.toInt();
        if (checkboxVar==true){
            const QString priorityVar = "Ważne";
                QSqlQuery query;
                   db.open();
                   query.prepare("INSERT INTO UserEntries (id, Name, Date, Priority, HOURS, MINUTES) "
                                 "VALUES (?, ?, ?, ?, ?, ?);");
                   query.addBindValue(latestIDVar);
                   query.addBindValue(nameVar);
                   query.addBindValue(dateVar);
                   query.addBindValue(priorityVar);
                   query.addBindValue(hoursVarInt);
                   query.addBindValue(minutesVarInt);
                   query.exec();
         } else {

                QSqlQuery query;
                db.open();
                   query.prepare("INSERT INTO UserEntries (id, Name, Date, Priority, HOURS, MINUTES) "
                                 "VALUES (?, ?, ?, 'NULL', ?, ?);");
                   query.addBindValue(latestIDVar);
                   query.addBindValue(nameVar);
                   query.addBindValue(dateVar);
                   query.addBindValue(hoursVarInt);
                   query.addBindValue(minutesVarInt);
                   query.exec();
          }
}


void database::deleteCurrent() {
    QSqlQuery query;
       query.prepare("DELETE FROM UserEntries WHERE id= ?;");
       query.addBindValue(idNumber);
      // query.prepare("UPDATE UserEntries SET id = id - 1 WHERE id > ?;");
      //  query.addBindValue(numberOfRowFromDatabase);
       query.exec();
       query.clear();


}

void database::deleteAll() {
    QSqlQuery query;
    //db.open();
    query.prepare("DELETE FROM UserEntries;");
    query.exec();
    query.clear();
}

QString database::login(QString name, QString password) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName ("C:/Projects/Reminder/reminderdatabase.sqlite");
    //db.open();
    QSqlQuery query("SELECT name, password FROM Users");
       query.next();
           QString userLoginFromDatabase = query.value(0).toString();
           QString userPasswordFromDatabase = query.value(1).toString();
           bytes = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5);
           passwordForCheck = QString(bytes.toHex());
           if (name == userLoginFromDatabase && passwordForCheck == userPasswordFromDatabase) {
    }
           return "true";
}


QString database::loadFromDatabase() {
       QString q = QString("SELECT id, Name, Date, Priority, HOURS, MINUTES FROM UserEntries WHERE id = %1 LIMIT 1;").arg(queriesCount);
       QSqlQuery query(q);
       query.next();
           idFromDatabase = query.value(0).toString();
           nameFromDatabase = query.value(1).toString();
           dateFromDatabase = query.value(2).toString();
           priorityFromDatabase = query.value(3).toString();
           hoursFromDatabase = query.value(4).toString();
           minutesFromDatabase = query.value(5).toString();
           hoursFromDatabaseInt = hoursFromDatabase.toInt();
           minutesFromDatabaseInt = minutesFromDatabase.toInt();
           queriesCount++;
           if (hoursFromDatabaseInt == 0) {
               hoursFromDatabase="00";
           }
           else if (minutesFromDatabaseInt == 0) {
                   minutesFromDatabase="00";
               }
           else {
           }
           if ((priorityFromDatabase == "Ważne")) {
             QString result = (QString("%1 | %2  | %3   |   ◔ %4:%5     |    %6").arg(idFromDatabase, nameFromDatabase, dateFromDatabase, hoursFromDatabase, minutesFromDatabase, priorityFromDatabase));
             return result;
           } else  {
             QString result = (QString("%1 | %2  | %3   |   ◔ %4:%5     ").arg(idFromDatabase, nameFromDatabase, dateFromDatabase, hoursFromDatabase, minutesFromDatabase));
             return result;
            }
       query.exec();
       db.close();
}

QString database::nextRecord() {
    idNumber++;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName ("C:/Projects/Reminder/reminderdatabase.sqlite");
    QString q = QString("SELECT id, Name, Date, Priority, HOURS, MINUTES FROM UserEntries WHERE id = %1 LIMIT 1;").arg(idNumber);
    db.open();
    QSqlQuery query(q);
    query.next();
    numberOfRowFromDatabaseForRemove = query.value(0).toString();
    nameFromDatabaseForRemove = query.value(1).toString();
    dateFromDatabaseForRemove = query.value(2).toString();
    priorityFromDatabaseForRemove = query.value(3).toString();
    hoursFromDatabaseForRemove = query.value(4).toString();
    minutesFromDatabaseForRemove = query.value(5).toString();
    hoursFromDatabaseIntForRemove = hoursFromDatabaseForRemove.toInt();
    minutesFromDatabaseIntForRemove = minutesFromDatabaseForRemove.toInt();
    numberOfRowFromDatabaseIntForRemove = numberOfRowFromDatabaseForRemove.toInt();
    if (numberOfRowFromDatabaseForRemove == "") {
        //idNumber=idNumber-1;
        return "Brak rekordów.";
    }
    if (hoursFromDatabaseIntForRemove == 0) {
        hoursFromDatabaseForRemove="00";
    }
    else if (minutesFromDatabaseIntForRemove == 0) {
            minutesFromDatabaseForRemove="00";
        }
    else {
    }
    if ((priorityFromDatabaseForRemove == "Ważne")) {
        QString priorityResult = (QString("%1 | %2 | %3 |  ◔ %4:%5 | %6 ").arg(numberOfRowFromDatabaseForRemove, nameFromDatabaseForRemove, dateFromDatabaseForRemove, hoursFromDatabaseForRemove, minutesFromDatabaseForRemove, priorityFromDatabaseForRemove));
        return priorityResult;

    } else  {
        priorityFromDatabaseForRemove = " ";
        QString result  = (QString("%1 | %2 | %3 |  ◔ %4:%5  ").arg(numberOfRowFromDatabaseForRemove, nameFromDatabaseForRemove, dateFromDatabaseForRemove, hoursFromDatabaseForRemove, minutesFromDatabaseForRemove));
        return result;
    }
}

QString database::previousRecord() {
    idNumber--;
    QString q = QString("SELECT id, Name, Date, Priority, HOURS, MINUTES FROM UserEntries WHERE id = %1 LIMIT 1;").arg(idNumber);
    QSqlQuery query(q);
    query.next();
    numberOfRowFromDatabaseForRemove = query.value(0).toString();
    nameFromDatabaseForRemove = query.value(1).toString();
    dateFromDatabaseForRemove = query.value(2).toString();
    priorityFromDatabaseForRemove = query.value(3).toString();
    hoursFromDatabaseForRemove = query.value(4).toString();
    minutesFromDatabaseForRemove = query.value(5).toString();
    hoursFromDatabaseIntForRemove = hoursFromDatabaseForRemove.toInt();
    minutesFromDatabaseIntForRemove = minutesFromDatabaseForRemove.toInt();
    numberOfRowFromDatabaseIntForRemove = numberOfRowFromDatabaseForRemove.toInt();
    if (numberOfRowFromDatabaseForRemove == "") {
        //idNumber=idNumber+1;
        return "Brak rekordów.";
    }
    if (hoursFromDatabaseIntForRemove == 0) {
        hoursFromDatabaseForRemove="00";
    }
    else if (minutesFromDatabaseIntForRemove == 0) {
            minutesFromDatabaseForRemove="00";
        }
    else {
    }
    if ((priorityFromDatabaseForRemove == "Ważne")) {
        QString priorityResult = (QString("%1 | %2 | %3 |  ◔ %4:%5 | %6 ").arg(numberOfRowFromDatabaseForRemove, nameFromDatabaseForRemove, dateFromDatabaseForRemove, hoursFromDatabaseForRemove, minutesFromDatabaseForRemove, priorityFromDatabaseForRemove));
        return priorityResult;
    } else  {
        priorityFromDatabaseForRemove = " ";
        QString result  = (QString("%1 | %2 | %3 |  ◔ %4:%5  ").arg(numberOfRowFromDatabaseForRemove, nameFromDatabaseForRemove, dateFromDatabaseForRemove, hoursFromDatabaseForRemove, minutesFromDatabaseForRemove));
        return result;
    }
}



QString database::loadFromDatabaseByName() {
           QString q = QString("SELECT id, Name, Date, Priority, HOURS, MINUTES FROM UserEntries WHERE id = %1 LIMIT 1;").arg(queriesCount);
           QSqlQuery query(q);
           query.next();
               idFromDatabase = query.value(0).toString();
               nameFromDatabase = query.value(1).toString();
               dateFromDatabase = query.value(2).toString();
               priorityFromDatabase = query.value(3).toString();
               hoursFromDatabase = query.value(4).toString();
               minutesFromDatabase = query.value(5).toString();
               hoursFromDatabaseInt = hoursFromDatabase.toInt();
               minutesFromDatabaseInt = minutesFromDatabase.toInt();
               queriesCount++;
               if (hoursFromDatabaseInt == 0) {
                   hoursFromDatabase="00";
               }
               else if (minutesFromDatabaseInt == 0) {
                       minutesFromDatabase="00";
                   }
               else {
               }
               if ((priorityFromDatabase == "Ważne")) {
                 QString result = (QString("%2  | %3   |   ◔ %4:%5     |    %6").arg(nameFromDatabase, dateFromDatabase, hoursFromDatabase, minutesFromDatabase, priorityFromDatabase));
                 return result;
               } else  {
                 QString result = (QString("%2  | %3   |   ◔ %4:%5     ").arg(nameFromDatabase, dateFromDatabase, hoursFromDatabase, minutesFromDatabase));
                 return result;
                }
           query.exec();
           db.close();
    }

int database::count(int nCount) {
    return nCount;
}


QString database::loadFromDatabaseByPriority() {
    QString q = QString("SELECT id, Name, Date, Priority, HOURS, MINUTES FROM UserEntries WHERE id = %1 LIMIT 1;").arg(queriesCount);
    QSqlQuery query(q);
    query.next();
        idFromDatabase = query.value(0).toString();
        nameFromDatabase = query.value(1).toString();
        dateFromDatabase = query.value(2).toString();
        priorityFromDatabase = query.value(3).toString();
        hoursFromDatabase = query.value(4).toString();
        minutesFromDatabase = query.value(5).toString();
        hoursFromDatabaseInt = hoursFromDatabase.toInt();
        minutesFromDatabaseInt = minutesFromDatabase.toInt();
        queriesCount++;
        if (hoursFromDatabaseInt == 0) {
            hoursFromDatabase="00";
        }
        else if (minutesFromDatabaseInt == 0) {
                minutesFromDatabase="00";
            }
        else {
        }
        if ((priorityFromDatabase == "Ważne")) {
          QString result = (QString("%6  |  %2  | %3   |   ◔ %4:%5         ").arg(nameFromDatabase, dateFromDatabase, hoursFromDatabase, minutesFromDatabase, priorityFromDatabase));
          return result;
        } else  {
          QString result = (QString("                    %2  | %3   |   ◔ %4:%5     ").arg(nameFromDatabase, dateFromDatabase, hoursFromDatabase, minutesFromDatabase));
          return result;
         }
    query.exec();
    db.close();

}

