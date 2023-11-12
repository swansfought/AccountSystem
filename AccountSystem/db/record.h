#ifndef RECORD_H
#define RECORD_H

#include <QString>
#include <QDateTime>
#include <QByteArray>

class Record
{
public:
    Record();
    ~Record();

    QString getAccountName() const;
    void setAccountName(const QString &newAccountName);

    QString getBookName() const;
    void setBookName(const QString &newBookName);

    QDateTime getRecordTime() const;
    void setRecordTime(const QDateTime &newRecordTime);

    QString getFlowType() const;
    void setFlowType(const QString &newFlowType);

    QString getFirstClassify() const;
    void setFirstClassify(const QString &newFirstClassify);

    QString getSecondClassify() const;
    void setSecondClassify(const QString &newSecondClassify);

    QString getTransferIn() const;
    void setTransferIn(const QString &newTransferIn);

    qreal getMoney() const;
    void setMoney(qreal newMoney);

    QString getRemark() const;
    void setRemark(const QString &newRemark);

    QByteArray getImage() const;
    void setImage(const QByteArray &newImage);

private:
    QString accountName;
    QString bookName;
    QDateTime recordTime;
    QString flowType;
    QString firstClassify;
    QString secondClassify;
    QString transferIn;
    qreal money;
    QString remark;
    QByteArray image;
};

#endif // RECORD_H
