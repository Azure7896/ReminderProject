#include "registerwindow.h"
#include "ui_registerwindow.h"
#include <QResource>
#include <QMessageBox>


registerwindow::registerwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerwindow)
{
    ui->setupUi(this);
    this -> setWindowTitle("Rejestracja");
    this->setFixedSize((QSize(480,500)));
    connectionCheck();
}

registerwindow::~registerwindow()
{
    delete ui;
}

void registerwindow::connectionCheck() {
    if (!databaseController.createConnection()) {
        QMessageBox::information(this, "Problem z bazą danych", "Sprawdź czy plik SQLite istnieje i znajduje się w odpowiednim katalogu");
        QApplication::quit();
    }
}

void registerwindow::on_registerbutton_clicked()
{
    QString registerLogin = ui->register_login-> text();
    QString registerPassword = ui->register_password-> text();
    QString confirmPassword = ui -> confirm_password-> text();

    if (registerLogin.isEmpty() || registerLogin.size()>10){
        QMessageBox::information(this, " ", "Nie wprowadziłeś loginu, bądź login ma powyżej 10 znaków.");

    }
    else if (registerPassword.size()>30 || confirmPassword.size()>30) {
        QMessageBox::information(this, " ", "Hasło jest zbyt długie.");
    }

    else if (registerPassword == confirmPassword) {
       databaseController.registerAccount(registerLogin, registerPassword);
       QMessageBox::information(this, " ", "Konto zostało zarejestrowane.");
           //close();
    }

    else {

            QMessageBox::information(this, " ", "Hasła się od siebie różnią, spróbuj ponownie.");
    }

}




