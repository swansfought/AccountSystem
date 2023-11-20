#include "recordtreewidget.h"

RecordTreeWidget::RecordTreeWidget(QWidget *parent)
    : QTreeWidget{parent}
{

//    this->setStyleSheet("QTreeView {outline:none;show-decoration-selected: 1;}"
//                        "QTreeView {outline:none;border:0px;}"
//                        "QTreeView::branch{ background-color: transparent;	}"
//                        "QTreeView::item:hover, QTreeView::branch:hover { background-color: transparent;border-color: rgb(255, 0, 0);}"
//                        "QTreeView::item:selected, QTreeView::branch:selected { background-color: #C5E0F7;}"
//                        "QTreeView::branch:open:has-children{image: url(:/branch-expand.png);}"
//                        "QTreeView::branch:closed:has-children{image: url(:/branch-collapse.png);}"
//                        "QTreeView::branch:has-siblings:!adjoins-item{border-image:url(:/branch-line.png) 0;}"
//                        "QTreeView::branch:has-siblings:adjoins-item{border-image:url(:/branch-more.png) 0;}"
//                        "QTreeView::branch:!has-children:!has-siblings:adjoins-item{border-image:url(:/branch-end.png) 0;	}"
//                        "QTreeView::branch:has-children:!has-siblings:closed,QTreeView::branch:closed:has-children:has-siblings{border-image:none;image: url(:/branch-collapse.png);	}"
//                        "QTreeView::branch:open:has-children:!has-siblings,QTreeView::branch:open:has-children:has-siblings{border-image:none;image: url(:/branch-expand.png);	}"
//                        );
//    qDebug()<<"--------";




}

RecordTreeWidget::~RecordTreeWidget()
{

}

//void RecordTreeWidget::drawRow(QPainter * painter, const QStyleOptionViewItem & options, const QModelIndex & index) const
//{
//    QTreeView::drawRow(painter, options, index);

//    //绘制网格线
//    QPen pen;
//    pen.setWidth(1);
//    pen.setColor(Qt::black);

//    painter->save();
//    painter->setPen(pen);
//    painter->drawRect(options.rect);
//    painter->restore();
//}


//void RecordTreeWidget::paintEvent(QPaintEvent *event)
//{
//    QTreeWidget::paintEvent(event);

//    QPainter painter(viewport());
//    QStyleOptionViewItem option;
//    for (int row = 0; row < topLevelItemCount(); ++row)
//    {
//        QTreeWidgetItem *item = topLevelItem(row);
//        initStyleOption(&option, item);
//        QRect r = visualRect(option.rect);

//        painter.setPen(Qt::lightGray); // 设置线条颜色
//        painter.drawLine(r.bottomLeft(), r.bottomRight()); // 绘制行之间的线条
//    }
//}
