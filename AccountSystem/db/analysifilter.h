#ifndef ANALYSIFILTER_H
#define ANALYSIFILTER_H

#include <QString>
#include <QDate>

class AnalysiFilter
{
public:
    AnalysiFilter();
    ~AnalysiFilter();

    bool getDateEnable() const;
    void setDateEnable(bool newDateEnable);

    bool getTextEnable() const;
    void setTextEnable(bool newTextEnable);

    QDate getStartDate() const;
    void setStartDate(const QDate &newStartDate);

    QDate getEndDate() const;
    void setEndDate(const QDate &newEndDate);

    QString getBook() const;
    void setBook(const QString &newBook);

    QString getFlowType() const;
    void setFlowType(const QString &newFlowType);

    QString getAccount() const;
    void setAccount(const QString &newAccount);

    QString getAccount_in() const;
    void setAccount_in(const QString &newAccount_in);

    QString getFirstClassify() const;
    void setFirstClassify(const QString &newFirstClassify);

    QString getSecondClassify() const;
    void setSecondClassify(const QString &newSecondClassify);

private:
    bool dateEnable;
    bool textEnable;

    QDate startDate;
    QDate endDate;
    QString book;
    QString flowType;
    QString account;
    QString account_in;
    QString firstClassify;
    QString secondClassify;

};

#endif // ANALYSIFILTER_H
