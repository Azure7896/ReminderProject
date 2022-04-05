#include "userentries.h"
#include "ui_userentries.h"
#include<QMessageBox>
#include <QDebug>
#include <QCloseEvent>
#include <QListWidgetItem>


Userentries::Userentries(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Userentries)
{
    ui->setupUi(this);

    this->setFixedSize((QSize(640,640)));
    this->setWindowTitle("ReminderProject by Szymon Napora 3DZI");
    databaseController.createConnection();
}

Userentries::~Userentries()
{
    delete ui;
}

void Userentries::on_addNewItemButton_clicked() ///// OK
{
    latestIDVarUI = ui->idLine->text();
    nameVarUI = ui->textLine->text();
    dateVarUI = ui->dateLine->text();
    hoursVarUI = ui->hourLine->text();
    minutesVarUI = ui->minuteLine->text();
    checkboxStatus = ui->priorityCheckbox->isChecked();
    latestIDVarIntUI = latestIDVarUI.toInt();
    hoursVarIntUI = hoursVarUI.toInt();
    minutesVarIntUI =  minutesVarUI.toInt();
    if (latestIDVarIntUI>50 || latestIDVarIntUI<=0 || latestIDVarUI.isEmpty() || nameVarUI.isEmpty() || (nameVarUI.size()>17 || nameVarUI.size()<4) || dateVarUI.isEmpty() || dateVarUI.size()>10 || hoursVarUI.isEmpty()
            || hoursVarUI.size()>2|| minutesVarUI.isEmpty() || minutesVarUI.size()>2 || hoursVarIntUI>23 || minutesVarIntUI>59){
        QMessageBox::information(this, "Error", "Błędnie wprowadzone dane.");
        } else {
    databaseController.addToDatabase(latestIDVarUI, nameVarUI, dateVarUI, hoursVarUI, minutesVarUI, checkboxStatus);
        if (ui->priorityCheckbox->isChecked()){
    ui->listWidget->addItem(QString("%1 | %2 | %3 | ◔ %4:%5 | %6").arg(latestIDVarUI, nameVarUI, dateVarUI, hoursVarUI, minutesVarUI, priorityVarUI));
        } else {
        ui->listWidget->addItem(QString("%1 | %2 | %3   |   ◔ %4:%5     ").arg(latestIDVarUI, nameVarUI, dateVarUI, hoursVarUI, minutesVarUI));
        }
    }
}


void Userentries::on_loadFromDatabaseButton_clicked()
{
    ui->listWidget->clear();
    int queries = databaseController.returnQueriesCount();
    for (int i=1; i<=queries; i++) {
    QString xx = databaseController.loadFromDatabase();
     ui->listWidget->addItem(xx);
    }
    databaseController.queriesCountToOne();
}

void Userentries::on_byID_clicked()
{
    ui->listWidget->clear();
    int queries = databaseController.returnQueriesCount();
    for (int i=1; i<=queries; i++) {
    QString xx = databaseController.loadFromDatabase();
     ui->listWidget->addItem(xx);
    }
    databaseController.queriesCountToOne();

}

void Userentries::on_searchItemsWindow_clicked() /////// OK
{
          resultVar = ui->searchLine->text();
          if (resultVar.isEmpty()) {
              QMessageBox::information(this, "Error", "Pole wyszukiwania jest puste.");
          } else {
          QList<QListWidgetItem *> list = ui->listWidget->findItems((resultVar), Qt::MatchContains);
          for ( QListWidgetItem *item : list )
              item->setBackground(Qt::darkGreen);
          }
}



void Userentries::on_sortByNameButton_clicked()
{
    ui->listWidget->clear();
    int queries = databaseController.returnQueriesCount();
    for (int i=1; i<=queries; i++) {
    QString xx = databaseController.loadFromDatabaseByName();
     ui->listWidget->addItem(xx);
    }
    databaseController.queriesCountToOne();
    ui->listWidget->sortItems(Qt::AscendingOrder);
}


void Userentries::on_byName2_clicked()
{
    ui->listWidget->clear();
    int queries = databaseController.returnQueriesCount();
    for (int i=1; i<=queries; i++) {
    QString xx = databaseController.loadFromDatabaseByName();
     ui->listWidget->addItem(xx);
    }
    databaseController.queriesCountToOne();
    ui->listWidget->sortItems(Qt::DescendingOrder);
}


void Userentries::on_byPriority_clicked()
{
    ui->listWidget->clear();
    queries = databaseController.returnQueriesCount();
    for (int i=1; i<=queries; i++) {
    QString xx = databaseController.loadFromDatabaseByPriority();
     ui->listWidget->addItem(xx);
    }
    databaseController.queriesCountToOne();
    ui->listWidget->sortItems(Qt::DescendingOrder);
}


void Userentries::on_removeItemWindowButton_clicked() ////// OK
{
    oneElementWindow = new onelementwindow(this);
    oneElementWindow -> show();
}


void Userentries::closeEvent(QCloseEvent *event) ///////OK
{
    event->ignore();
    if (QMessageBox::Yes == QMessageBox::question(this, "Wyjście", "Czy na pewno chcesz wyjść?", QMessageBox::Yes | QMessageBox::No))
    {
        event->accept();
    }

}



void Userentries::on_searchRange_clicked()
{
firstNumber = ui->bID->text();
secondNumber = ui->bID2->text();
secondNumberInt = secondNumber.toInt();
firstNumberInt = firstNumber.toInt();
while (firstNumberInt<=secondNumberInt) {
    firstNumberInt++;
    IntIntQString = QVariant(firstNumberInt).toString();
QList<QListWidgetItem *> list = ui->listWidget->findItems((IntIntQString), Qt::MatchContains);
for ( QListWidgetItem *item : list ) {
    item->setBackground(Qt::darkGreen);
    break;
        }
    }
}



