#ifndef USERENTRIES_H
#define USERENTRIES_H

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

    void on_byID_clicked();

    void on_loadFromDatabaseButton_clicked();

    void on_searchItemsWindow_clicked();

    void on_sortByNameButton_clicked();

    void on_removeItemWindowButton_clicked();

    void on_addNewItemButton_clicked();

    void on_byName2_clicked();

    void on_byPriority_clicked();

    void on_searchRange_clicked();

    void connectionCheck();

    void on_loadAll_clicked();

private:

    QString priorityVarUI = "Ważne";
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
    int latestIDVarIntUI;
    int hoursVarIntUI;
    int minutesVarIntUI;
    int queries;
    QString firstNumber;
    QString secondNumber;
    int firstNumberInt;
    int secondNumberInt;
    int numberCount;
    int IntInt;
    QString IntIntQString;
};


#endif // USERENTRIES_H
