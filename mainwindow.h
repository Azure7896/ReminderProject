#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <userentries.h>
#include <registerwindow.h>
#include <database.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
 void on_loginButton_clicked();
 void on_registerButton_clicked();
 void on_external_link_clicked();

private:
    Ui::MainWindow *ui;
    Userentries *UserEntries;
    registerwindow *RegisterWindow;
    QString username;
    QString password;
    DataBase databaseController;
    User user;
    void connectionCheck();
};
#endif // MAINWINDOW_H
