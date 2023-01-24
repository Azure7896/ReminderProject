#ifndef STARTLOGO_H
#define STARTLOGO_H

#include <QDialog>
#include <mainwindow.h>


namespace Ui {
class startlogo;
}

class startlogo : public QDialog
{
    Q_OBJECT

public:
    explicit startlogo(QWidget *parent = nullptr);
    ~startlogo();

private slots:
    void on_start_button_clicked();

private:
    Ui::startlogo *ui;
    MainWindow *mainwindow;
};

#endif // STARTLOGO_H
