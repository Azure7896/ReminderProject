#ifndef CALENDARWINDOW_H
#define CALENDARWINDOW_H

#include <QDialog>

namespace Ui {
class calendarWindow;
}

class calendarWindow : public QDialog
{
    Q_OBJECT

public:
    explicit calendarWindow(QWidget *parent = nullptr);
    ~calendarWindow();

private slots:


    void on_pushButton_2_clicked();

private:
    Ui::calendarWindow *ui;
    calendarWindow *calendarwindow;
};

#endif // CALENDARWINDOW_H
