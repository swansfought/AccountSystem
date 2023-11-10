#include "mainwin.h"
#include "./ui_mainwin.h"

MainWin::MainWin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWin)
{
    ui->setupUi(this);

    // 添加记账窗口
    addWin = new AddWin(this);
    QFont font;
    font.setFamily("微软雅黑");
    addWin->setFont(font);
    addWin->setWindowModality(Qt::WindowModal); //设置为模态窗口
    //    addWin->setWindowFlags(Qt::Dialog);
    addWin->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);//只显示关闭按钮 //| Qt::WindowTitleHint | Qt::CustomizeWindowHint

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

