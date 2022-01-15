#ifndef USERENTRIES_H
#define USERENTRIES_H

#include <QDialog>
#include <calendarwindow.h>



namespace Ui {
class Userentries;
}

class Userentries : public QDialog
{
    Q_OBJECT

public:
    explicit Userentries(QWidget *parent = nullptr);
    ~Userentries();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Userentries *ui;
    calendarWindow *CalendarWindow;


};

#endif // USERENTRIES_H
