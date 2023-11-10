#include "mainwin.h"
#include "./ui_mainwin.h"

MainWin::MainWin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWin)
{
    ui->setupUi(this);

    classify = Classify::getInstance();

    // 添加记账窗口
    addWin = new AddWin(this);
    QFont font;
    font.setFamily("微软雅黑");
    addWin->setFont(font);
    addWin->setWindowModality(Qt::WindowModal); //设置为模态窗口
    //    addWin->setWindowFlags(Qt::Dialog);
    addWin->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);//只显示关闭按钮 //| Qt::WindowTitleHint | Qt::CustomizeWindowHint

    initData();//初始化数据
}

MainWin::~MainWin()
{
    delete ui;
}


void MainWin::on_btn_record_clicked()
{
    ui->stackedWidget_dockPage->setCurrentWidget(ui->page_record);
}


void MainWin::on_btn_analysis_clicked()
{
    ui->stackedWidget_dockPage->setCurrentWidget(ui->page_analysis);

}


void MainWin::on_btn_borrowReturn_clicked()
{
    ui->stackedWidget_dockPage->setCurrentWidget(ui->page_borrowReturn);

}


void MainWin::on_btn_asset_clicked()
{
    ui->stackedWidget_dockPage->setCurrentWidget(ui->page_asset);

}


void MainWin::on_btn_accountBook_clicked()
{
    ui->stackedWidget_dockPage->setCurrentWidget(ui->page_accountBook);

}


void MainWin::on_btn_classify_clicked()
{
    ui->stackedWidget_dockPage->setCurrentWidget(ui->page_classify);

}


void MainWin::on_btn_setting_clicked()
{
    ui->stackedWidget_dockPage->setCurrentWidget(ui->page_setting);

}


void MainWin::on_btn_addRecord_clicked()
{
    addWin->show();
}

void MainWin::initData()
{
    //收入分类
    QJsonArray inArr = classify->getIncome();
    for (int i = 0; i < inArr.size(); ++i) {
        QTreeWidgetItem *rootItem = new QTreeWidgetItem(ui->treeWidget_income);
        rootItem->setText(0,inArr.at(i).toString());
    }

    //支出分类
    QJsonObject rootObj = classify->getExpend();
    //餐饮
    QTreeWidgetItem *rootCanyin = new QTreeWidgetItem(ui->treeWidget_expend);
    rootCanyin->setText(0,"餐饮");
    QJsonArray canyinArr = rootObj["canyin"].toArray();
    for (int i = 0; i < canyinArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootCanyin);
        subItem->setText(0,canyinArr.at(i).toString());
    }
    //购物
    QTreeWidgetItem *rootGouwu = new QTreeWidgetItem(ui->treeWidget_expend);
    rootGouwu->setText(0,"购物");
    QJsonArray gouwuArr = rootObj["gouwu"].toArray();
    for (int i = 0; i < gouwuArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootGouwu);
        subItem->setText(0,gouwuArr.at(i).toString());
    }
    //家居
    QTreeWidgetItem *rootJiaju = new QTreeWidgetItem(ui->treeWidget_expend);
    rootJiaju->setText(0,"家居");
    QJsonArray jiajuArr = rootObj["jiaju"].toArray();
    for (int i = 0; i < jiajuArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootJiaju);
        subItem->setText(0,jiajuArr.at(i).toString());
    }
    //交通
    QTreeWidgetItem *rootJiaotong = new QTreeWidgetItem(ui->treeWidget_expend);
    rootJiaotong->setText(0,"交通");
    QJsonArray jiaotongArr = rootObj["jiaotong"].toArray();
    for (int i = 0; i < jiaotongArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootJiaotong);
        subItem->setText(0,jiaotongArr.at(i).toString());
    }
    //教育
    QTreeWidgetItem *rootJiaoyu = new QTreeWidgetItem(ui->treeWidget_expend);
    rootJiaoyu->setText(0,"教育");
    QJsonArray jiaoyuArr = rootObj["jiaoyu"].toArray();
    for (int i = 0; i < jiaoyuArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootJiaoyu);
        subItem->setText(0,jiaoyuArr.at(i).toString());
    }
    //旅游
    QTreeWidgetItem *rootLvyou = new QTreeWidgetItem(ui->treeWidget_expend);
    rootLvyou->setText(0,"旅游");
    QJsonArray lvyouArr = rootObj["lvyou"].toArray();
    for (int i = 0; i < lvyouArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootLvyou);
        subItem->setText(0,lvyouArr.at(i).toString());
    }
    //人情
    QTreeWidgetItem *rootRenqing = new QTreeWidgetItem(ui->treeWidget_expend);
    rootRenqing->setText(0,"人情");
    QJsonArray renqingArr = rootObj["renqing"].toArray();
    for (int i = 0; i < renqingArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootRenqing);
        subItem->setText(0,renqingArr.at(i).toString());
    }
    //通讯
    QTreeWidgetItem *rootTongxun = new QTreeWidgetItem(ui->treeWidget_expend);
    rootTongxun->setText(0,"通讯");
    QJsonArray tongxunArr = rootObj["tongxun"].toArray();
    for (int i = 0; i < tongxunArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootTongxun);
        subItem->setText(0,tongxunArr.at(i).toString());
    }
    //医疗
    QTreeWidgetItem *rootYiliao = new QTreeWidgetItem(ui->treeWidget_expend);
    rootYiliao->setText(0,"医疗");
    QJsonArray yiliaoArr = rootObj["yiliao"].toArray();
    for (int i = 0; i < yiliaoArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootYiliao);
        subItem->setText(0,yiliaoArr.at(i).toString());
    }
    //娱乐
    QTreeWidgetItem *rootYule = new QTreeWidgetItem(ui->treeWidget_expend);
    rootYule->setText(0,"娱乐");
    QJsonArray yuleArr = rootObj["yule"].toArray();
    for (int i = 0; i < yuleArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootYule);
        subItem->setText(0,yuleArr.at(i).toString());
    }
    //杂项
    QTreeWidgetItem *rootZaxiang = new QTreeWidgetItem(ui->treeWidget_expend);
    rootZaxiang->setText(0,"杂项");
    QJsonArray zaxiangArr = rootObj["zaxiang"].toArray();
    for (int i = 0; i < zaxiangArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootZaxiang);
        subItem->setText(0,zaxiangArr.at(i).toString());
    }
}

