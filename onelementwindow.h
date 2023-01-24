#ifndef ONELEMENTWINDOW_H
#define ONELEMENTWINDOW_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSql>
#include <database.h>



namespace Ui {
class onelementwindow;
}

class onelementwindow : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit onelementwindow(QWidget *parent = nullptr);
    ~onelementwindow();

private slots:
    void on_beforeButton_clicked();

    void on_nextButton_clicked();

    void on_pushButton_clicked();

    void on_deleteAll_clicked();

private:
    Ui::onelementwindow *ui;
    int idNumber = 0;
    QString countString;
    QString numberString;
    QString dbResult;
    DataBase databaseController;
};

#endif // ONELEMENTWINDOW_H
