#ifndef CLASSIFYTREEWIDGET_H
#define CLASSIFYTREEWIDGET_H

#include <QApplication>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QMenu>
#include <QAction>

class ClassifyTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit ClassifyTreeWidget(QWidget *parent = nullptr);
    ~ClassifyTreeWidget();

private slots:
    void showContextMenu(const QPoint &pos);



};

#endif // CLASSIFYTREEWIDGET_H
