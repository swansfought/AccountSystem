#ifndef MAINWIN_H
#define MAINWIN_H

#include <QMainWindow>
#include <QToolButton>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QToolTip>

#include "ui/addwin.h"
#include "dev/config.h"
#include "db/database.h"
#include "db/account.h"
#include "db/book.h"
#include "global.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWin; }
QT_END_NAMESPACE

class MainWin : public QMainWindow
{
    Q_OBJECT

public:
    MainWin(QWidget *parent = nullptr);
    ~MainWin();


private:
    void initWinData();
    void initRecordData();
    void initSignalSlots();
    QToolButton* createBookItem(const Book& book);
    QToolButton* createAccountItem(const Account& account);
    bool bookIsChecked();
    bool accountIsChecked();

    qreal totalFund;
    qreal totalIncome;
    qreal totalExpend;
    DataBase *db; //数据库
    AddWin *addWin;//记账窗口
    Config *config;//配置管理

    QToolButton* currAccount;
    QToolButton* currBook;

private:
    Ui::MainWin *ui;
};
#endif // MAINWIN_H
