#include "userentries.h"
#include "ui_userentries.h"
#include <QPair>


Userentries::Userentries(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Userentries)
{
    ui->setupUi(this);
    this->setFixedSize((QSize(480,640)));
    }

Userentries::~Userentries()
{
    delete ui;

}



void Userentries::on_pushButton_clicked()
{
    QString add = ui->text_line->text();
    QString add2 = ui->date_text->text();
    QString testowy = "text";

    ui->listWidget->addItem(QString("%1 ◔ %2").arg(add, add2, testowy));


}







