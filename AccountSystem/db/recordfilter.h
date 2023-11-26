#ifndef RECORDFILTER_H
#define RECORDFILTER_H

#include <QString>
#include <QDateTime>

class RecordFilter
{
public:
    RecordFilter();
    ~RecordFilter();

    QString getInput() const;
    void setInput(const QString &newInput);

    QString getFlowType() const;
    void setFlowType(const QString &newFlowType);

    QString getDateType() const;
    void setDateType(const QString &newDateType);

    QDate getDate() const;
    void setDate(const QDate &newDate);

private:
    QString input;
    QString dateType;
    QDate date;
    QString flowType;

};

#endif // RECORDFILTER_H
