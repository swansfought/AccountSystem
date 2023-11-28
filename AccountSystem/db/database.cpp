#include "database.h"

QMutex DataBase::mutex;
DataBase* DataBase::instance = nullptr;

DataBase *DataBase::getInstance()
{
    if(nullptr == instance){
        QMutexLocker locker(&mutex);
        if(nullptr == instance)
            instance = new DataBase;
    }
    return instance;
}

bool DataBase::connect()
{
    if(connectState)
        return connectState;

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DB_FILE_PATH);
    if(db.open()){
        connectState = true;

        //创建表
        QStringList tables = db.tables(QSql::Tables);
        QSqlQuery query;
        QString sql;
        if(!tables.contains("account")){
            sql = "CREATE TABLE account( "
                                "id INTEGER PRIMARY KEY AUTOINCREMENT," // -- '自增id'
                                "act_name VARCHAR(20) UNIQUE NOT NULL," //------账户名称 唯一------
                                "act_fund REAL DEFAULT 0," // --账户金额
                                "act_nickname VARCHAR(20) DEFAULT NULL," // --账户别称
                                "act_cardnumber VARCHAR(30) DEFAULT NULL," // --账户卡号
                                "act_remark text DEFAULT NULL," // --账户备注
                                "act_enable bool default 1,"
                                "act_serial int default 0,"
                                "act_top bool default 0,"
                                "act_datetime DATETIME DEFAULT (datetime('now','localtime')) );"; //--创建时间
            query.exec(sql);

            //添加默认账户
            sql = "insert into account(act_name,act_remark) values('默认账户','此账户为系统自带的账户。');";
            query.exec(sql);
        }
        if(!tables.contains("book")){
            sql = "CREATE TABLE book( "
                                "id INTEGER PRIMARY KEY AUTOINCREMENT," // -- '自增id'
                                "bok_name VARCHAR(20) UNIQUE NOT NULL," // ------账本名称 唯一------
                                "bok_totalincome REAL DEFAULT 0," // --共计收入
                                "bok_totalexpend REAL DEFAULT 0," // --共计支出
                                "bok_remark text DEFAULT NULL," // --账本备注
                                "bok_enable bool default 1,"
                                "bok_serial int default 0,"
                                "bok_top bool default 0,"
                                "bok_datetime DATETIME DEFAULT (datetime('now','localtime')) );"; // --创建时间
            query.exec(sql);

            //添加默认账本
            sql = "insert into book(bok_name,bok_remark) values('默认账本','此账本为系统自带的账本。');";
            query.exec(sql);
        }
        if(!tables.contains("record")){
            sql = "CREATE TABLE record( "
                                "id INTEGER PRIMARY KEY AUTOINCREMENT," //
                                "act_name VARCHAR(20) NOT NULL," // ------账户名称------
                                "bok_name VARCHAR(20) NOT NULL," // ------账本名称-----
                                "red_datetime DATETIME NOT NULL," // --记账日期
                                "red_flow_type VARCHAR(10) NOT NULL," // --收支流向
                                "red_first_classify VARCHAR(10) NOT NULL," // --一级分类
                                "red_second_classify VARCHAR(10) NOT NULL," // --二级分类
                                "red_transfer_in VARCHAR(20) DEFAULT NULL," // ---转入账户
                                "red_money REAL NOT NULL," // --收支金额
                                "red_remark TEXT DEFAULT NULL," // --备注
                                "red_image BLOB DEFAULT NULL," // --图片
                                "FOREIGN KEY(act_name) REFERENCES account(act_name) ON DELETE CASCADE ON UPDATE CASCADE," // ------级联删除&更新------
                                "FOREIGN KEY(bok_name) REFERENCES book(bok_name) ON DELETE CASCADE ON UPDATE CASCADE);"; //------级联删除&更新-------
            query.exec(sql);
        }
        qDebug()<< QString("%1数据库连接成功...").arg(LOG_DATETIME);
    }else{
        connectState = false;
        qDebug()<< QString("%1数据库连接失败...").arg(LOG_DATETIME);
    }
    return connectState;
}

void DataBase::disconnect()
{
    db.close();
    qDebug()<< QString("%1数据库断开连接...").arg(LOG_DATETIME);
}

QVector<Account> DataBase::queryAllAccount()
{
    checkConnect(); //检查数据库连接
    QVector<Account> vec;

    Record record;
    QSqlQuery query;
    QString sql = "select * from account order by act_serial;";
    if(query.exec(sql)){
        while (query.next()) {
            Account account;
            account.setName(query.value("act_name").toString());
            account.setFund(query.value("act_fund").toDouble());
            account.setNickname(query.value("act_nickname").toString());
            account.setCardNumber(query.value("act_cardnumber").toString());
            account.setRemark(query.value("act_remark").toString());
            account.setEnable(query.value("act_enable").toBool());
            account.setCreateTime(query.value("act_datetime").toDateTime());
            account.setSerial(query.value("act_serial").toInt());
            account.setTop(query.value("act_top").toBool());
            vec.append(account);
        }
    }
    return vec;
}

QVector<Book> DataBase::queryAllBook()
{
    checkConnect(); //检查数据库连接
    QVector<Book> vec;

    Record record;
    QString sql,subSql;
    QSqlQuery query,subQuery;

    sql = "select * from book order by bok_serial;";
    if(query.exec(sql)){
        while (query.next()) {
            Book book;
            book.setName(query.value("bok_name").toString());
            book.setTotalIncome(query.value("bok_totalincome").toDouble());
            book.setTotalExpend(query.value("bok_totalexpend").toDouble());
            book.setRemark(query.value("bok_remark").toString());
            book.setEnable(query.value("bok_enable").toBool());
            book.setCreateTime(query.value("bok_datetime").toDateTime());
            book.setSerial(query.value("bok_serial").toInt());
            book.setTop(query.value("bok_top").toBool());

            // 拿到该账本的总记录数
            subSql = QString("select count (*) from record where bok_name='%1';").arg(query.value("bok_name").toString());
            if(subQuery.exec(subSql) && subQuery.next()){
                book.setTotalRecord(subQuery.value(0).toInt());
            }else{
                book.setTotalRecord(0);
            }
            vec.append(book);
        }
    }
    return vec;
}

void DataBase::queryLimitRecord(QSqlQuery& query, const int &start, const int &end)
{
    if(start < 0 || end < 0 || end < start)
        return;
    QString sql = QString("select * from record "
                          "order by red_datetime desc "
                          "limit %1,%2;").arg(QString::number(start),QString::number(end));
//    qDebug()<<sql;
    query.exec(sql);
}

void DataBase::queryLimitRecord(QSqlQuery& query, const int &start, const int &end, const RecordFilter& filter)
{
    if(start < 0 || end < 0 || end < start)
        return;

    QString condition_date, condition_input, condition_flowType;

    // 日期
    QString dateType = filter.getDateType();
    if("忽略日期" == dateType)
        condition_date = "";
    else  if("忽略日" == dateType)
        condition_date = QString("red_datetime like '%1'").arg(filter.getDate().toString("yyyy-MM-%"));
    else  if("忽略月" == dateType)
        condition_date = QString("red_datetime like '%1'").arg(filter.getDate().toString("yyyy-%-dd%"));
    else  if("保留日期" == dateType)
        condition_date = QString("red_datetime like '%1'").arg(filter.getDate().toString("yyyy-MM-dd%"));

    // 流向
    if("全部" == filter.getFlowType())
        condition_flowType = "";
    else
        condition_flowType = QString("red_flow_type = '%1'").arg(filter.getFlowType());

    //输入
    if(filter.getInput().isEmpty()){
        condition_input = "";
    }else{
        condition_input = QString("("
                                  "act_name like '%%1%' or "
                                  "bok_name like '%%1%' or "
                                  "red_first_classify like '%%1%' or "
                                  "red_second_classify like '%%1%' or "
                                  "red_transfer_in like '%%1%' or "
                                  "red_money like '%%1%' or "
                                  "red_remark like '%%1%'"
                                  ")").arg(filter.getInput());
    }

    // 开始整理sql语句
    QString sql;
    if(condition_date.isEmpty() && condition_input.isEmpty() && condition_flowType.isEmpty()){
        sql = QString("select * from record "
                      "order by red_datetime desc "
                      "limit %1,%2;").arg(QString::number(start),QString::number(end));
    }else{
        //如果条件为空会导致 and 前面为空，进而出现 where and 或者 where xxx and and 的情况
        QString condition = "";
        if(!condition_date.isEmpty())
            condition.append(condition_date);
        if(!condition_input.isEmpty() && !condition_date.isEmpty())
            condition.append(" and " + condition_input);
        else
            condition.append(condition_input);
        if(!condition_flowType.isEmpty() && (!condition_input.isEmpty() || !condition_date.isEmpty()) )
            condition.append(" and " + condition_flowType);
        else
            condition.append(condition_flowType);

        sql = QString("select * from record "
                      "where "
                      "%1 "
                      "order by red_datetime desc "
                      "limit %4,%5;"
                      ).arg(condition,QString::number(start),QString::number(end));
    }
//    qDebug()<<sql;
    query.exec(sql);
}

int DataBase::queryRecordRows()
{
    QSqlQuery query;
    QString sql = "select count(*) from record;";
    int counts = 0;
    if(query.exec(sql) && query.next())
        counts = query.value(0).toInt();
    return counts;
}

int DataBase::queryRecordRows(const QString &bookName)
{
    QSqlQuery query;
    QString sql = QString("select count(*) from record where bok_name='%1';").arg(bookName);
    int counts = 0;
    if(query.exec(sql) && query.next())
        counts = query.value(0).toInt();
    return counts;
}


Account DataBase::queryAccount(const QString &name)
{
    Account account;

    QSqlQuery query;
    QString sql = QString("select * from account where act_name='%1';").arg(name);
    if(query.exec(sql) && query.next()){
        account.setName(query.value("act_name").toString());
        account.setFund(query.value("act_fund").toDouble());
        account.setNickname(query.value("act_nickname").toString());
        account.setCardNumber(query.value("act_cardnumber").toString());
        account.setRemark(query.value("act_remark").toString());
        account.setEnable(query.value("act_enable").toBool());
        account.setCreateTime(query.value("act_datetime").toDateTime());
        account.setSerial(query.value("act_serial").toInt());
        account.setTop(query.value("act_top").toBool());
    }
    return account;
}

Book DataBase::queryBook(const QString &name)
{
    Book book;

    QSqlQuery query,subQuery;
    QString sql = QString("select * from book where bok_name='%1';").arg(name);
    if(query.exec(sql) && query.next()){
        book.setName(query.value("bok_name").toString());
        book.setTotalIncome(query.value("bok_totalincome").toDouble());
        book.setTotalExpend(query.value("bok_totalexpend").toDouble());
        book.setRemark(query.value("bok_remark").toString());
        book.setEnable(query.value("bok_enable").toBool());
        book.setCreateTime(query.value("bok_datetime").toDateTime());
        book.setSerial(query.value("bok_serial").toInt());
        book.setTop(query.value("bok_top").toBool());

        // 拿到该账本的总记录数
        QString subSql = QString("select count (*) from record where bok_name='%1';").arg(query.value("bok_name").toString());
        if(subQuery.exec(subSql) && subQuery.next()){
            book.setTotalRecord(subQuery.value(0).toInt());
        }else{
            book.setTotalRecord(0);
        }
    }
    return book;
}

Record DataBase::queryRecord(const QString &name)
{

}

qreal DataBase::queryTotalFund()
{
    qreal totalFund = 0;
    QSqlQuery query;
    if(query.exec("select act_fund from account;")){
        while (query.next())
            totalFund += query.value("act_fund").toDouble();
    }
    return totalFund;
}

qreal DataBase::queryMonthIncome(const QDate& date)
{
    qreal monthIncome = 0;
    QSqlQuery query;
    QString sql = QString("select red_money "
                          "from record "
                          "where red_flow_type = '收入' and red_datetime like '%1%';"
                          ).arg(date.toString("yyyy-MM"));
    if(query.exec(sql)){
        while (query.next())
            monthIncome += query.value("red_money").toDouble();
    }
    return monthIncome;
}

qreal DataBase::queryMonthExpend(const QDate& date)
{
    qreal monthExpend = 0;
    QSqlQuery query;
    QString sql = QString("select red_money "
                          "from record "
                          "where red_flow_type = '支出' and red_datetime like '%1%';"
                          ).arg(date.toString("yyyy-MM"));
    if(query.exec(sql)){
        while (query.next())
            monthExpend += query.value("red_money").toDouble();
    }
    return monthExpend;

}

bool DataBase::insertRecord(const Record &record)
{
    QSqlQuery query;
    query.prepare("insert into record(act_name,bok_name,red_datetime,red_flow_type,red_first_classify,red_second_classify,red_transfer_in,red_money,red_remark,red_image) "
                  "values(?,?,?,?,?,?,?,?,?,?);");
    query.bindValue(0,record.getAccountName());
    query.bindValue(1,record.getBookName());
    query.bindValue(2,record.getRecordTime());
    query.bindValue(3,record.getFlowType());
    query.bindValue(4,record.getFirstClassify());
    query.bindValue(5,record.getSecondClassify());
    query.bindValue(6,record.getTransferIn());
    query.bindValue(7,record.getMoney());
    query.bindValue(8,record.getRemark());
    query.bindValue(9,record.getImage());
    if(query.exec())
        return true;
    return false;
}

bool DataBase::updateRecord(const Record &record)
{
    QSqlQuery query;
    query.prepare("update record "
                  "set act_name=?,bok_name=?,red_datetime=?,red_flow_type=?,"
                  "red_first_classify=?,red_second_classify=?,red_transfer_in=?,red_money=?,red_remark=?,red_image=?  "
                  "where id=?;");
    query.bindValue(0,record.getAccountName());
    query.bindValue(1,record.getBookName());
    query.bindValue(2,record.getRecordTime());
    query.bindValue(3,record.getFlowType());
    query.bindValue(4,record.getFirstClassify());
    query.bindValue(5,record.getSecondClassify());
    query.bindValue(6,record.getTransferIn());
    query.bindValue(7,record.getMoney());
    query.bindValue(8,record.getRemark());
    query.bindValue(9,record.getImage());
    query.bindValue(10,record.getId());
    if(query.exec())
        return true;
    return false;
}

bool DataBase::deleteRecord(const int &id)
{
    QString sql = QString("delete from record where id=%1;").arg(QString::number(id));
    QSqlQuery query;
    if(query.exec(sql))
        return true;
    return false;
}

bool DataBase::insertAccount(const Account &account)
{
    QSqlQuery query;
    QString sql = "select count(act_name) from account;";
    int index = 1;
    if(query.exec(sql) && query.next())
        index = query.value(0).toInt() + 1;

    sql = QString("insert into account(act_name,act_fund,act_nickname,act_cardnumber,act_remark,act_enable,act_serial) "
                          "values('%1',%2,'%3','%4','%5',%6,%7);").arg(account.getName(),
                                                                    QString::number(account.getFund(),'f',2),
                                                                    account.getNickname(),
                                                                    account.getCardNumber(),
                                                                    account.getRemark(),
                                                                    QString::number(account.getEnable()),
                                                                    QString::number(index));

    if(query.exec(sql))
        return true;
    return false;
}

bool DataBase::updateAccount(const Account &account)
{
    QString sql = QString("update account "
                          "set act_fund=%1,act_nickname='%2',"
                          "act_cardnumber='%3',act_remark='%4',act_enable=%5,act_serial=%6,act_top=%7 "
                          "where act_name='%8';"
                          ).arg(QString::number(account.getFund(),'f',2),
                           account.getNickname(),
                           account.getCardNumber(),
                           account.getRemark(),
                           QString::number(account.getEnable()),
                           QString::number(account.getSerial()),
                           QString::number(account.getTop()),
                           account.getName());
    QSqlQuery query;
    if(query.exec(sql))
        return true;
    return false;
}

bool DataBase::updateAccountSerialTop(const QString &name, const int &serial, const bool &isTop)
{
    QString sql = QString("update account "
                          "set act_serial=%1,act_top=%2 "
                          "where act_name='%3';").arg(QString::number(serial), QString::number(isTop), name);
    //    qDebug()<<sql;
    QSqlQuery query;
    if(query.exec(sql))
        return true;
    return false;
}

bool DataBase::deleteAccount(const QString &name)
{
    QString sql = QString("delete from account where act_name='%1';").arg(name);
    QSqlQuery query;
    if(query.exec("PRAGMA foreign_keys = ON;") && query.exec(sql))
        return true;
    return false;
}

bool DataBase::insertBook(const Book &book)
{
    QSqlQuery query;
    QString sql = "select count(bok_name) from book;";
    int index = 1;
    if(query.exec(sql) && query.next())
        index = query.value(0).toInt() + 1;

    sql = QString("insert into "
                  "book(bok_name,bok_remark,bok_serial) "
                  "values('%1','%2',%3);").arg(book.getName(),book.getRemark(),QString::number(index));
    if(query.exec(sql))
        return true;
    return false;
}

bool DataBase::updateBook(const Book &book)
{
    QString sql = QString("update book "
                          "set bok_totalincome=%1,bok_totalexpend=%2,bok_remark='%3',bok_serial=%4,bok_top=%5 "
                          "where bok_name='%6';"
                          ).arg(QString::number(book.getTotalIncome(),'f',2),
                           QString::number(book.getTotalExpend(),'f',2),
                           book.getRemark(),
                           QString::number(book.getSerial()),
                           QString::number(book.getTop()),
                           book.getName());
//    qDebug()<<sql;
    QSqlQuery query;
    if(query.exec(sql))
        return true;
    return false;
}

bool DataBase::updateBookSerialTop(const QString &name, const int &serial, const bool &isTop)
{
    QString sql = QString("update book "
                          "set bok_serial=%1,bok_top=%2 "
                          "where bok_name='%3';").arg(QString::number(serial), QString::number(isTop), name);
//      qDebug()<<sql;
    QSqlQuery query;
    if(query.exec(sql))
        return true;
    return false;
}

bool DataBase::deleteBook(const QString &name)
{
    QString sql = QString("delete from book where bok_name='%1';").arg(name);
    QSqlQuery query;
    if(query.exec("PRAGMA foreign_keys = ON;") && query.exec(sql))
        return true;
    return false;
}

DataBase::DataBase()
{
    // 判断d资源文件夹是否存在
    QDir resPath(DATA_DIR_PATH);
    if(!resPath.exists()){
        resPath.setPath(CURR_PATH);
        resPath.mkdir("data");
    }
    connect();

    record_start_index = 0;
    record_end_index = 0;
}

void DataBase::checkConnect()
{
    if(db.isOpen())
        return;
    connect();
}

int DataBase::getMaxPages(const double& numOfPage)
{
    int total = queryRecordRows();
    int pages = 0;
    if(total/numOfPage > int(total/numOfPage))
        pages = int(total/numOfPage) + 1;
    else
        pages = int(total/numOfPage);

    return pages;
}
