#ifndef ROW_H
#define ROW_H
#include <QString>


class Row
{
public:
    Row();
    QString getName();
    QString getDate();
    QString getHours();
    QString getMinutes();
    bool getIsPriority();

    void setName(QString name);
    void setDate(QString date);
    void setHours(QString hours);
    void setMinutes(QString minutes);
    void setIsPriority(bool isPriority);
private:
    QString name;
    QString date;
    QString hours;
    QString minutes;
    bool isPriority;
};

#endif // ROW_H
