#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QResource>
#include <QDesktopServices>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QResource::registerResource(":/new/prefix1/");
    this->setFixedSize((QSize(480,640)));
    this->setWindowTitle("ReminderProject by Szymon Napora 3DZI");
    databaseController.createConnection();

 }


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loginButton_clicked() //Checking credentials
{
    username = ui->login_line -> text();
    password = ui->password_line-> text();
    isTrue = databaseController.login(username, password);
           if (isTrue=="true") {
               QMessageBox::information(this, " ", "Zalogowano pomyślnie. Naciśnij OK, aby kontyunować.");
               hide();
               UserEntries = new Userentries(this);
               UserEntries -> show();
           }
            else {
               QMessageBox::information(this, "Błąd ", "Błędna nazwa użytkownika bądź hasło");
           }
       }



void MainWindow::on_registerButton_clicked() //Openening register window
{
    RegisterWindow = new registerwindow(this);
    RegisterWindow -> show();    
    QMessageBox::information(this, "Rejestracja wyłączona", "Rejestracja jest wyłączona. Proszę zalogować się danymi podanymi w instrukcji obsługi.");
}




void MainWindow::on_external_link_clicked() //Open site in browser
{
    QDesktopServices::openUrl(QUrl("https://gradienta.io/"));
}


