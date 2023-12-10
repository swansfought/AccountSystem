#include "mainwin.h"
#include "./ui_mainwin.h"

MainWin::MainWin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWin)
{
    ui->setupUi(this);
    this->setWindowTitle("嘟嘟记账");
    db = DataBase::getInstance();
    recordWin = new RecordWin(this);
    config = Config::getInstance();
    isAccountRestore = false;
    currAccount = nullptr;
    currBook = nullptr;
    bookTopNum = 0;
    accountTopnum = 0;
    initStyle();
    initWinData();//先初始化数据
    initSignalSlots();
}

MainWin::~MainWin()
{
    db->disconnect();
    delete ui;
}

void MainWin::on_deleteRecord()
{
    recordWin->close(); //关闭窗口

    auto currItem = ui->record_tree->currentItem();
    QString flowType = currItem->text(3);
    qreal money = currItem->text(4).toDouble();

    Book book = db->queryBook(currItem->text(1));
    Account account = db->queryAccount(currItem->text(2));
    if("支出" == flowType){
        book.setTotalExpend(book.getTotalExpend() - money);// 更新账本总支出
        account.setFund(account.getFund() + money);// 更新账户总资产
    }else if("收入" == flowType){
        book.setTotalIncome(book.getTotalIncome() - money);// 更新账本总收入
        account.setFund(account.getFund() - money);// 更新账户总资产
    }

    //开始删除数据，并更新其他数据
    if(db->deleteRecord(currItem->data(0,Qt::UserRole).toInt())){
        book.setTotalRecord(book.getTotalRecord() - 1); //删除成功记录应该减去
        db->updateBook(book);
        db->updateAccount(account);
        flushWinData(account,book); //主窗口更新数据
    }
}

void MainWin::initStyle()
{
    // 加载样式表
    QFile styleFile(":/qss/style.qss" );
    if(styleFile.open(QFile::ReadOnly)){
        QTextStream stream(&styleFile);
        QString     styleSheet = styleFile.readAll();
        this->setStyleSheet(styleSheet);
        styleFile.close();
    }
}

void MainWin::initWinData()
{
    // 加载图标
    movie = new QMovie(":/img/loading.gif");
    ui->record_loading->setMovie(movie);
    ui->account_loading->setMovie(movie);
    ui->book_loading->setMovie(movie);
    ui->account_loading->setVisible(false);
    ui->book_loading->setVisible(false);

    // 界面初始位置
    ui->dock_record->setChecked(true);
    ui->stackedWidget_dock->setCurrentWidget(ui->page_record);
    ui->stackedWidget_record->setCurrentWidget(ui->page_record_tree);
    ui->stackedWidget_account_name->setCurrentWidget(ui->page_account_name);
    ui->stackedWidget_book->setCurrentWidget(ui->page_bookInfo);
    ui->record_input->setFocus();

//    ui->dock_analysis->setVisible(false);
    ui->dock_borrowReturn->setVisible(false);
    ui->dock_setting->setVisible(false);

    //dock栏
    ui->dock_monthIncome_hide->setIcon(QIcon(":/img/show.png"));
    ui->dock_monthExpend_hide->setIcon(QIcon(":/img/show.png"));
    ui->dock_totalFund_hide->setIcon(QIcon(":/img/show.png"));

    ui->dock_totalFund_num->setText(QString::number(db->queryTotalFund(),'f',2));
    ui->dock_monthIncome_num->setText(QString::number(db->queryMonthIncome(QDate::currentDate()),'f',2));
    ui->dock_monthExpend_num->setText(QString::number(db->queryMonthExpend(QDate::currentDate()),'f',2));

    //-------------流水账记录-------------
    ui->record_tree->setContextMenu(TreeWidget::Record);
    ui->record_date->setDateTime(QDateTime::currentDateTime());

    ui->record_pageRecordNum->setCurrentIndex(1);//默认100条/页
    initRecordBottomInfo(); // 底部提示

    //初始化标题
    QStringList headerLabels;
    headerLabels << "" << "账本" << "账户" << "流向" << "金额" << "一级分类" << "二级分类"  << "转入账户" << "备注" <<"图片";
    ui->record_tree->setHeaderLabels(headerLabels);

    //拿数据初始化
    QSqlQuery query;
    db->queryLimitRecord(query,0,99);
    initRecordData(query);

    // 设置每列的显示模式
    QHeaderView *header = ui->record_tree->header();
    for (int i = 0; i <= 9; ++i)
        header->setSectionResizeMode(i, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(0, QHeaderView::Fixed);
    header->setSectionResizeMode(8, QHeaderView::Fixed);
    header->setSectionResizeMode(9, QHeaderView::Fixed);
//    ui->record_tree->setColumnHidden(9,true); //隐藏图片
//    header->setSectionResizeMode(1, QHeaderView::ResizeToContents);//账本
//    header->setSectionResizeMode(2, QHeaderView::ResizeToContents);//账户
//    header->setSectionResizeMode(4, QHeaderView::ResizeToContents);//金额
//    header->setSectionResizeMode(7, QHeaderView::ResizeToContents);//账户

    // 设置每列的宽度
    header->resizeSection(0, 51); //解决子项距离父项左边偏距，暂没想到其他解决方法
//    header->resizeSection(1, 95);
//    header->resizeSection(2, 145);
//    header->resizeSection(3, 50);
//    header->resizeSection(4, 105);
//    header->resizeSection(5, 85);
//    header->resizeSection(6, 85);
//    header->resizeSection(7, 145);
    header->resizeSection(8, 320);
    header->resizeSection(9, 80);
    header->setDefaultAlignment(Qt::AlignCenter);//设置整个标题栏居中
    header->setSectionsMovable(false);// 禁用列拖动
    //----------------------------------

    //账本
    ui->widget_account_enable->setVisible(false);// 暂不开启
    auto bookVec = db->queryAllBook();
    for (int i = 0; i < bookVec.size(); ++i) {
        auto toolBtn = createBookItem(bookVec.at(i));
        ui->vLayout_book->insertWidget(i, qobject_cast<QWidget*>(toolBtn));
        recordWin->addBook(bookVec.at(i).getName()); //记账窗口 账本
    }

    //账户
    auto accountVec = db->queryAllAccount();
    for (int i = 0; i < accountVec.size(); ++i) {
        auto toolBtn = createAccountItem(accountVec.at(i));
        ui->vLayout_account->insertWidget(i, qobject_cast<QWidget*>(toolBtn));

        recordWin->addAccount(accountVec.at(i).getName());//记账窗口 账户
    }

    //所有账户
    QJsonArray actArr = config->getJsonArray(Config::Type::Account_Type);
    for (int i = 0; i < actArr.size(); ++i)
        ui->account_newName->addItem(actArr.at(i).toString());

    //收入分类
    QJsonArray inArr = config->getJsonArray(Config::Type::Income_Classify);
    for (int i = 0; i < inArr.size(); ++i) {
        QTreeWidgetItem *rootItem = new QTreeWidgetItem(ui->classify_incomeTree);
        rootItem->setText(0,inArr.at(i).toString());
    }

    //支出分类
    //购物
    QTreeWidgetItem *rootGouwu = new QTreeWidgetItem(ui->classify_expendTree);
    rootGouwu->setFlags(rootGouwu->flags() & ~Qt::ItemIsDropEnabled); // 禁用顶部子项放入到另一个顶部子项中
    rootGouwu->setText(0,"购物");
    QJsonArray gouwuArr = config->getJsonArray(Config::Type::Expend_Second_GouWu);
    for (int i = 0; i < gouwuArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootGouwu);
        subItem->setText(0,gouwuArr.at(i).toString());
    }
    //餐饮
    QTreeWidgetItem *rootCanyin = new QTreeWidgetItem(ui->classify_expendTree);
    rootCanyin->setFlags(rootCanyin->flags() & ~Qt::ItemIsDropEnabled); // 禁用顶部子项放入到另一个顶部子项中
    rootCanyin->setText(0,"餐饮");
    QJsonArray canyinArr = config->getJsonArray(Config::Type::Expend_Second_CanYin);
    for (int i = 0; i < canyinArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootCanyin);
        subItem->setText(0,canyinArr.at(i).toString());
    }
    //交通
    QTreeWidgetItem *rootJiaotong = new QTreeWidgetItem(ui->classify_expendTree);
    rootJiaotong->setFlags(rootJiaotong->flags() & ~Qt::ItemIsDropEnabled); // 禁用顶部子项放入到另一个顶部子项中
    rootJiaotong->setText(0,"交通");
    QJsonArray jiaotongArr = config->getJsonArray(Config::Type::Expend_Second_JiaoTong);
    for (int i = 0; i < jiaotongArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootJiaotong);
        subItem->setText(0,jiaotongArr.at(i).toString());
    }
    //娱乐
    QTreeWidgetItem *rootYule = new QTreeWidgetItem(ui->classify_expendTree);
    rootYule->setFlags(rootYule->flags() & ~Qt::ItemIsDropEnabled); // 禁用顶部子项放入到另一个顶部子项中
    rootYule->setText(0,"娱乐");
    QJsonArray yuleArr = config->getJsonArray(Config::Type::Expend_Second_YuLe);
    for (int i = 0; i < yuleArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootYule);
        subItem->setText(0,yuleArr.at(i).toString());
    }
    //旅游
    QTreeWidgetItem *rootLvyou = new QTreeWidgetItem(ui->classify_expendTree);
    rootLvyou->setFlags(rootLvyou->flags() & ~Qt::ItemIsDropEnabled); // 禁用顶部子项放入到另一个顶部子项中
    rootLvyou->setText(0,"旅游");
    QJsonArray lvyouArr = config->getJsonArray(Config::Type::Expend_Second_LvYou);
    for (int i = 0; i < lvyouArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootLvyou);
        subItem->setText(0,lvyouArr.at(i).toString());
    }
    //家居
    QTreeWidgetItem *rootJiaju = new QTreeWidgetItem(ui->classify_expendTree);
    rootJiaju->setFlags(rootJiaju->flags() & ~Qt::ItemIsDropEnabled); // 禁用顶部子项放入到另一个顶部子项中
    rootJiaju->setText(0,"家居");
    QJsonArray jiajuArr = config->getJsonArray(Config::Type::Expend_Second_JiaJu);
    for (int i = 0; i < jiajuArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootJiaju);
        subItem->setText(0,jiajuArr.at(i).toString());
    }
    //教育
    QTreeWidgetItem *rootJiaoyu = new QTreeWidgetItem(ui->classify_expendTree);
    rootJiaoyu->setFlags(rootJiaoyu->flags() & ~Qt::ItemIsDropEnabled); // 禁用顶部子项放入到另一个顶部子项中
    rootJiaoyu->setText(0,"教育");
    QJsonArray jiaoyuArr = config->getJsonArray(Config::Type::Expend_Second_JiaoYu);
    for (int i = 0; i < jiaoyuArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootJiaoyu);
        subItem->setText(0,jiaoyuArr.at(i).toString());
    }
    //人情
    QTreeWidgetItem *rootRenqing = new QTreeWidgetItem(ui->classify_expendTree);
    rootRenqing->setFlags(rootRenqing->flags() & ~Qt::ItemIsDropEnabled); // 禁用顶部子项放入到另一个顶部子项中
    rootRenqing->setText(0,"人情");
    QJsonArray renqingArr = config->getJsonArray(Config::Type::Expend_Second_RenQing);
    for (int i = 0; i < renqingArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootRenqing);
        subItem->setText(0,renqingArr.at(i).toString());
    }
    //医疗
    QTreeWidgetItem *rootYiliao = new QTreeWidgetItem(ui->classify_expendTree);
    rootYiliao->setFlags(rootYiliao->flags() & ~Qt::ItemIsDropEnabled); // 禁用顶部子项放入到另一个顶部子项中
    rootYiliao->setText(0,"医疗");
    QJsonArray yiliaoArr = config->getJsonArray(Config::Type::Expend_Second_YiLiao);
    for (int i = 0; i < yiliaoArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootYiliao);
        subItem->setText(0,yiliaoArr.at(i).toString());
    }
    //通讯
    QTreeWidgetItem *rootTongxun = new QTreeWidgetItem(ui->classify_expendTree);
    rootTongxun->setFlags(rootTongxun->flags() & ~Qt::ItemIsDropEnabled); // 禁用顶部子项放入到另一个顶部子项中
    rootTongxun->setText(0,"通讯");
    QJsonArray tongxunArr = config->getJsonArray(Config::Type::Expend_Second_TongXun);
    for (int i = 0; i < tongxunArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootTongxun);
        subItem->setText(0,tongxunArr.at(i).toString());
    }
    //杂项
    QTreeWidgetItem *rootZaxiang = new QTreeWidgetItem(ui->classify_expendTree);
    rootZaxiang->setFlags(rootZaxiang->flags() & ~Qt::ItemIsDropEnabled); // 禁用顶部子项放入到另一个顶部子项中
    rootZaxiang->setText(0,"杂项");
    QJsonArray zaxiangArr = config->getJsonArray(Config::Type::Expend_Second_ZaXiang);
    for (int i = 0; i < zaxiangArr.size(); ++i) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootZaxiang);
        subItem->setText(0,zaxiangArr.at(i).toString());

//        subItem->setFlags(subItem->flags() & ~Qt::ItemIsDragEnabled); // 防止移动
        // 关闭子item的Drop功能。
        // 防止其他item项被放入到该item的子树中
//        subItem->setFlags(subItem->flags() & ~Qt::ItemIsDropEnabled);
    }

    //显隐设置
    ui->widget_account_enable->setVisible(false);

}

void MainWin::initSignalSlots()
{
    // dock栏
    connect(ui->dock_monthIncome_hide,&QPushButton::clicked,this,[=](){
        //显示
        if(ui->dock_monthIncome_hide->isChecked()){
            ui->dock_monthIncome_num->setText("*****");
            ui->dock_monthIncome_hide->setIcon(QIcon(":/img/hide.png"));
        }else{//隐藏
            ui->dock_monthIncome_num->setText(QString::number(db->queryMonthIncome(QDate::currentDate()),'f',2));
            ui->dock_monthIncome_hide->setIcon(QIcon(":/img/show.png"));
        }
    });
    connect(ui->dock_monthExpend_hide,&QPushButton::clicked,this,[=](){
        //显示
        if(ui->dock_monthExpend_hide->isChecked()) {
            ui->dock_monthExpend_num->setText("*****");
            ui->dock_monthExpend_hide->setIcon(QIcon(":/img/hide.png"));
        }else{//隐藏
            ui->dock_monthExpend_num->setText(QString::number(db->queryMonthExpend(QDate::currentDate()),'f',2));
            ui->dock_monthExpend_hide->setIcon(QIcon(":/img/show.png"));
        }
    });
    connect(ui->dock_totalFund_hide,&QPushButton::clicked,this,[=](){
        //显示
        if(ui->dock_totalFund_hide->isChecked()){
            ui->dock_totalFund_num->setText("*****");
            ui->dock_totalFund_hide->setIcon(QIcon(":/img/hide.png"));
        }else{//隐藏
            ui->dock_totalFund_num->setText(QString::number(db->queryTotalFund(),'f',2));
            ui->dock_totalFund_hide->setIcon(QIcon(":/img/show.png"));
        }
    });
    connect(ui->dock_record,&QPushButton::clicked,this,[=](){
        ui->stackedWidget_dock->setCurrentWidget(ui->page_record);
    });
    connect(ui->dock_analysis,&QPushButton::clicked,this,[=](){
        ui->stackedWidget_dock->setCurrentWidget(ui->page_analysis);
        ui->analysis_book->setFocus();
    });
    connect(ui->dock_borrowReturn,&QPushButton::clicked,this,[=](){
        ui->stackedWidget_dock->setCurrentWidget(ui->page_borrowReturn);
    });
    connect(ui->dock_account,&QPushButton::clicked,this,[=](){
        ui->stackedWidget_dock->setCurrentWidget(ui->page_account);

        ui->account_fund->setFocus();
        if(nullptr != currAccount)
            return;
        auto item = ui->vLayout_account->itemAt(0); //拿第一个
        auto toolBtn = qobject_cast<QToolButton*>(item->widget());
        toolBtn->click();
        ui->account_fund->setFocus();
    });
    connect(ui->dock_book,&QPushButton::clicked,this,[=](){
        ui->stackedWidget_dock->setCurrentWidget(ui->page_book);

        ui->book_remark->setFocus();
        if(nullptr != currBook)
            return;
        auto item = ui->vLayout_book->itemAt(0); //拿第一个
        auto toolBtn = qobject_cast<QToolButton*>(item->widget());
        toolBtn->click();
    });
    connect(ui->dock_classify,&QPushButton::clicked,this,[=](){
        ui->stackedWidget_dock->setCurrentWidget(ui->page_classify);
    });
    connect(ui->dock_setting,&QPushButton::clicked,this,[=](){
        ui->stackedWidget_dock->setCurrentWidget(ui->page_setting);
    });
    connect(ui->dock_addRecord,&QPushButton::clicked,this,[=](){
        int ax = this->x() + ui->stackedWidget_dock->x() + (ui->stackedWidget_dock->width() - recordWin->width())/2;
        //30为主窗口状态栏高
        int ay = this->y() + 30 + 10 + (this->height() - recordWin->height())/2;
        recordWin->move(ax,ay);
        recordWin->setWinMode(RecordWin::Add);
        recordWin->show();
    });

    //刷新窗口数据
    connect(recordWin,&RecordWin::flushWinData,this,[=](Account account, Book book){  flushWinData(account,book);   });

    // 流水账界面
    connect(ui->record_input,&QLineEdit::textChanged,this,[=](){ flushRecordData(true); });
    connect(ui->record_filter,&QComboBox::currentTextChanged,this,[=](){ flushRecordData(true); });
    connect(ui->record_flowType,&QComboBox::currentTextChanged,this,[=](){ flushRecordData(true); });
    connect(ui->record_date,&QDateEdit::dateChanged,this,[=](){
        if("忽略日期" == ui->record_filter->currentText())
            return;
        flushRecordData(true);
    });
    connect(ui->record_expand,&QPushButton::clicked,this,[=](){ ui->record_tree->expandAll(); });
    connect(ui->record_collapse,&QPushButton::clicked,this,[=](){ ui->record_tree->collapseAll();});
    connect(ui->record_reset,&QPushButton::clicked,this,[=](){
        ui->record_input->clear();
        ui->record_filter->setCurrentIndex(0);
        ui->record_date->setDate(QDate::currentDate());
        ui->record_flowType->setCurrentIndex(0);
        flushRecordData(true);
    });
    connect(ui->record_flush,&QPushButton::clicked,this,[=](){ flushRecordData(true);  });
    connect(ui->record_tree,&TreeWidget::deleteRecord,this,&MainWin::on_deleteRecord); //删除记录
    connect(ui->record_tree,&QTreeWidget::currentItemChanged,this,[=](QTreeWidgetItem *current, QTreeWidgetItem *previous){
        if(nullptr == current->parent())
            return;
    });
    //双击展示信息
    connect(ui->record_tree,&QTreeWidget::itemDoubleClicked,this,[=](QTreeWidgetItem *item, int column){
        if(nullptr == item->parent())
            return;

        // 设置数据
        recordWin->setBook(item->text(1));
        recordWin->setAccount(item->text(2));
        recordWin->setFlowType(item->text(3));
        recordWin->setMoney(item->text(4).toDouble());
        recordWin->setFirstClassify(item->text(5));
        recordWin->setSecondClassify(item->text(6));
        recordWin->setAccountIn(item->text(7));
        recordWin->setRemark(item->text(8));
        recordWin->setImage(item->data(9,Qt::UserRole).toByteArray());

        // 设置窗口位置
        int ax = this->x() + ui->stackedWidget_dock->x() + (ui->stackedWidget_dock->width() - recordWin->width())/2;
        //30为主窗口状态栏高
        int ay = this->y() + 30 + 10 + (this->height() - recordWin->height())/2;
        recordWin->move(ax,ay);
        recordWin->setWinMode(RecordWin::Show,item->data(0,Qt::UserRole).toInt());
        recordWin->show();
    });
    connect(recordWin,&RecordWin::deleteRecord,this,&MainWin::on_deleteRecord);//删除记录
    connect(ui->record_pageNext,&QPushButton::clicked,this,[=](){
        int newValue = ui->record_pageIndex->value() + 1;
        ui->record_pageIndex->setValue(newValue);
    });
    connect(ui->record_pagePrevious,&QPushButton::clicked,this,[=](){
        int newValue = ui->record_pageIndex->value() - 1;
        ui->record_pageIndex->setValue(newValue);
    });
    connect(ui->record_pageRecordNum,&QComboBox::currentTextChanged,this,[=](const QString &text){
        double numOfPage = text.split("条").at(0).toDouble();
        int maxPage = db->getMaxPages(numOfPage);
        int index = ui->record_pageIndex->value();
        // 防止页数超过实际情况
        // 举例：60条记录，当前在第2页。 发生50条/页-->100条/页跳变
        if(index > maxPage)
            ui->record_pageIndex->setValue(maxPage);
    });
    //切换页面，需要考虑当前页面记录数量、过滤条件
    connect(ui->record_pageIndex,qOverload<int>(&QSpinBox::valueChanged),this,[=](int index){
        double numOfPage = ui->record_pageRecordNum->currentText().split("条").at(0).toDouble();
        int maxPage = db->getMaxPages(numOfPage);
        if(1<maxPage){
            if(1<index && index<maxPage ){ //索引值在中间
                ui->record_pagePrevious->setEnabled(true);
                ui->record_pageNext->setEnabled(true);
            }else if(index==maxPage ){ //索引值在最右边
                ui->record_pagePrevious->setEnabled(true);
                ui->record_pageNext->setEnabled(false);
            }else if(1==index ){ //索引值在最左边
                ui->record_pagePrevious->setEnabled(false);
                ui->record_pageNext->setEnabled(true);
            }
        }else if(1==maxPage ){//只有一页的情况
            ui->record_pagePrevious->setEnabled(false);
            ui->record_pageNext->setEnabled(false);
            ui->record_pageIndex->setValue(maxPage);
            return;
        }
        flushRecordData(true); //重加载页面数据
    });


    // account - 账户
    connect(ui->account_top,&QPushButton::clicked,this,[=](){
        if("置顶账户"== ui->account_top->text()){
            int index = currAccount->text().indexOf("\n");
            currAccount->setText(currAccount->text().insert(index,DEFAULT_TOP_FLAG));
            ui->account_top->setText("取消置顶");

            //插入到原置顶的尾部
            ui->vLayout_account->insertWidget(accountTopnum,currAccount);
            ++accountTopnum;
        }else{
            int index = currAccount->text().indexOf("\n");
            currAccount->setText(currAccount->text().remove(DEFAULT_TOP_FLAG));
            ui->account_top->setText("置顶账户");

            //插入到未置顶的头部
            --accountTopnum;
            ui->vLayout_account->insertWidget(accountTopnum,currAccount);
        }
        updateAccountSerialTop(); //更新状态
    });
    connect(ui->account_up,&QPushButton::clicked,this,[=](){
        // 计算索引值
        int index = ui->vLayout_account->indexOf(currAccount) - 1;
        if(index <= 0)
            index = 0; //索引值从0开始

        //置顶范围和非置顶范围
        QLayoutItem* item = ui->vLayout_account->itemAt(index);
        if (item->widget()) {
            auto preBook = qobject_cast<QToolButton*>(item->widget());
            if(!currAccount->text().contains(DEFAULT_TOP_FLAG) && preBook->text().contains(DEFAULT_TOP_FLAG))
                return;
        }

        if(index < 5){ // 手动上滑
            auto scrollBar = ui->scrollArea_account->verticalScrollBar();
            scrollBar->setValue(scrollBar->minimumHeight());
        }
        ui->vLayout_account->insertWidget(index,currAccount);
        updateAccountSerialTop(); //更新状态
    });
    connect(ui->account_down,&QPushButton::clicked,this,[=](){
        // 计算索引值
        int index = ui->vLayout_account->indexOf(currAccount) + 1;
        int count = ui->vLayout_account->count() - 1;//总数要减去弹簧
        if(index >= count)
            index = count - 1; //索引值从0开始

        //置顶范围和非置顶范围
        QLayoutItem* item = ui->vLayout_account->itemAt(index);
        if (item->widget()) {
            auto lastBook = qobject_cast<QToolButton*>(item->widget());
            if(currAccount->text().contains(DEFAULT_TOP_FLAG) && !lastBook->text().contains(DEFAULT_TOP_FLAG))
                return;
        }

        if(index >= 5){  // 手动下滑
            auto scrollBar = ui->scrollArea_account->verticalScrollBar();
            scrollBar->setValue(scrollBar->maximumHeight());
        }
        ui->vLayout_account->insertWidget(index,currAccount);
        updateAccountSerialTop(); //更新状态
    });
    connect(ui->account_add,&QPushButton::clicked,this,[=](){
        //重置数据
        ui->account_fund->setValue(0);
        ui->account_nickname->clear();
        ui->account_card->clear();
        ui->account_remark->clear();
        ui->account_enable->setChecked(true);

        ui->account_delete->setVisible(false);
        ui->account_return->setVisible(true);
        ui->stackedWidget_account_name->setCurrentWidget(ui->page_account_newName);

        ui->account_fund->setFocus();
    });
    connect(ui->account_save,&QPushButton::clicked,this,[=](){

        // 初始化公共部分数据
        Account account;
        account.setFund(ui->account_fund->value());
        account.setNickname(ui->account_nickname->text());
        account.setCardNumber(ui->account_card->text());
        account.setRemark(ui->account_remark->toPlainText());
        account.setEnable(ui->account_enable->isChecked());

        //添加账户
        if(ui->page_account_newName == ui->stackedWidget_account_name->currentWidget()){
            QSqlQuery query;
            QString sql = QString("select act_name from account where act_name='%1';").arg(ui->account_newName->currentText());
            if(query.exec(sql) && query.next()){
                QMessageBox::information(this,"账户添加","此账户已存在，无法再次添加！",QMessageBox::Ok);
                return;
            }

            loadingTip(true);//加载提示

            account.setName(ui->account_newName->currentText());
            account.setCreateTime(QDateTime::currentDateTime());
            if(db->insertAccount(account)){
                recordWin->addAccount(account.getName());

                //插入到末尾
                auto item = createAccountItem(account);//
                int index = ui->vLayout_account->count() - 1;
                ui->vLayout_account->insertWidget(index, qobject_cast<QWidget*>(item));

                //提示窗口
                loadingTip(false);//关闭提示
                QMessageBox::information(this,"账户添加","账户添加成功！",QMessageBox::Ok);

                //重置数据
                ui->account_fund->setValue(0);
                ui->account_nickname->clear();
                ui->account_card->clear();
                ui->account_remark->clear();
                ui->account_enable->setChecked(true);
            }else{
                loadingTip(false);//关闭提示
                QMessageBox::information(this,"账户添加","账户添加失败！\n注：请再次尝试或检查资源文件是否正确。",QMessageBox::Ok);
            }
        }else{ //更改账户信息
            if(ui->account_name->text().isEmpty()){
                QMessageBox::information(this,"账户更新","账户名称为空，无法更新账户信息！",QMessageBox::Ok);
                return;
            }
            loadingTip(true);//加载提示

            account.setName(ui->account_name->text());
            if(ui->account_name->text().contains(DEFAULT_TOP_FLAG))
                account.setTop(true);
            else
                account.setTop(false);
            account.setSerial(ui->vLayout_account->indexOf(currAccount));
            if(db->updateAccount(account)){
                QString text = QString("%1\n现有资产%2元").arg(account.getName(),
                                                             QString::number(account.getFund(),'f',2));
                currAccount->setText(text);
                loadingTip(false);//关闭提示
                QMessageBox::information(this,"账户更新","账户更新成功！",QMessageBox::Ok);
            }else{
                loadingTip(false);//关闭提示
                QMessageBox::information(this,"账户更新","账户更新失败！\n注：请再次尝试或检查资源文件是否正确。",QMessageBox::Ok);
            }
        }
        ui->account_fund->setFocus();
    });
    connect(ui->account_delete,&QPushButton::clicked,this,[=](){
        QString name = currAccount->text().split("\n").at(0);
        QString tip = QString("⚠注意：\n->确定要删除“%1”账户吗?\n->删除会导致账户所有记录都会被清空!!!").arg(name);
        auto ret = QMessageBox::information(this,"账户删除",tip,QMessageBox::Yes,QMessageBox::No);
        if(QMessageBox::Yes == ret && db->deleteAccount(name)){ // 直接删除
            recordWin->removeAccount(name);

            int index = ui->vLayout_account->indexOf(currAccount);
            ui->vLayout_account->removeWidget(currAccount);
            currAccount->deleteLater();
            currAccount = nullptr;

            //更改选中项
            int count = ui->vLayout_account->count()-1; //不算弹簧
            QLayoutItem *item;
            if(index >= count) //删除的是末尾的一项
                item = ui->vLayout_account->itemAt(index - 1); //拿前面一个
            else
                item = ui->vLayout_account->itemAt(index); //拿后面一个
            auto toolBtn = qobject_cast<QToolButton*>(item->widget());
            toolBtn->click();
        }
        flushRecordData(true);// 刷新记账记录
        ui->account_fund->setFocus();
    });
    connect(ui->account_return,&QPushButton::clicked,this,[=](){
        if(nullptr != currAccount){
            isAccountRestore = true;
            currAccount->click();//还原数据
        }else
            ui->groupBox_account_right_dock->setVisible(false);
        ui->stackedWidget_account_name->setCurrentWidget(ui->page_account_name);
        ui->account_fund->setFocus();
    });

    // book - 账本
    connect(ui->book_top,&QPushButton::clicked,this,[=](){
        if("置顶账本"== ui->book_top->text()){
            int index = currBook->text().indexOf("\n");
            currBook->setText(currBook->text().insert(index,DEFAULT_TOP_FLAG));
            ui->book_top->setText("取消置顶");

            //插入到原置顶的尾部
            ui->vLayout_book->insertWidget(bookTopNum,currBook);
            ++bookTopNum;
        }else{
            int index = currBook->text().indexOf("\n");
            currBook->setText(currBook->text().remove(DEFAULT_TOP_FLAG));
            ui->book_top->setText("置顶账本");

            //插入到未置顶的头部
            --bookTopNum;
            ui->vLayout_book->insertWidget(bookTopNum,currBook);
        }
        updateBookSerialTop(); //更新状态
    });
    connect(ui->book_up,&QPushButton::clicked,this,[=](){
        // 计算索引值
        int index = ui->vLayout_book->indexOf(currBook) - 1;
//        ui->vLayout_book->removeWidget(currBook);
        if(index <= 0)
            index = 0; //索引值从0开始

        //置顶范围和非置顶范围
        QLayoutItem* item = ui->vLayout_book->itemAt(index);
        if (item->widget()) {
            auto preBook = qobject_cast<QToolButton*>(item->widget());
            if(!currBook->text().contains(DEFAULT_TOP_FLAG) && preBook->text().contains(DEFAULT_TOP_FLAG))
                return;
        }

        if(index < 5){ // 手动上滑
            auto scrollBar = ui->scrollArea_book->verticalScrollBar();
            scrollBar->setValue(scrollBar->minimumHeight());
        }
        ui->vLayout_book->insertWidget(index,currBook);
        updateBookSerialTop(); //更新状态
    });
    connect(ui->book_down,&QPushButton::clicked,this,[=](){
        // 计算索引值
        int index = ui->vLayout_book->indexOf(currBook) + 1;
        int count = ui->vLayout_book->count() - 1;//总数要减去弹簧
        if(index >= count)
            index = count - 1; //索引值从0开始

        //置顶范围和非置顶范围
        QLayoutItem* item = ui->vLayout_book->itemAt(index);
        if (item->widget()) {
            auto lastBook = qobject_cast<QToolButton*>(item->widget());
            if(currBook->text().contains(DEFAULT_TOP_FLAG) && !lastBook->text().contains(DEFAULT_TOP_FLAG))
                return;
        }

        if(index >= 5){  // 手动下滑
            auto scrollBar = ui->scrollArea_book->verticalScrollBar();
            scrollBar->setValue(scrollBar->maximumHeight());
        }
        ui->vLayout_book->insertWidget(index,currBook);
        updateBookSerialTop(); //更新状态
    });
    connect(ui->book_add,&QPushButton::clicked,this,[=](){
        //重置数据
        ui->book_newName->clear();
        ui->book_newRemark->clear();

        ui->book_delete->setVisible(false);
        ui->book_return->setVisible(true);
        ui->stackedWidget_book->setCurrentWidget(ui->page_addBook);
        ui->book_newName->setFocus();
    });
    connect(ui->book_save,&QPushButton::clicked,this,[=](){
        //添加账本
        if(ui->page_addBook == ui->stackedWidget_book->currentWidget()){
            if(ui->book_newName->text().isEmpty()){
                QMessageBox::information(this,"账本添加","账本名称为空，无法添加账本！",QMessageBox::Ok);
                return;
            }

            QSqlQuery query;
            QString sql = QString("select bok_name from book where bok_name='%1';").arg(ui->book_newName->text());
            if(query.exec(sql) && query.next()){
                QMessageBox::information(this,"账本添加","此账本已存在，无法再次添加！",QMessageBox::Ok);
                return;
            }

            loadingTip(true);//加载提示

            // 初始化数据
            Book book;
            book.setName(ui->book_newName->text());
            book.setRemark(ui->book_newRemark->toPlainText());
            book.setCreateTime(QDateTime::currentDateTime());
            if(db->insertBook(book)){
                recordWin->addBook(book.getName());

                //插入到末尾
                auto item = createBookItem(book);//
                int index = ui->vLayout_book->count() - 1;
                ui->vLayout_book->insertWidget(index, qobject_cast<QWidget*>(item));

                //提示窗口
                loadingTip(false);
                QMessageBox::information(this,"账户添加","账户添加成功！",QMessageBox::Ok);

                //重置数据
                ui->book_newName->clear();
                ui->book_newRemark->clear();
            }else{
                loadingTip(false);
                QMessageBox::information(this,"账本添加","账本添加失败！\n注：请再次尝试或检查资源文件是否正确。",QMessageBox::Ok);
            }
            ui->book_newName->setFocus();
        }else{ //更改账户信息
            if(ui->book_name->text().isEmpty()){
                QMessageBox::information(this,"账本更新","账本名称为空，无法更新账本信息！",QMessageBox::Ok);
                return;
            }

            loadingTip(true);

            // 初始化数据
            Book book;
            book.setTotalIncome(ui->book_totalIncome->value());
            book.setTotalExpend(ui->book_totalExpend->value());
            book.setRemark(ui->book_remark->toPlainText());
            book.setName(ui->book_name->text());
            if(ui->book_name->text().contains(DEFAULT_TOP_FLAG))
                book.setTop(true);
            else
                book.setTop(false);
            book.setSerial(ui->vLayout_book->indexOf(currBook));

            if(db->updateBook(book)){
                loadingTip(false);
                QMessageBox::information(this,"账本更新","账本更新成功！",QMessageBox::Ok);
            }else{
                loadingTip(false);
                QMessageBox::information(this,"账本更新","账本更新失败！\n注：请再次尝试或检查资源文件是否正确。",QMessageBox::Ok);
            }
            ui->book_remark->setFocus();
        }
    });
    connect(ui->book_delete,&QPushButton::clicked,this,[=](){
        QString name = currBook->text().split("\n").at(0);
        QString tip = QString("⚠注意：\n->确定要删除“%1”账本吗?\n->删除会导致账本所有记录都会被清空!!!").arg(name);
        auto ret = QMessageBox::information(this,"账本删除",tip,QMessageBox::Yes,QMessageBox::No);
        if(QMessageBox::Yes == ret && db->deleteBook(name)){ // 直接删除
            recordWin->removeBook(name);

            int index = ui->vLayout_book->indexOf(currBook);
            ui->vLayout_book->removeWidget(qobject_cast<QWidget*>(currBook));
            currBook->deleteLater();
            currBook = nullptr;

            //更改选中项
            int count = ui->vLayout_book->count()-1; //不算弹簧
            QLayoutItem *item;
            if(index >= count) //删除的是末尾的一项
                item = ui->vLayout_book->itemAt(index - 1); //拿前面一个
            else
                item = ui->vLayout_book->itemAt(index); //拿后面一个
            auto toolBtn = qobject_cast<QToolButton*>(item->widget());
            toolBtn->click();
        }
        flushRecordData(true);// 刷新记账记录
        ui->book_remark->setFocus();
    });
    connect(ui->book_return,&QPushButton::clicked,this,[=](){
        if(nullptr != currBook)
            currBook->click();//还原数据
        else
            ui->groupBox_book_right_dock->setVisible(false);
        ui->stackedWidget_book->setCurrentWidget(ui->page_bookInfo);
        ui->book_remark->setFocus();
    });
}

void MainWin:: initRecordData(QSqlQuery &query)
{
    ui->record_tree->deleteAll();

    ui->dock_totalFund_num->setText(QString::number(db->queryTotalFund(),'f',2));
    ui->dock_monthIncome_num->setText(QString::number(db->queryMonthIncome(QDate::currentDate()),'f',2));
    ui->dock_monthExpend_num->setText(QString::number(db->queryMonthExpend(QDate::currentDate()),'f',2));

    qreal expend = 0;
    qreal income = 0;
    qreal transfer = 0;
    QString defaultIncomeStr = "收:0.00" + QString(RECORD_WIDTH - QString("收:0.00").length(),' ');
    QString defaultExpendStr = "支:0.00" + QString(RECORD_WIDTH - QString("支:0.00").length(),' ');
    QString defaultTransferStr = "转:0.00" + QString(RECORD_WIDTH - QString("转:0.00").length(),' ');
    while(query.next()){
        // 遍历根节点，判断日期
        QTreeWidgetItem* rootItem = nullptr;
        int counts = ui->record_tree->topLevelItemCount();
        if(0 == counts){ //第一个根节点
            rootItem = new QTreeWidgetItem(ui->record_tree);
            QString info = QString("%1    %2    %3    %4    %5").arg(query.value("red_datetime").toDateTime().toString("yyyy年MM月dd日"),
                                                                    currentWeek(query.value("red_datetime").toDateTime()),
                                                                    defaultIncomeStr,defaultExpendStr,defaultTransferStr);
            rootItem->setText(0,info);
            rootItem->setSizeHint(0,QSize(ui->record_tree->header()->width(),35));

            QFont font;
            font.setBold(true);
            font.setPointSize(10);
            rootItem->setFont(0,font);
            rootItem->setFirstColumnSpanned(true); //列合并
            ui->record_tree->expandItem(rootItem);//展开根节点
        }else{
            QString datetime = query.value("red_datetime").toDateTime().toString("yyyy年MM月dd日");
            for (int i = 0; i < counts; ++i) {
                QTreeWidgetItem* topItem = ui->record_tree->topLevelItem(i);
                if(datetime == topItem->text(0).split(" ").at(0)){
                    rootItem = topItem;
                    break;
                }
                if(counts - 1 == i){ //新根节点
                    rootItem = new QTreeWidgetItem(ui->record_tree);
                    QString info = QString("%1    %2    %3    %4    %5").arg(query.value("red_datetime").toDateTime().toString("yyyy年MM月dd日"),
                                                                             currentWeek(query.value("red_datetime").toDateTime()),
                                                                             defaultIncomeStr,defaultExpendStr,defaultTransferStr);
                    rootItem->setText(0,info);
                    rootItem->setSizeHint(0,QSize(ui->record_tree->header()->width(),35));

                    QFont font;
                    font.setBold(true);
                    font.setPointSize(10);
                    rootItem->setFont(0,font);
                    rootItem->setFirstColumnSpanned(true); //列合并
                    ui->record_tree->expandItem(rootItem);//展开根节点

                    expend = 0;
                    income = 0;
                    transfer = 0;
                }
            }
        }

        //子项
        QTreeWidgetItem *subItem = new QTreeWidgetItem(rootItem);
        subItem->setSizeHint(0,QSize(ui->record_tree->header()->width(),35));
        subItem->setData(0,Qt::UserRole,query.value("id").toInt()); //存放记录id用户删除
        subItem->setText(1,query.value("bok_name").toString());
        subItem->setText(2,query.value("act_name").toString());
        subItem->setText(3,query.value("red_flow_type").toString());
        qreal money = query.value("red_money").toDouble();
        subItem->setText(4,QString::number(money,'f',2));
        subItem->setText(5,query.value("red_first_classify").toString());
        subItem->setText(6,query.value("red_second_classify").toString());
        subItem->setText(7,query.value("red_transfer_in").toString());
        subItem->setText(8,query.value("red_remark").toString());
        subItem->setToolTip(8,query.value("red_remark").toString()); //设置备注提示

        subItem->setText(9,"查看图片");
        subItem->setData(9,Qt::UserRole,query.value("red_image").toByteArray()); //图片
        QFont font;
        font.setUnderline(true);
        subItem->setFont(9,font);
        QBrush brush(Qt::blue);
        subItem->setForeground(9,brush);

        subItem->setTextAlignment(1,Qt::AlignCenter);
        subItem->setTextAlignment(2,Qt::AlignCenter);
        subItem->setTextAlignment(3,Qt::AlignCenter);
        subItem->setTextAlignment(4,Qt::AlignCenter);
        subItem->setTextAlignment(5,Qt::AlignCenter);
        subItem->setTextAlignment(6,Qt::AlignCenter);
        subItem->setTextAlignment(7,Qt::AlignCenter);

        //2023年11月08日  星期三  收入:xxxx    支出:xxxx    转账:xxxx
        QStringList strList = rootItem->text(0).split(":");
        if("支出" == query.value("red_flow_type").toString()){
            QBrush brush(QColor(216, 30, 6));
            subItem->setForeground(3,brush);
            subItem->setForeground(4,brush);

            expend = strList.at(2).split(" ").at(0).toDouble() + money; //支出

        }else if("收入" == query.value("red_flow_type").toString()){
            QBrush brush(QColor(37, 184, 122));
            subItem->setForeground(3,brush);
            subItem->setForeground(4,brush);

            income = strList.at(1).split(" ").at(0).toDouble() + money;//收入

        }else{ //转账
            QBrush brush(QColor(254, 118, 95));
            subItem->setForeground(3,brush);
            subItem->setForeground(4,brush);

            transfer = strList.at(3).split(" ").at(0).toDouble() + money;//转账
        }

        QString incomeStr = QString("收:%1").arg(QString::number(income,'f',2));
        QString expendStr = QString("支:%1").arg(QString::number(expend,'f',2));
        QString transferStr = QString("转:%1").arg(QString::number(transfer,'f',2));
        QString newincomeStr = incomeStr.leftJustified(RECORD_WIDTH,' ');
        QString newexpendStr = expendStr.leftJustified(RECORD_WIDTH,' ');
        QString newtransferStr = transferStr.leftJustified(RECORD_WIDTH,' ');/*
        QString newincomeStr = incomeStr + QString(RECORD_WIDTH - incomeStr.length(),' ');
        QString newexpendStr = expendStr + QString(RECORD_WIDTH - expendStr.length(),' ');
        QString newtransferStr = transferStr + QString(RECORD_WIDTH - transferStr.length(),' ');*/
        QString newInfo = QString("%1    %2    %3    %4    %5").arg(query.value("red_datetime").toDateTime().toString("yyyy年MM月dd日"),
                                                                     currentWeek(query.value("red_datetime").toDateTime()),
                                                                     newincomeStr,newexpendStr,newtransferStr);
        rootItem->setText(0,newInfo);
//        qDebug()<<newInfo;
    } //while结束处
    initRecordBottomInfo();//更新信息
}

void MainWin::flushRecordData(const bool &filter)
{
    loadingTip(true); //加载提示

    double numOfPage = ui->record_pageRecordNum->currentText().split("条").at(0).toDouble();
    int index = ui->record_pageIndex->value();

    //结算开始和结束索引
    int start = (index-1)*numOfPage;
    int end = start + (numOfPage-1);

    QSqlQuery query;
    if(filter){ //包括顶部过滤条件
        RecordFilter recordfilter;
        recordfilter.setInput(ui->record_input->text());
        recordfilter.setDateType(ui->record_filter->currentText());
        recordfilter.setFlowType(ui->record_flowType->currentText());
        recordfilter.setDate(ui->record_date->date());
        db->queryLimitRecord(query,start,end,recordfilter);
    }else{
        db->queryLimitRecord(query,start,end);
    }

    initRecordData(query); //加载页面数据

    loadingTip(false);//结束提示
    ui->record_input->setFocus();
}

void MainWin::flushWinData(const Account &account, const Book &book)
{
    // 流水记录
    flushRecordData(true);

    // 账户
    auto it = accountMap.find(account.getName());
    if(it != accountMap.end()){
        QString text = QString("%1\n现有资产%2元").arg(account.getName(),
                                                       QString::number(account.getFund(),'f',2));
        it.value()->setText(text);
        if(nullptr != currAccount)
            ui->account_fund->setValue(account.getFund());
    }

    // 账本
    auto _it = bookMap.find(book.getName());
    if(_it != bookMap.end()){
        QString text = QString("%1\n存在%2条账单\n账本创建于%3").arg(book.getName(),
                                                 QString::number(book.getTotalRecord()),
                                                 book.getCreateTime().toString("yyyy年MM月dd日 hh:mm"));
        _it.value()->setText(text);
        if(nullptr != currBook){
            ui->book_totalIncome->setValue(book.getTotalIncome());
            ui->book_totalExpend->setValue(book.getTotalExpend());
        }
    }
    ui->dock_totalFund_num->setText(QString::number(db->queryTotalFund(),'f',2));
    ui->dock_monthIncome_num->setText(QString::number(db->queryMonthIncome(QDate::currentDate()),'f',2));
    ui->dock_monthExpend_num->setText(QString::number(db->queryMonthExpend(QDate::currentDate()),'f',2));
}

void MainWin::initRecordBottomInfo()
{
    double numOfPage = ui->record_pageRecordNum->currentText().split("条").at(0).toDouble();
    QString pageInfo = QString(" 存在%1条记账记录，共%2页。").arg(QString::number(db->queryRecordRows()),
                                                             QString::number(db->getMaxPages(numOfPage)));
    ui->record_pageInfo->setText(pageInfo);
}

QToolButton* MainWin::createBookItem(const Book& book)
{
    QToolButton *toolBtn = new QToolButton(this);
    toolBtn->setMinimumSize(QSize(400,100));
    toolBtn->setMaximumSize(QSize(400,100));
    toolBtn->setIcon(QIcon(":/img/book.png"));
    toolBtn->setIconSize(QSize(85,85));
    toolBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    toolBtn->setContextMenuPolicy(Qt::CustomContextMenu);
    toolBtn->setCheckable(true);
    toolBtn->setAutoExclusive(true);

    QString name;
    if(book.getTop()){
        name = book.getName() + DEFAULT_TOP_FLAG;
        ++bookTopNum;
    }else
        name = book.getName();
    QString text = QString("%1\n存在%2条账单\n账本创建于%3").arg(name,
                                             QString::number(book.getTotalRecord()),
                                             book.getCreateTime().toString("yyyy年MM月dd日 hh:mm"));
    toolBtn->setText(text);
    bookMap.insert(book.getName(),toolBtn);//加入map中

    // 选择展示信息
    connect(toolBtn,&QToolButton::clicked,this,[=](){
        if(toolBtn == currBook){
            if(ui->vLayout_book->count() <= 2) //弹簧
                toolBtn->setChecked(true);
            return;
        }
        currBook = toolBtn;

        //显隐
        ui->book_return->setVisible(false);
        ui->book_delete->setVisible(true);
        ui->stackedWidget_book->setCurrentWidget(ui->page_bookInfo);

        //更改
        if(DEFAULT_BOOK == book.getName()){
            ui->book_delete->setVisible(false); //默认账本不可删除
            ui->book_totalIncome->setReadOnly(true);
            ui->book_totalExpend->setReadOnly(true);
        }else{
            ui->book_delete->setVisible(true);
            ui->book_totalIncome->setReadOnly(false);
            ui->book_totalExpend->setReadOnly(false);
        }

        //数据
        //判断是否置顶
        Book book;
        QString name;
        if(toolBtn->text().contains(DEFAULT_TOP_FLAG)){
            book = db->queryBook(toolBtn->text().split(DEFAULT_TOP_FLAG).at(0));
            name = book.getName() + DEFAULT_TOP_FLAG;
            ui->book_top->setText("取消置顶");
        }else{
            book = db->queryBook(toolBtn->text().split("\n").at(0));
            name = book.getName();
            ui->book_top->setText("置顶账本");
        }
        QString text = QString("%1\n存在%2条账单\n账本创建于%3").arg(name,
                                                 QString::number(book.getTotalRecord()),
                                                 book.getCreateTime().toString("yyyy年MM月dd日 hh:mm"));
        toolBtn->setText(text);
        ui->book_totalIncome->setValue(book.getTotalIncome());
        ui->book_totalExpend->setValue(book.getTotalExpend());
        ui->book_name->setText(book.getName());
        ui->book_remark->setPlainText(book.getRemark());

        QString info = QString("账本创建于%1，已记录“%2”条账单。").arg(book.getCreateTime().toString("yyyy年MM月dd日"),
                                                                                            QString::number(book.getTotalRecord()));
        ui->book_info->setText(info);
        ui->book_remark->setFocus();
    });
    return toolBtn;
}

QToolButton *MainWin::createAccountItem(const Account &account)
{
    QToolButton *toolBtn = new QToolButton(this);
    toolBtn->setMinimumSize(QSize(400,70));
    toolBtn->setMaximumSize(QSize(400,70));
    toolBtn->setIcon(QIcon(":/img/account.png"));
    toolBtn->setIconSize(QSize(55,55));
    toolBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    toolBtn->setCheckable(true);
    toolBtn->setAutoExclusive(true);

    QString name;
    if(account.getTop()){
        name = account.getName() + DEFAULT_TOP_FLAG;
        ++accountTopnum;
    }else
        name = account.getName();
    QString text = QString("%1\n现有资产%2元").arg(name,QString::number(account.getFund(),'f',2));
    toolBtn->setText(text);
    accountMap.insert(account.getName(),toolBtn);//加入map中

    // 选择展示信息
    connect(toolBtn,&QToolButton::clicked,this,[=](){
        if(toolBtn == currAccount && !isAccountRestore ){
            if(ui->vLayout_account->count() <= 2) //弹簧
                toolBtn->setChecked(true);
            return;
        }

        currAccount = toolBtn;
        isAccountRestore = false;

        //显隐
        ui->account_return->setVisible(false);
        ui->account_delete->setVisible(true);
        ui->stackedWidget_account_name->setCurrentWidget(ui->page_account_name);

        //更改
        if(DEFAULT_ACCOUNT == account.getName()){
            ui->account_delete->setVisible(false);//默认账户不可删除
            ui->widget_account_enable->setVisible(false);
        }else{
//            ui->widget_account_enable->setVisible(true);// 暂不开启
            ui->widget_account_enable->setVisible(false);
            ui->account_delete->setVisible(true);
        }

        //数据
        //判断是否置顶
        Account account;
        QString name;
        if(toolBtn->text().contains(DEFAULT_TOP_FLAG)){
            account = db->queryAccount(toolBtn->text().split(DEFAULT_TOP_FLAG).at(0));
            name = account.getName() + DEFAULT_TOP_FLAG;
            ui->account_top->setText("取消置顶");
        }else{
            account = db->queryAccount(toolBtn->text().split("\n").at(0));
            name = account.getName();
            ui->account_top->setText("置顶账户");
        }
        QString text = QString("%1\n现有资产%2元").arg(name,QString::number(account.getFund(),'f',2));
        toolBtn->setText(text);
        ui->account_name->setText(name);
        ui->account_fund->setValue(account.getFund());
        ui->account_nickname->setText(account.getNickname());
        ui->account_card->setText(account.getCardNumber());
        ui->account_remark->setPlainText(account.getRemark());
        ui->account_enable->setChecked(account.getEnable());

        ui->account_fund->setFocus();
    });
    return toolBtn;
}

void MainWin::updateBookSerialTop()
{
    int count = ui->vLayout_book->count() - 1;//弹簧不算
    recordWin->removeAllBook();
    for (int i = 0; i < count; ++i) {
        QLayoutItem* item = ui->vLayout_book->itemAt(i);
//        if (item->widget()) {
        auto toolBtn = qobject_cast<QToolButton*>(item->widget());
        QString name = toolBtn->text().split("\n").at(0);
        if(name.contains(DEFAULT_TOP_FLAG)){
            name.remove(DEFAULT_TOP_FLAG);
            db->updateBookSerialTop(name,(i+1),true);
        }else
            db->updateBookSerialTop(name,(i+1),false);
        recordWin->addBook(name);
//        }
    }
}

void MainWin::updateAccountSerialTop()
{
    int count = ui->vLayout_account->count() - 1;//弹簧不算
    recordWin->removeAllAccount();
    for (int i = 0; i < count; ++i) {
        QLayoutItem* item = ui->vLayout_account->itemAt(i);
//        if (item->widget()) {
        auto toolBtn = qobject_cast<QToolButton*>(item->widget());
        QString name = toolBtn->text().split("\n").at(0);
        if(name.contains(DEFAULT_TOP_FLAG)){
            name.remove(DEFAULT_TOP_FLAG);
            db->updateAccountSerialTop(name,(i+1),true);
        }else
            db->updateAccountSerialTop(name,(i+1),false);
        recordWin->addAccount(name);
//        }
    }
}

/*
QToolButton* MainWin::currCheckedBook()
{
    int counts = ui->vLayout_book->count();
    for (int i = 0; i < counts; ++i) {
        QLayoutItem* item = ui->vLayout_book->itemAt(i);
        if (item->widget() != nullptr && item->widget()->isWidgetType() && qobject_cast<QToolButton*>(item->widget())) {
            QToolButton* toolBtn = qobject_cast<QToolButton*>(item->widget());
            if(toolBtn->isChecked())
                return toolBtn;
        }
    }
    return nullptr;
}

QToolButton* MainWin::currCheckedAccount()
{
    int counts = ui->vLayout_account->count();
    for (int i = 0; i < counts; ++i) {
        QLayoutItem* item = ui->vLayout_account->itemAt(i);
        if (item->widget() != nullptr && item->widget()->isWidgetType() && qobject_cast<QToolButton*>(item->widget())) {
            QToolButton* toolBtn = qobject_cast<QToolButton*>(item->widget());
            if(toolBtn->isChecked())
                return toolBtn;
        }
    }
    return nullptr;
}
*/

QString MainWin::currentWeek(const QDateTime &datetime)
{
    int dayOfWeek = datetime.date().dayOfWeek(); // 获取星期几的枚举值

    QString week;
    switch (dayOfWeek) {
    case Qt::Monday:
        week = "星期一";
        break;
    case Qt::Tuesday:
        week = "星期二";
        break;
    case Qt::Wednesday:
        week = "星期三";
        break;
    case Qt::Thursday:
        week = "星期四";
        break;
    case Qt::Friday:
        week = "星期五";
        break;
    case Qt::Saturday:
        week = "星期六";
        break;
    case Qt::Sunday:
        week = "星期天";
        break;
    default:
        break;
    }
    return week;
}

void MainWin::loadingTip(const bool &bol)
{
    if(bol){
        movie->start();
        if(ui->dock_record->isChecked())
            ui->stackedWidget_record->setCurrentWidget(ui->page_record_loading);
        else if(ui->dock_account->isChecked())
            ui->account_loading->setVisible(bol);
        else if(ui->dock_book->isChecked())
            ui->book_loading->setVisible(bol);
    }else{
        if(ui->dock_record->isChecked()){
            ui->stackedWidget_record->setCurrentWidget(ui->page_record_tree);
            movie->stop();
        }else if(ui->dock_account->isChecked()){
            QTimer::singleShot(300,this,[=](){
                ui->account_loading->setVisible(bol);
                movie->stop();
            });
        }else if(ui->dock_book->isChecked()){
            QTimer::singleShot(300,this,[=](){
                ui->book_loading->setVisible(bol);
                movie->stop();
            });
        }
    }
}

