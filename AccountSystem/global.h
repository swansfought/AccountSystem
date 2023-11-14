#ifndef GLOBAL_H
#define GLOBAL_H

#include <QDateTime>

#define CURR_PATH QCoreApplication::applicationDirPath()
#define RES_DIR_PATH CURR_PATH + "/resources"
#define CFG_FILE_PATH CURR_PATH + "/resources/config.json"
#define DB_FILE_PATH CURR_PATH + "/resources/data.db"

#define DEFAULT_BOOK "默认账本(系统自带)"

#define LOG_DATETIME QString("[%1]").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"))


#endif // GLOBAL_H
