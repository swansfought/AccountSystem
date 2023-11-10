#include "treewidget.h"

TreeWidget::TreeWidget(QWidget *parent)
    : QTreeWidget{parent}
{
    // 自定义右键菜单
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &TreeWidget::customContextMenuRequested, this, &TreeWidget::showContextMenu);
}

TreeWidget::~TreeWidget()
{

}

void TreeWidget::showContextMenu(const QPoint &pos)
{
    QTreeWidgetItem *item = itemAt(pos);
    if(nullptr == item)
        return;

    //构建右键菜单
    QMenu menu(this);
    QAction *action1 = new QAction("新增分类", this);
    QAction *action2 = new QAction("删除分类", this);
    menu.addAction(action1);
    menu.addAction(action2);

    connect(action1, &QAction::triggered, this, [](){

    });
    connect(action2, &QAction::triggered, this, [](){

    });
    menu.exec(mapToGlobal(pos));

}
