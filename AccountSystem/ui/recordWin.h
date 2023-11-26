#ifndef RECORDWIN_H
#define RECORDWIN_H

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
class RecordWin;
}

class RecordWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit RecordWin(QWidget *parent = nullptr);
    ~RecordWin();

    enum RecordWMode{
        Show,
        Add
    };

    void setWinMode(const RecordWMode& mode);

    void addBook(const QString& name);
    void removeBook(const QString& name);
    void addAccount(const QString& name);
    void removeAccount(const QString& name);

    void setBook(const QString& name);
    void setAccount(const QString& name);
    void setFlowType(const QString& name);
    void setFirstClassify(const QString& text);
    void setSecondClassify(const QString& text);
    void setMoney(const qreal& money);
    void setRemark(const QString& text);
    void setDateEdit(const QDateTime& datetime);

signals:
    void flushWinData(Account account, Book book);

protected:
    void closeEvent(QCloseEvent *event);
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
    Ui::RecordWin *ui;
};

#endif // RECORDWIN_H
