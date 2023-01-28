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
    user.setName(ui->register_login -> text());
    user.setPassword(ui -> register_password -> text());
    confirmPassword = ui -> confirm_password -> text();
    if (user.getName().isEmpty() || user.getName().size()>10){
        QMessageBox::information(this, " ", "Nie wprowadziłeś loginu, bądź login ma powyżej 10 znaków.");
    }

    else if (user.getPassword().size()>30 || user.getPassword().size()>30) {
        QMessageBox::information(this, " ", "Hasło jest zbyt długie.");
    }

    else if (user.getPassword() == confirmPassword) {
       databaseController.registerAccount(user);
       QMessageBox::information(this, " ", "Konto zostało zarejestrowane.");
       close();
    }

    else {

        QMessageBox::information(this, " ", "Hasła się od siebie różnią, spróbuj ponownie.");
    }

}




