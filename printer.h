#ifndef PRINTER_H
#define PRINTER_H

#include <qprintdialog.h>
#include <qtableview.h>
#include <QPrinter>
#include <QTextDocument>

class Printer
{
public:
    Printer();
    void printRecords(QTableView tableView);
};

#endif // PRINTER_H
