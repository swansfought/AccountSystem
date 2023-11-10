#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QApplication>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QMenu>
#include <QAction>

class TreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit TreeWidget(QWidget *parent = nullptr);
    ~TreeWidget();


private slots:
    void showContextMenu(const QPoint &pos);



};

#endif // TREEWIDGET_H
