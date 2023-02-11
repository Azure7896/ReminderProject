#include "onelementwindow.h"

#include "ui_onelementwindow.h"

#include <QMessageBox>

#include <QSqlDatabase>

#include <QtSql>

onelementwindow::onelementwindow(QWidget * parent):
  QDialog(parent),
  ui(new Ui::onelementwindow) {
    ui -> setupUi(this);
    this -> setWindowTitle("Usuwanie rekordów");
    connectionCheck();
    QMessageBox::information(this, "Brak funkcjonalności", "Usuwanie pojedynczych rekordów zostanie dodane wkrótce.");
  }

void onelementwindow::connectionCheck() {
  if (!databaseController.createConnection()) {
    QMessageBox::information(this, "Problem z bazą danych", "Sprawdź czy plik SQLite istnieje i znajduje się w odpowiednim katalogu");
    QApplication::quit();
  }
}

onelementwindow::~onelementwindow() {
  delete ui;
}

void onelementwindow::on_pushButton_clicked() {
  if (QMessageBox::Yes == QMessageBox::question(this, "Usuwanie", "Czy na pewno chcesz usunąć wybrany rekord?", QMessageBox::Yes | QMessageBox::No)) {
    //databaseController.deleteCurrent();
  }
}

void onelementwindow::on_deleteAll_clicked() {
  if (QMessageBox::Yes == QMessageBox::question(this, "Usuwanie zawartości bazy danych", "Czy na pewno chcesz usunąć wszystkie rekordy?", QMessageBox::Yes | QMessageBox::No))
    databaseController.deleteAll();

}

