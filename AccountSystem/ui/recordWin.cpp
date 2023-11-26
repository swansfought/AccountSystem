#include "recordWin.h"
#include "ui_recordwin.h"

RecordWin::RecordWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RecordWin)
{
    ui->setupUi(this);

    QFont font;
    font.setFamily("微软雅黑");
    this->setFont(font);
    this->setWindowModality(Qt::WindowModal); //设置为模态窗口
    this->setWindowFlags(Qt::Window | Qt::CustomizeWindowHint);

    config = Config::getInstance();
    db = DataBase::getInstance();

    initSignalSlots();
    initData(); //先绑定槽，涉及到槽函数触发设置数据
}

RecordWin::~RecordWin()
{
    delete ui;
}

void RecordWin::setWinMode(const RecordWMode &mode)
{
    switch (mode) {
    case Show:{
        ui->save_again->setVisible(false);
        break;
    }
    case Add:{
        ui->save_again->setVisible(true);
        break;
    }
    default:
        break;
    }
}


void RecordWin::addBook(const QString &name)
{
    ui->book->addItem(name);
}

void RecordWin::removeBook(const QString &name)
{
    ui->book->removeItem( ui->book->findText(name));
}

void RecordWin::addAccount(const QString &name)
{
    ui->account->addItem(name);
    ui->account_in->addItem(name);
}

void RecordWin::removeAccount(const QString &name)
{
    ui->account->removeItem( ui->account->findText(name));
    ui->account_in->removeItem( ui->account_in->findText(name));
}

void RecordWin::setBook(const QString &name)
{
    ui->book->setCurrentText(name);
}

void RecordWin::setAccount(const QString &name)
{
    ui->account->setCurrentText(name);
    ui->account_in->setCurrentText(name);
}

void RecordWin::setFlowType(const QString &text)
{
    ui->flowType->setCurrentText(text);
}

void RecordWin::setFirstClassify(const QString &text)
{
    ui->firstClassify->setCurrentText(text);
}

void RecordWin::setSecondClassify(const QString &text)
{
    ui->secondClassify->setCurrentText(text);
}

void RecordWin::setMoney(const qreal &money)
{
    ui->money->setValue(money);
}

void RecordWin::setRemark(const QString &text)
{
    ui->remark->setPlainText(text);
}

void RecordWin::setDateEdit(const QDateTime& datetime)
{
    ui->dateEdit->setDateTime(datetime);
}

void RecordWin::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    resetWin();
    this->hide();
}

void RecordWin::initData()
{
    QJsonArray accountArr = config->getJsonArray(Config::Type::Accounts);
    for (int i = 0; i < accountArr.size(); ++i){
        ui->account->addItem(accountArr.at(i).toString());
        ui->account_in->addItem(accountArr.at(i).toString());
    }

    QJsonArray flowTypeArr = config->getJsonArray(Config::Type::Money_Flow_Type);
    for (int j = 0; j < flowTypeArr.size(); ++j){
        ui->flowType->addItem(flowTypeArr.at(j).toString());
    }

    ui->flowType->setCurrentText("支出"); //默认为支出
    ui->dateEdit->setDateTime(QDateTime::currentDateTime()); //当前时间
}

void RecordWin::initSignalSlots()
{
    connect(ui->save,&QPushButton::clicked,this,[=](){
        if(0 == ui->money->value()){
            QMessageBox::information(this,"记账添加","请确保金额>=0！",QMessageBox::Ok);
            return;
        }else if("转账" == ui->flowType->currentText() && ui->account->currentText() == ui->account_in->currentText()){
            QMessageBox::information(this,"记账添加","无法对自己进行转账！",QMessageBox::Ok);
            return;
        }
        if(saveRecord())
            this->close();
        else
            QMessageBox::information(this,"记账添加","记账失败！\n注：请再次尝试或检查资源文件是否正确。",QMessageBox::Ok);
    });
    connect(ui->save_again,&QPushButton::clicked,this,[=](){
        if(0 == ui->money->value()){
            QMessageBox::information(this,"记账添加","请确保金额>=0！",QMessageBox::Ok);
            return;
        }else if("转账" == ui->flowType->currentText() && ui->account->currentText() == ui->account_in->currentText()){
            QMessageBox::information(this,"记账添加","无法对自己进行转账！",QMessageBox::Ok);
            return;
        }
        if(saveRecord()){
            ui->money->setValue(0);
            ui->remark->clear();
            ui->image->clear();
        }else
            QMessageBox::information(this,"记账添加","记账失败！\n注：请再次尝试或检查资源文件是否正确。",QMessageBox::Ok);
    });
    connect(ui->close,&QPushButton::clicked,this,[=](){
        this->close();
    });
    connect(ui->selectImage,&QPushButton::clicked,this,[=](){
        QString filter = "*.png *jpeg *jpg *bmp";
        QString fileName = QFileDialog::getOpenFileName(this,"选择图片","C:/",filter);
        if(fileName.isEmpty())
            return;
        ui->image->clear(); //清除之前剩余的
        QPixmap pixmap;
        pixmap.load(fileName);
        ui->image->setPixmap(pixmap);
    });
    connect(ui->deleteImage,&QPushButton::clicked,this,[=](){ ui->image->clear(); });
    connect(ui->firstClassify,&QComboBox::currentTextChanged,this,[=](const QString& text){
        QJsonArray arr;
        if("购物" == text)
            arr = config->getJsonArray(Config::Type::Expend_Second_GouWu);
        else if("餐饮" == text)
            arr = config->getJsonArray(Config::Type::Expend_Second_CanYin);
        else if("交通" == text)
            arr = config->getJsonArray(Config::Type::Expend_Second_JiaoTong);
        else if("娱乐" == text)
            arr = config->getJsonArray(Config::Type::Expend_Second_YuLe);
        else if("旅游" == text)
            arr = config->getJsonArray(Config::Type::Expend_Second_LvYou);
        else if("家居" == text)
            arr = config->getJsonArray(Config::Type::Expend_Second_JiaJu);
        else if("教育" == text)
            arr = config->getJsonArray(Config::Type::Expend_Second_JiaoYu);
        else if("人情" == text)
            arr = config->getJsonArray(Config::Type::Expend_Second_RenQing);
        else if("医疗" == text)
            arr = config->getJsonArray(Config::Type::Expend_Second_YiLiao);
        else if("通讯" == text)
            arr = config->getJsonArray(Config::Type::Expend_Second_TongXun);
        else if("杂项" == text)
            arr = config->getJsonArray(Config::Type::Expend_Second_ZaXiang);

        ui->secondClassify->clear(); //清除之前的
        for (int i = 0; i < arr.size(); ++i)
            ui->secondClassify->addItem(arr.at(i).toString());
    });
    connect(ui->flowType,&QComboBox::currentTextChanged,this,[=](const QString& text){
        if("收入" == text){
            ui->lab_firstClassify->setText("分       类");
            ui->widget_first->setVisible(true);
            ui->widget_second->setVisible(false);
            ui->widget_transfer_in->setVisible(false);

            ui->firstClassify->clear();
            QJsonArray arr = config->getJsonArray(Config::Type::Income_Classify);
            for (int i = 0; i < arr.size(); ++i){
                ui->firstClassify->addItem(arr.at(i).toString());
            }
        }else if("支出" == text){
            ui->lab_firstClassify->setText("一级分类");
            ui->widget_first->setVisible(true);
            ui->widget_second->setVisible(true);
            ui->widget_transfer_in->setVisible(false);

            ui->firstClassify->clear();
            QJsonArray arr = config->getJsonArray(Config::Type::Expend_First_Classify);
            for (int i = 0; i < arr.size(); ++i){
                ui->firstClassify->addItem(arr.at(i).toString());
            }
        }else if("转账" == text){
            ui->widget_first->setVisible(false);
            ui->widget_second->setVisible(false);
            ui->widget_transfer_in->setVisible(true);
        }
    });
}

void RecordWin::resetWin()
{
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
    ui->book->setCurrentIndex(0);
    ui->account->setCurrentIndex(0);
    ui->flowType->setCurrentText("支出");
    ui->firstClassify->setCurrentIndex(0);
    ui->secondClassify->setCurrentIndex(0);
    ui->money->setValue(0);
    ui->remark->clear();
    ui->image->clear();
}

bool RecordWin::saveRecord()
{
    Record record;
    QString flowType = ui->flowType->currentText();

    record.setBookName(ui->book->currentText());
    record.setFlowType(ui->flowType->currentText());
    record.setAccountName(ui->account->currentText());
    record.setMoney(ui->money->value());
    record.setRemark(ui->remark->toPlainText());

    //设置日期时间，时间按照当前时间记录，日期供用户可选择
    QDateTime dateTime = ui->dateEdit->dateTime();
    dateTime.setTime(QDateTime::currentDateTime().time());
    record.setRecordTime(dateTime.toString("yyyy-MM-dd hh:mm:ss"));

    //获取图片
    QPixmap pixmap = ui->image->pixmap(Qt::ReturnByValue);

    //从pixmap加载图片的二进制数据
    QByteArray imageArray;
    QBuffer buffer(&imageArray);
    buffer.open(QIODevice::WriteOnly);
    pixmap.save(&buffer, "PNG");
    buffer.close();

    record.setImage(imageArray);

    Book book = db->queryBook(ui->book->currentText());
    Account account = db->queryAccount(ui->account->currentText());
    if("支出" == flowType){
        record.setFirstClassify(ui->firstClassify->currentText());
        record.setSecondClassify(ui->secondClassify->currentText());

        book.setTotalExpend(book.getTotalExpend() + ui->money->value());// 更新账本总支出
        account.setFund(account.getFund() - ui->money->value());// 更新账户总资产

    }else if("收入" == flowType){
        record.setFirstClassify(ui->firstClassify->currentText());

        book.setTotalIncome(book.getTotalIncome() + ui->money->value());// 更新账本总收入
        account.setFund(account.getFund() + ui->money->value());// 更新账户总资产

    }else{ //转账
        record.setTransferIn(ui->account_in->currentText());
    }

     //开始保存数据
    if(db->insertRecord(record)){
        db->updateBook(book);
        db->updateAccount(account);

        //通知主窗口更新数据
        book.setTotalRecord(db->queryRecordRows(ui->book->currentText())); //总记录保存一下
        emit flushWinData(account,book);
        return true;
    }
    return false;
}


