#ifndef DATABASE_H
#define DATABASE_H

#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMutex>
#include <QMessageBox>
#include <QDateTime>
#include <QFile>
#include <QDir>
#include <QVector>

#include <QDebug>
#include "db/record.h"
#include "db/account.h"
#include "db/recordfilter.h"
#include "db/book.h"
#include "global.h"

class DataBase
{
public:
    static DataBase* getInstance();
    bool connect();
    void disconnect();

    QVector<Account> queryAllAccount();
    QVector<Book> queryAllBook();

    void queryLimitRecord(QSqlQuery& query, const int& start,const int& end);
    void queryLimitRecord(QSqlQuery& query, const int& start,const int& end, const RecordFilter& filter);

    int queryRecordRows();
    int queryRecordRows(const QString& bookName);

    Account queryAccount(const QString& name);
    Book queryBook(const QString& name);
    Record queryRecord(const QString& name);

    qreal queryTotalFund();
    qreal queryMonthIncome();
    qreal queryMonthExpend();

    bool insertAccount(const Account& account);
    bool updateAccount(const Account& account);
    bool deleteAccount(const QString& name);

    bool insertBook(const Book& book);
    bool updateBook(const Book& book);
    bool deleteBook(const QString& name);

    bool insertRecord(const Record& record);

    int getMaxPages(const double& numOfPage);

private:
    DataBase();
    ~DataBase();
    DataBase(const DataBase&) = delete;
    DataBase& operator=(const DataBase&) = delete;

    void checkConnect();

    static QMutex mutex;
    static DataBase* instance;

    bool connectState;
    QSqlDatabase db;

    int record_start_index;
    int record_end_index;
};

#endif // DATABASE_H
