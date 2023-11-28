#include "record.h"

Record::Record()
{
    id = 0;
    bookName = "";
    flowType = "";
    accountName = "";
    transferIn = "";
    firstClassify = "";
    secondClassify = "";
    money = 0;
    remark = "";
}

Record::~Record()
{

}

QString Record::getAccountName() const
{
    return accountName;
}

void Record::setAccountName(const QString &newAccountName)
{
    accountName = newAccountName;
}

QString Record::getBookName() const
{
    return bookName;
}

void Record::setBookName(const QString &newBookName)
{
    bookName = newBookName;
}

QString Record::getRecordTime() const
{
    return recordTime;
}

void Record::setRecordTime(const QString &newRecordTime)
{
    recordTime = newRecordTime;
}

QString Record::getFlowType() const
{
    return flowType;
}

void Record::setFlowType(const QString &newFlowType)
{
    flowType = newFlowType;
}

QString Record::getFirstClassify() const
{
    return firstClassify;
}

void Record::setFirstClassify(const QString &newFirstClassify)
{
    firstClassify = newFirstClassify;
}

QString Record::getSecondClassify() const
{
    return secondClassify;
}

void Record::setSecondClassify(const QString &newSecondClassify)
{
    secondClassify = newSecondClassify;
}

QString Record::getTransferIn() const
{
    return transferIn;
}

void Record::setTransferIn(const QString &newTransferIn)
{
    transferIn = newTransferIn;
}

qreal Record::getMoney() const
{
    return money;
}

void Record::setMoney(qreal newMoney)
{
    money = newMoney;
}

QString Record::getRemark() const
{
    return remark;
}

void Record::setRemark(const QString &newRemark)
{
    remark = newRemark;
}

QByteArray Record::getImage() const
{
    return image;
}

void Record::setImage(const QByteArray &newImage)
{
    image = newImage;
}

int Record::getId() const
{
    return id;
}

void Record::setId(int newId)
{
    id = newId;
}
