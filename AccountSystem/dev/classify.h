#ifndef CLASSIFY_H
#define CLASSIFY_H

#include <QMutex>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>
#include <QCoreApplication>
#include <QDir>

#define CURR_PATH QCoreApplication::applicationDirPath()
#define CFG_FILE_PATH CURR_PATH + "/classify.json"

#include <QDebug>

class Classify
{
public:
    static Classify* getInstance();

    void checkClassifyFile(bool isCheck = true);

//    QJsonObject getCanyin();
//    QJsonObject getGouwu();
//    QJsonObject getJiaju();
//    QJsonObject getJiaotong();
//    QJsonObject getJiaoy();
//    QJsonObject getLvyou();
//    QJsonObject getRenqing();
//    QJsonObject getTongxun();
//    QJsonObject getYiliao();
//    QJsonObject getYule();
//    QJsonObject getZaxiang();
    QJsonObject getExpend();
    QJsonArray getIncome();


private:
    bool writeClassifyJson(const QJsonObject &rootObj);
    QJsonObject readClassifyJson();
    QJsonObject getDefaultClassify();
//    void loadCfg();


private:
    Classify();
    Classify(const Classify&) = delete;
    Classify& operator=(const Classify&) = delete;

    static QMutex mutex;
    static Classify* instance;
};

#endif // CLASSIFY_H
