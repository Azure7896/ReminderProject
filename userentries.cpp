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

    this -> setFixedSize((QSize(640, 640)));
    this -> setWindowTitle("ReminderProject by Szymon Napora 5ION");
    connectionCheck();
    on_loadAll_clicked();
  }

Userentries::~Userentries() {
  delete ui;
}

void Userentries::connectionCheck() {
  if (!databaseController.createConnection()) {
    QMessageBox::information(this, "Problem z bazą danych", "Sprawdź czy plik SQLite istnieje i znajduje się w odpowiednim katalogu");
    QApplication::quit();
  }
}

void Userentries::on_addNewItemButton_clicked() ///// OK
{
  latestIDVarUI = ui -> idLine -> text();
  nameVarUI = ui -> textLine -> text();
  dateVarUI = ui -> dateLine -> text();
  hoursVarUI = ui -> hourLine -> text();
  minutesVarUI = ui -> minuteLine -> text();
  checkboxStatus = ui -> priorityCheckbox -> isChecked();
  latestIDVarIntUI = latestIDVarUI.toInt();
  hoursVarIntUI = hoursVarUI.toInt();
  minutesVarIntUI = minutesVarUI.toInt();
  if (latestIDVarIntUI > 50 || latestIDVarIntUI <= 0 || latestIDVarUI.isEmpty() || nameVarUI.isEmpty() || (nameVarUI.size() > 17 || nameVarUI.size() < 4) || dateVarUI.isEmpty() || dateVarUI.size() > 10 || hoursVarUI.isEmpty() ||
    hoursVarUI.size() > 2 || minutesVarUI.isEmpty() || minutesVarUI.size() > 2 || hoursVarIntUI > 23 || minutesVarIntUI > 59) {
    QMessageBox::information(this, "Error", "Błędnie wprowadzone dane.");
  } else {
    databaseController.addToDatabase(latestIDVarUI, nameVarUI, dateVarUI, hoursVarUI, minutesVarUI, checkboxStatus);
    if (ui -> priorityCheckbox -> isChecked()) {
      ui -> listWidget -> addItem(QString("%1 | %2 | %3 | ◔ %4:%5 | %6").arg(latestIDVarUI, nameVarUI, dateVarUI, hoursVarUI, minutesVarUI, priorityVarUI));
    } else {
      ui -> listWidget -> addItem(QString("%1 | %2 | %3   |   ◔ %4:%5     ").arg(latestIDVarUI, nameVarUI, dateVarUI, hoursVarUI, minutesVarUI));
    }
  }
}

void Userentries::on_searchItemsWindow_clicked() /////// OK
{
  resultVar = ui -> searchLine -> text();
  if (resultVar.isEmpty()) {
    QMessageBox::information(this, "Error", "Pole wyszukiwania jest puste.");
  } else {
    QList < QListWidgetItem * > list = ui -> listWidget -> findItems((resultVar), Qt::MatchContains);
    for (QListWidgetItem * item: list)
      item -> setBackground(Qt::darkGreen);
  }
}

void Userentries::on_removeItemWindowButton_clicked()
{
  oneElementWindow = new onelementwindow(this);
  oneElementWindow -> show();
}

void Userentries::on_loadAll_clicked() {
  QSqlQueryModel * model = new QSqlQueryModel();
  model -> setQuery(databaseController.loadFromDatabase());
  QTableView * view = new QTableView;
  view -> setModel(model);
  ui -> tableView -> setModel(model);
}

void Userentries::closeEvent(QCloseEvent * event) {
  event -> ignore();
  if (QMessageBox::Yes == QMessageBox::question(this, "Wyjście", "Czy na pewno chcesz wyjść?", QMessageBox::Yes | QMessageBox::No)) {
    event -> accept();
  }

}
