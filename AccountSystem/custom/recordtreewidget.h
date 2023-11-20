#ifndef RECORDTREEWIDGET_H
#define RECORDTREEWIDGET_H

#include <QApplication>
#include <QTreeWidget>
#include <QPainter>


#include <QDebug>

class RecordTreeWidget : public QTreeWidget
{

public:
    explicit RecordTreeWidget(QWidget *parent = nullptr);
    ~RecordTreeWidget();

protected:
//    void drawRow(QPainter * painter, const QStyleOptionViewItem & options, const QModelIndex & index) const;
//    void paintEvent(QPaintEvent *event) override;

private:
//    void initStyle();

};

#endif // RECORDTREEWIDGET_H
