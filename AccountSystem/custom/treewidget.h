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

    void setContextMenu(const bool& bol);

    void collapseAll();

private slots:
    void showContextMenu(const QPoint &pos);


private:
    bool contextMenu;


};

#endif // TREEWIDGET_H
