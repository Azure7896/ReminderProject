#ifndef USERENTRIES_H
#define USERENTRIES_H

#include "row.h"
#include <QDialog>
#include <QSqlDatabase>
#include <QSql>
#include <onelementwindow.h>
#include <database.h>
#include <search.h>





namespace Ui {
class Userentries;
}

class Userentries : public QDialog
{
    Q_OBJECT

public:
    explicit Userentries(QWidget *parent = nullptr);
    ~Userentries();
private slots:

    void closeEvent(QCloseEvent* event);

    void on_removeItemWindowButton_clicked();

    void on_addNewItemButton_clicked();


    void on_loadAll_clicked();

    void on_byDesc_clicked();

    void on_sortByNameButton_clicked();

    void on_search_clicked();

    void on_byPriority_clicked();

private:
    void connectionCheck();
    QString const priorityVarUI = "Ważne";
    DataBase databaseController;
    Ui::Userentries *ui;
    QString nameVarUI;
    QString dateVarUI;
    QString hoursVarUI;
    QString minutesVarUI;
    bool checkboxStatus;
    int hoursFromDatabaseInt;
    int minutesFromDatabaseInt;
    QString latestIDVarUI;
    QString idFromDatabase;
    QString resultVar;
    onelementwindow *oneElementWindow;
    QString firstNumber;
    QString secondNumber;
    int firstNumberInt;
    int secondNumberInt;
    int numberCount;
    QString time;
    Row row;
};


#endif // USERENTRIES_H
