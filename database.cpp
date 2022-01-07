#include "database.h"
#include "ui_database.h"
#include <QMessageBox>

database::database(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::database)
{
    ui->setupUi(this);
}

database::~database()
{
    delete ui;
}

bool CreateConnection::dbcon() const{
    return 1;
}
