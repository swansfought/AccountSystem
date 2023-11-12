#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <QDateTime>

class Book
{
public:
    Book();
    ~Book();

    QString getName() const;
    void setName(const QString &newName);

    qreal getTotalIncome() const;
    void setTotalIncome(qreal newTotalIncome);

    qreal getTotalExpend() const;
    void setTotalExpend(qreal newTotalExpend);

    QString getRemark() const;
    void setRemark(const QString &newRemark);

    QDateTime getCreateTime() const;
    void setCreateTime(const QDateTime &newCreateTime);

    int getTotalRecord() const;
    void setTotalRecord(int newTotalRecord);

private:
    QString name;
    qreal totalIncome;
    qreal totalExpend;
    int totalRecord;
    QString remark;
    QDateTime createTime;

};

#endif // BOOK_H
