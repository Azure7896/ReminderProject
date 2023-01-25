#include "userentries.h"

#include "ui_userentries.h"

#include<QMessageBox>

#include <QDebug>

#include <QCloseEvent>

#include <QListWidgetItem>


Userentries::Userentries(QWidget * parent):
  QDialog(parent),
  ui(new Ui::Userentries) {
    ui -> setupUi(this);

    this -> setFixedSize((QSize(695, 640)));
    this -> setWindowTitle("ReminderProject by Szymon Napora 5ION");
    connectionCheck();
    on_loadAll_clicked();
  }


Userentries::~Userentries() {
  delete ui;
}

void Userentries::on_loadAll_clicked() {
  QSqlQueryModel * model = new QSqlQueryModel();
  model -> setQuery(databaseController.loadFromDatabase());
  QTableView * view = new QTableView;
  view -> setModel(model);
  ui -> tableView -> setModel(model);
}

void Userentries::connectionCheck() {
  if (!databaseController.createConnection()) {
    QMessageBox::information(this, "Problem z bazą danych", "Sprawdź czy plik SQLite istnieje i znajduje się w odpowiednim katalogu");
    QApplication::quit();
  }
}

void Userentries::on_addNewItemButton_clicked() {
      nameVarUI = ui -> textLine -> text();
      dateVarUI = ui -> dateLine -> text();
      hoursVarUI = ui -> hourLine -> text();
      minutesVarUI = ui -> minuteLine -> text();
      checkboxStatus = ui -> priorityCheckbox -> isChecked();
      hoursVarIntUI = hoursVarUI.toInt();
      minutesVarIntUI = minutesVarUI.toInt();
      QString time = hoursVarUI+":"+minutesVarUI;
      if ((nameVarUI.size() > 17 || nameVarUI.size() < 4) || dateVarUI.isEmpty() || dateVarUI.size() > 10 || hoursVarUI.isEmpty() ||
        hoursVarUI.size() > 2 || minutesVarUI.isEmpty() || minutesVarUI.size() > 2 || hoursVarIntUI > 23 || minutesVarIntUI > 59) {
        QMessageBox::information(this, "Error", "Błędnie wprowadzone dane.");
      } else {
        databaseController.addToDatabase(nameVarUI, dateVarUI, time, checkboxStatus);
        on_loadAll_clicked();
        QMessageBox::information(this, "Udało się!", "Rekord pomyślnie został dodany do bazy danych.");
    }
}

void Userentries::on_removeItemWindowButton_clicked()
{
  oneElementWindow = new onelementwindow(this);
  oneElementWindow -> show();
}

void Userentries::closeEvent(QCloseEvent * event) {
  event -> ignore();
  if (QMessageBox::Yes == QMessageBox::question(this, "Wyjście", "Czy na pewno chcesz wyjść?", QMessageBox::Yes | QMessageBox::No)) {
    event -> accept();
  }

}

void Userentries::on_byDesc_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model -> setQuery(databaseController.loadFromDatabaseByDesc());
    QTableView * view = new QTableView;
    view -> setModel(model);
    ui -> tableView -> setModel(model);
}


void Userentries::on_sortByNameButton_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model -> setQuery(databaseController.loadFromDatabaseByAscend());
    QTableView * view = new QTableView;
    view -> setModel(model);
    ui -> tableView -> setModel(model);
}

void Userentries::on_search_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model -> setQuery(databaseController.loadFromDatabaseByItem(ui->searchLine->text()));
    QTableView * view = new QTableView;
    view -> setModel(model);
    ui -> tableView -> setModel(model);
}


void Userentries::on_byPriority_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model -> setQuery(databaseController.loadFromDatabaseByPriority());
    QTableView * view = new QTableView;
    view -> setModel(model);
    ui -> tableView -> setModel(model);
}

