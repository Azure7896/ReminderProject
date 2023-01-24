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
       query.prepare("INSERT INTO UserEntries (idUser, name password) "
                     "VALUES (?,?,?);");
       query.addBindValue(2);
       query.addBindValue(login);
       query.addBindValue(passwordToCheck);
       query.exec();
       return true;
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

void DataBase::addToDatabase(QString latestIDVar, QString nameVar, QString dateVar, QString time, bool checkboxVar) {
    latestIDVarInt = latestIDVar.toInt();
        if (checkboxVar==true){
            const QString priorityVar = "Ważne";
                QSqlQuery query;
                   query.prepare("INSERT INTO UserEntries (id, Name, Date, Priority, Time) "
                                 "VALUES (?, ?, ?, ?, ?);");
                   query.addBindValue(latestIDVar);
                   query.addBindValue(nameVar);
                   query.addBindValue(dateVar);
                   query.addBindValue(priorityVar);
                   query.addBindValue(time);
                   query.exec();
         } else {
                QSqlQuery query;
                   query.prepare("INSERT INTO UserEntries (id, Name, Date, Priority, Time) "
                                 "VALUES (?, ?, ?, '-', ?);");
                   query.addBindValue(latestIDVar);
                   query.addBindValue(nameVar);
                   query.addBindValue(dateVar);
                   query.addBindValue(time);
                   query.exec();
          }
}


void DataBase::deleteCurrent() {
    QSqlQuery query;
       query.prepare("DELETE FROM UserEntries WHERE id= ?;");
       query.addBindValue(idNumber);
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
    QString q = QString("SELECT id, Name, Date, Priority, Time FROM UserEntries WHERE id = %1 LIMIT 1;").arg(idNumber);
    QSqlQuery query(q);
    query.next();
    numberOfRowsFromDatabaseToRemove = query.value(0).toString();
    nameFromDatabaseToRemove = query.value(1).toString();
    dateFromDatabaseToRemove = query.value(2).toString();
    priorityFromDatabaseToRemove = query.value(3).toString();
    time = query.value(4).toString();
    numberOfRowFromDatabaseIntToRemove = numberOfRowsFromDatabaseToRemove.toInt();
    if (numberOfRowsFromDatabaseToRemove == "") {
        return "Brak rekordów.";
        }
    else {
    }
    if ((priorityFromDatabaseToRemove == "Ważne")) {
        QString priorityResult = (QString("%1 | %2 | %3 |  ◔ %4:%5 | %6 ").arg(numberOfRowsFromDatabaseToRemove, nameFromDatabaseToRemove, dateFromDatabaseToRemove,
                                                                               hoursFromDatabaseToRemove, minutesFromDatabaseToRemove, priorityFromDatabaseToRemove));
        return priorityResult;

    } else  {
        priorityFromDatabaseToRemove = " ";
        QString result  = (QString("%1 | %2 | %3 |  ◔ %4:%5  ").arg(numberOfRowsFromDatabaseToRemove, nameFromDatabaseToRemove, dateFromDatabaseToRemove, time));
        return result;
    }
}

QString DataBase::previousRecord() {
    /*idNumber--;
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
    return nCount; */
}


