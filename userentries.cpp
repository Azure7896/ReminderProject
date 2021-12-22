#include "userentries.h"
#include "ui_userentries.h"
#include <QDateTime>


Userentries::Userentries(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Userentries)
{

    ui->setupUi(this);
    clock_timer = new QTimer(this);
    connect(clock_timer, SIGNAL(timeout()), this, SLOT (clock()));
    clock_timer -> start(1000);
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

void Userentries::clock(){
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    ui->label_time->setText(time_text);
}


