#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QApplication>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include <QPainter>

class TreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit TreeWidget(QWidget *parent = nullptr);
    ~TreeWidget();

    enum MenuMode{
        Record,
        Classify,
        Show
    };

    void setContextMenu(const MenuMode& mode);

    void collapseAll();
    void deleteAll();

signals:
    void deleteRecord();
    void deleteClassify();


protected:
//    void drawRow(QPainter *painter, const QStyleOptionViewItem &options, const QModelIndex &index) const override;

private slots:
    void showContextMenu(const QPoint &pos);


private:
    MenuMode menuMode;


};

#endif // TREEWIDGET_H
