#include "treewidget.h"

TreeWidget::TreeWidget(QWidget *parent)
    : QTreeWidget{parent}
{
    contextMenu = true;


    // 自定义右键菜单
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &TreeWidget::customContextMenuRequested, this, &TreeWidget::showContextMenu);
}

TreeWidget::~TreeWidget()
{

}

void TreeWidget::setContextMenu(const bool &bol)
{
    contextMenu = bol;
}

void TreeWidget::collapseAll()
{
    int rootCount = this->topLevelItemCount(); // 获取根节点数量
    for (int i = 0; i < rootCount; ++i) {
        QTreeWidgetItem* rootItem = this->topLevelItem(i); // 获取根节点
        this->collapseItem(rootItem); // 折叠根节点
    }
}

void TreeWidget::showContextMenu(const QPoint &pos)
{
    if(!contextMenu)
        return;
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
