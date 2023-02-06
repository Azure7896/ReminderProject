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

    void on_Wyloguj_clicked();

private:
    Ui::Userentries *ui;
    void connectionCheck();
    DataBase databaseController;
    bool checkboxStatus;
    onelementwindow *oneElementWindow;
    QString time;
    Row row;
    date date;
    bool withActualDate;
    int activeUserId;
};


#endif // USERENTRIES_H
