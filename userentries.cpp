#include "userentries.h"
#include "ui_userentries.h"
#include <QDateTime>


Userentries::Userentries(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Userentries)
{
    ui->setupUi(this);
}

Userentries::~Userentries()
{
    delete ui;

}



void Userentries::on_pushButton_clicked()
{
    CalendarWindow = new calendarWindow();
    CalendarWindow -> show();
}




