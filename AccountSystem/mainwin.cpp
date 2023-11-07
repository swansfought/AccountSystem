#include "mainwin.h"
#include "./ui_mainwin.h"

MainWin::MainWin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWin)
{
    ui->setupUi(this);

    this->setMinimumSize(QSize(1300,750));


}

MainWin::~MainWin()
{
    delete ui;
}


void MainWin::on_btn_record_clicked()
{

}


void MainWin::on_btn_borrow_clicked()
{

}


void MainWin::on_btn_analysis_clicked()
{

}


void MainWin::on_btn_asset_clicked()
{

}


void MainWin::on_btn_book_clicked()
{

}


void MainWin::on_btn_classify_clicked()
{

}


void MainWin::on_btn_setting_clicked()
{

}

