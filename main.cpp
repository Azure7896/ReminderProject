#include "startlogo.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication Reminder(argc, argv);

    startlogo w;
    w.show();
    return Reminder.exec();
}
