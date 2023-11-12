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
    bool connectDB();

//    QVector<Record> queryAccount();
//    QVector<Record> queryBook();
//    QVector<Record> queryRecord();
    QVector<Account> queryAllAccount();
    QVector<Book> queryAllBook();
    QVector<Record> queryAllRecord();


private:
    DataBase();
    ~DataBase();
    DataBase(const DataBase&) = delete;
    DataBase& operator=(const DataBase&) = delete;

    static QMutex mutex;
    static DataBase* instance;


    bool connectState;
    QSqlDatabase db;
};

#endif // DATABASE_H
