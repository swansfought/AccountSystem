#include "addwin.h"
#include "ui_addwin.h"

AddWin::AddWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddWin)
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
    initData();
}

AddWin::~AddWin()
{
    delete ui;
}

void AddWin::initData()
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
}

void AddWin::initSignalSlots()
{
    connect(ui->save,&QPushButton::clicked,this,[=](){
        saveRecord();
        this->close();
    });
    connect(ui->save_again,&QPushButton::clicked,this,[=](){
        saveRecord();
        ui->money->setValue(0);
        ui->remark->clear();
        ui->image->clear();
    });
    connect(ui->close,&QPushButton::clicked,this,[=](){
        this->close();
        resetWin();
    });
    connect(ui->selectImage,&QPushButton::clicked,this,[=](){
        QString filter = "*.png *jpeg *jpg *bmp";
        QString fileName = QFileDialog::getOpenFileName(this,"选择图片","C:/",filter);
        if(fileName.isEmpty())
            return;
        ui->image->clear(); //清除之前剩余的
        QPixmap pixmap;
        pixmap.load(fileName);

        //从pixmap加载图片的二进制数据
        QByteArray imageArray;
        QBuffer buffer(&imageArray);
        buffer.open(QIODevice::WriteOnly);
        pixmap.save(&buffer, "PNG");
        buffer.close();

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

void AddWin::resetWin()
{
    ui->account->setCurrentIndex(0);
    ui->flowType->setCurrentIndex(0);
    ui->firstClassify->setCurrentIndex(0);
    ui->secondClassify->setCurrentIndex(0);
    ui->money->setValue(0);
    ui->remark->clear();
    ui->image->clear();
}

void AddWin::saveRecord()
{

}


