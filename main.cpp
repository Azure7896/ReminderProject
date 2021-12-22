#include "mainwindow.h"

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication Reminder(argc, argv);

    MainWindow w;
    w.show();
    return Reminder.exec();
}
