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

bool DataBase::connectDB()
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
                                "act_datetime TIMESTAMP DEFAULT CURRENT_TIMESTAMP);"; //--创建时间
            query.exec(sql);
        }
        if(!tables.contains("book")){
            sql = "CREATE TABLE book( "
                                "id INTEGER PRIMARY KEY AUTOINCREMENT," // -- '自增id'
                                "bok_name VARCHAR(20) UNIQUE NOT NULL," // ------账本名称 唯一------
                                "bok_totalincome REAL DEFAULT 0," // --共计收入
                                "bok_totalexpend REAL DEFAULT 0," // --共计支出
                                "bok_remark text DEFAULT NULL," // --账本备注
                                "bok_datetime TIMESTAMP DEFAULT CURRENT_TIMESTAMP);"; // --创建时间
            query.exec(sql);

            //添加默认账本
            sql = QString("insert into book(bok_name,bok_datetime) values('%1','%2');").arg("默认账本(系统自带)",QDateTime::currentDateTime().toString("yyyy年MM月dd日 hh:mm:ss"));
            query.exec(sql);
        }
        if(!tables.contains("record")){
            sql = "CREATE TABLE recocrd( "
                                "id INTEGER PRIMARY KEY AUTOINCREMENT," //
                                "act_name VARCHAR(20) NOT NULL," // ------账户名称------
                                "bok_name VARCHAR(20) NOT NULL," // ------账本名称-----
                                "red_datetime TIMESTAMP NOT NULL," // --记账日期
                                "red_flowType VARCHAR(10) NOT NULL," // --收支流向
                                "red_first_classify VARCHAR(10) NOT NULL," // --一级分类
                                "red_second_classify VARCHAR(10) NOT NULL," // --二级分类
                                "red_transfer_in VARCHAR(20) DEFAULT NULL," // ---转入账户
                                "red_money REAL NOT NULL," // --收支金额
                                "red_remark TEXT DEFAULT NULL," // --备注
                                "red_image BLOD DEFAULT NULL," // --图片
                                "FOREIGN KEY(act_name) REFERENCES account(act_name) ON DELETE CASCADE ON UPDATE CASCADE," // ------级联删除&更新------
                                "FOREIGN KEY(bok_name) REFERENCES book(bok_name) ON DELETE CASCADE ON UPDATE CASCADE);"; //------级联删除&更新-------
            query.exec(sql);
        }
        qDebug()<<"数据库连接成功...";
    }else{
        connectState = false;
    }

    return connectState;
}

QVector<Account> DataBase::queryAllAccount()
{

}

QVector<Book> DataBase::queryAllBook()
{
    QVector<Book> vec;

    Record record;
    QString sql,subSql;
    QSqlQuery query,subQuery;

    sql = "select * from book;";
    if(query.exec(sql)){
        while (query.next()) {
            Book book;
            book.setName(query.value("bok_name").toString());
            book.setTotalIncome(query.value("bok_totalincome").toDouble());
            book.setTotalExpend(query.value("bok_totalexpend").toDouble());
            book.setRemark(query.value("bok_remark").toString());
            book.setCreateTime(query.value("bok_datetime").toDateTime());

            // 拿到该账本的总记录数
            subSql = QString("select count (*) from record where bok_name='%1';").arg(query.value("bok_name").toString());
            if(subQuery.exec(subSql) && subQuery.next()){
                book.setTotalRecord(subQuery.value(0).toInt());
            }
            vec.append(book);
        }
    }
    return vec;
}

QVector<Record> DataBase::queryAllRecord()
{

}

DataBase::DataBase()
{
    // 判断d资源文件夹是否存在
    QDir resPath(RES_DIR_PATH);
    if(!resPath.exists()){
        resPath.setPath(CURR_PATH);
        resPath.mkdir("resources");
    }

    connectDB();
}