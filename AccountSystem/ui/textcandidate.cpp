#include "textcandidate.h"
#include "ui_textcandidate.h"

TextCandidate::TextCandidate(QWidget *parent) :
    QWidget(parent),
    flag(0),
    ui(new Ui::TextCandidate)
{
    ui->setupUi(this);
    this->hide();
}

TextCandidate::TextCandidate(const int &width, const int &height, QWidget *parent) :
    QWidget(parent),
    flag(0),
    ui(new Ui::TextCandidate)
{
    ui->setupUi(this);
    this->setMinimumSize(width,height);
    this->setMaximumSize(width,height);
    this->_width = width;
    this->_height = height;

    this->hide();
}

TextCandidate::TextCandidate(const int &ax, const int &ay, const int &width, const int &height, QWidget *parent):
    QWidget(parent),
    flag(0),
    ui(new Ui::TextCandidate)
{
    ui->setupUi(this);
    this->setMinimumSize(width,height);
    this->setMaximumSize(width,height);
    this->_width = width;
    this->_height = height;
    this->hide();
}

TextCandidate::~TextCandidate()
{
    delete ui;
}

void TextCandidate::setWindowSize(const QSize &size)
{
    this->setMinimumSize(size);
    this->setMaximumSize(size);
}

void TextCandidate::setWindowSize(int minw, int minh)
{
    this->setMinimumSize(minw,minh);
    this->setMaximumSize(minw,minh);
}

void TextCandidate::setText(const QStringList &list)
{
    removeAll();
    if(list.isEmpty()){
        this->hide();
        return;
    }
    int count = list.count();
    for (int i = 0; i < count; ++i) {
        QTreeWidgetItem* topItem = new QTreeWidgetItem(ui->treeWidget);
        topItem->setSizeHint(0,QSize(ui->treeWidget->header()->width(),ITEM_HEIGHT));
        topItem->setText(0,list.at(i));

        QFont font;
        font.setPointSize(10);
        topItem->setFont(0,font);

        ui->treeWidget->insertTopLevelItem(i,topItem);
    }
    if(count*ITEM_HEIGHT < _height)
        this->setWindowSize(_width, count*ITEM_HEIGHT);
    else
        this->setWindowSize(_width, _height);
}

void TextCandidate::setText(const QVector<QString> &vec)
{
    removeAll();
    if(vec.isEmpty()){
        this->hide();
        return;
    }
    int count = vec.count();
    for (int i = 0; i < count; ++i) {
        QTreeWidgetItem* topItem = new QTreeWidgetItem(ui->treeWidget);
        topItem->setSizeHint(0,QSize(ui->treeWidget->header()->width(),ITEM_HEIGHT));
        topItem->setText(0,vec.at(i));

        QFont font;
        font.setPointSize(10);
        topItem->setFont(0,font);

        ui->treeWidget->insertTopLevelItem(i,topItem);
    }
    if(count*ITEM_HEIGHT < _height)
        this->setWindowSize(_width, count*ITEM_HEIGHT);
    else
        this->setWindowSize(_width, _height);
}

void TextCandidate::setText(const QString text)
{
    removeAll();
    if(text.isEmpty()){
        this->hide();
    }
    QTreeWidgetItem* topItem = new QTreeWidgetItem(ui->treeWidget);
    topItem->setSizeHint(0,QSize(ui->treeWidget->header()->width(),ITEM_HEIGHT));
    topItem->setText(0,text);

    QFont font;
    font.setPointSize(10);
    topItem->setFont(0,font);

    ui->treeWidget->insertTopLevelItem(0,topItem);
    this->setWindowSize(_width, ITEM_HEIGHT);
}

void TextCandidate::removeAll()
{
    QTreeWidgetItemIterator it(ui->treeWidget);
    while (ui->treeWidget->topLevelItemCount() > 0) { // 递归删除
        QTreeWidgetItem *topItem = ui->treeWidget->takeTopLevelItem(0);
        delete topItem;
    }
}

//void TextCandidate::showEvent(QShowEvent *event)
//{
//    QWidget::showEvent(event);
//}

void TextCandidate::paintEvent(QPaintEvent *event)
{
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRoundedRect(0, 0, this->width(), this->height(), 1, 1);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillPath(path, QBrush(QColor(230,230,230)));

    this->setContentsMargins(1,0,1,1); // 给垂直布局器设置边距(此步很重要, 设置宽度为阴影的宽度)
}


void TextCandidate::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    emit selectedText(flag, item->text(column));
    this->hide();
}

int TextCandidate::getFlag() const
{
    return flag;
}

void TextCandidate::setFlag(int newFlag)
{
    flag = newFlag;
}

