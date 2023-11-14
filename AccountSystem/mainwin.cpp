#include "mainwin.h"
#include "./ui_mainwin.h"

MainWin::MainWin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWin)
{
    ui->setupUi(this);

    totalFund = 0;
    totalIncome = 0;
    totalExpend = 0;
    db = DataBase::getInstance();
    addWin = new AddWin(this);
    config = Config::getInstance();

    initWinData();//初始化数据
    initSignalSlots();
}

MainWin::~MainWin()
{
    db->disconnect();
    delete ui;
}

void MainWin::initWinData()
{
    //dock栏
    ui->dock_totalIncome_hide->setIcon(QIcon(":/img/show.png"));
    ui->dock_totalExpend_hide->setIcon(QIcon(":/img/show.png"));
    ui->dock_totalFund_hide->setIcon(QIcon(":/img/show.png"));

    //账本
    auto bookVec = db->queryAllBook();
    for (int i = 0; i < bookVec.size(); ++i) {
        auto toolBtn = createBookItem(bookVec.at(i));
        ui->vLayout_book->insertWidget(i, qobject_cast<QWidget*>(toolBtn));
    }

    //账户
    auto accountVec = db->queryAllAccount();
    for (int i = 0; i < accountVec.size(); ++i) {
        auto toolBtn = createAccountItem(accountVec.at(i));
        ui->vLayout_account->insertWidget(i, qobject_cast<QWidget*>(toolBtn));
    }

    //收入分类
    QJsonArray inArr = config->getJsonArray(Config::Type::Income_Classify);
    for (int i = 0; i < inArr.size(); ++i) {
        QTreeWidgetItem *rootItem = new QTreeWidgetItem(ui->classify_incomeTree);
        rootItem->setText(0,inArr.at(i).toString());
    }

    //支出分类
    //购物
    QTreeWidgetItem *rootGouwu = new QTreeWidgetItem(ui->classify_expendTree);
    rootGouwu->setText(0,"购物");
    QJsonArray gouwuArr = config->getJsonArray(Config::Type::Expend_Second_GouWu);
    for (int i = 0; i < gouwuArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootGouwu);
        subItem->setText(0,gouwuArr.at(i).toString());
    }
    //餐饮
    QTreeWidgetItem *rootCanyin = new QTreeWidgetItem(ui->classify_expendTree);
    rootCanyin->setText(0,"餐饮");
    QJsonArray canyinArr = config->getJsonArray(Config::Type::Expend_Second_CanYin);
    for (int i = 0; i < canyinArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootCanyin);
        subItem->setText(0,canyinArr.at(i).toString());
    }
    //交通
    QTreeWidgetItem *rootJiaotong = new QTreeWidgetItem(ui->classify_expendTree);
    rootJiaotong->setText(0,"交通");
    QJsonArray jiaotongArr = config->getJsonArray(Config::Type::Expend_Second_JiaoTong);
    for (int i = 0; i < jiaotongArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootJiaotong);
        subItem->setText(0,jiaotongArr.at(i).toString());
    }
    //娱乐
    QTreeWidgetItem *rootYule = new QTreeWidgetItem(ui->classify_expendTree);
    rootYule->setText(0,"娱乐");
    QJsonArray yuleArr = config->getJsonArray(Config::Type::Expend_Second_YuLe);
    for (int i = 0; i < yuleArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootYule);
        subItem->setText(0,yuleArr.at(i).toString());
    }
    //旅游
    QTreeWidgetItem *rootLvyou = new QTreeWidgetItem(ui->classify_expendTree);
    rootLvyou->setText(0,"旅游");
    QJsonArray lvyouArr = config->getJsonArray(Config::Type::Expend_Second_LvYou);
    for (int i = 0; i < lvyouArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootLvyou);
        subItem->setText(0,lvyouArr.at(i).toString());
    }
    //家居
    QTreeWidgetItem *rootJiaju = new QTreeWidgetItem(ui->classify_expendTree);
    rootJiaju->setText(0,"家居");
    QJsonArray jiajuArr = config->getJsonArray(Config::Type::Expend_Second_JiaJu);
    for (int i = 0; i < jiajuArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootJiaju);
        subItem->setText(0,jiajuArr.at(i).toString());
    }
    //教育
    QTreeWidgetItem *rootJiaoyu = new QTreeWidgetItem(ui->classify_expendTree);
    rootJiaoyu->setText(0,"教育");
    QJsonArray jiaoyuArr = config->getJsonArray(Config::Type::Expend_Second_JiaoYu);
    for (int i = 0; i < jiaoyuArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootJiaoyu);
        subItem->setText(0,jiaoyuArr.at(i).toString());
    }
    //人情
    QTreeWidgetItem *rootRenqing = new QTreeWidgetItem(ui->classify_expendTree);
    rootRenqing->setText(0,"人情");
    QJsonArray renqingArr = config->getJsonArray(Config::Type::Expend_Second_RenQing);
    for (int i = 0; i < renqingArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootRenqing);
        subItem->setText(0,renqingArr.at(i).toString());
    }
    //医疗
    QTreeWidgetItem *rootYiliao = new QTreeWidgetItem(ui->classify_expendTree);
    rootYiliao->setText(0,"医疗");
    QJsonArray yiliaoArr = config->getJsonArray(Config::Type::Expend_Second_YiLiao);
    for (int i = 0; i < yiliaoArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootYiliao);
        subItem->setText(0,yiliaoArr.at(i).toString());
    }
    //通讯
    QTreeWidgetItem *rootTongxun = new QTreeWidgetItem(ui->classify_expendTree);
    rootTongxun->setText(0,"通讯");
    QJsonArray tongxunArr = config->getJsonArray(Config::Type::Expend_Second_TongXun);
    for (int i = 0; i < tongxunArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootTongxun);
        subItem->setText(0,tongxunArr.at(i).toString());
    }
    //杂项
    QTreeWidgetItem *rootZaxiang = new QTreeWidgetItem(ui->classify_expendTree);
    rootZaxiang->setText(0,"杂项");
    QJsonArray zaxiangArr = config->getJsonArray(Config::Type::Expend_Second_ZaXiang);
    for (int i = 0; i < zaxiangArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootZaxiang);
        subItem->setText(0,zaxiangArr.at(i).toString());
    }

    //显隐设置
    ui->groupBox_book_left_dock->setVisible(false);
    ui->groupBox_book_right_dock->setVisible(false);
    ui->groupBox_account_left_dock->setVisible(false);
    ui->groupBox_account_right_dock->setVisible(false);

}

void MainWin::initSignalSlots()
{
    // dock栏
    connect(ui->dock_totalIncome_hide,&QPushButton::clicked,this,[=](){
        //显示
        if(ui->dock_totalIncome_hide->isChecked()){
            ui->dock_totalIncome_num->setText("*****");
            ui->dock_totalIncome_hide->setIcon(QIcon(":/img/hide.png"));
        }else{//隐藏
            ui->dock_totalIncome_num->setText(QString::number(totalIncome,'f',2));
            ui->dock_totalIncome_hide->setIcon(QIcon(":/img/show.png"));
        }
    });
    connect(ui->dock_totalExpend_hide,&QPushButton::clicked,this,[=](){
        //显示
        if(ui->dock_totalExpend_hide->isChecked()){
            ui->dock_totalExpend_num->setText("*****");
            ui->dock_totalExpend_hide->setIcon(QIcon(":/img/hide.png"));
        }else{//隐藏
            ui->dock_totalExpend_num->setText(QString::number(totalExpend,'f',2));
            ui->dock_totalExpend_hide->setIcon(QIcon(":/img/show.png"));
        }
    });
    connect(ui->dock_totalFund_hide,&QPushButton::clicked,this,[=](){
        //显示
        if(ui->dock_totalFund_hide->isChecked()){
            ui->dock_totalFund_num->setText("*****");
            ui->dock_totalFund_hide->setIcon(QIcon(":/img/hide.png"));
        }else{//隐藏
            ui->dock_totalFund_num->setText(QString::number(totalFund,'f',2));
            ui->dock_totalFund_hide->setIcon(QIcon(":/img/show.png"));
        }
    });
    connect(ui->dock_record,&QPushButton::clicked,this,[=](){
        ui->stackedWidget_dock->setCurrentWidget(ui->page_record);
    });
    connect(ui->dock_analysis,&QPushButton::clicked,this,[=](){
        ui->stackedWidget_dock->setCurrentWidget(ui->page_analysis);
    });
    connect(ui->dock_borrowReturn,&QPushButton::clicked,this,[=](){
        ui->stackedWidget_dock->setCurrentWidget(ui->page_borrowReturn);
    });
    connect(ui->dock_account,&QPushButton::clicked,this,[=](){
        ui->stackedWidget_dock->setCurrentWidget(ui->page_account);
    });
    connect(ui->dock_book,&QPushButton::clicked,this,[=](){
        ui->stackedWidget_dock->setCurrentWidget(ui->page_book);
    });
    connect(ui->dock_classify,&QPushButton::clicked,this,[=](){
        ui->stackedWidget_dock->setCurrentWidget(ui->page_classify);
    });
    connect(ui->dock_setting,&QPushButton::clicked,this,[=](){
        ui->stackedWidget_dock->setCurrentWidget(ui->page_setting);
    });
    connect(ui->dock_addRecord,&QPushButton::clicked,this,[=](){
        int ax = this->x() + ui->stackedWidget_dock->x() + (ui->stackedWidget_dock->width() - addWin->width())/2;
        //30为主窗口状态栏高
        int ay = this->y() + 30 + 10 + (this->height() - addWin->height())/2;
        addWin->move(ax,ay);
        addWin->setFlowType("支出");//默认为支出
        addWin->show();
    });

    // account - 账户
    connect(ui->account_add,&QPushButton::clicked,this,[=](){
        ui->account_delete->setVisible(false);
        ui->account_return->setVisible(true);
        ui->stackedWidget_account_name->setCurrentWidget(ui->page_account_newName);
        //重置数据
        ui->account_fund->setValue(0);
        ui->account_nickname->clear();
        ui->account_card->clear();
        ui->account_remark->clear();
        ui->account_enable->setChecked(true);
    });
    connect(ui->account_save,&QPushButton::clicked,this,[=](){
        QString name = ui->account_newName->currentText();
        QString nickname = ui->account_nickname->text();
        qreal fund = ui->account_fund->value();
        QString card = ui->account_card->text();
        QString remark = ui->account_remark->toPlainText();
        bool enable = false;
        if(ui->account_enable->isChecked())
            enable = true;
//        if(!nickname.isEmpty() || !card.isEmpty() || !remark.isEmpty() )
    });
    connect(ui->account_delete,&QPushButton::clicked,this,[=](){
        ;
    });
    connect(ui->account_return,&QPushButton::clicked,this,[=](){
        //显隐
        ui->account_delete->setVisible(true);
        ui->account_return->setVisible(false);
        ui->stackedWidget_account_name->setCurrentWidget(ui->page_account_name);

        //还原数据
        ui->account_name->setText(currAccount.getName());
        ui->account_fund->setValue(currAccount.getFund());
        ui->account_nickname->setText(currAccount.getNickname());
        ui->account_card->setText(currAccount.getCardNumber());
        ui->account_remark->setPlainText(currAccount.getRemark());
        ui->account_enable->setChecked(currAccount.getEnable());
    });

    // book - 账本
    connect(ui->book_add,&QPushButton::clicked,this,[=](){
        ui->book_delete->setVisible(false);
        ui->book_return->setVisible(true);
        ui->stackedWidget_book->setCurrentWidget(ui->page_addBook);
    });
    connect(ui->book_save,&QPushButton::clicked,this,[=](){
        ;
    });
    connect(ui->book_delete,&QPushButton::clicked,this,[=](){
        ;
    });
    connect(ui->book_return,&QPushButton::clicked,this,[=](){
        ui->book_delete->setVisible(true);
        ui->book_return->setVisible(false);
//        QString name = ui->book_newName->text();
//        QString remark = ui->book_newRemark->toPlainText();
        ui->stackedWidget_book->setCurrentWidget(ui->page_bookInfo);
    });
}

QToolButton* MainWin::createBookItem(const Book& book)
{
    QToolButton *toolBtn = new QToolButton(this);
    toolBtn->setMinimumSize(QSize(400,100));
    toolBtn->setMaximumSize(QSize(400,100));
    toolBtn->setIcon(QIcon(":/img/book.png"));
    toolBtn->setIconSize(QSize(90,90));
    toolBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    toolBtn->setCheckable(true);
    toolBtn->setAutoExclusive(true);

    QString text = QString("%1\n存在%2条账单\n账本创建于%3").arg(book.getName(),
                                             QString::number(book.getTotalRecord()),
                                             book.getCreateTime().toString("yyyy年MM月dd日 hh:mm"));
    toolBtn->setText(text);
    // 选择展示信息
    connect(toolBtn,&QToolButton::clicked,this,[=](){
        currBook = book;
        //前提是选择按钮互斥
        if(!toolBtn->isChecked() && !bookIsChecked()){
            toolBtn->setChecked(true);
            return;
        }
        //数据
        ui->book_totalIncome->setValue(book.getTotalIncome());
        ui->book_totalExpend->setValue(book.getTotalExpend());
        ui->book_name->setText(book.getName());
        QString info = QString("账本创建于%1，已记录“%2”条账单。").arg(book.getCreateTime().toString("yyyy年MM月dd日"),
                                                                   QString::number(book.getTotalRecord()));
        ui->book_info->setText(info);

        //显隐
        ui->book_return->setVisible(false);
        ui->groupBox_book_left_dock->setVisible(true);
        ui->groupBox_book_right_dock->setVisible(true);

        //更改
        if(DEFAULT_BOOK == book.getName()){
            ui->book_name->setReadOnly(true);
            ui->book_remark->setReadOnly(true);
        }else{
            ui->book_name->setReadOnly(false);
            ui->book_remark->setReadOnly(false);
        }

    });
    return toolBtn;
}

QToolButton *MainWin::createAccountItem(const Account &account)
{
    QToolButton *toolBtn = new QToolButton(this);
    toolBtn->setMinimumSize(QSize(400,100));
    toolBtn->setMaximumSize(QSize(400,100));
    toolBtn->setIcon(QIcon(":/img/book.png"));
    toolBtn->setIconSize(QSize(90,90));
    toolBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    toolBtn->setCheckable(true);
    toolBtn->setAutoExclusive(true);

    QString text = QString("%1\n现有资产%2元").arg(account.getName(),
                                                   QString::number(account.getFund(),'f',2));
    toolBtn->setText(text);
    // 选择展示信息
    connect(toolBtn,&QToolButton::clicked,this,[=](){
        currAccount = account;
        //前提是选择按钮互斥
        if(!toolBtn->isChecked() && !accountIsChecked()){
            toolBtn->setChecked(true);
            return;
        }
        //数据
        ui->account_name->setText(account.getName());
        ui->account_fund->setValue(account.getFund());
        ui->account_nickname->setText(account.getNickname());
        ui->account_card->setText(account.getCardNumber());
        ui->account_remark->setPlainText(account.getRemark());
        ui->account_enable->setChecked(account.getEnable());

        //显隐
        ui->account_return->setVisible(false);
        ui->groupBox_account_left_dock->setVisible(true);
        ui->groupBox_account_right_dock->setVisible(true);
    });
    return toolBtn;
}

bool MainWin::bookIsChecked()
{
    int counts = ui->vLayout_book->count();
    for (int i = 0; i < counts; ++i) {
        QLayoutItem* item = ui->vLayout_book->itemAt(i);
        if (item->widget() != nullptr && item->widget()->isWidgetType() && qobject_cast<QToolButton*>(item->widget())) {
            QToolButton* toolBtn = qobject_cast<QToolButton*>(item->widget());
            if(toolBtn->isChecked())
                return true;
        }
    }
    return false;
}

bool MainWin::accountIsChecked()
{
    int counts = ui->vLayout_account->count();
    for (int i = 0; i < counts; ++i) {
        QLayoutItem* item = ui->vLayout_account->itemAt(i);
        if (item->widget() != nullptr && item->widget()->isWidgetType() && qobject_cast<QToolButton*>(item->widget())) {
            QToolButton* toolBtn = qobject_cast<QToolButton*>(item->widget());
            if(toolBtn->isChecked())
                return true;
        }
    }
    return false;
}

