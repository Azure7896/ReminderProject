#include "row.h"

Row::Row(/*QString name, QString date, QString hours, QString minutes, bool isPriority*/)
{
    /*this->name=name;
    this-> date=date;
    this->hours=hours;
    this->minutes=minutes;
    this->isPriority=isPriority;*/
}

QString Row::getName() {
    return this->name;
}

QString Row::getDate() {
    return this->date;
}

QString Row::getHours() {
    return this->hours;
}

QString Row::getMinutes() {
    return this->minutes;
}

bool Row::getIsPriority() {
    return this->isPriority;
}


void Row::setName(QString name) {
    this->name = name;
}
void Row::setDate(QString date) {
    this->date = date;
}
void Row::setHours(QString hours) {
    this->hours = hours;
}
void Row::setMinutes(QString minutes) {
    this->minutes = minutes;
}
void Row::setIsPriority(bool isPriority) {
    this->isPriority = isPriority;
}
