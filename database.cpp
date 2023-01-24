#include "database.h"
#include "user.h"



DataBase::DataBase()
{
}


bool DataBase::createConnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName ("C:/Users/Azure/Desktop/Reminder/reminderdatabase.sqlite");
    return db.open();
}

bool DataBase::login(User user) {
    QSqlQuery query("SELECT name, password FROM Users");
       query.next();
           QString userLoginFromDatabase = query.value(0).toString();
           QString userPasswordFromDatabase = query.value(1).toString();
           QByteArray bytes = QCryptographicHash::hash(user.getPassword().toUtf8(), QCryptographicHash::Md5);
           passwordToCheck = QString(bytes.toHex());
           return (user.getName() == userLoginFromDatabase && passwordToCheck == userPasswordFromDatabase);
}

bool DataBase::registerAccount(QString login, QString password) {
    QByteArray bytes = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5);
    passwordToCheck = QString(bytes.toHex());
    QSqlQuery query;
       query.prepare("INSERT INTO UserEntries (idUser, name, password) "
                     "VALUES (?,?,?);");
       query.addBindValue(2);
       query.addBindValue(login);
       query.addBindValue(passwordToCheck);
       query.exec();
       return true;
}

QSqlQuery DataBase::loadFromDatabase() {
       QString q = QString("SELECT * FROM UserEntries");
       QSqlQuery query(q);
       query.exec();
       return query;
       /*query.next();
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
       db.close(); */
}

void DataBase::refreshIDs() {
    QSqlQuery query;
    query.prepare("UPDATE UserEntries SET id = id - 1 WHERE id > ?;");
    query.addBindValue(idNumber);
    query.exec();
    query.clear();
}

int DataBase::returnQueriesCount(){

    QSqlQuery query("SELECT id FROM UserEntries ORDER BY id DESC LIMIT 1;");
    query.next();
    int queriesCount = query.value(0).toInt();
    return queriesCount;
}

void DataBase::queriesCountToOne(){
    queriesCount = 1;
}

void DataBase::addToDatabase(QString latestIDVar, QString nameVar, QString dateVar, QString hoursVar, QString minutesVar, bool checkboxVar) {
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


void DataBase::deleteCurrent() {
    QSqlQuery query;
       query.prepare("DELETE FROM UserEntries WHERE id= ?;");
       query.addBindValue(idNumber);
      // query.prepare("UPDATE UserEntries SET id = id - 1 WHERE id > ?;");
      //  query.addBindValue(numberOfRowFromDatabase);
       query.exec();
       query.clear();
}

void DataBase::deleteAll() {
    QSqlQuery query;
    query.prepare("DELETE FROM UserEntries;");
    query.exec();
    query.clear();
}


QString DataBase::nextRecord() {
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

QString DataBase::previousRecord() {
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

int DataBase::count(int nCount) {
    return nCount;
}



