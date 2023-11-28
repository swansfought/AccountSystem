#include "book.h"

Book::Book()
{
    totalIncome = 0;
    totalExpend = 0;
    totalRecord = 0;
    enable = true;
    top = false;
    serial = 0;
    top = false;
}

Book::~Book()
{

}

QString Book::getName() const
{
    return name;
}

void Book::setName(const QString &newName)
{
    name = newName;
}

qreal Book::getTotalIncome() const
{
    return totalIncome;
}

void Book::setTotalIncome(qreal newTotalIncome)
{
    totalIncome = newTotalIncome;
}

qreal Book::getTotalExpend() const
{
    return totalExpend;
}

void Book::setTotalExpend(qreal newTotalExpend)
{
    totalExpend = newTotalExpend;
}

QString Book::getRemark() const
{
    return remark;
}

void Book::setRemark(const QString &newRemark)
{
    remark = newRemark;
}

QDateTime Book::getCreateTime() const
{
    return createTime;
}

void Book::setCreateTime(const QDateTime &newCreateTime)
{
    createTime = newCreateTime;
}

int Book::getTotalRecord() const
{
    return totalRecord;
}

void Book::setTotalRecord(int newTotalRecord)
{
    totalRecord = newTotalRecord;
}

bool Book::getEnable() const
{
    return enable;
}

void Book::setEnable(bool newEnable)
{
    enable = newEnable;
}

int Book::getSerial() const
{
    return serial;
}

void Book::setSerial(int newSerial)
{
    serial = newSerial;
}

bool Book::getTop() const
{
    return top;
}

void Book::setTop(bool newTop)
{
    top = newTop;
}
