#include "registerwindow.h"
#include "ui_registerwindow.h"
#include <QResource>
#include <QMessageBox>


registerwindow::registerwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerwindow)
{
    ui->setupUi(this);
    QResource::registerResource(":/new/prefix1/");
    this->setFixedSize((QSize(480,500)));
    QMessageBox::information(this, "Rejestracja wyłączona", "Rejestracja jest wyłączona. Proszę zalogować się danymi podanymi w instrukcji obsługi.");
    hide();

}

registerwindow::~registerwindow()
{
    delete ui;
}

void registerwindow::on_registerbutton_clicked()
{
    QString registerLogin = ui->register_login-> text();
    QString registerPassword = ui->register_password-> text();
    QString confirmPassword = ui -> confirm_password-> text();
    QMessageBox::information(this, "Rejestracja wyłączona", "Rejestracja jest wyłączona. Zostanie dodana w przyszłości.");
    close();

    /*
    if (registerLogin.isEmpty() || registerLogin.size()>10){
        QMessageBox::information(this, " ", "Nie wprowadziłeś loginu, bądź login ma powyżej 10 znaków.");
        ///////////////////////////
    }
    else if (registerPassword.size()>30 || confirmPassword.size()>30) {
        QMessageBox::information(this, " ", "Hasło jest zbyt długie.");
    }

    else if (registerPassword == confirmPassword) {
       QMessageBox::information(this, " ", "Konto zostało zarejestrowane.");
            close();
    }

    else {

            QMessageBox::information(this, " ", "Hasła się od siebie różnią, spróbuj ponownie.");
    }
    */

}




