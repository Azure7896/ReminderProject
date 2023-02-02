#include "date.h"
#include "qdatetime.h"
#include <QApplication>

date::date()
{

}

//Date creating
QString date::createDate() {
    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime = date.toString("dd/MM/yyyy");
    QByteArray formattedTimeMsg = formattedTime.toLocal8Bit();
    return formattedTime;
}
