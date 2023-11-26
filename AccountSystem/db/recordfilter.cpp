#include "recordfilter.h"

RecordFilter::RecordFilter()
{

}

RecordFilter::~RecordFilter()
{

}

QString RecordFilter::getInput() const
{
    return input;
}

void RecordFilter::setInput(const QString &newInput)
{
    input = newInput;
}


QString RecordFilter::getFlowType() const
{
    return flowType;
}

void RecordFilter::setFlowType(const QString &newFlowType)
{
    flowType = newFlowType;
}

QString RecordFilter::getDateType() const
{
    return dateType;
}

void RecordFilter::setDateType(const QString &newDateType)
{
    dateType = newDateType;
}

QDate RecordFilter::getDate() const
{
    return date;
}

void RecordFilter::setDate(const QDate &newDate)
{
    date = newDate;
}
