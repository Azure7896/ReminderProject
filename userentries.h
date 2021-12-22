#ifndef USERENTRIES_H
#define USERENTRIES_H

#include <QDialog>
#include <calendarwindow.h>
#include <QTimer>
namespace Ui {
class Userentries;
}

class Userentries : public QDialog
{
    Q_OBJECT

public:
    explicit Userentries(QWidget *parent = nullptr);
    ~Userentries();
    void clock();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Userentries *ui;
    calendarWindow *CalendarWindow;
    QTimer *clock_timer;


};

#endif // USERENTRIES_H
