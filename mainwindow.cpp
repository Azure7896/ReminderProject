#include "mainwindow.h"

#include "ui_mainwindow.h"
#include "user.h"

#include <QMessageBox>

#include <QResource>

#include <QDesktopServices>


MainWindow::MainWindow(QWidget * parent): QMainWindow(parent), ui(new Ui::MainWindow) {
  ui -> setupUi(this);
  //Windows flags and resolution settings
  QResource::registerResource(":/new/prefix1/");
  this -> setFixedSize((QSize(480, 640)));
  this -> setWindowTitle("ReminderProject by Szymon Napora 5ION");
  connectionCheck();
}

MainWindow::~MainWindow() {
  delete ui;
}

//Checking connection - when connection to the DB isn't working, apllication will be close
void MainWindow::connectionCheck() {
    if (!databaseController.createConnection()) {
        QMessageBox::information(this, "Problem z bazą danych", "Sprawdź czy plik SQLite istnieje i znajduje się w odpowiednim katalogu");
        QApplication::quit();
    }
}

//Logging and checking credentials
void MainWindow::on_loginButton_clicked() {
  username = ui -> login_line -> text();
  password = ui -> password_line -> text();
  //Tutaj skonczylem nie dziala klasa User
  QString test = user.getPassword();
  //databaseController.login(user)
  if (true) {
      QMessageBox::information(this, "Witaj w ReminderProject!", "Zalogowano pomyślnie. Naciśnij OK, aby kontyunować.");
      hide();
      UserEntries = new Userentries(this);
      UserEntries -> show();
    } else {
      QMessageBox::information(this, "Błędne poświadczenia", "Błędna nazwa użytkownika bądź hasło");
    }
}

//Open register window
void MainWindow::on_registerButton_clicked()
{
  RegisterWindow = new registerwindow(this);
  RegisterWindow -> show();
}

//Open bottom url
void MainWindow::on_external_link_clicked()
{
  QDesktopServices::openUrl(QUrl("https://gradienta.io/"));
}
