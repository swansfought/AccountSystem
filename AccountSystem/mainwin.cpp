#include "mainwin.h"
#include "./ui_mainwin.h"

MainWin::MainWin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWin)
{
    ui->setupUi(this);

    //    this->setMinimumSize(QSize(1300,750));


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

