#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include "database.h"
#include <QDialog>

namespace Ui {
class registerwindow;
}

class registerwindow : public QDialog
{
    Q_OBJECT

public:
    void connectionCheck();
    explicit registerwindow(QWidget *parent = nullptr);
    ~registerwindow();
private slots:
    void on_registerbutton_clicked();
private:
    Ui::registerwindow *ui;
    DataBase databaseController;
    QString registerLogin;
    QString registerPassword;
    QString confirmPassword;
    User user;
};

#endif // REGISTERWINDOW_H
