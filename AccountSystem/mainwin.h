#ifndef MAINWIN_H
#define MAINWIN_H

#include <QMainWindow>
#include <QToolButton>

#include "ui/addwin.h"
#include "dev/config.h"
#include "db/database.h"

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
    void initData();
    void initSignalSlots();
    QToolButton* createBookItem(const Book& book);

    AddWin *addWin;//记账窗口
    Config *config;//配置管理
    DataBase *db;

private:
    Ui::MainWin *ui;
};
#endif // MAINWIN_H
