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
//    QVector<Record> queryAllRecord();

    Account queryAccount(const QString& name);
    Book queryBook(const QString& name);
    Record queryRecord(const QString& name);

    bool insertAccount(const Account& account);
    bool updateAccount(const Account& account);
    bool deleteAccount(const QString& name);

    bool insertBook(const Book& book);
    bool updateBook(const Book& book);
    bool deleteBook(const QString& name);

    bool insertRecord(const Record& record);

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
};

#endif // DATABASE_H
