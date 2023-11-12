#include "config.h"

QMutex Config::mutex;
Config* Config::instance = nullptr;

Config *Config::getInstance()
{
    if(instance == nullptr){
        QMutexLocker locker(&mutex);
        if(instance == nullptr){
            instance = new Config;
        }
    }
    return instance;
}

void Config::checkConfigFile(bool isCheck)
{
    //1.配置文件是否存在
    QFile file(CFG_FILE_PATH);
    if(isCheck && file.exists()){
        loadConfigMap();
        return;
    }

    //2.新建配置文件
    // 判断d资源文件夹是否存在
    QDir resPath(RES_DIR_PATH);
    if(!resPath.exists()){
        resPath.setPath(CURR_PATH);
        resPath.mkdir("resources");
    }

    QJsonDocument doc( getDefaultClassify() );
    QByteArray bytes = doc.toJson(QJsonDocument::Compact);

    if(file.open(QIODevice::ReadWrite)){ //用户配置文件
        file.write(bytes);
        file.close();
    }
    loadConfigMap();
}

QJsonArray Config::getJsonArray(const Type &type)
{
    QJsonArray arr;
    switch (type) {
    case Expend_First_Classify:{
        arr = configMap.find("Expend_First_Classify").value();
        break;
    }
    case Income_Classify:{
        arr = configMap.find("Income_First_Classify").value();
        break;
    }
    case Money_Flow_Type:{
        arr = configMap.find("Money_Flow_Type").value();
        break;
    }
    case Expend_Second_GouWu:{
        arr = configMap.find("Expend_Second_GouWu").value();
        break;
    }
    case Expend_Second_CanYin:{
        arr = configMap.find("Expend_Second_CanYin").value();
        break;
    }
    case Expend_Second_JiaoTong:{
        arr =configMap.find("Expend_Second_JiaoTong").value();
        break;
    }
    case Expend_Second_YuLe:{
        arr = configMap.find("Expend_Second_YuLe").value();
        break;
    }
    case Expend_Second_LvYou:{
        arr = configMap.find("Expend_Second_LvYou").value();
        break;
    }
    case Expend_Second_JiaJu:{
        arr = configMap.find("Expend_Second_JiaJu").value();
        break;
    }
    case Expend_Second_JiaoYu:{
        arr = configMap.find("Expend_Second_JiaoYu").value();
        break;
    }
    case Expend_Second_RenQing:{
        arr = configMap.find("Expend_Second_RenQing").value();
        break;
    }
    case Expend_Second_YiLiao:{
        arr = configMap.find("Expend_Second_YiLiao").value();
        break;
    }
    case Expend_Second_TongXun:{
        arr = configMap.find("Expend_Second_TongXun").value();
        break;
    }
    case Expend_Second_ZaXiang:{
        arr = configMap.find("Expend_Second_ZaXiang").value();
        break;
    }
    case Account_Top_Sequence:{
        arr = configMap.find("Account_Top_Sequence").value();
        break;
    }
    case Account_Normal_Sequence:{
        arr = configMap.find("Account_Normal_Sequence").value();
        break;
    }
    case Book_Top_Sequence:{
        arr = configMap.find("Book_Top_Sequence").value();
        break;
    }
    case Book_Normal_Sequence:{
        arr = configMap.find("Book_Normal_Sequence").value();
        break;
    }
    default:
        break;
    }
    return arr;
}


QJsonObject Config::readConfigJson()
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

bool Config::writeConfigJson(const QJsonObject &rootObj)
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
QJsonObject Config::getDefaultClassify()
{
    QJsonObject rootObj;
    QJsonObject subObj;

    // 一级分类
    QJsonArray firstClassify;
    firstClassify.append("购物");
    firstClassify.append("餐饮");
    firstClassify.append("交通");
    firstClassify.append("娱乐");
    firstClassify.append("旅游");
    firstClassify.append("家居");
    firstClassify.append("教育");
    firstClassify.append("人情");
    firstClassify.append("医疗");
    firstClassify.append("通讯");
    firstClassify.append("杂项");
    subObj.insert("expend_first_classify",firstClassify);

    QJsonArray flowType;
    flowType.append("收入");
    flowType.append("支出");
    flowType.append("转账");
    subObj.insert("money_flow_type",flowType);

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
    subObj.insert("income_classify",inObj);

    // 二级分类
    QJsonObject outObj;//支出
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
    canyinArr.append("其他");
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

    // 支出-人情
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

    subObj.insert("expend_second_classify",outObj);

    rootObj.insert("classify",subObj); //分类配置

    //账户顺序
    QJsonObject accountObj;
    QJsonArray topArr;
    QJsonArray normalArr;
    accountObj.insert("top_list",topArr);
    topArr.removeFirst();
    accountObj.insert("normal_list",normalArr);  //空的
    rootObj.insert("account",accountObj); //分类配置

    //账本顺序
    QJsonObject bookObj;
    normalArr.append("日常账本(系统自带)");
    bookObj.insert("top_list",topArr); //空的
    bookObj.insert("normal_list",normalArr);  //空的
    rootObj.insert("book",bookObj); //分类配置

    return rootObj;
}

void Config::loadConfigMap()
{
    QJsonObject rootObj = readConfigJson();

    //账户顺序
    QJsonObject accountObj = rootObj["account"].toObject();
    configMap.insert("Account_Top_Sequence",accountObj["top_list"].toArray());
    configMap.insert("Account_Top_Sequence",accountObj["normal_list"].toArray());

    //账本顺序
    QJsonObject bookObj = rootObj["book"].toObject();
    configMap.insert("Account_Top_Sequence",bookObj["top_list"].toArray());
    configMap.insert("Account_Top_Sequence",bookObj["normal_list"].toArray());

    //分类
    QJsonObject classifyObj = rootObj["classify"].toObject();
    configMap.insert("Expend_First_Classify",classifyObj["expend_first_classify"].toArray());

    QJsonObject expendSecondObj = classifyObj["expend_second_classify"].toObject();
    configMap.insert("Expend_Second_GouWu",expendSecondObj["gouwu"].toArray());
    configMap.insert("Expend_Second_CanYin",expendSecondObj["canyin"].toArray());
    configMap.insert("Expend_Second_JiaoTong",expendSecondObj["jiaotong"].toArray());
    configMap.insert("Expend_Second_YuLe",expendSecondObj["yule"].toArray());
    configMap.insert("Expend_Second_LvYou",expendSecondObj["lvyou"].toArray());
    configMap.insert("Expend_Second_JiaJu",expendSecondObj["jiaju"].toArray());
    configMap.insert("Expend_Second_JiaoYu",expendSecondObj["jiaoyu"].toArray());
    configMap.insert("Expend_Second_RenQing",expendSecondObj["renqing"].toArray());
    configMap.insert("Expend_Second_YiLiao",expendSecondObj["yiliao"].toArray());
    configMap.insert("Expend_Second_TongXun",expendSecondObj["tongxun"].toArray());
    configMap.insert("Expend_Second_ZaXiang",expendSecondObj["zaxiang"].toArray());

    configMap.insert("Income_First_Classify",classifyObj["income_classify"].toArray());
    configMap.insert("Money_Flow_Type",classifyObj["money_flow_type"].toArray());
}

Config::Config()
{
    checkConfigFile();
}
