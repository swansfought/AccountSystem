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
#include <QMovie>
#include <QTimer>

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

    void setWinMode(const RecordWMode& mode,int itemId = 0);

    void addBook(const QString& name);
    void removeBook(const QString& name);
    void removeAllBook();
    void addAccount(const QString& name);
    void removeAccount(const QString& name);
    void removeAllAccount();

    void setBook(const QString& name);
    void setAccount(const QString& name);
    void setAccountIn(const QString& name);
    void setFlowType(const QString& name);
    void setFirstClassify(const QString& text);
    void setSecondClassify(const QString& text);
    void setMoney(const qreal& money);
    void setRemark(const QString& text);
    void setDateEdit(const QDateTime& datetime);
    void setImage(const QByteArray &image);

signals:
    void flushWinData(Account account, Book book);
    void deleteRecord();

protected:
    void closeEvent(QCloseEvent *event) override;
//    bool event(QEvent * event) override;
//    void mouseMoveEvent(QMouseEvent* event) override;


private:
    void initData();
    void initSignalSlots();
    void resetWin();
    bool saveRecord();
    void loadingTip(const bool& bol);
//    void setAccount(const QJsonArray& arr);
//    void setFlowType(const QJsonArray& arr);
//    void setFirstClassify(const QJsonArray& arr);
//    void setSecondClassify(const QJsonArray& arr);

    Config *config;//分类管理
    DataBase *db;

    RecordWMode currMode;
    int itemId;
    QPixmap imgPixmap;
    QMovie* movie;

private:
    Ui::RecordWin *ui;
};

#endif // RECORDWIN_H
