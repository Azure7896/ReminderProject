#include "calendarwindow.h"
#include "ui_calendarwindow.h"

calendarWindow::calendarWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calendarWindow)
{
    ui->setupUi(this);
}

calendarWindow::~calendarWindow()
{
    delete ui;
}



void calendarWindow::on_pushButton_2_clicked()
{
    this->hide();
}

