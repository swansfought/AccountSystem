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
//    this->setWindowFlags(Qt::Window | Qt::CustomizeWindowHint);

    this->setMinimumSize(QSize(600,350));
    this->setMaximumSize(QSize(600,350));

    config = Config::getInstance();
    db = DataBase::getInstance();
    currMode = RecordWMode::Add;
    itemId = 0;

    initSignalSlots();
    initData(); //先绑定槽，涉及到槽函数触发设置数据
}

RecordWin::~RecordWin()
{
    delete ui;
}

void RecordWin::setWinMode(const RecordWMode &mode,int itemId)
{
    this->itemId = itemId;
    switch (mode) {
    case Show:{
        this->setWindowTitle("记录更新");
        currMode = RecordWMode::Show;
        ui->save_again->setVisible(false);
        ui->deleteRecord->setVisible(true);
        ui->money->setFocus();
        break;
    }
    case Add:{
        this->setWindowTitle("记录新增");
        currMode = RecordWMode::Add;
        ui->save_again->setVisible(true);
        ui->deleteRecord->setVisible(false);
        ui->money->setFocus();
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

void RecordWin::removeAllBook()
{
    ui->book->clear();
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

void RecordWin::removeAllAccount()
{
    ui->account->clear();
    ui->account_in->clear();
}

void RecordWin::setBook(const QString &name)
{
    ui->book->setCurrentText(name);
}

void RecordWin::setAccount(const QString &name)
{
    ui->account->setCurrentText(name);
}

void RecordWin::setAccountIn(const QString &name)
{
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

void RecordWin::setImage(const QByteArray &image)
{
    imgPixmap.loadFromData(image);
}

void RecordWin::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    resetWin();
    this->hide();
}

//bool RecordWin::event(QEvent * event)
//{
//    if (QEvent::ActivationChange == event->type()) {
//        if (QApplication::activeWindow() != this){
//            this->hide();
//        }
//    }

//    return QWidget::event(event);
//}


void RecordWin::initData()
{
    // 加载图标
    movie = new QMovie(":/img/loading.gif");
    ui->loading->setMovie(movie);
    ui->loading->setVisible(false);


    //流向
    QJsonArray flowTypeArr = config->getJsonArray(Config::Type::Money_Flow_Type);
    for (int j = 0; j < flowTypeArr.size(); ++j){
        ui->flowType->addItem(flowTypeArr.at(j).toString());
    }

    ui->flowType->setCurrentText("支出"); //默认为支出，触发加载一二级分类
    ui->dateEdit->setDateTime(QDateTime::currentDateTime()); //当前时间
}

void RecordWin::initSignalSlots()
{
    connect(ui->save,&QPushButton::clicked,this,[=](){
        if(RecordWMode::Add == currMode){
            if(0 == ui->money->value()){
                QMessageBox::information(this,"记账添加","请确保金额>=0！",QMessageBox::Ok);
                return;
            }else if("转账" == ui->flowType->currentText() && ui->account->currentText() == ui->account_in->currentText()){
                QMessageBox::information(this,"记账添加","无法对自己进行转账！",QMessageBox::Ok);
                return;
            }
            loadingTip(true);
            if(saveRecord()){
                loadingTip(false);
                this->close();
            }else{
                loadingTip(false);
                QMessageBox::information(this,"记账添加","记账失败！\n注：请再次尝试或检查资源文件是否正确。",QMessageBox::Ok);
            }
        }else{
            if(0 == ui->money->value()){
                QMessageBox::information(this,"记录更新","请确保金额>=0！",QMessageBox::Ok);
                return;
            }else if("转账" == ui->flowType->currentText() && ui->account->currentText() == ui->account_in->currentText()){
                QMessageBox::information(this,"记录更新","无法对自己进行转账！",QMessageBox::Ok);
                return;
            }
            loadingTip(true);
            if(saveRecord()){
                loadingTip(false);
                this->close();
            }else{
                loadingTip(false);
                QMessageBox::information(this,"记录更新","更新失败！\n注：请再次尝试或检查资源文件是否正确。",QMessageBox::Ok);
            }
        }

    });
    connect(ui->save_again,&QPushButton::clicked,this,[=](){
        if(0 == ui->money->value()){
            QMessageBox::information(this,"记账添加","请确保金额>=0！",QMessageBox::Ok);
            return;
        }else if("转账" == ui->flowType->currentText() && ui->account->currentText() == ui->account_in->currentText()){
            QMessageBox::information(this,"记账添加","无法对自己进行转账！",QMessageBox::Ok);
            return;
        }
        loadingTip(true);
        if(saveRecord()){
            loadingTip(false);
            ui->money->setValue(0);
            ui->remark->clear();
//            ui->image->clear();
            ui->deleteImage->click();
            ui->money->setFocus();
        }else{
            loadingTip(false);
            QMessageBox::information(this,"记账添加","记账失败！\n注：请再次尝试或检查资源文件是否正确。",QMessageBox::Ok);
            ui->money->setFocus();
        }
    });
    connect(ui->selectImage,&QPushButton::clicked,this,[=](){
        QString filter = "*.png *jpeg *jpg *bmp";
        QString fileName = QFileDialog::getOpenFileName(this,"选择图片","C:/",filter);
        if(fileName.isEmpty())
            return;
//        ui->image->clear(); //清除之前剩余的
//        QPixmap pixmap;
        ui->loading_image->setText("上传中...");
        if(imgPixmap.load(fileName))
            ui->loading_image->setText("上传成功!");
        else
            ui->loading_image->setText("上传失败!");
//        ui->image->setPixmap(pixmap);
        ui->remark->setFocus();
    });
    connect(ui->deleteImage,&QPushButton::clicked,this,[=](){
//        ui->image->clear();
        ui->loading_image->setText("");
        imgPixmap = QPixmap();
        ui->remark->setFocus();
    });
    connect(ui->deleteRecord,&QPushButton::clicked,this,[=](){
        auto ret = QMessageBox::information(this,"记录删除","确定要删除此记录吗？",QMessageBox::Yes,QMessageBox::No);
        if(QMessageBox::Yes == ret)
            emit deleteRecord();
    });
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
    connect(ui->dateEdit,&QDateEdit::dateChanged,this,[=](const QDate &date){
        if(date > QDate::currentDate()){
            ui->dateEdit->setDate(QDate::currentDate());
        }
    });
    connect(ui->money,qOverload<double>(&QDoubleSpinBox::valueChanged),this,[=](double money){
        if(99999999 < money)
            ui->money->setValue(99999999.99);
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
//    ui->image->clear();
}

bool RecordWin::saveRecord()
{
    Record record;
    QString flowType = ui->flowType->currentText();

    record.setId(itemId);
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
//    QPixmap pixmap = ui->image->pixmap(Qt::ReturnByValue);

    //从pixmap加载图片的二进制数据
    QByteArray imageArray;
    QBuffer buffer(&imageArray);
    buffer.open(QIODevice::WriteOnly);
    imgPixmap.save(&buffer, "PNG");
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
    bool ret = false;
    if(RecordWin::Add == currMode){
        if(db->insertRecord(record))
            ret = true;
    }else{
        if(db->updateRecord(record))
            ret = true;
    }
    if(ret){
        db->updateBook(book);
        db->updateAccount(account);

        //通知主窗口更新数据
        book.setTotalRecord(db->queryRecordRows(ui->book->currentText())); //总记录保存一下
        emit flushWinData(account,book);
        return true;
    }
    return false;
}

void RecordWin::loadingTip(const bool &bol)
{
    if(bol){
        ui->loading->setVisible(bol);
        movie->start();
    }else{
        QTimer::singleShot(500,this,[=](){
            ui->loading->setVisible(bol);
            movie->stop();
        });
    }
}


