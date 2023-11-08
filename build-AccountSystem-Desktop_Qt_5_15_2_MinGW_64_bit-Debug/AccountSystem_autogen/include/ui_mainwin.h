/********************************************************************************
** Form generated from reading UI file 'mainwin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIN_H
#define UI_MAINWIN_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWin
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *line_bottom;
    QWidget *widget_background;
    QGridLayout *gridLayout_3;
    QWidget *widget_dock;
    QGridLayout *gridLayout_2;
    QPushButton *btn_analysis;
    QPushButton *btn_borrowReturn;
    QPushButton *btn_classify;
    QPushButton *btn_accountBook;
    QPushButton *btn_asset;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_setting;
    QPushButton *btn_record;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QWidget *widget_3;
    QGridLayout *gridLayout_15;
    QWidget *widget_4;
    QGridLayout *gridLayout_9;
    QWidget *widget_6;
    QGridLayout *gridLayout_5;
    QLabel *label_3;
    QLabel *label_6;
    QWidget *widget_7;
    QGridLayout *gridLayout_8;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_15;
    QFrame *line_3;
    QWidget *widget_5;
    QGridLayout *gridLayout_10;
    QWidget *widget_8;
    QGridLayout *gridLayout_6;
    QLabel *label_5;
    QWidget *widget_9;
    QGridLayout *gridLayout_11;
    QPushButton *pushButton_2;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_8;
    QFrame *line_4;
    QWidget *widget_10;
    QGridLayout *gridLayout_12;
    QWidget *widget_12;
    QGridLayout *gridLayout_14;
    QLabel *label_10;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_11;
    QGridLayout *gridLayout_13;
    QLabel *label_9;
    QLabel *label_11;
    QWidget *widget_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QToolButton *btn_addRecord;
    QFrame *line_5;
    QFrame *line_2;
    QSpacerItem *horizontalSpacer_7;
    QFrame *line_central;
    QStackedWidget *stackedWidget_dockPage;
    QWidget *page_record;
    QGridLayout *gridLayout_7;
    QStackedWidget *stackedWidget_2;
    QWidget *page;
    QGridLayout *gridLayout_20;
    QTreeView *treeView;
    QWidget *page_2;
    QWidget *widget_13;
    QGridLayout *gridLayout_19;
    QSpacerItem *horizontalSpacer_5;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_11;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_5;
    QFrame *line_6;
    QFrame *line_7;
    QLabel *label_2;
    QDateEdit *dateEdit;
    QWidget *page_classify;
    QWidget *page_analysis;
    QWidget *page_asset;
    QWidget *page_accountBook;
    QWidget *page_setting;
    QWidget *page_borrowReturn;
    QFrame *line;
    QFrame *line_top;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWin)
    {
        if (MainWin->objectName().isEmpty())
            MainWin->setObjectName(QString::fromUtf8("MainWin"));
        MainWin->resize(1300, 750);
        MainWin->setMinimumSize(QSize(1300, 750));
        centralwidget = new QWidget(MainWin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(4, 4, 4, 4);
        line_bottom = new QFrame(centralwidget);
        line_bottom->setObjectName(QString::fromUtf8("line_bottom"));
        line_bottom->setMinimumSize(QSize(0, 2));
        line_bottom->setMaximumSize(QSize(16777215, 2));
        line_bottom->setFrameShape(QFrame::HLine);
        line_bottom->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_bottom, 2, 0, 1, 1);

        widget_background = new QWidget(centralwidget);
        widget_background->setObjectName(QString::fromUtf8("widget_background"));
        gridLayout_3 = new QGridLayout(widget_background);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_dock = new QWidget(widget_background);
        widget_dock->setObjectName(QString::fromUtf8("widget_dock"));
        widget_dock->setMinimumSize(QSize(140, 0));
        widget_dock->setMaximumSize(QSize(140, 16777215));
        gridLayout_2 = new QGridLayout(widget_dock);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        btn_analysis = new QPushButton(widget_dock);
        btn_analysis->setObjectName(QString::fromUtf8("btn_analysis"));
        btn_analysis->setMinimumSize(QSize(0, 60));
        btn_analysis->setMaximumSize(QSize(16777215, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        btn_analysis->setFont(font);

        gridLayout_2->addWidget(btn_analysis, 1, 0, 1, 1);

        btn_borrowReturn = new QPushButton(widget_dock);
        btn_borrowReturn->setObjectName(QString::fromUtf8("btn_borrowReturn"));
        btn_borrowReturn->setMinimumSize(QSize(0, 60));
        btn_borrowReturn->setMaximumSize(QSize(16777215, 60));
        btn_borrowReturn->setFont(font);

        gridLayout_2->addWidget(btn_borrowReturn, 2, 0, 1, 1);

        btn_classify = new QPushButton(widget_dock);
        btn_classify->setObjectName(QString::fromUtf8("btn_classify"));
        btn_classify->setMinimumSize(QSize(0, 60));
        btn_classify->setMaximumSize(QSize(16777215, 60));
        btn_classify->setFont(font);

        gridLayout_2->addWidget(btn_classify, 6, 0, 1, 1);

        btn_accountBook = new QPushButton(widget_dock);
        btn_accountBook->setObjectName(QString::fromUtf8("btn_accountBook"));
        btn_accountBook->setMinimumSize(QSize(0, 60));
        btn_accountBook->setMaximumSize(QSize(16777215, 60));
        btn_accountBook->setFont(font);

        gridLayout_2->addWidget(btn_accountBook, 5, 0, 1, 1);

        btn_asset = new QPushButton(widget_dock);
        btn_asset->setObjectName(QString::fromUtf8("btn_asset"));
        btn_asset->setMinimumSize(QSize(0, 60));
        btn_asset->setMaximumSize(QSize(16777215, 60));
        btn_asset->setFont(font);

        gridLayout_2->addWidget(btn_asset, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 8, 0, 1, 1);

        btn_setting = new QPushButton(widget_dock);
        btn_setting->setObjectName(QString::fromUtf8("btn_setting"));
        btn_setting->setMinimumSize(QSize(0, 60));
        btn_setting->setMaximumSize(QSize(16777215, 60));
        btn_setting->setFont(font);

        gridLayout_2->addWidget(btn_setting, 7, 0, 1, 1);

        btn_record = new QPushButton(widget_dock);
        btn_record->setObjectName(QString::fromUtf8("btn_record"));
        btn_record->setMinimumSize(QSize(0, 60));
        btn_record->setMaximumSize(QSize(16777215, 60));
        btn_record->setFont(font);

        gridLayout_2->addWidget(btn_record, 0, 0, 1, 1);


        gridLayout_3->addWidget(widget_dock, 2, 0, 1, 1);

        widget = new QWidget(widget_background);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 90));
        widget->setMaximumSize(QSize(16777215, 90));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        gridLayout_15 = new QGridLayout(widget_3);
        gridLayout_15->setSpacing(0);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_15->setContentsMargins(4, 0, 0, 0);
        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        gridLayout_9 = new QGridLayout(widget_4);
        gridLayout_9->setSpacing(5);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(5, 5, 5, 5);
        widget_6 = new QWidget(widget_4);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setMinimumSize(QSize(70, 70));
        widget_6->setMaximumSize(QSize(70, 70));
        gridLayout_5 = new QGridLayout(widget_6);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 0);"));
        label_3->setScaledContents(true);

        gridLayout_5->addWidget(label_3, 0, 0, 1, 1);


        gridLayout_9->addWidget(widget_6, 0, 0, 2, 1);

        label_6 = new QLabel(widget_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(180, 30));
        label_6->setMaximumSize(QSize(180, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(13);
        font1.setBold(true);
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(55, 146, 250);"));

        gridLayout_9->addWidget(label_6, 1, 1, 1, 1);

        widget_7 = new QWidget(widget_4);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setMinimumSize(QSize(180, 30));
        widget_7->setMaximumSize(QSize(180, 30));
        gridLayout_8 = new QGridLayout(widget_7);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setHorizontalSpacing(5);
        gridLayout_8->setVerticalSpacing(0);
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget_7);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(30, 30));
        pushButton->setMaximumSize(QSize(30, 30));

        gridLayout_8->addWidget(pushButton, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        label_15 = new QLabel(widget_7);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMinimumSize(QSize(0, 0));
        label_15->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        label_15->setFont(font2);

        gridLayout_8->addWidget(label_15, 0, 1, 1, 1);


        gridLayout_9->addWidget(widget_7, 0, 1, 1, 1);


        gridLayout_15->addWidget(widget_4, 0, 0, 1, 1);

        line_3 = new QFrame(widget_3);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setMinimumSize(QSize(2, 0));
        line_3->setMaximumSize(QSize(2, 16777215));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_15->addWidget(line_3, 0, 1, 1, 1);

        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        gridLayout_10 = new QGridLayout(widget_5);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(-1, 5, -1, 5);
        widget_8 = new QWidget(widget_5);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setMinimumSize(QSize(70, 70));
        widget_8->setMaximumSize(QSize(70, 70));
        gridLayout_6 = new QGridLayout(widget_8);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget_8);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 0);"));
        label_5->setScaledContents(true);

        gridLayout_6->addWidget(label_5, 0, 0, 1, 1);


        gridLayout_10->addWidget(widget_8, 0, 0, 2, 1);

        widget_9 = new QWidget(widget_5);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        widget_9->setMinimumSize(QSize(180, 30));
        widget_9->setMaximumSize(QSize(180, 30));
        gridLayout_11 = new QGridLayout(widget_9);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setHorizontalSpacing(5);
        gridLayout_11->setVerticalSpacing(0);
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(widget_9);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(30, 30));
        pushButton_2->setMaximumSize(QSize(30, 30));

        gridLayout_11->addWidget(pushButton_2, 0, 2, 1, 1);

        label_7 = new QLabel(widget_9);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(0, 0));
        label_7->setMaximumSize(QSize(16777215, 16777215));
        label_7->setFont(font2);

        gridLayout_11->addWidget(label_7, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_3, 0, 3, 1, 1);


        gridLayout_10->addWidget(widget_9, 0, 1, 1, 1);

        label_8 = new QLabel(widget_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(180, 30));
        label_8->setMaximumSize(QSize(180, 30));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(55, 146, 250);"));

        gridLayout_10->addWidget(label_8, 1, 1, 1, 1);


        gridLayout_15->addWidget(widget_5, 0, 2, 1, 1);

        line_4 = new QFrame(widget_3);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setMinimumSize(QSize(2, 0));
        line_4->setMaximumSize(QSize(2, 16777215));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_15->addWidget(line_4, 0, 3, 1, 1);

        widget_10 = new QWidget(widget_3);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        gridLayout_12 = new QGridLayout(widget_10);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(-1, 5, -1, 5);
        widget_12 = new QWidget(widget_10);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        widget_12->setMinimumSize(QSize(180, 30));
        widget_12->setMaximumSize(QSize(180, 30));
        gridLayout_14 = new QGridLayout(widget_12);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_14->setHorizontalSpacing(5);
        gridLayout_14->setVerticalSpacing(0);
        gridLayout_14->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(widget_12);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(0, 0));
        label_10->setMaximumSize(QSize(16777215, 16777215));
        label_10->setFont(font2);

        gridLayout_14->addWidget(label_10, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(widget_12);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(30, 30));
        pushButton_3->setMaximumSize(QSize(30, 30));

        gridLayout_14->addWidget(pushButton_3, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(59, 27, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_14->addItem(horizontalSpacer_4, 0, 3, 1, 1);


        gridLayout_12->addWidget(widget_12, 0, 1, 1, 1);

        widget_11 = new QWidget(widget_10);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        widget_11->setMinimumSize(QSize(70, 70));
        widget_11->setMaximumSize(QSize(70, 70));
        gridLayout_13 = new QGridLayout(widget_11);
        gridLayout_13->setSpacing(0);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(widget_11);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 0);"));
        label_9->setScaledContents(true);

        gridLayout_13->addWidget(label_9, 0, 0, 1, 1);


        gridLayout_12->addWidget(widget_11, 0, 0, 2, 1);

        label_11 = new QLabel(widget_10);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(180, 30));
        label_11->setMaximumSize(QSize(180, 30));
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(55, 146, 250);"));

        gridLayout_12->addWidget(label_11, 1, 1, 1, 1);


        gridLayout_15->addWidget(widget_10, 0, 4, 1, 1);


        gridLayout_4->addWidget(widget_3, 0, 2, 1, 1);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(140, 0));
        widget_2->setMaximumSize(QSize(16777215, 16777215));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 111, 41));

        gridLayout_4->addWidget(widget_2, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 6, 1, 1);

        btn_addRecord = new QToolButton(widget);
        btn_addRecord->setObjectName(QString::fromUtf8("btn_addRecord"));
        btn_addRecord->setMinimumSize(QSize(80, 80));
        btn_addRecord->setMaximumSize(QSize(80, 80));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        btn_addRecord->setFont(font3);
        btn_addRecord->setStyleSheet(QString::fromUtf8(""));

        gridLayout_4->addWidget(btn_addRecord, 0, 7, 1, 1);

        line_5 = new QFrame(widget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setMinimumSize(QSize(2, 0));
        line_5->setMaximumSize(QSize(2, 16777215));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_5, 0, 3, 1, 1);

        line_2 = new QFrame(widget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setMinimumSize(QSize(2, 0));
        line_2->setMaximumSize(QSize(2, 16777215));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_2, 0, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(10, 27, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_7, 0, 8, 1, 1);


        gridLayout_3->addWidget(widget, 0, 0, 1, 3);

        line_central = new QFrame(widget_background);
        line_central->setObjectName(QString::fromUtf8("line_central"));
        line_central->setFrameShape(QFrame::VLine);
        line_central->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_central, 2, 1, 1, 1);

        stackedWidget_dockPage = new QStackedWidget(widget_background);
        stackedWidget_dockPage->setObjectName(QString::fromUtf8("stackedWidget_dockPage"));
        page_record = new QWidget();
        page_record->setObjectName(QString::fromUtf8("page_record"));
        gridLayout_7 = new QGridLayout(page_record);
        gridLayout_7->setSpacing(5);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(5, 5, 5, 5);
        stackedWidget_2 = new QStackedWidget(page_record);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout_20 = new QGridLayout(page);
        gridLayout_20->setSpacing(0);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        gridLayout_20->setContentsMargins(0, 0, 0, 0);
        treeView = new QTreeView(page);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        gridLayout_20->addWidget(treeView, 0, 0, 1, 1);

        stackedWidget_2->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget_2->addWidget(page_2);

        gridLayout_7->addWidget(stackedWidget_2, 1, 0, 1, 1);

        widget_13 = new QWidget(page_record);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));
        widget_13->setMinimumSize(QSize(0, 45));
        widget_13->setMaximumSize(QSize(16777215, 45));
        widget_13->setStyleSheet(QString::fromUtf8(""));
        gridLayout_19 = new QGridLayout(widget_13);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        gridLayout_19->setHorizontalSpacing(8);
        gridLayout_19->setVerticalSpacing(0);
        gridLayout_19->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_5 = new QSpacerItem(231, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_19->addItem(horizontalSpacer_5, 0, 13, 1, 1);

        checkBox = new QCheckBox(widget_13);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setMinimumSize(QSize(0, 35));
        checkBox->setMaximumSize(QSize(16777215, 35));
        QFont font4;
        font4.setPointSize(11);
        checkBox->setFont(font4);
        checkBox->setLayoutDirection(Qt::RightToLeft);
        checkBox->setChecked(true);

        gridLayout_19->addWidget(checkBox, 0, 3, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_19->addItem(horizontalSpacer_10, 0, 4, 1, 1);

        label_17 = new QLabel(widget_13);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMinimumSize(QSize(0, 0));
        label_17->setMaximumSize(QSize(16777215, 16777215));
        label_17->setFont(font4);

        gridLayout_19->addWidget(label_17, 0, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_19->addItem(horizontalSpacer_8, 0, 9, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_19->addItem(horizontalSpacer_11, 0, 11, 1, 1);

        lineEdit = new QLineEdit(widget_13);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(255, 35));
        lineEdit->setMaximumSize(QSize(255, 35));
        QFont font5;
        font5.setPointSize(10);
        lineEdit->setFont(font5);

        gridLayout_19->addWidget(lineEdit, 0, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_19->addItem(horizontalSpacer_6, 0, 6, 1, 1);

        pushButton_5 = new QPushButton(widget_13);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(80, 35));
        pushButton_5->setMaximumSize(QSize(80, 35));
        pushButton_5->setFont(font4);

        gridLayout_19->addWidget(pushButton_5, 0, 12, 1, 1);

        line_6 = new QFrame(widget_13);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setMinimumSize(QSize(2, 0));
        line_6->setMaximumSize(QSize(2, 16777215));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_19->addWidget(line_6, 0, 5, 1, 1);

        line_7 = new QFrame(widget_13);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setMinimumSize(QSize(2, 0));
        line_7->setMaximumSize(QSize(2, 16777215));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout_19->addWidget(line_7, 0, 10, 1, 1);

        label_2 = new QLabel(widget_13);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 0));
        label_2->setMaximumSize(QSize(16777215, 16777215));
        label_2->setFont(font4);

        gridLayout_19->addWidget(label_2, 0, 7, 1, 1);

        dateEdit = new QDateEdit(widget_13);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setMinimumSize(QSize(185, 35));
        dateEdit->setMaximumSize(QSize(185, 35));
        dateEdit->setFont(font4);
        dateEdit->setCalendarPopup(true);
        dateEdit->setDate(QDate(2023, 11, 8));

        gridLayout_19->addWidget(dateEdit, 0, 8, 1, 1);


        gridLayout_7->addWidget(widget_13, 0, 0, 1, 1);

        stackedWidget_dockPage->addWidget(page_record);
        page_classify = new QWidget();
        page_classify->setObjectName(QString::fromUtf8("page_classify"));
        stackedWidget_dockPage->addWidget(page_classify);
        page_analysis = new QWidget();
        page_analysis->setObjectName(QString::fromUtf8("page_analysis"));
        stackedWidget_dockPage->addWidget(page_analysis);
        page_asset = new QWidget();
        page_asset->setObjectName(QString::fromUtf8("page_asset"));
        stackedWidget_dockPage->addWidget(page_asset);
        page_accountBook = new QWidget();
        page_accountBook->setObjectName(QString::fromUtf8("page_accountBook"));
        stackedWidget_dockPage->addWidget(page_accountBook);
        page_setting = new QWidget();
        page_setting->setObjectName(QString::fromUtf8("page_setting"));
        stackedWidget_dockPage->addWidget(page_setting);
        page_borrowReturn = new QWidget();
        page_borrowReturn->setObjectName(QString::fromUtf8("page_borrowReturn"));
        stackedWidget_dockPage->addWidget(page_borrowReturn);

        gridLayout_3->addWidget(stackedWidget_dockPage, 2, 2, 1, 1);

        line = new QFrame(widget_background);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(0, 2));
        line->setMaximumSize(QSize(16777215, 2));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 1, 0, 1, 3);


        gridLayout->addWidget(widget_background, 1, 0, 1, 1);

        line_top = new QFrame(centralwidget);
        line_top->setObjectName(QString::fromUtf8("line_top"));
        line_top->setMinimumSize(QSize(0, 2));
        line_top->setMaximumSize(QSize(16777215, 2));
        line_top->setFrameShape(QFrame::HLine);
        line_top->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_top, 0, 0, 1, 1);

        MainWin->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWin->setStatusBar(statusbar);

        retranslateUi(MainWin);

        QMetaObject::connectSlotsByName(MainWin);
    } // setupUi

    void retranslateUi(QMainWindow *MainWin)
    {
        MainWin->setWindowTitle(QCoreApplication::translate("MainWin", "MainWin", nullptr));
        btn_analysis->setText(QCoreApplication::translate("MainWin", "\350\264\246\347\233\256\347\273\237\350\256\241", nullptr));
        btn_borrowReturn->setText(QCoreApplication::translate("MainWin", "\345\200\237\350\277\230\350\256\260\345\275\225", nullptr));
        btn_classify->setText(QCoreApplication::translate("MainWin", "\345\210\206\347\261\273\347\256\241\347\220\206", nullptr));
        btn_accountBook->setText(QCoreApplication::translate("MainWin", "\350\264\246\346\234\254\347\256\241\347\220\206", nullptr));
        btn_asset->setText(QCoreApplication::translate("MainWin", "\350\265\204\344\272\247\347\256\241\347\220\206", nullptr));
        btn_setting->setText(QCoreApplication::translate("MainWin", "\350\256\276       \347\275\256", nullptr));
        btn_record->setText(QCoreApplication::translate("MainWin", "\346\265\201\346\260\264\350\264\246\347\233\256", nullptr));
        label_3->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWin", "0.00", nullptr));
        pushButton->setText(QString());
        label_15->setText(QCoreApplication::translate("MainWin", "\346\200\273\350\265\204\344\272\247", nullptr));
        label_5->setText(QString());
        pushButton_2->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWin", "\346\234\210\346\224\266\345\205\245", nullptr));
        label_8->setText(QCoreApplication::translate("MainWin", "0.00", nullptr));
        label_10->setText(QCoreApplication::translate("MainWin", "\346\234\210\346\224\257\345\207\272", nullptr));
        pushButton_3->setText(QString());
        label_9->setText(QString());
        label_11->setText(QCoreApplication::translate("MainWin", "0.00", nullptr));
        label->setText(QCoreApplication::translate("MainWin", "\346\231\232\351\243\216\346\235\245\347\232\204\346\255\243\345\267\247", nullptr));
        btn_addRecord->setText(QCoreApplication::translate("MainWin", "\350\256\260\344\270\200\347\254\224", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWin", "\345\277\275\347\225\245\346\227\245\346\234\237", nullptr));
        label_17->setText(QCoreApplication::translate("MainWin", "\346\250\241\347\263\212\346\237\245\350\257\242", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWin", "\351\207\215  \347\275\256", nullptr));
        label_2->setText(QCoreApplication::translate("MainWin", "\351\200\211\346\213\251\346\227\245\346\234\237", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("MainWin", "yyyy\345\271\264MM\346\234\210dd\346\227\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWin: public Ui_MainWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIN_H
