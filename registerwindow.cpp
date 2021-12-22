#include "registerwindow.h"
#include "ui_registerwindow.h"


registerwindow::registerwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerwindow)
{
    ui->setupUi(this);
}

registerwindow::~registerwindow()
{
    delete ui;
}

void registerwindow::on_registerbutton_clicked()
{
    QString registerlogin = ui->register_login-> text();
    QString registerpassword = ui->register_password-> text();
}

