#ifndef PRINTER_H
#define PRINTER_H


class Printer
{
public:
    Printer();
    void printRecords(QSqlQueryModel queryModel);
};

#endif // PRINTER_H
