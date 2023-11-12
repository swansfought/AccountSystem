#include "account.h"

Account::Account()
{

}

Account::~Account()
{

}

QString Account::getName() const
{
    return name;
}

void Account::setName(const QString &newName)
{
    name = newName;
}

qreal Account::getFund() const
{
    return fund;
}

void Account::setFund(qreal newFund)
{
    fund = newFund;
}

QString Account::getNickname() const
{
    return nickname;
}

void Account::setNickname(const QString &newNickname)
{
    nickname = newNickname;
}

QString Account::getCardNumber() const
{
    return cardNumber;
}

void Account::setCardNumber(const QString &newCardNumber)
{
    cardNumber = newCardNumber;
}

QString Account::getRemark() const
{
    return remark;
}

void Account::setRemark(const QString &newRemark)
{
    remark = newRemark;
}

QDateTime Account::getCreateTime() const
{
    return createTime;
}

void Account::setCreateTime(const QDateTime &newCreateTime)
{
    createTime = newCreateTime;
}
