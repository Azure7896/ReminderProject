#include "onelementwindow.h"
#include "ui_onelementwindow.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QtSql>

onelementwindow::onelementwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::onelementwindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Usuwanie rekordów");
    connectionCheck();
}

void onelementwindow::connectionCheck() {
    if (!databaseController.createConnection()) {
        QMessageBox::information(this, "Problem z bazą danych", "Sprawdź czy plik SQLite istnieje i znajduje się w odpowiednim katalogu");
        QApplication::quit();
    }
}

onelementwindow::~onelementwindow()
{
    delete ui;
}


void onelementwindow::on_pushButton_clicked()
{
    if (QMessageBox::Yes == QMessageBox::question(this, "Usuwanie", "Czy na pewno chcesz usunąć wybrany rekord?", QMessageBox::Yes | QMessageBox::No)) {
        databaseController.deleteCurrent();
        databaseController.refreshIDs();
    }
}


void onelementwindow::on_nextButton_clicked()
{
           dbResult = databaseController.nextRecord();
           if (dbResult == "Brak rekordów.") {
               QMessageBox::information(this, "Error", "Przekroczyłeś maksymalną liczbę rekordów.");
               QString itemForPrint = databaseController.previousRecord();
               ui->label->setText(itemForPrint);
           } else {
           ui->label->setText(dbResult);
           }
}


void onelementwindow::on_beforeButton_clicked()
{
    //idNumber--;
    //numberString = QVariant (idNumber).toString();
    dbResult = databaseController.previousRecord();
    //ui->label->setText(dbResult);
    if (dbResult == "Brak rekordów.") {
       // idNumber=idNumber+1;
       // numberString = QVariant(idNumber).toString();
        ui->label->setText(dbResult);
        QMessageBox::information(this, "Error", "Przekroczyłeś maksymalną liczbę rekordów.");
        QString itemForPrint = databaseController.nextRecord();
        ui->label->setText(itemForPrint);
    } else {
    ui->label->setText(dbResult);
    }
}

void onelementwindow::on_deleteAll_clicked()
{
    if (QMessageBox::Yes == QMessageBox::question(this, "Usuwanie zawartości bazy danych", "Czy na pewno chcesz usunąć wszystkie rekordy?", QMessageBox::Yes | QMessageBox::No))
     databaseController.deleteAll();

}