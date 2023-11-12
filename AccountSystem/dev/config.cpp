#include "classify.h"

QMutex Classify::mutex;
Classify* Classify::instance = nullptr;

Classify *Classify::getInstance()
{
    if(instance == nullptr){
        QMutexLocker locker(&mutex);
        if(instance == nullptr){
            instance = new Classify;
        }
    }
    return instance;
}

void Classify::checkClassifyFile(bool isCheck)
{
    //1.配置文件是否存在
    QFile file(CFG_FILE_PATH);
    if(isCheck && file.exists()){
//        loadCfg(); //加载配置
        return;
    }

    //2.新建配置文件
    QJsonDocument doc( getDefaultClassify() );
    QByteArray bytes = doc.toJson(QJsonDocument::Compact);

    if(file.open(QIODevice::ReadWrite)){ //用户配置文件
        file.write(bytes);
        file.close();
    }
    //    loadCfg(); //加载配置
}

QJsonObject Classify::getExpend()
{
    QJsonObject rootObj = readClassifyJson();
    return rootObj["expend"].toObject();
}

QJsonArray Classify::getIncome()
{
    QJsonObject rootObj = readClassifyJson();
    return rootObj["income"].toArray();
}

QJsonObject Classify::readClassifyJson()
{
    QFile file(CFG_FILE_PATH);
    if(file.open(QIODevice::ReadOnly)){
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        file.close();
        return doc.object();
    }
    QJsonObject rootObj;
    return rootObj;
}

bool Classify::writeClassifyJson(const QJsonObject &rootObj)
{
    QFile file(CFG_FILE_PATH);
    if(file.open(QIODevice::WriteOnly)){
        QJsonDocument newDoc(rootObj);
        file.write(newDoc.toJson(QJsonDocument::Compact));
        file.close();
        return true;
    }
    return false;
}

// 获取默认配置
QJsonObject Classify::getDefaultClassify()
{
    QJsonObject rootObj;
    QJsonObject outObj;//支出

    QJsonArray inObj;//收入
    inObj.append("薪资");
    inObj.append("中奖");
    inObj.append("奖金");
    inObj.append("兼职");
    inObj.append("补贴");
    inObj.append("报销");
    inObj.append("利息");
    inObj.append("闲置品");
    inObj.append("人情礼金");
    inObj.append("其他");
    rootObj.insert("income",inObj);

    // 支出-购物
    QJsonArray gouwuArr;
    gouwuArr.append("家居用品");
    gouwuArr.append("护肤美妆");
    gouwuArr.append("数码产品");
    gouwuArr.append("衣着服饰");
    gouwuArr.append("宠物用品");
    gouwuArr.append("办公用品");
    gouwuArr.append("学习用品");
    gouwuArr.append("装修装饰");
    gouwuArr.append("娱乐产品");
    gouwuArr.append("家用电器");
    gouwuArr.append("出行工具");
    gouwuArr.append("健身器材");
    gouwuArr.append("其他");
    outObj.insert("gouwu",gouwuArr);

    // 支出-餐饮
    QJsonArray canyinArr;
    canyinArr.append("三餐");
    canyinArr.append("蔬菜");
    canyinArr.append("水果");
    canyinArr.append("外卖");
    canyinArr.append("零食");
    canyinArr.append("其他");
    canyinArr.append("肉禽类");
    canyinArr.append("水产品");
    canyinArr.append("饮料酒水");
    canyinArr.append("材米油盐");
    outObj.insert("canyin",canyinArr);

    // 支出-交通
    QJsonArray jiaotongArr;
    jiaotongArr.append("打车");
    jiaotongArr.append("飞机");
    jiaotongArr.append("公交车");
    jiaotongArr.append("高铁火车");
    jiaotongArr.append("共享单车");
    jiaotongArr.append("停车费");
    jiaotongArr.append("加油费");
    jiaotongArr.append("车辆保养");
    jiaotongArr.append("其他");
    outObj.insert("jiaotong",jiaotongArr);

    // 支出-娱乐
    QJsonArray yuleArr;
    yuleArr.append("游戏");
    yuleArr.append("健身");
    yuleArr.append("充值");
    yuleArr.append("演唱会");
    yuleArr.append("电影唱歌");
    yuleArr.append("其他");
    outObj.insert("yule",yuleArr);

    // 支出-旅游
    QJsonArray lvyouArr;
    lvyouArr.append("门票");
    lvyouArr.append("酒店");
    lvyouArr.append("团费");
    lvyouArr.append("餐饮费");
    lvyouArr.append("交通费");
    lvyouArr.append("纪念品");
    lvyouArr.append("伴手礼");
    lvyouArr.append("其他");
    outObj.insert("lvyou",lvyouArr);

    // 支出-居家
    QJsonArray jujiaArr;
    jujiaArr.append("电费");
    jujiaArr.append("水费");
    jujiaArr.append("房租");
    jujiaArr.append("燃气费");
    jujiaArr.append("物业费");
    jujiaArr.append("车位费");
    jujiaArr.append("维修费");
    jujiaArr.append("房租还贷");
    jujiaArr.append("家政清洁");
    jujiaArr.append("其他");
    outObj.insert("jiaju",jujiaArr);

    // 支出-教育
    QJsonArray jiaoyuArr;
    jiaoyuArr.append("学费");
    jiaoyuArr.append("书籍");
    jiaoyuArr.append("培训");
    jiaoyuArr.append("网课");
    jiaoyuArr.append("其他");
    outObj.insert("jiaoyu",jiaoyuArr);

    // 支出-教育
    QJsonArray renqingArr;
    renqingArr.append("送礼");
    renqingArr.append("红包");
    renqingArr.append("孝心");
    renqingArr.append("请客");
    renqingArr.append("其他");
    outObj.insert("renqing",renqingArr);

    // 支出-医疗
    QJsonArray yiliaoArr;
    yiliaoArr.append("买药");
    yiliaoArr.append("诊所");
    yiliaoArr.append("医院");
    yiliaoArr.append("保健品");
    yiliaoArr.append("其他");
    outObj.insert("yiliao",yiliaoArr);

    // 支出-通讯
    QJsonArray tongxunArr;
    tongxunArr.append("花费");
    tongxunArr.append("办卡");
    tongxunArr.append("宽带费");
    tongxunArr.append("其他");
    outObj.insert("tongxun",tongxunArr);

    // 支出-杂项
    QJsonArray zaxiangArr;
    zaxiangArr.append("寄快递");
    zaxiangArr.append("剪头发");
    zaxiangArr.append("其他");
    outObj.insert("zaxiang",zaxiangArr);

    rootObj.insert("expend",outObj);

    return rootObj;
}

Classify::Classify()
{
    checkClassifyFile();
}
