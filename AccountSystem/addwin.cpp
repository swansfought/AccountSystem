#include "addwin.h"
#include "ui_addwin.h"

AddWin::AddWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddWin)
{
    ui->setupUi(this);
}

AddWin::~AddWin()
{
    delete ui;
}
