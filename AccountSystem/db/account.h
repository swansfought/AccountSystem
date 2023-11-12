#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>
#include <QDateTime>

class Account
{
public:
    Account();
    ~Account();

    QString getName() const;
    void setName(const QString &newName);

    qreal getFund() const;
    void setFund(qreal newFund);

    QString getNickname() const;
    void setNickname(const QString &newNickname);

    QString getCardNumber() const;
    void setCardNumber(const QString &newCardNumber);

    QString getRemark() const;
    void setRemark(const QString &newRemark);

    QDateTime getCreateTime() const;
    void setCreateTime(const QDateTime &newCreateTime);

private:
    QString name;
    qreal fund;
    QString nickname;
    QString cardNumber;
    QString remark;
    QDateTime createTime;
};

#endif // ACCOUNT_H
