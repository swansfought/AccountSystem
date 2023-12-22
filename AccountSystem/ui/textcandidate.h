#ifndef TEXTCANDIDATE_H
#define TEXTCANDIDATE_H

#include <QWidget>
#include <QStringList>
#include <QVector>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QPainterPath>
#include <QPainter>

#include <QDebug>

#define ITEM_HEIGHT 30

namespace Ui {
class TextCandidate;
}

class TextCandidate : public QWidget
{
    Q_OBJECT

public:
    explicit TextCandidate(QWidget *parent = nullptr);
    explicit TextCandidate(const int& width, const int& height, QWidget *parent = nullptr);
    explicit TextCandidate(const int &ax, const int& ay,const int& width, const int& height, QWidget *parent = nullptr);
    ~TextCandidate();

    void setWindowSize(const QSize &size);
    void setWindowSize(int minw, int minh);

    void setText(const QStringList& list);
    void setText(const QVector<QString>& vec);
    void setText(const QString text);

//    void appendText(const QString text);
//    void appendText(const QStringList& list);
//    void appendText(const QVector<QString>& vec);

//    void insertText(const int& index, const QString text);
//    void insertText(const int& index, const QStringList& list);
//    void insertText(const int& index, const QVector<QString>& vec);

    void removeAll();

    int getFlag() const;
    void setFlag(int newFlag);

signals:
    void selectedText(const int& flag, const QString &text);

protected:
//    void showEvent(QShowEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
//    void focusInEvent(QFocusEvent *e) override;
//    void focusOutEvent(QFocusEvent *e);s


private slots:
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);


private:
    int flag;
    int _width;
    int _height;

    Ui::TextCandidate *ui;

};

#endif // TEXTCANDIDATE_H
