#ifndef CONFIG_H
#define CONFIG_H

#include <QMutex>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>
#include <QCoreApplication>
#include <QDir>

#include <QDebug>

#include "global.h"
#include "global.h"

class Config
{
public:
    static Config* getInstance();

    void checkConfigFile(bool isCheck = true);


    enum Type{
        Expend_First_Classify = 0x00000000,
        Expend_Second_GouWu,
        Expend_Second_CanYin,
        Expend_Second_JiaoTong,
        Expend_Second_YuLe,
        Expend_Second_LvYou,
        Expend_Second_JiaJu,
        Expend_Second_JiaoYu,
        Expend_Second_RenQing,
        Expend_Second_YiLiao,
        Expend_Second_TongXun,
        Expend_Second_ZaXiang,
        Income_Classify,
        Money_Flow_Type,
        Account_Type
    };
    QJsonArray getJsonArray(const Type& type);

private:
    bool writeConfigJson(const QJsonObject &rootObj);
    QJsonObject readConfigJson();
    QJsonObject getDefaultClassify();
    void loadConfigMap();

    QMap<QString,QJsonArray> configMap;


private:
    Config();
    Config(const Config&) = delete;
    Config& operator=(const Config&) = delete;

    static QMutex mutex;
    static Config* instance;
};

#endif // CONFIG_H
