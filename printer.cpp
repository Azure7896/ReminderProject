#include "printer.h"


Printer::Printer()
{

}

void Printer::printRecords(QTableView tableView) {

//    const QString format("<td>%1</td>");
//       QString html;
//       QAbstractItemModel *md = tableView.model();
//       html = "<html><body><table border=\"0\">";

//       html += "<td></td>";
//       for(int column = 0; column < md->columnCount();
//           column++) {
//           QString data = md->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
//           html += format.arg(data);
//       }
//       for(int row = 0; row < md->rowCount() ; row++) {
//           html += "<tr>";
//           QString data = md->headerData(row, Qt::Vertical, Qt::DisplayRole).toString();
//           html += format.arg(data);
//           for(int column = 0; column < md->columnCount();
//               column++) {
//               QString data = md->index(row, column).data(Qt::DisplayRole).toString();
//               html += format.arg(data);
//           }
//           html += "</tr>";
//       }
//       html += "</table></body></html>";

//       QPrinter printer;
//       QPrintDialog *dialog = new QPrintDialog(&printer);
//       if(dialog->exec() == QDialog::Accepted) {
//           QTextDocument document;
//           document.setHtml(html);
//           document.print(&printer);
//       }
}
