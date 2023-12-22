#ifndef MAINWIN_H
#define MAINWIN_H

#include <QMainWindow>
#include <QToolButton>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QToolTip>
#include <QMovie>
#include <QScrollArea>
#include <QScrollBar>
#include <QTreeWidget>

#include "ui/recordWin.h"
#include "ui/textcandidate.h"
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

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    void on_deleteRecord();

private:
    void initStyle();
    void initWinData();
    void initSignalSlots();

    void initRecordData(QSqlQuery &query);
    void initRecordBottomInfo();
    void flushRecordData(const bool& filter);
    void flushAnalysisData();
    void flushWinData(const Account &account, const Book &book);


    QToolButton* createBookItem(const Book& book);
    QToolButton* createAccountItem(const Account& account);
    void updateBookSerialTop();
    void updateAccountSerialTop();

    QString currentWeek(const QDateTime &datetime);

    QMovie *movie;
    void loadingTip(const bool& bol);

//    void save

    DataBase *db; //数据库
    RecordWin *recordWin;//记账窗口
//    Config *config;//配置管理
    TextCandidate *textCandidate;

    bool isAccountRestore;
    QToolButton* currAccount;
    QToolButton* currBook;
    QMap<QString,QToolButton*> accountMap;
    QMap<QString,QToolButton*> bookMap;

    int bookTopNum;
    int accountTopnum;

    bool isFlushAnalysis;

private:
    Ui::MainWin *ui;
};
#endif // MAINWIN_H
