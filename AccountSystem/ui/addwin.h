#ifndef ADDWIN_H
#define ADDWIN_H

#include <QMainWindow>
#include <QFileDialog>
#include <QComboBox>
#include <QGraphicsDropShadowEffect>
#include <QBuffer>

#include "dev/config.h"
#include "db/database.h"

namespace Ui {
class AddWin;
}

class AddWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddWin(QWidget *parent = nullptr);
    ~AddWin();


protected:
//    void closeEvent(QCloseEvent *event);
//    void mouseMoveEvent(QMouseEvent* event) override;


private:
    void initData();
    void initSignalSlots();
    void resetWin();
    void saveRecord();
//    void setAccount(const QJsonArray& arr);
//    void setFlowType(const QJsonArray& arr);
//    void setFirstClassify(const QJsonArray& arr);
//    void setSecondClassify(const QJsonArray& arr);

    Config *config;//分类管理
    DataBase *db;



private:
    Ui::AddWin *ui;
};

#endif // ADDWIN_H
