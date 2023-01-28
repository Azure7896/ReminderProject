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

//Checking database connection, when it's not working, program will be closed
void MainWindow::connectionCheck() {
    if (!databaseController.createConnection()) {
        QMessageBox::information(this, "Problem z bazą danych", "Sprawdź czy plik SQLite istnieje i znajduje się w odpowiednim katalogu");
        QApplication::quit();
    }
}

//Logging and checking credentials
void MainWindow::on_loginButton_clicked() {
  user.setName(ui->login_line -> text());
  user.setPassword(ui->password_line -> text());
  if (databaseController.login(user)) {
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
