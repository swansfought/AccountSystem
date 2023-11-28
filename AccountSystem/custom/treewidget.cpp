#include "treewidget.h"

TreeWidget::TreeWidget(QWidget *parent)
    : QTreeWidget{parent}
{
    menuMode = Classify;

//    setDragEnabled(true);  // 开启拖拽功能
//    setDragDropMode(QAbstractItemView::InternalMove); // 设置控件内部移动
//    setDefaultDropAction(Qt::MoveAction); // 设置移动模式

    // 自定义右键菜单
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &TreeWidget::customContextMenuRequested, this, &TreeWidget::showContextMenu);
}

TreeWidget::~TreeWidget()
{

}

void TreeWidget::setContextMenu(const MenuMode& mode)
{
    menuMode = mode;
}

void TreeWidget::collapseAll()
{
    int rootCount = this->topLevelItemCount(); // 获取根节点数量
    for (int i = 0; i < rootCount; ++i) {
        QTreeWidgetItem* rootItem = this->topLevelItem(i); // 获取根节点
        this->collapseItem(rootItem); // 折叠根节点
    }
}

void TreeWidget::deleteAll()
{
    QTreeWidgetItemIterator it(this);
    while (this->topLevelItemCount() > 0) { // 递归删除
        QTreeWidgetItem *topItem = this->takeTopLevelItem(0);
        while (topItem->childCount() > 0)
            topItem->removeChild(topItem->child(0));
        delete topItem;
    }
}

#include <QPainter>
void TreeWidget::showContextMenu(const QPoint &pos)
{
    QTreeWidgetItem *item = itemAt(pos);
    if(nullptr == item)
        return;

    //构建右键菜单
    QMenu menu(this);
    switch (menuMode) {
    case Record:{
        if(nullptr != this->currentItem()->parent()){
            QAction *act = new QAction("删除记录", this);

            //自带: QApplication::style()->standardIcon(QStyle::SP_DockWidgetCloseButton);
            // 创建自定义红色叉叉图标
            int iconSize = 12;
            QPixmap pixmap(iconSize, iconSize);
            pixmap.fill(Qt::transparent);
            QPainter painter(&pixmap);
            painter.setRenderHint(QPainter::Antialiasing);
            painter.setPen(QPen(Qt::red, 2));
            painter.drawLine(0, 0, iconSize, iconSize);
            painter.drawLine(0, iconSize, iconSize, 0);
            painter.end();
            act->setIcon(QIcon(pixmap));


            menu.addAction(act);
            connect(act, &QAction::triggered, this, [=](){
                auto ret = QMessageBox::information(this,"记录删除","确定要删除此记录吗？",QMessageBox::Yes,QMessageBox::No);
                if(QMessageBox::Yes == ret)
                    emit deleteRecord();
            });
        }
        break;
    }
    case Classify:{
        if(nullptr == this->currentItem()->parent()){
            QAction *act = new QAction("新增分类", this);
            menu.addAction(act);
            connect(act, &QAction::triggered, this, [=](){

            });
        }else{
            QAction *act1 = new QAction("上移", this);
            QAction *act2 = new QAction("下移", this);
            QAction *act3 = new QAction("插入分类", this);
            QAction *act4 = new QAction("删除分类", this);
            menu.addAction(act1);
            menu.addAction(act2);
            menu.addAction(act3);
            menu.addAction(act4);
            connect(act1, &QAction::triggered, this, [=](){

            });
            connect(act2, &QAction::triggered, this, [=](){

            });
            connect(act3, &QAction::triggered, this, [=](){

            });
            connect(act4, &QAction::triggered, this, [=](){

            });
        }
        break;
    }
    default:
        break;
    }
    menu.exec(mapToGlobal(pos));
}
