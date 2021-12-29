#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QResource>
#include <QDesktopServices>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QResource::registerResource(":/new/prefix1/");
    this->setFixedSize((QSize(480,640)));



}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loginButton_clicked() //Checking credentials
{
    QString username = ui->login_line -> text();
    QString password = ui->password_line-> text();
        if (username== "szymon.napora" && password=="12345"){
            QMessageBox::information(this, " ", "Zalogowano pomyślnie. Naciśnij OK, aby kontyunować.");
            hide();
            UserEntries = new Userentries(this);
            UserEntries -> show();
        }

        else {

                QMessageBox::information(this, " ", "Wprowadziłeś błędny login lub hasło. Spróbuj ponownie.");
        }

}



void MainWindow::on_registerButton_clicked() //Openening register window
{
    RegisterWindow = new registerwindow(this);
    RegisterWindow -> show();
}




void MainWindow::on_external_link_clicked() //Open site in browser
{
    QDesktopServices::openUrl(QUrl("https://gradienta.io/"));
}

