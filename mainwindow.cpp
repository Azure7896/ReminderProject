#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap background ("C:/Users/Azure/Desktop/background.jpg");
    ui->main_window_background->setPixmap(background);
    this->setFixedSize((QSize(480,640)));


}


MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_loginButton_clicked()
{
    QString username = ui->lineEdit -> text();
    QString password = ui->lineEdit_2 -> text();
        if (username== "szymon.napora" && password=="12345"){
            QMessageBox::information(this, "Login", "Logowanie zakończono pomyślnie");
            hide();
            UserEntries = new Userentries(this);
            UserEntries -> show();
        }

        else {
                QMessageBox::information(this, "Login", "Dane niepoprawne, spróbuj ponownie");
        }

}



void MainWindow::on_registerButton_clicked()
{
    RegisterWindow = new registerwindow(this);
    RegisterWindow -> show();
}

