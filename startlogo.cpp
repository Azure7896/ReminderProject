#include "startlogo.h"
#include "ui_startlogo.h"
#include <QPixmap>

startlogo::startlogo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::startlogo)
{
    setWindowFlags(Qt::CustomizeWindowHint);
    ui->setupUi(this);
    QPixmap logo ("C:/Users/Azure/Desktop/reminderlogo.png");
    ui->label_start_Logo->setPixmap(logo);
    this->setFixedSize((QSize(570,360)));
}

startlogo::~startlogo()
{
    delete ui;
}

void startlogo::on_start_button_clicked()
{
    hide();
    mainwindow = new MainWindow(this);
    mainwindow->show();

}



