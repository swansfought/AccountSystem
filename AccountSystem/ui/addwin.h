#ifndef ADDWIN_H
#define ADDWIN_H

#include <QGraphicsDropShadowEffect>
#include <QMainWindow>
#include <QFileDialog>
#include <QComboBox>
#include <QMessageBox>
#include <QBuffer>
#include <QPixmap>
#include <QImage>

#include "dev/config.h"
#include "db/database.h"
#include "db/record.h"
#include "global.h"

namespace Ui {
class AddWin;
}

class AddWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddWin(QWidget *parent = nullptr);
    ~AddWin();

    void addBook(const QString& name);
    void addAccount(const QString& name);

    void setBook(const QString& name);
    void setAccount(const QString& name);
    void setFlowType(const QString& name);
    void setFirstClassify(const QString& text);
    void setSecondClassify(const QString& text);
    void setMoney(const qreal& money);
    void setRemark(const QString& text);
    void setDateEdit(const QDateTime& datetime);

protected:
//    void closeEvent(QCloseEvent *event);
//    void mouseMoveEvent(QMouseEvent* event) override;


private:
    void initData();
    void initSignalSlots();
    void resetWin();
    bool saveRecord();
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
