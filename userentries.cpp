#include "userentries.h"

#include "ui_userentries.h"

#include<QMessageBox>

#include <QDebug>

#include <QCloseEvent>

#include <QListWidgetItem>

#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>



Userentries::Userentries(QWidget * parent):
  QDialog(parent),
  ui(new Ui::Userentries) {
    ui -> setupUi(this);

    this -> setFixedSize((QSize(695, 640)));
    this -> setWindowTitle("ReminderProject by Szymon Napora 5ION");
    connectionCheck();
    on_loadAll_clicked();
    ui->nameLabel->setFocus();
    ui->date->setText("Dziś mamy: " + date.createDate());
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
      row.setName(ui->textLine->text());
      row.setDate(ui -> dateLine -> text());
      row.setHours(ui -> hourLine -> text());
      row.setMinutes(ui -> minuteLine -> text());
      row.setIsPriority(ui -> priorityCheckbox -> isChecked());
      withActualDate = ui->checkBox->isChecked();
      time = row.getHours()+":"+row.getMinutes();
      if ((row.getName().size() > 17 || row.getName().size() < 4) || row.getDate().isEmpty() || row.getDate().size() > 10 || row.getHours().isEmpty() ||
        row.getHours().size() > 2 || row.getMinutes().isEmpty() || row.getMinutes().size() > 2 || row.getHours().toInt() > 23 || row.getMinutes().toInt() > 59) {
        QMessageBox::information(this, "Error", "Błędnie wprowadzone dane.");
      } else {
        databaseController.addToDatabase(row.getName(), row.getDate(), time, row.getIsPriority(), withActualDate);
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


