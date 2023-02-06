#include "printer.h"
#include "qsqlquerymodel.h"

Printer::Printer()
{

}

void printRecords(QSqlQueryModel queryModel) {

        QPrinter printer;
        QPrintDialog *dialog = new QPrintDialog(&printer);
        if(dialog->exec() == QDialog::Accepted) {
            QTextDocument document;
            document.setHtml(html);
            document.print(&printer);
        }
}
