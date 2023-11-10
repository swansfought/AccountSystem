#ifndef MAINWIN_H
#define MAINWIN_H

#include <QMainWindow>

#include "addwin.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWin; }
QT_END_NAMESPACE

class MainWin : public QMainWindow
{
    Q_OBJECT

public:
    MainWin(QWidget *parent = nullptr);
    ~MainWin();

private slots:
    // dock栏按
    void on_btn_record_clicked();
    void on_btn_analysis_clicked();
    void on_btn_borrowReturn_clicked();
    void on_btn_asset_clicked();
    void on_btn_accountBook_clicked();
    void on_btn_classify_clicked();
    void on_btn_setting_clicked();


    void on_btn_addRecord_clicked();

private:
    AddWin *addWin;//记账窗口

private:
    Ui::MainWin *ui;
};
#endif // MAINWIN_H
