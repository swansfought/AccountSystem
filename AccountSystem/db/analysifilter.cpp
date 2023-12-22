#include "analysifilter.h"

AnalysiFilter::AnalysiFilter()
{
    dateEnable = true;
    textEnable = true;

    startDate = QDate::currentDate();
    endDate = QDate::currentDate();
    book = "";
    flowType = "";
    account = "";
    account_in = "";
    firstClassify = "";
    secondClassify = "";
}

AnalysiFilter::~AnalysiFilter()
{

}

bool AnalysiFilter::getDateEnable() const
{
    return dateEnable;
}

void AnalysiFilter::setDateEnable(bool newDateEnable)
{
    dateEnable = newDateEnable;
}

bool AnalysiFilter::getTextEnable() const
{
    return textEnable;
}

void AnalysiFilter::setTextEnable(bool newTextEnable)
{
    textEnable = newTextEnable;
}

QDate AnalysiFilter::getStartDate() const
{
    return startDate;
}

void AnalysiFilter::setStartDate(const QDate &newStartDate)
{
    startDate = newStartDate;
}

QDate AnalysiFilter::getEndDate() const
{
    return endDate;
}

void AnalysiFilter::setEndDate(const QDate &newEndDate)
{
    endDate = newEndDate;
}

QString AnalysiFilter::getBook() const
{
    if(book.isEmpty())
        return "?";
    return book;
}

void AnalysiFilter::setBook(const QString &newBook)
{
    book = newBook;
}

QString AnalysiFilter::getFlowType() const
{
    if(flowType.isEmpty())
        return "?";
    return flowType;
}

void AnalysiFilter::setFlowType(const QString &newFlowType)
{
    flowType = newFlowType;
}

QString AnalysiFilter::getAccount() const
{
    if(account.isEmpty())
        return "?";
    return account;
}

void AnalysiFilter::setAccount(const QString &newAccount)
{
        account = newAccount;
}

QString AnalysiFilter::getAccount_in() const
{
    if(account_in.isEmpty())
        return "?";
    return account_in;
}

void AnalysiFilter::setAccount_in(const QString &newAccount_in)
{
   account_in = newAccount_in;
}

QString AnalysiFilter::getFirstClassify() const
{
   if(firstClassify.isEmpty())
        return "?";
    return firstClassify;
}

void AnalysiFilter::setFirstClassify(const QString &newFirstClassify)
{
    firstClassify = newFirstClassify;
}

QString AnalysiFilter::getSecondClassify() const
{
    if(secondClassify.isEmpty())
        return "?";
    return secondClassify;
}

void AnalysiFilter::setSecondClassify(const QString &newSecondClassify)
{
    secondClassify = newSecondClassify;
}
