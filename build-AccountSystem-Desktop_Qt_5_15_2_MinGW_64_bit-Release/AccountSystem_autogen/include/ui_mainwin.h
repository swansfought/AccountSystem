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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <custom/treewidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWin
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *line_bottom;
    QFrame *line_top;
    QWidget *widget_background;
    QGridLayout *gridLayout_3;
    QFrame *line;
    QFrame *line_central;
    QWidget *widget_top_dock;
    QGridLayout *gridLayout_4;
    QWidget *widget_3;
    QGridLayout *gridLayout_15;
    QWidget *widget_totalFund;
    QGridLayout *gridLayout_9;
    QWidget *widget_6;
    QGridLayout *gridLayout_5;
    QLabel *label_3;
    QWidget *widget_7;
    QGridLayout *gridLayout_8;
    QPushButton *dock_totalFund_hide;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_15;
    QLabel *dock_totalFund_num;
    QFrame *line_3;
    QWidget *widget_monthIncome;
    QGridLayout *gridLayout_10;
    QWidget *widget_8;
    QGridLayout *gridLayout_6;
    QLabel *label_5;
    QWidget *widget_9;
    QGridLayout *gridLayout_11;
    QPushButton *dock_monthIncome_hide;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_7;
    QLabel *dock_monthIncome_num;
    QFrame *line_4;
    QWidget *widget_monthExpend;
    QGridLayout *gridLayout_12;
    QWidget *widget_12;
    QGridLayout *gridLayout_14;
    QLabel *label_10;
    QPushButton *dock_monthExpend_hide;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_11;
    QGridLayout *gridLayout_13;
    QLabel *label_9;
    QLabel *dock_monthExpend_num;
    QPushButton *dock_addRecord;
    QFrame *line_5;
    QWidget *widget_2;
    QGridLayout *gridLayout_37;
    QLabel *label;
    QFrame *line_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_10;
    QWidget *widget_left_dock;
    QGridLayout *gridLayout_2;
    QPushButton *dock_classify;
    QPushButton *dock_analysis;
    QPushButton *dock_borrowReturn;
    QPushButton *dock_account;
    QSpacerItem *verticalSpacer;
    QPushButton *dock_record;
    QPushButton *dock_book;
    QPushButton *dock_setting;
    QStackedWidget *stackedWidget_dock;
    QWidget *page_record_analysis;
    QGridLayout *gridLayout_7;
    QStackedWidget *stackedWidget_record;
    QWidget *page_record_tree;
    QGridLayout *gridLayout_20;
    QWidget *widget;
    QGridLayout *gridLayout_32;
    QWidget *widget_10;
    QGridLayout *gridLayout_31;
    QComboBox *record_pageRecordNum;
    QLabel *record_pageInfo;
    QWidget *widget_4;
    QGridLayout *gridLayout_29;
    QSpinBox *record_pageIndex;
    QPushButton *record_pageNext;
    QPushButton *record_pagePrevious;
    QWidget *widget_5;
    QGridLayout *gridLayout_30;
    QPushButton *record_output_all;
    QPushButton *record_output;
    QSpacerItem *horizontalSpacer_8;
    QWidget *widget_13;
    QGridLayout *gridLayout_33;
    QPushButton *record_collapse;
    QPushButton *record_expand;
    TreeWidget *record_tree;
    QWidget *page_record_loading;
    QGridLayout *gridLayout_36;
    QLabel *record_loading;
    QStackedWidget *stackedWidget_record_analysis;
    QWidget *page_record;
    QGridLayout *gridLayout_65;
    QGroupBox *groupBox_13;
    QGridLayout *gridLayout_19;
    QLineEdit *record_input;
    QWidget *widget_17;
    QGridLayout *gridLayout_34;
    QLabel *label_4;
    QComboBox *record_flowType;
    QFrame *line_6;
    QComboBox *record_filter;
    QPushButton *record_reset;
    QPushButton *record_flush;
    QWidget *widget_19;
    QGridLayout *gridLayout_35;
    QLabel *label_2;
    QDateEdit *record_date;
    QFrame *line_7;
    QWidget *page_analysis;
    QGridLayout *gridLayout_63;
    QWidget *widget_33;
    QGridLayout *gridLayout_59;
    QWidget *widget_22;
    QGridLayout *gridLayout_38;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *analysis_reset;
    QPushButton *analysis_flush;
    QWidget *widget_30;
    QGridLayout *gridLayout_44;
    QDateEdit *analysis_startDate;
    QLabel *label_11;
    QDateEdit *analysis_endDate;
    QLabel *label_8;
    QCheckBox *cBox_analysisDate;
    QCheckBox *cBox_analysisText;
    QSpacerItem *horizontalSpacer_11;
    QWidget *widget_20;
    QGridLayout *gridLayout_57;
    QWidget *widget_analysis_book;
    QGridLayout *gridLayout_61;
    QLabel *label_34;
    QLineEdit *analysis_book;
    QWidget *widget_32;
    QGridLayout *gridLayout_50;
    QLabel *label_31;
    QLineEdit *analysis_flowType;
    QWidget *widget_31;
    QGridLayout *gridLayout_42;
    QLabel *label_24;
    QLineEdit *analysis_account;
    QWidget *widget_first;
    QGridLayout *gridLayout_39;
    QLineEdit *analysis_firstClassify;
    QLabel *lab_firstClassify;
    QWidget *widget_second;
    QGridLayout *gridLayout_60;
    QLineEdit *analysis_secondClassify;
    QLabel *lab_secondClassify;
    QWidget *widget_transfer_in;
    QGridLayout *gridLayout_62;
    QLabel *label_25;
    QLineEdit *analysis_account_in;
    QGroupBox *groupBox_34;
    QGridLayout *gridLayout_66;
    QPushButton *analysis_chart;
    QWidget *widget_35;
    QGridLayout *gridLayout_64;
    QLabel *label_19;
    QDoubleSpinBox *analysis_totalExpend;
    QLabel *label_13;
    QLabel *label_17;
    QDoubleSpinBox *analysis_totalIncome;
    QDoubleSpinBox *analysis_totalTransfer;
    QSpacerItem *horizontalSpacer_14;
    QWidget *page_classify;
    QGridLayout *gridLayout_58;
    TreeWidget *classify_incomeTree;
    TreeWidget *classify_expendTree;
    QWidget *page_account;
    QGridLayout *gridLayout_56;
    QWidget *widget_24;
    QGridLayout *gridLayout_46;
    QGroupBox *groupBox_account_left_dock;
    QGridLayout *gridLayout_47;
    QPushButton *account_up;
    QPushButton *account_add;
    QPushButton *account_down;
    QPushButton *account_top;
    QSpacerItem *horizontalSpacer_21;
    QScrollArea *scrollArea_account;
    QWidget *scrollAreaWidgetContents_3;
    QGridLayout *gridLayout_48;
    QVBoxLayout *vLayout_account;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget_21;
    QGridLayout *gridLayout_53;
    QGroupBox *groupBox_account_right_dock;
    QGridLayout *gridLayout_43;
    QLabel *account_loading;
    QPushButton *account_delete;
    QPushButton *account_return;
    QSpacerItem *horizontalSpacer_22;
    QPushButton *account_save;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_25;
    QGridLayout *gridLayout_41;
    QLabel *label_23;
    QStackedWidget *stackedWidget_account_name;
    QWidget *page_account_newName;
    QGridLayout *gridLayout_54;
    QComboBox *account_newName;
    QWidget *page_account_name;
    QGridLayout *gridLayout_55;
    QLineEdit *account_name;
    QWidget *widget_26;
    QGridLayout *gridLayout_49;
    QLabel *label_29;
    QDoubleSpinBox *account_fund;
    QWidget *widget_27;
    QGridLayout *gridLayout_51;
    QLabel *label_30;
    QLineEdit *account_nickname;
    QWidget *widget_28;
    QGridLayout *gridLayout_52;
    QLabel *label_28;
    QLineEdit *account_card;
    QWidget *widget_23;
    QGridLayout *gridLayout_45;
    QLabel *label_27;
    QPlainTextEdit *account_remark;
    QWidget *widget_account_enable;
    QGridLayout *gridLayout_40;
    QLabel *label_26;
    QPushButton *account_enable;
    QWidget *page_book;
    QGridLayout *gridLayout_28;
    QWidget *widget_14;
    QGridLayout *gridLayout_27;
    QGroupBox *groupBox_book_left_dock;
    QGridLayout *gridLayout_21;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *book_top;
    QPushButton *book_down;
    QPushButton *book_add;
    QPushButton *book_up;
    QScrollArea *scrollArea_book;
    QWidget *scrollAreaWidgetContents_4;
    QGridLayout *gridLayout_22;
    QVBoxLayout *vLayout_book;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_29;
    QGridLayout *gridLayout_24;
    QGroupBox *groupBox_book_right_dock;
    QGridLayout *gridLayout_23;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *book_save;
    QPushButton *book_delete;
    QPushButton *book_return;
    QLabel *book_loading;
    QStackedWidget *stackedWidget_book;
    QWidget *page_addBook;
    QGridLayout *gridLayout_25;
    QPlainTextEdit *book_newRemark;
    QLineEdit *book_newName;
    QWidget *page_bookInfo;
    QGridLayout *gridLayout_26;
    QWidget *widget_15;
    QGridLayout *gridLayout_16;
    QLabel *label_12;
    QPlainTextEdit *book_remark;
    QLabel *book_info;
    QWidget *widget_16;
    QGridLayout *gridLayout_17;
    QLabel *label_14;
    QLineEdit *book_name;
    QWidget *widget_18;
    QGridLayout *gridLayout_18;
    QLabel *label_16;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_18;
    QDoubleSpinBox *book_totalIncome;
    QDoubleSpinBox *book_totalExpend;
    QWidget *page_setting;
    QWidget *page_borrowReturn;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWin)
    {
        if (MainWin->objectName().isEmpty())
            MainWin->setObjectName(QString::fromUtf8("MainWin"));
        MainWin->resize(1100, 750);
        MainWin->setMinimumSize(QSize(1100, 750));
        MainWin->setMaximumSize(QSize(1100, 750));
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

        line_top = new QFrame(centralwidget);
        line_top->setObjectName(QString::fromUtf8("line_top"));
        line_top->setMinimumSize(QSize(0, 2));
        line_top->setMaximumSize(QSize(16777215, 2));
        line_top->setFrameShape(QFrame::HLine);
        line_top->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_top, 0, 0, 1, 1);

        widget_background = new QWidget(centralwidget);
        widget_background->setObjectName(QString::fromUtf8("widget_background"));
        gridLayout_3 = new QGridLayout(widget_background);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        line = new QFrame(widget_background);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(0, 2));
        line->setMaximumSize(QSize(16777215, 2));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 1, 0, 1, 4);

        line_central = new QFrame(widget_background);
        line_central->setObjectName(QString::fromUtf8("line_central"));
        line_central->setFrameShape(QFrame::VLine);
        line_central->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_central, 2, 1, 1, 1);

        widget_top_dock = new QWidget(widget_background);
        widget_top_dock->setObjectName(QString::fromUtf8("widget_top_dock"));
        widget_top_dock->setMinimumSize(QSize(0, 0));
        widget_top_dock->setMaximumSize(QSize(16777215, 80));
        gridLayout_4 = new QGridLayout(widget_top_dock);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget_top_dock);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        gridLayout_15 = new QGridLayout(widget_3);
        gridLayout_15->setSpacing(0);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_15->setContentsMargins(4, 0, 0, 0);
        widget_totalFund = new QWidget(widget_3);
        widget_totalFund->setObjectName(QString::fromUtf8("widget_totalFund"));
        QFont font;
        font.setPointSize(13);
        widget_totalFund->setFont(font);
        gridLayout_9 = new QGridLayout(widget_totalFund);
        gridLayout_9->setSpacing(5);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(5, 5, 5, 5);
        widget_6 = new QWidget(widget_totalFund);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setMinimumSize(QSize(70, 70));
        widget_6->setMaximumSize(QSize(70, 70));
        gridLayout_5 = new QGridLayout(widget_6);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(65, 65));
        label_3->setStyleSheet(QString::fromUtf8(""));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/img/fund.png")));
        label_3->setScaledContents(true);

        gridLayout_5->addWidget(label_3, 0, 0, 1, 1);


        gridLayout_9->addWidget(widget_6, 0, 0, 2, 1);

        widget_7 = new QWidget(widget_totalFund);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setMinimumSize(QSize(180, 30));
        widget_7->setMaximumSize(QSize(180, 30));
        gridLayout_8 = new QGridLayout(widget_7);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setHorizontalSpacing(5);
        gridLayout_8->setVerticalSpacing(0);
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        dock_totalFund_hide = new QPushButton(widget_7);
        dock_totalFund_hide->setObjectName(QString::fromUtf8("dock_totalFund_hide"));
        dock_totalFund_hide->setMinimumSize(QSize(30, 30));
        dock_totalFund_hide->setMaximumSize(QSize(30, 30));
        dock_totalFund_hide->setCheckable(true);
        dock_totalFund_hide->setAutoExclusive(true);

        gridLayout_8->addWidget(dock_totalFund_hide, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        label_15 = new QLabel(widget_7);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMinimumSize(QSize(0, 0));
        label_15->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        label_15->setFont(font1);

        gridLayout_8->addWidget(label_15, 0, 1, 1, 1);


        gridLayout_9->addWidget(widget_7, 0, 1, 1, 1);

        dock_totalFund_num = new QLabel(widget_totalFund);
        dock_totalFund_num->setObjectName(QString::fromUtf8("dock_totalFund_num"));
        dock_totalFund_num->setMinimumSize(QSize(180, 35));
        dock_totalFund_num->setMaximumSize(QSize(180, 35));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(13);
        font2.setBold(true);
        dock_totalFund_num->setFont(font2);
        dock_totalFund_num->setStyleSheet(QString::fromUtf8("color: rgb(254, 118, 95);"));

        gridLayout_9->addWidget(dock_totalFund_num, 1, 1, 1, 1);


        gridLayout_15->addWidget(widget_totalFund, 0, 0, 1, 1);

        line_3 = new QFrame(widget_3);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setMinimumSize(QSize(2, 0));
        line_3->setMaximumSize(QSize(2, 16777215));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_15->addWidget(line_3, 0, 1, 1, 1);

        widget_monthIncome = new QWidget(widget_3);
        widget_monthIncome->setObjectName(QString::fromUtf8("widget_monthIncome"));
        gridLayout_10 = new QGridLayout(widget_monthIncome);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(-1, 5, -1, 5);
        widget_8 = new QWidget(widget_monthIncome);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setMinimumSize(QSize(70, 70));
        widget_8->setMaximumSize(QSize(70, 70));
        gridLayout_6 = new QGridLayout(widget_8);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget_8);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(56, 56));
        label_5->setStyleSheet(QString::fromUtf8(""));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/img/income.png")));
        label_5->setScaledContents(true);

        gridLayout_6->addWidget(label_5, 0, 0, 1, 1);


        gridLayout_10->addWidget(widget_8, 0, 0, 2, 1);

        widget_9 = new QWidget(widget_monthIncome);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        widget_9->setMinimumSize(QSize(180, 30));
        widget_9->setMaximumSize(QSize(180, 30));
        gridLayout_11 = new QGridLayout(widget_9);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setHorizontalSpacing(5);
        gridLayout_11->setVerticalSpacing(0);
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        dock_monthIncome_hide = new QPushButton(widget_9);
        dock_monthIncome_hide->setObjectName(QString::fromUtf8("dock_monthIncome_hide"));
        dock_monthIncome_hide->setMinimumSize(QSize(30, 30));
        dock_monthIncome_hide->setMaximumSize(QSize(30, 30));
        dock_monthIncome_hide->setCheckable(true);
        dock_monthIncome_hide->setAutoExclusive(true);

        gridLayout_11->addWidget(dock_monthIncome_hide, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        label_7 = new QLabel(widget_9);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(0, 0));
        label_7->setMaximumSize(QSize(16777215, 16777215));
        label_7->setFont(font1);

        gridLayout_11->addWidget(label_7, 0, 1, 1, 1);


        gridLayout_10->addWidget(widget_9, 0, 1, 1, 1);

        dock_monthIncome_num = new QLabel(widget_monthIncome);
        dock_monthIncome_num->setObjectName(QString::fromUtf8("dock_monthIncome_num"));
        dock_monthIncome_num->setMinimumSize(QSize(180, 35));
        dock_monthIncome_num->setMaximumSize(QSize(180, 35));
        dock_monthIncome_num->setFont(font2);
        dock_monthIncome_num->setStyleSheet(QString::fromUtf8("color: rgb(37, 184, 122);"));

        gridLayout_10->addWidget(dock_monthIncome_num, 1, 1, 1, 1);


        gridLayout_15->addWidget(widget_monthIncome, 0, 2, 1, 1);

        line_4 = new QFrame(widget_3);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setMinimumSize(QSize(2, 0));
        line_4->setMaximumSize(QSize(2, 16777215));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_15->addWidget(line_4, 0, 3, 1, 1);

        widget_monthExpend = new QWidget(widget_3);
        widget_monthExpend->setObjectName(QString::fromUtf8("widget_monthExpend"));
        gridLayout_12 = new QGridLayout(widget_monthExpend);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(-1, 5, -1, 5);
        widget_12 = new QWidget(widget_monthExpend);
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
        label_10->setFont(font1);

        gridLayout_14->addWidget(label_10, 0, 1, 1, 1);

        dock_monthExpend_hide = new QPushButton(widget_12);
        dock_monthExpend_hide->setObjectName(QString::fromUtf8("dock_monthExpend_hide"));
        dock_monthExpend_hide->setMinimumSize(QSize(30, 30));
        dock_monthExpend_hide->setMaximumSize(QSize(30, 30));
        dock_monthExpend_hide->setCheckable(true);
        dock_monthExpend_hide->setAutoExclusive(true);

        gridLayout_14->addWidget(dock_monthExpend_hide, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(59, 27, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_14->addItem(horizontalSpacer_4, 0, 3, 1, 1);


        gridLayout_12->addWidget(widget_12, 0, 1, 1, 1);

        widget_11 = new QWidget(widget_monthExpend);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        widget_11->setMinimumSize(QSize(70, 70));
        widget_11->setMaximumSize(QSize(70, 70));
        gridLayout_13 = new QGridLayout(widget_11);
        gridLayout_13->setSpacing(0);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(widget_11);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8(""));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/img/pay.png")));
        label_9->setScaledContents(true);

        gridLayout_13->addWidget(label_9, 0, 0, 1, 1);


        gridLayout_12->addWidget(widget_11, 0, 0, 2, 1);

        dock_monthExpend_num = new QLabel(widget_monthExpend);
        dock_monthExpend_num->setObjectName(QString::fromUtf8("dock_monthExpend_num"));
        dock_monthExpend_num->setMinimumSize(QSize(180, 35));
        dock_monthExpend_num->setMaximumSize(QSize(180, 35));
        dock_monthExpend_num->setFont(font2);
        dock_monthExpend_num->setStyleSheet(QString::fromUtf8("color: rgb(216, 30, 6);"));

        gridLayout_12->addWidget(dock_monthExpend_num, 1, 1, 1, 1);


        gridLayout_15->addWidget(widget_monthExpend, 0, 4, 1, 1);


        gridLayout_4->addWidget(widget_3, 0, 2, 1, 1);

        dock_addRecord = new QPushButton(widget_top_dock);
        dock_addRecord->setObjectName(QString::fromUtf8("dock_addRecord"));
        dock_addRecord->setMinimumSize(QSize(70, 70));
        dock_addRecord->setMaximumSize(QSize(70, 70));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        dock_addRecord->setFont(font3);
        dock_addRecord->setStyleSheet(QString::fromUtf8(""));

        gridLayout_4->addWidget(dock_addRecord, 0, 5, 1, 1);

        line_5 = new QFrame(widget_top_dock);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setMinimumSize(QSize(2, 0));
        line_5->setMaximumSize(QSize(2, 16777215));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_5, 0, 3, 1, 1);

        widget_2 = new QWidget(widget_top_dock);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(140, 0));
        widget_2->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_37 = new QGridLayout(widget_2);
        gridLayout_37->setObjectName(QString::fromUtf8("gridLayout_37"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_37->addWidget(label, 0, 0, 1, 1);


        gridLayout_4->addWidget(widget_2, 0, 0, 1, 1);

        line_2 = new QFrame(widget_top_dock);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setMinimumSize(QSize(2, 0));
        line_2->setMaximumSize(QSize(2, 16777215));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_2, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 4, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_10, 0, 6, 1, 1);


        gridLayout_3->addWidget(widget_top_dock, 0, 0, 1, 4);

        widget_left_dock = new QWidget(widget_background);
        widget_left_dock->setObjectName(QString::fromUtf8("widget_left_dock"));
        widget_left_dock->setMinimumSize(QSize(140, 0));
        widget_left_dock->setMaximumSize(QSize(140, 16777215));
        gridLayout_2 = new QGridLayout(widget_left_dock);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        dock_classify = new QPushButton(widget_left_dock);
        dock_classify->setObjectName(QString::fromUtf8("dock_classify"));
        dock_classify->setMinimumSize(QSize(0, 60));
        dock_classify->setMaximumSize(QSize(16777215, 60));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(11);
        dock_classify->setFont(font4);
        dock_classify->setCheckable(true);
        dock_classify->setAutoExclusive(true);

        gridLayout_2->addWidget(dock_classify, 6, 0, 1, 1);

        dock_analysis = new QPushButton(widget_left_dock);
        dock_analysis->setObjectName(QString::fromUtf8("dock_analysis"));
        dock_analysis->setMinimumSize(QSize(0, 60));
        dock_analysis->setMaximumSize(QSize(16777215, 60));
        dock_analysis->setFont(font4);
        dock_analysis->setCheckable(true);
        dock_analysis->setAutoExclusive(true);

        gridLayout_2->addWidget(dock_analysis, 1, 0, 1, 1);

        dock_borrowReturn = new QPushButton(widget_left_dock);
        dock_borrowReturn->setObjectName(QString::fromUtf8("dock_borrowReturn"));
        dock_borrowReturn->setMinimumSize(QSize(0, 60));
        dock_borrowReturn->setMaximumSize(QSize(16777215, 60));
        dock_borrowReturn->setFont(font4);
        dock_borrowReturn->setCheckable(true);
        dock_borrowReturn->setAutoExclusive(true);

        gridLayout_2->addWidget(dock_borrowReturn, 2, 0, 1, 1);

        dock_account = new QPushButton(widget_left_dock);
        dock_account->setObjectName(QString::fromUtf8("dock_account"));
        dock_account->setMinimumSize(QSize(0, 60));
        dock_account->setMaximumSize(QSize(16777215, 60));
        dock_account->setFont(font4);
        dock_account->setCheckable(true);
        dock_account->setAutoExclusive(true);

        gridLayout_2->addWidget(dock_account, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 8, 0, 1, 1);

        dock_record = new QPushButton(widget_left_dock);
        dock_record->setObjectName(QString::fromUtf8("dock_record"));
        dock_record->setMinimumSize(QSize(0, 60));
        dock_record->setMaximumSize(QSize(16777215, 60));
        dock_record->setFont(font4);
        dock_record->setCheckable(true);
        dock_record->setChecked(true);
        dock_record->setAutoExclusive(true);

        gridLayout_2->addWidget(dock_record, 0, 0, 1, 1);

        dock_book = new QPushButton(widget_left_dock);
        dock_book->setObjectName(QString::fromUtf8("dock_book"));
        dock_book->setMinimumSize(QSize(0, 60));
        dock_book->setMaximumSize(QSize(16777215, 60));
        dock_book->setFont(font4);
        dock_book->setCheckable(true);
        dock_book->setAutoExclusive(true);

        gridLayout_2->addWidget(dock_book, 5, 0, 1, 1);

        dock_setting = new QPushButton(widget_left_dock);
        dock_setting->setObjectName(QString::fromUtf8("dock_setting"));
        dock_setting->setMinimumSize(QSize(0, 60));
        dock_setting->setMaximumSize(QSize(16777215, 60));
        dock_setting->setFont(font4);
        dock_setting->setCheckable(true);
        dock_setting->setAutoExclusive(true);

        gridLayout_2->addWidget(dock_setting, 7, 0, 1, 1);


        gridLayout_3->addWidget(widget_left_dock, 2, 0, 1, 1);

        stackedWidget_dock = new QStackedWidget(widget_background);
        stackedWidget_dock->setObjectName(QString::fromUtf8("stackedWidget_dock"));
        page_record_analysis = new QWidget();
        page_record_analysis->setObjectName(QString::fromUtf8("page_record_analysis"));
        gridLayout_7 = new QGridLayout(page_record_analysis);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setHorizontalSpacing(5);
        gridLayout_7->setVerticalSpacing(8);
        gridLayout_7->setContentsMargins(5, 5, 5, 5);
        stackedWidget_record = new QStackedWidget(page_record_analysis);
        stackedWidget_record->setObjectName(QString::fromUtf8("stackedWidget_record"));
        page_record_tree = new QWidget();
        page_record_tree->setObjectName(QString::fromUtf8("page_record_tree"));
        gridLayout_20 = new QGridLayout(page_record_tree);
        gridLayout_20->setSpacing(0);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        gridLayout_20->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(page_record_tree);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 40));
        widget->setMaximumSize(QSize(16777215, 40));
        gridLayout_32 = new QGridLayout(widget);
        gridLayout_32->setObjectName(QString::fromUtf8("gridLayout_32"));
        gridLayout_32->setHorizontalSpacing(10);
        gridLayout_32->setVerticalSpacing(0);
        gridLayout_32->setContentsMargins(0, 5, 0, 0);
        widget_10 = new QWidget(widget);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        widget_10->setMinimumSize(QSize(300, 0));
        widget_10->setMaximumSize(QSize(300, 16777215));
        gridLayout_31 = new QGridLayout(widget_10);
        gridLayout_31->setObjectName(QString::fromUtf8("gridLayout_31"));
        gridLayout_31->setHorizontalSpacing(5);
        gridLayout_31->setVerticalSpacing(0);
        gridLayout_31->setContentsMargins(0, 0, 0, 0);
        record_pageRecordNum = new QComboBox(widget_10);
        record_pageRecordNum->addItem(QString());
        record_pageRecordNum->addItem(QString());
        record_pageRecordNum->addItem(QString());
        record_pageRecordNum->setObjectName(QString::fromUtf8("record_pageRecordNum"));
        record_pageRecordNum->setMinimumSize(QSize(95, 30));
        record_pageRecordNum->setMaximumSize(QSize(95, 30));
        QFont font5;
        font5.setPointSize(9);
        record_pageRecordNum->setFont(font5);

        gridLayout_31->addWidget(record_pageRecordNum, 0, 1, 1, 1);

        record_pageInfo = new QLabel(widget_10);
        record_pageInfo->setObjectName(QString::fromUtf8("record_pageInfo"));
        record_pageInfo->setMinimumSize(QSize(200, 30));
        record_pageInfo->setMaximumSize(QSize(200, 30));
        record_pageInfo->setFont(font5);
        record_pageInfo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_31->addWidget(record_pageInfo, 0, 2, 1, 1);


        gridLayout_32->addWidget(widget_10, 0, 2, 1, 1);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMinimumSize(QSize(140, 0));
        widget_4->setMaximumSize(QSize(140, 16777215));
        gridLayout_29 = new QGridLayout(widget_4);
        gridLayout_29->setObjectName(QString::fromUtf8("gridLayout_29"));
        gridLayout_29->setHorizontalSpacing(5);
        gridLayout_29->setVerticalSpacing(0);
        gridLayout_29->setContentsMargins(0, 0, 0, 0);
        record_pageIndex = new QSpinBox(widget_4);
        record_pageIndex->setObjectName(QString::fromUtf8("record_pageIndex"));
        record_pageIndex->setMinimumSize(QSize(70, 26));
        record_pageIndex->setMaximumSize(QSize(70, 26));
        record_pageIndex->setFrame(false);
        record_pageIndex->setAlignment(Qt::AlignCenter);
        record_pageIndex->setButtonSymbols(QAbstractSpinBox::NoButtons);
        record_pageIndex->setMinimum(1);
        record_pageIndex->setMaximum(9999);
        record_pageIndex->setValue(1);

        gridLayout_29->addWidget(record_pageIndex, 0, 2, 1, 1);

        record_pageNext = new QPushButton(widget_4);
        record_pageNext->setObjectName(QString::fromUtf8("record_pageNext"));
        record_pageNext->setMinimumSize(QSize(30, 30));
        record_pageNext->setMaximumSize(QSize(30, 30));
        QFont font6;
        font6.setPointSize(12);
        record_pageNext->setFont(font6);

        gridLayout_29->addWidget(record_pageNext, 0, 3, 1, 1);

        record_pagePrevious = new QPushButton(widget_4);
        record_pagePrevious->setObjectName(QString::fromUtf8("record_pagePrevious"));
        record_pagePrevious->setMinimumSize(QSize(30, 30));
        record_pagePrevious->setMaximumSize(QSize(30, 30));
        record_pagePrevious->setFont(font6);

        gridLayout_29->addWidget(record_pagePrevious, 0, 1, 1, 1);


        gridLayout_32->addWidget(widget_4, 0, 1, 1, 1);

        widget_5 = new QWidget(widget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setMinimumSize(QSize(150, 0));
        widget_5->setMaximumSize(QSize(145, 16777215));
        gridLayout_30 = new QGridLayout(widget_5);
        gridLayout_30->setObjectName(QString::fromUtf8("gridLayout_30"));
        gridLayout_30->setHorizontalSpacing(10);
        gridLayout_30->setVerticalSpacing(0);
        gridLayout_30->setContentsMargins(0, 0, 0, 0);
        record_output_all = new QPushButton(widget_5);
        record_output_all->setObjectName(QString::fromUtf8("record_output_all"));
        record_output_all->setMinimumSize(QSize(70, 30));
        record_output_all->setMaximumSize(QSize(70, 30));
        record_output_all->setFont(font5);

        gridLayout_30->addWidget(record_output_all, 0, 1, 1, 1);

        record_output = new QPushButton(widget_5);
        record_output->setObjectName(QString::fromUtf8("record_output"));
        record_output->setMinimumSize(QSize(70, 30));
        record_output->setMaximumSize(QSize(70, 30));
        record_output->setFont(font5);

        gridLayout_30->addWidget(record_output, 0, 0, 1, 1);


        gridLayout_32->addWidget(widget_5, 0, 7, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_32->addItem(horizontalSpacer_8, 0, 3, 1, 1);

        widget_13 = new QWidget(widget);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));
        widget_13->setMinimumSize(QSize(150, 0));
        widget_13->setMaximumSize(QSize(145, 16777215));
        gridLayout_33 = new QGridLayout(widget_13);
        gridLayout_33->setObjectName(QString::fromUtf8("gridLayout_33"));
        gridLayout_33->setHorizontalSpacing(10);
        gridLayout_33->setVerticalSpacing(0);
        gridLayout_33->setContentsMargins(0, 0, 0, 0);
        record_collapse = new QPushButton(widget_13);
        record_collapse->setObjectName(QString::fromUtf8("record_collapse"));
        record_collapse->setMinimumSize(QSize(70, 30));
        record_collapse->setMaximumSize(QSize(70, 30));
        record_collapse->setFont(font5);

        gridLayout_33->addWidget(record_collapse, 0, 1, 1, 1);

        record_expand = new QPushButton(widget_13);
        record_expand->setObjectName(QString::fromUtf8("record_expand"));
        record_expand->setMinimumSize(QSize(70, 30));
        record_expand->setMaximumSize(QSize(70, 30));
        record_expand->setFont(font5);

        gridLayout_33->addWidget(record_expand, 0, 0, 1, 1);


        gridLayout_32->addWidget(widget_13, 0, 6, 1, 1);


        gridLayout_20->addWidget(widget, 2, 0, 1, 1);

        record_tree = new TreeWidget(page_record_tree);
        record_tree->setObjectName(QString::fromUtf8("record_tree"));
        QFont font7;
        font7.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font7.setPointSize(10);
        record_tree->setFont(font7);
        record_tree->setStyleSheet(QString::fromUtf8("QHeaderView::section {\n"
"	border: 1px solid black;  /*\350\256\276\347\275\256\350\276\271\346\241\206\346\240\267\345\274\217*/\n"
"	border-left:transparent;\n"
"	border-top:transparent;\n"
"	font:16px;\n"
"	height:36px;\n"
"	background-color: rgb(221, 221, 221);/*lightgray;  /*\350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"	/*padding: 4px; \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235*/\n"
"	font-weight: bold;\n"
" }\n"
"\n"
"QTreeWidget{\n"
"	border:1px solid black;\n"
"     gridline-color: gray;  /*\350\256\276\347\275\256\347\275\221\346\240\274\347\272\277\351\242\234\350\211\262*/\n"
"	outline:none;\n"
"	/*alternate-background-color:lightgray;*/\n"
"	selection-background-color:transparent;\n"
"}\n"
"\n"
"QTreeView::item{\n"
"	border:1px solid black;\n"
"	border-left:transparent;\n"
"	border-top:transparent;\n"
"	height:30px;\n"
"}\n"
"\n"
"QTreeView::branch{\n"
"	border:1px solid black;\n"
"	border-right:transparent;\n"
"	border-left:transparent;\n"
"	bor"
                        "der-top:transparent;\n"
"}\n"
"\n"
"QTreeView::item:selected{\n"
"	/*color:black;\n"
"	color:inherit;\n"
"	background:rgb(230, 230, 230);\n"
"	color:blue;\n"
"	font-weight: bold;*/\n"
"	color:inherit;\n"
"	background:rgb(235, 235, 235);\n"
"}\n"
"\n"
"QTreeView::branch:has-children:!has-siblings:closed,\n"
"QTreeView::branch:closed:has-children:has-siblings{\n"
"	border-image: none;\n"
"	image:url(:/img/branch-close.png);\n"
"}\n"
"\n"
"QTreeView::branch:open:has-children:!has-siblings,\n"
"QTreeView::branch:open:has-children:has-siblings{\n"
"	border-image: none;\n"
"	image:url(:/img/branch-open.png);\n"
"}\n"
""));
        record_tree->setFrameShape(QFrame::StyledPanel);
        record_tree->setFrameShadow(QFrame::Sunken);
        record_tree->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        gridLayout_20->addWidget(record_tree, 1, 0, 1, 1);

        stackedWidget_record->addWidget(page_record_tree);
        page_record_loading = new QWidget();
        page_record_loading->setObjectName(QString::fromUtf8("page_record_loading"));
        gridLayout_36 = new QGridLayout(page_record_loading);
        gridLayout_36->setObjectName(QString::fromUtf8("gridLayout_36"));
        record_loading = new QLabel(page_record_loading);
        record_loading->setObjectName(QString::fromUtf8("record_loading"));
        record_loading->setMinimumSize(QSize(50, 50));
        record_loading->setMaximumSize(QSize(50, 50));
        record_loading->setScaledContents(true);

        gridLayout_36->addWidget(record_loading, 0, 0, 1, 1);

        stackedWidget_record->addWidget(page_record_loading);

        gridLayout_7->addWidget(stackedWidget_record, 3, 0, 1, 1);

        stackedWidget_record_analysis = new QStackedWidget(page_record_analysis);
        stackedWidget_record_analysis->setObjectName(QString::fromUtf8("stackedWidget_record_analysis"));
        stackedWidget_record_analysis->setMaximumSize(QSize(16777215, 180));
        page_record = new QWidget();
        page_record->setObjectName(QString::fromUtf8("page_record"));
        gridLayout_65 = new QGridLayout(page_record);
        gridLayout_65->setSpacing(0);
        gridLayout_65->setObjectName(QString::fromUtf8("gridLayout_65"));
        gridLayout_65->setContentsMargins(0, 0, 0, 0);
        groupBox_13 = new QGroupBox(page_record);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        groupBox_13->setMinimumSize(QSize(0, 48));
        groupBox_13->setMaximumSize(QSize(16777215, 48));
        groupBox_13->setStyleSheet(QString::fromUtf8(""));
        gridLayout_19 = new QGridLayout(groupBox_13);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        gridLayout_19->setHorizontalSpacing(8);
        gridLayout_19->setVerticalSpacing(0);
        gridLayout_19->setContentsMargins(4, 0, 4, 0);
        record_input = new QLineEdit(groupBox_13);
        record_input->setObjectName(QString::fromUtf8("record_input"));
        record_input->setMinimumSize(QSize(245, 35));
        record_input->setMaximumSize(QSize(245, 35));
        QFont font8;
        font8.setPointSize(10);
        record_input->setFont(font8);

        gridLayout_19->addWidget(record_input, 0, 1, 1, 1);

        widget_17 = new QWidget(groupBox_13);
        widget_17->setObjectName(QString::fromUtf8("widget_17"));
        widget_17->setMinimumSize(QSize(145, 0));
        widget_17->setMaximumSize(QSize(145, 16777215));
        gridLayout_34 = new QGridLayout(widget_17);
        gridLayout_34->setObjectName(QString::fromUtf8("gridLayout_34"));
        gridLayout_34->setHorizontalSpacing(5);
        gridLayout_34->setVerticalSpacing(0);
        gridLayout_34->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget_17);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(70, 0));
        label_4->setMaximumSize(QSize(70, 16777215));
        label_4->setFont(font8);

        gridLayout_34->addWidget(label_4, 0, 0, 1, 1);

        record_flowType = new QComboBox(widget_17);
        record_flowType->addItem(QString());
        record_flowType->addItem(QString());
        record_flowType->addItem(QString());
        record_flowType->addItem(QString());
        record_flowType->setObjectName(QString::fromUtf8("record_flowType"));
        record_flowType->setMinimumSize(QSize(70, 35));
        record_flowType->setMaximumSize(QSize(70, 35));
        record_flowType->setFont(font8);

        gridLayout_34->addWidget(record_flowType, 0, 1, 1, 1);


        gridLayout_19->addWidget(widget_17, 0, 7, 1, 1);

        line_6 = new QFrame(groupBox_13);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setMinimumSize(QSize(2, 0));
        line_6->setMaximumSize(QSize(2, 16777215));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_19->addWidget(line_6, 0, 6, 1, 1);

        record_filter = new QComboBox(groupBox_13);
        record_filter->addItem(QString());
        record_filter->addItem(QString());
        record_filter->addItem(QString());
        record_filter->addItem(QString());
        record_filter->setObjectName(QString::fromUtf8("record_filter"));
        record_filter->setMinimumSize(QSize(105, 35));
        record_filter->setMaximumSize(QSize(105, 35));
        record_filter->setFont(font8);

        gridLayout_19->addWidget(record_filter, 0, 2, 1, 1);

        record_reset = new QPushButton(groupBox_13);
        record_reset->setObjectName(QString::fromUtf8("record_reset"));
        record_reset->setMinimumSize(QSize(70, 35));
        record_reset->setMaximumSize(QSize(70, 35));
        record_reset->setFont(font5);

        gridLayout_19->addWidget(record_reset, 0, 12, 1, 1);

        record_flush = new QPushButton(groupBox_13);
        record_flush->setObjectName(QString::fromUtf8("record_flush"));
        record_flush->setMinimumSize(QSize(50, 35));
        record_flush->setMaximumSize(QSize(50, 35));
        record_flush->setFont(font5);

        gridLayout_19->addWidget(record_flush, 0, 13, 1, 1);

        widget_19 = new QWidget(groupBox_13);
        widget_19->setObjectName(QString::fromUtf8("widget_19"));
        widget_19->setMinimumSize(QSize(240, 0));
        widget_19->setMaximumSize(QSize(240, 16777215));
        gridLayout_35 = new QGridLayout(widget_19);
        gridLayout_35->setObjectName(QString::fromUtf8("gridLayout_35"));
        gridLayout_35->setHorizontalSpacing(5);
        gridLayout_35->setVerticalSpacing(0);
        gridLayout_35->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget_19);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(70, 0));
        label_2->setMaximumSize(QSize(70, 16777215));
        label_2->setFont(font8);

        gridLayout_35->addWidget(label_2, 0, 0, 1, 1);

        record_date = new QDateEdit(widget_19);
        record_date->setObjectName(QString::fromUtf8("record_date"));
        record_date->setMinimumSize(QSize(165, 35));
        record_date->setMaximumSize(QSize(165, 35));
        record_date->setFont(font8);
        record_date->setCalendarPopup(true);
        record_date->setDate(QDate(2023, 11, 8));

        gridLayout_35->addWidget(record_date, 0, 1, 1, 1);


        gridLayout_19->addWidget(widget_19, 0, 8, 1, 1);

        line_7 = new QFrame(groupBox_13);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setMinimumSize(QSize(2, 0));
        line_7->setMaximumSize(QSize(2, 16777215));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout_19->addWidget(line_7, 0, 11, 1, 1);


        gridLayout_65->addWidget(groupBox_13, 0, 0, 1, 1);

        stackedWidget_record_analysis->addWidget(page_record);
        page_analysis = new QWidget();
        page_analysis->setObjectName(QString::fromUtf8("page_analysis"));
        gridLayout_63 = new QGridLayout(page_analysis);
        gridLayout_63->setObjectName(QString::fromUtf8("gridLayout_63"));
        gridLayout_63->setHorizontalSpacing(0);
        gridLayout_63->setVerticalSpacing(10);
        gridLayout_63->setContentsMargins(0, 0, 0, 0);
        widget_33 = new QWidget(page_analysis);
        widget_33->setObjectName(QString::fromUtf8("widget_33"));
        widget_33->setMinimumSize(QSize(0, 120));
        widget_33->setMaximumSize(QSize(16777215, 120));
        gridLayout_59 = new QGridLayout(widget_33);
        gridLayout_59->setObjectName(QString::fromUtf8("gridLayout_59"));
        gridLayout_59->setHorizontalSpacing(0);
        gridLayout_59->setVerticalSpacing(10);
        gridLayout_59->setContentsMargins(0, 0, 0, 0);
        widget_22 = new QWidget(widget_33);
        widget_22->setObjectName(QString::fromUtf8("widget_22"));
        gridLayout_38 = new QGridLayout(widget_22);
        gridLayout_38->setObjectName(QString::fromUtf8("gridLayout_38"));
        gridLayout_38->setHorizontalSpacing(5);
        gridLayout_38->setVerticalSpacing(0);
        gridLayout_38->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_7 = new QSpacerItem(226, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_38->addItem(horizontalSpacer_7, 0, 4, 1, 1);

        analysis_reset = new QPushButton(widget_22);
        analysis_reset->setObjectName(QString::fromUtf8("analysis_reset"));
        analysis_reset->setMinimumSize(QSize(70, 35));
        analysis_reset->setMaximumSize(QSize(70, 35));
        analysis_reset->setFont(font5);

        gridLayout_38->addWidget(analysis_reset, 0, 5, 1, 1);

        analysis_flush = new QPushButton(widget_22);
        analysis_flush->setObjectName(QString::fromUtf8("analysis_flush"));
        analysis_flush->setMinimumSize(QSize(50, 35));
        analysis_flush->setMaximumSize(QSize(50, 35));
        analysis_flush->setFont(font5);

        gridLayout_38->addWidget(analysis_flush, 0, 6, 1, 1);

        widget_30 = new QWidget(widget_22);
        widget_30->setObjectName(QString::fromUtf8("widget_30"));
        widget_30->setMinimumSize(QSize(575, 35));
        widget_30->setMaximumSize(QSize(575, 35));
        gridLayout_44 = new QGridLayout(widget_30);
        gridLayout_44->setObjectName(QString::fromUtf8("gridLayout_44"));
        gridLayout_44->setHorizontalSpacing(5);
        gridLayout_44->setVerticalSpacing(0);
        gridLayout_44->setContentsMargins(0, 0, 0, 0);
        analysis_startDate = new QDateEdit(widget_30);
        analysis_startDate->setObjectName(QString::fromUtf8("analysis_startDate"));
        analysis_startDate->setMinimumSize(QSize(0, 35));
        analysis_startDate->setMaximumSize(QSize(16777215, 35));
        analysis_startDate->setFont(font8);
        analysis_startDate->setCalendarPopup(true);
        analysis_startDate->setDate(QDate(2023, 11, 8));

        gridLayout_44->addWidget(analysis_startDate, 0, 1, 1, 1);

        label_11 = new QLabel(widget_30);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(25, 0));
        label_11->setMaximumSize(QSize(25, 16777215));
        QFont font9;
        font9.setPointSize(15);
        label_11->setFont(font9);
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_44->addWidget(label_11, 0, 2, 1, 1);

        analysis_endDate = new QDateEdit(widget_30);
        analysis_endDate->setObjectName(QString::fromUtf8("analysis_endDate"));
        analysis_endDate->setMinimumSize(QSize(0, 35));
        analysis_endDate->setMaximumSize(QSize(16777215, 35));
        analysis_endDate->setFont(font8);
        analysis_endDate->setCalendarPopup(true);
        analysis_endDate->setDate(QDate(2023, 11, 8));

        gridLayout_44->addWidget(analysis_endDate, 0, 3, 1, 1);

        label_8 = new QLabel(widget_30);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(70, 0));
        label_8->setMaximumSize(QSize(70, 16777215));
        label_8->setFont(font8);

        gridLayout_44->addWidget(label_8, 0, 0, 1, 1);


        gridLayout_38->addWidget(widget_30, 0, 0, 1, 1);

        cBox_analysisDate = new QCheckBox(widget_22);
        cBox_analysisDate->setObjectName(QString::fromUtf8("cBox_analysisDate"));
        cBox_analysisDate->setMinimumSize(QSize(0, 35));
        cBox_analysisDate->setFont(font8);
        cBox_analysisDate->setChecked(true);

        gridLayout_38->addWidget(cBox_analysisDate, 0, 2, 1, 1);

        cBox_analysisText = new QCheckBox(widget_22);
        cBox_analysisText->setObjectName(QString::fromUtf8("cBox_analysisText"));
        cBox_analysisText->setMinimumSize(QSize(0, 35));
        cBox_analysisText->setFont(font8);
        cBox_analysisText->setChecked(false);

        gridLayout_38->addWidget(cBox_analysisText, 0, 3, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_38->addItem(horizontalSpacer_11, 0, 1, 1, 1);


        gridLayout_59->addWidget(widget_22, 0, 0, 1, 1);

        widget_20 = new QWidget(widget_33);
        widget_20->setObjectName(QString::fromUtf8("widget_20"));
        gridLayout_57 = new QGridLayout(widget_20);
        gridLayout_57->setSpacing(8);
        gridLayout_57->setObjectName(QString::fromUtf8("gridLayout_57"));
        gridLayout_57->setContentsMargins(0, 0, 0, 0);
        widget_analysis_book = new QWidget(widget_20);
        widget_analysis_book->setObjectName(QString::fromUtf8("widget_analysis_book"));
        widget_analysis_book->setMinimumSize(QSize(200, 0));
        widget_analysis_book->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_61 = new QGridLayout(widget_analysis_book);
        gridLayout_61->setObjectName(QString::fromUtf8("gridLayout_61"));
        gridLayout_61->setHorizontalSpacing(5);
        gridLayout_61->setVerticalSpacing(0);
        gridLayout_61->setContentsMargins(0, 0, 0, 0);
        label_34 = new QLabel(widget_analysis_book);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setMinimumSize(QSize(70, 35));
        label_34->setMaximumSize(QSize(70, 35));
        label_34->setFont(font8);

        gridLayout_61->addWidget(label_34, 0, 0, 1, 1);

        analysis_book = new QLineEdit(widget_analysis_book);
        analysis_book->setObjectName(QString::fromUtf8("analysis_book"));
        analysis_book->setMinimumSize(QSize(0, 35));
        QFont font10;
        font10.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font10.setPointSize(10);
        font10.setBold(false);
        font10.setItalic(false);
        font10.setUnderline(false);
        font10.setStrikeOut(false);
        font10.setKerning(true);
        font10.setStyleStrategy(QFont::PreferDefault);
        analysis_book->setFont(font10);
        analysis_book->setCursor(QCursor(Qt::IBeamCursor));
        analysis_book->setMaxLength(30);
        analysis_book->setFrame(false);

        gridLayout_61->addWidget(analysis_book, 0, 1, 1, 1);


        gridLayout_57->addWidget(widget_analysis_book, 0, 0, 1, 1);

        widget_32 = new QWidget(widget_20);
        widget_32->setObjectName(QString::fromUtf8("widget_32"));
        widget_32->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_50 = new QGridLayout(widget_32);
        gridLayout_50->setObjectName(QString::fromUtf8("gridLayout_50"));
        gridLayout_50->setHorizontalSpacing(5);
        gridLayout_50->setVerticalSpacing(0);
        gridLayout_50->setContentsMargins(0, 0, 0, 0);
        label_31 = new QLabel(widget_32);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setMinimumSize(QSize(70, 35));
        label_31->setMaximumSize(QSize(70, 35));
        label_31->setFont(font8);

        gridLayout_50->addWidget(label_31, 0, 0, 1, 1);

        analysis_flowType = new QLineEdit(widget_32);
        analysis_flowType->setObjectName(QString::fromUtf8("analysis_flowType"));
        analysis_flowType->setMinimumSize(QSize(0, 35));
        analysis_flowType->setFont(font10);
        analysis_flowType->setCursor(QCursor(Qt::IBeamCursor));
        analysis_flowType->setMaxLength(30);
        analysis_flowType->setFrame(false);

        gridLayout_50->addWidget(analysis_flowType, 0, 1, 1, 1);


        gridLayout_57->addWidget(widget_32, 0, 1, 1, 1);

        widget_31 = new QWidget(widget_20);
        widget_31->setObjectName(QString::fromUtf8("widget_31"));
        widget_31->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_42 = new QGridLayout(widget_31);
        gridLayout_42->setObjectName(QString::fromUtf8("gridLayout_42"));
        gridLayout_42->setHorizontalSpacing(5);
        gridLayout_42->setVerticalSpacing(0);
        gridLayout_42->setContentsMargins(0, 0, 0, 0);
        label_24 = new QLabel(widget_31);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setMinimumSize(QSize(70, 35));
        label_24->setMaximumSize(QSize(70, 16777215));
        label_24->setFont(font8);

        gridLayout_42->addWidget(label_24, 0, 0, 1, 1);

        analysis_account = new QLineEdit(widget_31);
        analysis_account->setObjectName(QString::fromUtf8("analysis_account"));
        analysis_account->setMinimumSize(QSize(0, 35));
        analysis_account->setFont(font10);
        analysis_account->setCursor(QCursor(Qt::IBeamCursor));
        analysis_account->setMaxLength(30);
        analysis_account->setFrame(false);

        gridLayout_42->addWidget(analysis_account, 0, 1, 1, 1);


        gridLayout_57->addWidget(widget_31, 0, 2, 1, 1);

        widget_first = new QWidget(widget_20);
        widget_first->setObjectName(QString::fromUtf8("widget_first"));
        widget_first->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_39 = new QGridLayout(widget_first);
        gridLayout_39->setObjectName(QString::fromUtf8("gridLayout_39"));
        gridLayout_39->setHorizontalSpacing(5);
        gridLayout_39->setVerticalSpacing(0);
        gridLayout_39->setContentsMargins(0, 0, 0, 0);
        analysis_firstClassify = new QLineEdit(widget_first);
        analysis_firstClassify->setObjectName(QString::fromUtf8("analysis_firstClassify"));
        analysis_firstClassify->setMinimumSize(QSize(0, 35));
        analysis_firstClassify->setFont(font10);
        analysis_firstClassify->setCursor(QCursor(Qt::IBeamCursor));
        analysis_firstClassify->setMaxLength(30);
        analysis_firstClassify->setFrame(false);

        gridLayout_39->addWidget(analysis_firstClassify, 0, 1, 1, 1);

        lab_firstClassify = new QLabel(widget_first);
        lab_firstClassify->setObjectName(QString::fromUtf8("lab_firstClassify"));
        lab_firstClassify->setMinimumSize(QSize(70, 35));
        lab_firstClassify->setMaximumSize(QSize(70, 16777215));
        lab_firstClassify->setFont(font8);

        gridLayout_39->addWidget(lab_firstClassify, 0, 0, 1, 1);


        gridLayout_57->addWidget(widget_first, 1, 0, 1, 1);

        widget_second = new QWidget(widget_20);
        widget_second->setObjectName(QString::fromUtf8("widget_second"));
        widget_second->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_60 = new QGridLayout(widget_second);
        gridLayout_60->setObjectName(QString::fromUtf8("gridLayout_60"));
        gridLayout_60->setHorizontalSpacing(5);
        gridLayout_60->setVerticalSpacing(0);
        gridLayout_60->setContentsMargins(0, 0, 0, 0);
        analysis_secondClassify = new QLineEdit(widget_second);
        analysis_secondClassify->setObjectName(QString::fromUtf8("analysis_secondClassify"));
        analysis_secondClassify->setMinimumSize(QSize(0, 35));
        analysis_secondClassify->setFont(font10);
        analysis_secondClassify->setCursor(QCursor(Qt::IBeamCursor));
        analysis_secondClassify->setMaxLength(30);
        analysis_secondClassify->setFrame(false);

        gridLayout_60->addWidget(analysis_secondClassify, 0, 1, 1, 1);

        lab_secondClassify = new QLabel(widget_second);
        lab_secondClassify->setObjectName(QString::fromUtf8("lab_secondClassify"));
        lab_secondClassify->setMinimumSize(QSize(70, 35));
        lab_secondClassify->setMaximumSize(QSize(70, 16777215));
        lab_secondClassify->setFont(font8);

        gridLayout_60->addWidget(lab_secondClassify, 0, 0, 1, 1);


        gridLayout_57->addWidget(widget_second, 1, 1, 1, 1);

        widget_transfer_in = new QWidget(widget_20);
        widget_transfer_in->setObjectName(QString::fromUtf8("widget_transfer_in"));
        widget_transfer_in->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_62 = new QGridLayout(widget_transfer_in);
        gridLayout_62->setObjectName(QString::fromUtf8("gridLayout_62"));
        gridLayout_62->setHorizontalSpacing(5);
        gridLayout_62->setVerticalSpacing(0);
        gridLayout_62->setContentsMargins(0, 0, 0, 0);
        label_25 = new QLabel(widget_transfer_in);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setMinimumSize(QSize(70, 35));
        label_25->setMaximumSize(QSize(70, 16777215));
        label_25->setFont(font8);

        gridLayout_62->addWidget(label_25, 0, 0, 1, 1);

        analysis_account_in = new QLineEdit(widget_transfer_in);
        analysis_account_in->setObjectName(QString::fromUtf8("analysis_account_in"));
        analysis_account_in->setMinimumSize(QSize(0, 35));
        analysis_account_in->setFont(font10);
        analysis_account_in->setCursor(QCursor(Qt::IBeamCursor));
        analysis_account_in->setMaxLength(30);
        analysis_account_in->setFrame(false);

        gridLayout_62->addWidget(analysis_account_in, 0, 1, 1, 1);


        gridLayout_57->addWidget(widget_transfer_in, 1, 2, 1, 1);


        gridLayout_59->addWidget(widget_20, 1, 0, 1, 1);


        gridLayout_63->addWidget(widget_33, 0, 0, 1, 1);

        groupBox_34 = new QGroupBox(page_analysis);
        groupBox_34->setObjectName(QString::fromUtf8("groupBox_34"));
        groupBox_34->setMinimumSize(QSize(0, 40));
        groupBox_34->setStyleSheet(QString::fromUtf8(""));
        gridLayout_66 = new QGridLayout(groupBox_34);
        gridLayout_66->setSpacing(0);
        gridLayout_66->setObjectName(QString::fromUtf8("gridLayout_66"));
        gridLayout_66->setContentsMargins(0, 0, 0, 0);
        analysis_chart = new QPushButton(groupBox_34);
        analysis_chart->setObjectName(QString::fromUtf8("analysis_chart"));
        analysis_chart->setMinimumSize(QSize(70, 35));
        analysis_chart->setMaximumSize(QSize(70, 35));
        analysis_chart->setFont(font5);

        gridLayout_66->addWidget(analysis_chart, 0, 2, 1, 1);

        widget_35 = new QWidget(groupBox_34);
        widget_35->setObjectName(QString::fromUtf8("widget_35"));
        widget_35->setMinimumSize(QSize(700, 0));
        widget_35->setMaximumSize(QSize(700, 16777215));
        gridLayout_64 = new QGridLayout(widget_35);
        gridLayout_64->setObjectName(QString::fromUtf8("gridLayout_64"));
        gridLayout_64->setHorizontalSpacing(5);
        gridLayout_64->setVerticalSpacing(0);
        gridLayout_64->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(widget_35);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setMinimumSize(QSize(60, 30));
        label_19->setMaximumSize(QSize(60, 30));
        label_19->setFont(font1);

        gridLayout_64->addWidget(label_19, 0, 4, 1, 1);

        analysis_totalExpend = new QDoubleSpinBox(widget_35);
        analysis_totalExpend->setObjectName(QString::fromUtf8("analysis_totalExpend"));
        analysis_totalExpend->setMinimumSize(QSize(0, 35));
        QFont font11;
        font11.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font11.setPointSize(12);
        font11.setBold(true);
        analysis_totalExpend->setFont(font11);
        analysis_totalExpend->setStyleSheet(QString::fromUtf8("color: rgb(216, 30, 6);"));
        analysis_totalExpend->setFrame(false);
        analysis_totalExpend->setReadOnly(true);
        analysis_totalExpend->setButtonSymbols(QAbstractSpinBox::NoButtons);
        analysis_totalExpend->setMaximum(999999999.990000009536743);

        gridLayout_64->addWidget(analysis_totalExpend, 0, 3, 1, 1);

        label_13 = new QLabel(widget_35);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(60, 30));
        label_13->setMaximumSize(QSize(60, 30));
        label_13->setFont(font1);

        gridLayout_64->addWidget(label_13, 0, 0, 1, 1);

        label_17 = new QLabel(widget_35);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMinimumSize(QSize(60, 30));
        label_17->setMaximumSize(QSize(60, 30));
        label_17->setFont(font1);

        gridLayout_64->addWidget(label_17, 0, 2, 1, 1);

        analysis_totalIncome = new QDoubleSpinBox(widget_35);
        analysis_totalIncome->setObjectName(QString::fromUtf8("analysis_totalIncome"));
        analysis_totalIncome->setMinimumSize(QSize(0, 35));
        analysis_totalIncome->setFont(font11);
        analysis_totalIncome->setStyleSheet(QString::fromUtf8("color: rgb(37, 184, 122);"));
        analysis_totalIncome->setFrame(false);
        analysis_totalIncome->setReadOnly(true);
        analysis_totalIncome->setButtonSymbols(QAbstractSpinBox::NoButtons);
        analysis_totalIncome->setMaximum(999999999.990000009536743);

        gridLayout_64->addWidget(analysis_totalIncome, 0, 1, 1, 1);

        analysis_totalTransfer = new QDoubleSpinBox(widget_35);
        analysis_totalTransfer->setObjectName(QString::fromUtf8("analysis_totalTransfer"));
        analysis_totalTransfer->setMinimumSize(QSize(0, 35));
        analysis_totalTransfer->setFont(font11);
        analysis_totalTransfer->setStyleSheet(QString::fromUtf8("color: rgb(104, 147, 223);"));
        analysis_totalTransfer->setFrame(false);
        analysis_totalTransfer->setReadOnly(true);
        analysis_totalTransfer->setButtonSymbols(QAbstractSpinBox::NoButtons);
        analysis_totalTransfer->setMaximum(999999999.990000009536743);

        gridLayout_64->addWidget(analysis_totalTransfer, 0, 5, 1, 1);


        gridLayout_66->addWidget(widget_35, 0, 0, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_66->addItem(horizontalSpacer_14, 0, 1, 1, 1);


        gridLayout_63->addWidget(groupBox_34, 1, 0, 1, 1);

        stackedWidget_record_analysis->addWidget(page_analysis);

        gridLayout_7->addWidget(stackedWidget_record_analysis, 0, 0, 1, 1);

        stackedWidget_dock->addWidget(page_record_analysis);
        page_classify = new QWidget();
        page_classify->setObjectName(QString::fromUtf8("page_classify"));
        gridLayout_58 = new QGridLayout(page_classify);
        gridLayout_58->setObjectName(QString::fromUtf8("gridLayout_58"));
        gridLayout_58->setHorizontalSpacing(10);
        gridLayout_58->setVerticalSpacing(0);
        gridLayout_58->setContentsMargins(5, 5, 0, 5);
        classify_incomeTree = new TreeWidget(page_classify);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("\346\224\266\345\205\245\345\210\206\347\261\273"));
        classify_incomeTree->setHeaderItem(__qtreewidgetitem);
        classify_incomeTree->setObjectName(QString::fromUtf8("classify_incomeTree"));
        classify_incomeTree->setMinimumSize(QSize(465, 0));
        classify_incomeTree->setMaximumSize(QSize(465, 16777215));
        QFont font12;
        font12.setPointSize(11);
        classify_incomeTree->setFont(font12);
        classify_incomeTree->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        classify_incomeTree->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout_58->addWidget(classify_incomeTree, 0, 1, 1, 1);

        classify_expendTree = new TreeWidget(page_classify);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QString::fromUtf8("\346\224\257\345\207\272\345\210\206\347\261\273"));
        classify_expendTree->setHeaderItem(__qtreewidgetitem1);
        classify_expendTree->setObjectName(QString::fromUtf8("classify_expendTree"));
        classify_expendTree->setMinimumSize(QSize(465, 0));
        classify_expendTree->setMaximumSize(QSize(465, 16777215));
        classify_expendTree->setFont(font12);
        classify_expendTree->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        classify_expendTree->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout_58->addWidget(classify_expendTree, 0, 0, 1, 1);

        stackedWidget_dock->addWidget(page_classify);
        page_account = new QWidget();
        page_account->setObjectName(QString::fromUtf8("page_account"));
        gridLayout_56 = new QGridLayout(page_account);
        gridLayout_56->setObjectName(QString::fromUtf8("gridLayout_56"));
        gridLayout_56->setHorizontalSpacing(20);
        gridLayout_56->setVerticalSpacing(0);
        gridLayout_56->setContentsMargins(5, 5, 5, 5);
        widget_24 = new QWidget(page_account);
        widget_24->setObjectName(QString::fromUtf8("widget_24"));
        widget_24->setMinimumSize(QSize(400, 0));
        widget_24->setMaximumSize(QSize(400, 16777215));
        gridLayout_46 = new QGridLayout(widget_24);
        gridLayout_46->setObjectName(QString::fromUtf8("gridLayout_46"));
        gridLayout_46->setHorizontalSpacing(0);
        gridLayout_46->setVerticalSpacing(5);
        gridLayout_46->setContentsMargins(0, 0, 0, 0);
        groupBox_account_left_dock = new QGroupBox(widget_24);
        groupBox_account_left_dock->setObjectName(QString::fromUtf8("groupBox_account_left_dock"));
        groupBox_account_left_dock->setMinimumSize(QSize(0, 48));
        groupBox_account_left_dock->setMaximumSize(QSize(16777215, 48));
        gridLayout_47 = new QGridLayout(groupBox_account_left_dock);
        gridLayout_47->setObjectName(QString::fromUtf8("gridLayout_47"));
        gridLayout_47->setHorizontalSpacing(4);
        gridLayout_47->setVerticalSpacing(0);
        gridLayout_47->setContentsMargins(4, 0, 4, 0);
        account_up = new QPushButton(groupBox_account_left_dock);
        account_up->setObjectName(QString::fromUtf8("account_up"));
        account_up->setMinimumSize(QSize(55, 35));
        account_up->setMaximumSize(QSize(55, 35));
        account_up->setFont(font5);

        gridLayout_47->addWidget(account_up, 0, 1, 1, 1);

        account_add = new QPushButton(groupBox_account_left_dock);
        account_add->setObjectName(QString::fromUtf8("account_add"));
        account_add->setMinimumSize(QSize(55, 35));
        account_add->setMaximumSize(QSize(55, 35));
        account_add->setFont(font5);

        gridLayout_47->addWidget(account_add, 0, 4, 1, 1);

        account_down = new QPushButton(groupBox_account_left_dock);
        account_down->setObjectName(QString::fromUtf8("account_down"));
        account_down->setMinimumSize(QSize(55, 35));
        account_down->setMaximumSize(QSize(55, 35));
        account_down->setFont(font5);

        gridLayout_47->addWidget(account_down, 0, 2, 1, 1);

        account_top = new QPushButton(groupBox_account_left_dock);
        account_top->setObjectName(QString::fromUtf8("account_top"));
        account_top->setMinimumSize(QSize(70, 35));
        account_top->setMaximumSize(QSize(70, 35));
        account_top->setFont(font5);

        gridLayout_47->addWidget(account_top, 0, 0, 1, 1);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_47->addItem(horizontalSpacer_21, 0, 3, 1, 1);


        gridLayout_46->addWidget(groupBox_account_left_dock, 0, 0, 1, 1);

        scrollArea_account = new QScrollArea(widget_24);
        scrollArea_account->setObjectName(QString::fromUtf8("scrollArea_account"));
        scrollArea_account->setFrameShape(QFrame::NoFrame);
        scrollArea_account->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_account->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_account->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        scrollArea_account->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 400, 16));
        gridLayout_48 = new QGridLayout(scrollAreaWidgetContents_3);
        gridLayout_48->setSpacing(0);
        gridLayout_48->setObjectName(QString::fromUtf8("gridLayout_48"));
        gridLayout_48->setContentsMargins(0, 0, 0, 0);
        vLayout_account = new QVBoxLayout();
        vLayout_account->setSpacing(5);
        vLayout_account->setObjectName(QString::fromUtf8("vLayout_account"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vLayout_account->addItem(verticalSpacer_3);


        gridLayout_48->addLayout(vLayout_account, 2, 0, 1, 1);

        scrollArea_account->setWidget(scrollAreaWidgetContents_3);

        gridLayout_46->addWidget(scrollArea_account, 1, 0, 1, 1);


        gridLayout_56->addWidget(widget_24, 0, 0, 1, 1);

        widget_21 = new QWidget(page_account);
        widget_21->setObjectName(QString::fromUtf8("widget_21"));
        widget_21->setMinimumSize(QSize(450, 0));
        widget_21->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_53 = new QGridLayout(widget_21);
        gridLayout_53->setObjectName(QString::fromUtf8("gridLayout_53"));
        gridLayout_53->setHorizontalSpacing(0);
        gridLayout_53->setVerticalSpacing(5);
        gridLayout_53->setContentsMargins(0, 0, 0, 0);
        groupBox_account_right_dock = new QGroupBox(widget_21);
        groupBox_account_right_dock->setObjectName(QString::fromUtf8("groupBox_account_right_dock"));
        groupBox_account_right_dock->setMinimumSize(QSize(0, 48));
        groupBox_account_right_dock->setMaximumSize(QSize(16777215, 48));
        gridLayout_43 = new QGridLayout(groupBox_account_right_dock);
        gridLayout_43->setObjectName(QString::fromUtf8("gridLayout_43"));
        gridLayout_43->setHorizontalSpacing(4);
        gridLayout_43->setVerticalSpacing(0);
        gridLayout_43->setContentsMargins(4, 0, 4, 0);
        account_loading = new QLabel(groupBox_account_right_dock);
        account_loading->setObjectName(QString::fromUtf8("account_loading"));
        account_loading->setMinimumSize(QSize(25, 25));
        account_loading->setMaximumSize(QSize(25, 25));
        account_loading->setScaledContents(true);

        gridLayout_43->addWidget(account_loading, 0, 3, 1, 1);

        account_delete = new QPushButton(groupBox_account_right_dock);
        account_delete->setObjectName(QString::fromUtf8("account_delete"));
        account_delete->setMinimumSize(QSize(55, 35));
        account_delete->setMaximumSize(QSize(55, 35));
        account_delete->setFont(font5);

        gridLayout_43->addWidget(account_delete, 0, 1, 1, 1);

        account_return = new QPushButton(groupBox_account_right_dock);
        account_return->setObjectName(QString::fromUtf8("account_return"));
        account_return->setMinimumSize(QSize(55, 35));
        account_return->setMaximumSize(QSize(55, 35));
        account_return->setFont(font5);

        gridLayout_43->addWidget(account_return, 0, 7, 1, 1);

        horizontalSpacer_22 = new QSpacerItem(238, 29, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_43->addItem(horizontalSpacer_22, 0, 6, 1, 1);

        account_save = new QPushButton(groupBox_account_right_dock);
        account_save->setObjectName(QString::fromUtf8("account_save"));
        account_save->setEnabled(true);
        account_save->setMinimumSize(QSize(55, 35));
        account_save->setMaximumSize(QSize(55, 35));
        account_save->setFont(font5);
        account_save->setAutoDefault(false);

        gridLayout_43->addWidget(account_save, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_43->addItem(horizontalSpacer_5, 0, 2, 1, 1);


        gridLayout_53->addWidget(groupBox_account_right_dock, 0, 0, 1, 1);

        widget_25 = new QWidget(widget_21);
        widget_25->setObjectName(QString::fromUtf8("widget_25"));
        widget_25->setMinimumSize(QSize(0, 35));
        widget_25->setMaximumSize(QSize(16777215, 35));
        gridLayout_41 = new QGridLayout(widget_25);
        gridLayout_41->setObjectName(QString::fromUtf8("gridLayout_41"));
        gridLayout_41->setHorizontalSpacing(5);
        gridLayout_41->setVerticalSpacing(0);
        gridLayout_41->setContentsMargins(0, 0, 0, 0);
        label_23 = new QLabel(widget_25);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setMinimumSize(QSize(70, 35));
        label_23->setMaximumSize(QSize(70, 16777215));
        label_23->setFont(font8);

        gridLayout_41->addWidget(label_23, 0, 0, 1, 1);

        stackedWidget_account_name = new QStackedWidget(widget_25);
        stackedWidget_account_name->setObjectName(QString::fromUtf8("stackedWidget_account_name"));
        stackedWidget_account_name->setMinimumSize(QSize(0, 35));
        stackedWidget_account_name->setMaximumSize(QSize(16777215, 35));
        page_account_newName = new QWidget();
        page_account_newName->setObjectName(QString::fromUtf8("page_account_newName"));
        gridLayout_54 = new QGridLayout(page_account_newName);
        gridLayout_54->setSpacing(0);
        gridLayout_54->setObjectName(QString::fromUtf8("gridLayout_54"));
        gridLayout_54->setContentsMargins(0, 0, 0, 0);
        account_newName = new QComboBox(page_account_newName);
        account_newName->setObjectName(QString::fromUtf8("account_newName"));
        account_newName->setMinimumSize(QSize(0, 35));
        account_newName->setMaximumSize(QSize(16777215, 35));
        account_newName->setFont(font8);

        gridLayout_54->addWidget(account_newName, 0, 0, 1, 1);

        stackedWidget_account_name->addWidget(page_account_newName);
        page_account_name = new QWidget();
        page_account_name->setObjectName(QString::fromUtf8("page_account_name"));
        gridLayout_55 = new QGridLayout(page_account_name);
        gridLayout_55->setSpacing(0);
        gridLayout_55->setObjectName(QString::fromUtf8("gridLayout_55"));
        gridLayout_55->setContentsMargins(0, 0, 0, 0);
        account_name = new QLineEdit(page_account_name);
        account_name->setObjectName(QString::fromUtf8("account_name"));
        account_name->setMinimumSize(QSize(0, 35));
        account_name->setMaximumSize(QSize(16777215, 35));
        account_name->setFont(font8);
        account_name->setFrame(false);
        account_name->setReadOnly(true);

        gridLayout_55->addWidget(account_name, 0, 0, 1, 1);

        stackedWidget_account_name->addWidget(page_account_name);

        gridLayout_41->addWidget(stackedWidget_account_name, 0, 1, 1, 1);


        gridLayout_53->addWidget(widget_25, 1, 0, 1, 1);

        widget_26 = new QWidget(widget_21);
        widget_26->setObjectName(QString::fromUtf8("widget_26"));
        widget_26->setMinimumSize(QSize(0, 35));
        widget_26->setMaximumSize(QSize(16777215, 35));
        gridLayout_49 = new QGridLayout(widget_26);
        gridLayout_49->setObjectName(QString::fromUtf8("gridLayout_49"));
        gridLayout_49->setHorizontalSpacing(5);
        gridLayout_49->setVerticalSpacing(0);
        gridLayout_49->setContentsMargins(0, 0, 0, 0);
        label_29 = new QLabel(widget_26);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setMinimumSize(QSize(70, 35));
        label_29->setMaximumSize(QSize(70, 35));
        label_29->setFont(font8);

        gridLayout_49->addWidget(label_29, 0, 0, 1, 1);

        account_fund = new QDoubleSpinBox(widget_26);
        account_fund->setObjectName(QString::fromUtf8("account_fund"));
        account_fund->setMinimumSize(QSize(0, 35));
        account_fund->setMaximumSize(QSize(16777215, 35));
        account_fund->setFont(font8);
        account_fund->setFrame(false);
        account_fund->setButtonSymbols(QAbstractSpinBox::NoButtons);
        account_fund->setProperty("showGroupSeparator", QVariant(true));
        account_fund->setMinimum(-999999999.990000009536743);
        account_fund->setMaximum(999999999.990000009536743);
        account_fund->setSingleStep(100.000000000000000);
        account_fund->setValue(0.000000000000000);

        gridLayout_49->addWidget(account_fund, 0, 1, 1, 1);


        gridLayout_53->addWidget(widget_26, 2, 0, 1, 1);

        widget_27 = new QWidget(widget_21);
        widget_27->setObjectName(QString::fromUtf8("widget_27"));
        widget_27->setMinimumSize(QSize(0, 35));
        widget_27->setMaximumSize(QSize(16777215, 35));
        gridLayout_51 = new QGridLayout(widget_27);
        gridLayout_51->setObjectName(QString::fromUtf8("gridLayout_51"));
        gridLayout_51->setHorizontalSpacing(5);
        gridLayout_51->setVerticalSpacing(0);
        gridLayout_51->setContentsMargins(0, 0, 0, 0);
        label_30 = new QLabel(widget_27);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setMinimumSize(QSize(70, 35));
        label_30->setMaximumSize(QSize(70, 16777215));
        label_30->setFont(font8);

        gridLayout_51->addWidget(label_30, 0, 0, 1, 1);

        account_nickname = new QLineEdit(widget_27);
        account_nickname->setObjectName(QString::fromUtf8("account_nickname"));
        account_nickname->setMinimumSize(QSize(0, 35));
        account_nickname->setMaximumSize(QSize(16777215, 35));
        account_nickname->setFont(font8);
        account_nickname->setFrame(false);
        account_nickname->setReadOnly(false);

        gridLayout_51->addWidget(account_nickname, 0, 1, 1, 1);


        gridLayout_53->addWidget(widget_27, 3, 0, 1, 1);

        widget_28 = new QWidget(widget_21);
        widget_28->setObjectName(QString::fromUtf8("widget_28"));
        widget_28->setMinimumSize(QSize(0, 35));
        widget_28->setMaximumSize(QSize(16777215, 35));
        gridLayout_52 = new QGridLayout(widget_28);
        gridLayout_52->setObjectName(QString::fromUtf8("gridLayout_52"));
        gridLayout_52->setHorizontalSpacing(5);
        gridLayout_52->setVerticalSpacing(0);
        gridLayout_52->setContentsMargins(0, 0, 0, 0);
        label_28 = new QLabel(widget_28);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setMinimumSize(QSize(70, 35));
        label_28->setMaximumSize(QSize(70, 16777215));
        label_28->setFont(font8);

        gridLayout_52->addWidget(label_28, 0, 0, 1, 1);

        account_card = new QLineEdit(widget_28);
        account_card->setObjectName(QString::fromUtf8("account_card"));
        account_card->setMinimumSize(QSize(0, 35));
        account_card->setMaximumSize(QSize(16777215, 35));
        account_card->setFont(font8);
        account_card->setFrame(false);
        account_card->setReadOnly(false);

        gridLayout_52->addWidget(account_card, 0, 1, 1, 1);


        gridLayout_53->addWidget(widget_28, 4, 0, 1, 1);

        widget_23 = new QWidget(widget_21);
        widget_23->setObjectName(QString::fromUtf8("widget_23"));
        gridLayout_45 = new QGridLayout(widget_23);
        gridLayout_45->setSpacing(0);
        gridLayout_45->setObjectName(QString::fromUtf8("gridLayout_45"));
        gridLayout_45->setContentsMargins(0, 0, 0, 0);
        label_27 = new QLabel(widget_23);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setMinimumSize(QSize(0, 35));
        label_27->setMaximumSize(QSize(16777215, 35));
        label_27->setFont(font8);

        gridLayout_45->addWidget(label_27, 0, 0, 1, 1);

        account_remark = new QPlainTextEdit(widget_23);
        account_remark->setObjectName(QString::fromUtf8("account_remark"));
        account_remark->setFont(font8);
        account_remark->setFrameShape(QFrame::NoFrame);
        account_remark->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        account_remark->setTabChangesFocus(false);
        account_remark->setBackgroundVisible(false);

        gridLayout_45->addWidget(account_remark, 1, 0, 1, 1);


        gridLayout_53->addWidget(widget_23, 5, 0, 1, 1);

        widget_account_enable = new QWidget(widget_21);
        widget_account_enable->setObjectName(QString::fromUtf8("widget_account_enable"));
        widget_account_enable->setMinimumSize(QSize(0, 35));
        widget_account_enable->setMaximumSize(QSize(16777215, 35));
        gridLayout_40 = new QGridLayout(widget_account_enable);
        gridLayout_40->setSpacing(0);
        gridLayout_40->setObjectName(QString::fromUtf8("gridLayout_40"));
        gridLayout_40->setContentsMargins(0, 0, 0, 0);
        label_26 = new QLabel(widget_account_enable);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setMinimumSize(QSize(0, 35));
        label_26->setMaximumSize(QSize(16777215, 35));
        label_26->setFont(font8);

        gridLayout_40->addWidget(label_26, 0, 0, 1, 1);

        account_enable = new QPushButton(widget_account_enable);
        account_enable->setObjectName(QString::fromUtf8("account_enable"));
        account_enable->setMinimumSize(QSize(50, 30));
        account_enable->setMaximumSize(QSize(50, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/switchLeft.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/img/switchRight.png"), QSize(), QIcon::Normal, QIcon::On);
        account_enable->setIcon(icon);
        account_enable->setIconSize(QSize(50, 50));
        account_enable->setCheckable(true);

        gridLayout_40->addWidget(account_enable, 0, 1, 1, 1);


        gridLayout_53->addWidget(widget_account_enable, 6, 0, 1, 1);


        gridLayout_56->addWidget(widget_21, 0, 1, 1, 1);

        stackedWidget_dock->addWidget(page_account);
        page_book = new QWidget();
        page_book->setObjectName(QString::fromUtf8("page_book"));
        gridLayout_28 = new QGridLayout(page_book);
        gridLayout_28->setObjectName(QString::fromUtf8("gridLayout_28"));
        gridLayout_28->setHorizontalSpacing(20);
        gridLayout_28->setVerticalSpacing(0);
        gridLayout_28->setContentsMargins(5, 5, 5, 5);
        widget_14 = new QWidget(page_book);
        widget_14->setObjectName(QString::fromUtf8("widget_14"));
        widget_14->setMinimumSize(QSize(400, 0));
        widget_14->setMaximumSize(QSize(400, 16777215));
        gridLayout_27 = new QGridLayout(widget_14);
        gridLayout_27->setObjectName(QString::fromUtf8("gridLayout_27"));
        gridLayout_27->setHorizontalSpacing(0);
        gridLayout_27->setVerticalSpacing(5);
        gridLayout_27->setContentsMargins(0, 0, 0, 0);
        groupBox_book_left_dock = new QGroupBox(widget_14);
        groupBox_book_left_dock->setObjectName(QString::fromUtf8("groupBox_book_left_dock"));
        groupBox_book_left_dock->setMinimumSize(QSize(0, 48));
        groupBox_book_left_dock->setMaximumSize(QSize(16777215, 48));
        gridLayout_21 = new QGridLayout(groupBox_book_left_dock);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        gridLayout_21->setHorizontalSpacing(4);
        gridLayout_21->setVerticalSpacing(0);
        gridLayout_21->setContentsMargins(4, 0, 4, 0);
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_21->addItem(horizontalSpacer_12, 0, 5, 1, 1);

        book_top = new QPushButton(groupBox_book_left_dock);
        book_top->setObjectName(QString::fromUtf8("book_top"));
        book_top->setMinimumSize(QSize(70, 35));
        book_top->setMaximumSize(QSize(70, 35));
        book_top->setFont(font5);

        gridLayout_21->addWidget(book_top, 0, 0, 1, 1);

        book_down = new QPushButton(groupBox_book_left_dock);
        book_down->setObjectName(QString::fromUtf8("book_down"));
        book_down->setMinimumSize(QSize(55, 35));
        book_down->setMaximumSize(QSize(55, 35));
        book_down->setFont(font5);

        gridLayout_21->addWidget(book_down, 0, 2, 1, 1);

        book_add = new QPushButton(groupBox_book_left_dock);
        book_add->setObjectName(QString::fromUtf8("book_add"));
        book_add->setMinimumSize(QSize(55, 35));
        book_add->setMaximumSize(QSize(55, 35));
        book_add->setFont(font5);

        gridLayout_21->addWidget(book_add, 0, 6, 1, 1);

        book_up = new QPushButton(groupBox_book_left_dock);
        book_up->setObjectName(QString::fromUtf8("book_up"));
        book_up->setMinimumSize(QSize(55, 35));
        book_up->setMaximumSize(QSize(55, 35));
        book_up->setFont(font5);

        gridLayout_21->addWidget(book_up, 0, 1, 1, 1);


        gridLayout_27->addWidget(groupBox_book_left_dock, 0, 0, 1, 1);

        scrollArea_book = new QScrollArea(widget_14);
        scrollArea_book->setObjectName(QString::fromUtf8("scrollArea_book"));
        scrollArea_book->setFrameShape(QFrame::NoFrame);
        scrollArea_book->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_book->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_book->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        scrollArea_book->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 400, 16));
        gridLayout_22 = new QGridLayout(scrollAreaWidgetContents_4);
        gridLayout_22->setSpacing(0);
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        gridLayout_22->setContentsMargins(0, 0, 0, 0);
        vLayout_book = new QVBoxLayout();
        vLayout_book->setSpacing(5);
        vLayout_book->setObjectName(QString::fromUtf8("vLayout_book"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vLayout_book->addItem(verticalSpacer_2);


        gridLayout_22->addLayout(vLayout_book, 0, 0, 1, 1);

        scrollArea_book->setWidget(scrollAreaWidgetContents_4);

        gridLayout_27->addWidget(scrollArea_book, 1, 0, 1, 1);


        gridLayout_28->addWidget(widget_14, 0, 0, 1, 1);

        widget_29 = new QWidget(page_book);
        widget_29->setObjectName(QString::fromUtf8("widget_29"));
        widget_29->setMinimumSize(QSize(450, 0));
        widget_29->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_24 = new QGridLayout(widget_29);
        gridLayout_24->setObjectName(QString::fromUtf8("gridLayout_24"));
        gridLayout_24->setHorizontalSpacing(0);
        gridLayout_24->setVerticalSpacing(5);
        gridLayout_24->setContentsMargins(0, 0, 0, 0);
        groupBox_book_right_dock = new QGroupBox(widget_29);
        groupBox_book_right_dock->setObjectName(QString::fromUtf8("groupBox_book_right_dock"));
        groupBox_book_right_dock->setMinimumSize(QSize(0, 48));
        groupBox_book_right_dock->setMaximumSize(QSize(16777215, 48));
        gridLayout_23 = new QGridLayout(groupBox_book_right_dock);
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        gridLayout_23->setHorizontalSpacing(4);
        gridLayout_23->setVerticalSpacing(0);
        gridLayout_23->setContentsMargins(4, 0, 4, 0);
        horizontalSpacer_13 = new QSpacerItem(238, 29, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_23->addItem(horizontalSpacer_13, 0, 4, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_23->addItem(horizontalSpacer_6, 0, 2, 1, 1);

        book_save = new QPushButton(groupBox_book_right_dock);
        book_save->setObjectName(QString::fromUtf8("book_save"));
        book_save->setMinimumSize(QSize(55, 35));
        book_save->setMaximumSize(QSize(55, 35));
        book_save->setFont(font5);

        gridLayout_23->addWidget(book_save, 0, 0, 1, 1);

        book_delete = new QPushButton(groupBox_book_right_dock);
        book_delete->setObjectName(QString::fromUtf8("book_delete"));
        book_delete->setMinimumSize(QSize(55, 35));
        book_delete->setMaximumSize(QSize(55, 35));
        book_delete->setFont(font5);

        gridLayout_23->addWidget(book_delete, 0, 1, 1, 1);

        book_return = new QPushButton(groupBox_book_right_dock);
        book_return->setObjectName(QString::fromUtf8("book_return"));
        book_return->setMinimumSize(QSize(55, 35));
        book_return->setMaximumSize(QSize(55, 35));
        book_return->setFont(font5);

        gridLayout_23->addWidget(book_return, 0, 5, 1, 1);

        book_loading = new QLabel(groupBox_book_right_dock);
        book_loading->setObjectName(QString::fromUtf8("book_loading"));
        book_loading->setMinimumSize(QSize(25, 25));
        book_loading->setMaximumSize(QSize(25, 25));
        book_loading->setScaledContents(true);

        gridLayout_23->addWidget(book_loading, 0, 3, 1, 1);


        gridLayout_24->addWidget(groupBox_book_right_dock, 0, 0, 1, 1);

        stackedWidget_book = new QStackedWidget(widget_29);
        stackedWidget_book->setObjectName(QString::fromUtf8("stackedWidget_book"));
        stackedWidget_book->setMinimumSize(QSize(0, 0));
        stackedWidget_book->setMaximumSize(QSize(16777215, 16777215));
        page_addBook = new QWidget();
        page_addBook->setObjectName(QString::fromUtf8("page_addBook"));
        gridLayout_25 = new QGridLayout(page_addBook);
        gridLayout_25->setObjectName(QString::fromUtf8("gridLayout_25"));
        gridLayout_25->setHorizontalSpacing(0);
        gridLayout_25->setVerticalSpacing(5);
        gridLayout_25->setContentsMargins(0, 0, 0, 0);
        book_newRemark = new QPlainTextEdit(page_addBook);
        book_newRemark->setObjectName(QString::fromUtf8("book_newRemark"));
        book_newRemark->setFont(font8);
        book_newRemark->setFrameShape(QFrame::NoFrame);
        book_newRemark->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        book_newRemark->setTabChangesFocus(false);
        book_newRemark->setBackgroundVisible(false);

        gridLayout_25->addWidget(book_newRemark, 2, 0, 1, 1);

        book_newName = new QLineEdit(page_addBook);
        book_newName->setObjectName(QString::fromUtf8("book_newName"));
        book_newName->setMinimumSize(QSize(0, 35));
        book_newName->setMaximumSize(QSize(16777215, 35));
        book_newName->setFont(font8);
        book_newName->setFrame(false);

        gridLayout_25->addWidget(book_newName, 0, 0, 1, 1);

        stackedWidget_book->addWidget(page_addBook);
        page_bookInfo = new QWidget();
        page_bookInfo->setObjectName(QString::fromUtf8("page_bookInfo"));
        gridLayout_26 = new QGridLayout(page_bookInfo);
        gridLayout_26->setObjectName(QString::fromUtf8("gridLayout_26"));
        gridLayout_26->setHorizontalSpacing(0);
        gridLayout_26->setVerticalSpacing(5);
        gridLayout_26->setContentsMargins(0, 0, 0, 0);
        widget_15 = new QWidget(page_bookInfo);
        widget_15->setObjectName(QString::fromUtf8("widget_15"));
        gridLayout_16 = new QGridLayout(widget_15);
        gridLayout_16->setSpacing(0);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(widget_15);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(0, 35));
        label_12->setMaximumSize(QSize(16777215, 35));
        label_12->setFont(font8);

        gridLayout_16->addWidget(label_12, 0, 0, 1, 1);

        book_remark = new QPlainTextEdit(widget_15);
        book_remark->setObjectName(QString::fromUtf8("book_remark"));
        book_remark->setFont(font8);
        book_remark->setFrameShape(QFrame::NoFrame);
        book_remark->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        book_remark->setTabChangesFocus(false);
        book_remark->setReadOnly(false);
        book_remark->setBackgroundVisible(false);

        gridLayout_16->addWidget(book_remark, 1, 0, 1, 1);

        book_info = new QLabel(widget_15);
        book_info->setObjectName(QString::fromUtf8("book_info"));
        book_info->setMinimumSize(QSize(0, 35));
        book_info->setMaximumSize(QSize(16777215, 35));
        book_info->setFont(font8);

        gridLayout_16->addWidget(book_info, 2, 0, 1, 1);


        gridLayout_26->addWidget(widget_15, 3, 0, 2, 2);

        widget_16 = new QWidget(page_bookInfo);
        widget_16->setObjectName(QString::fromUtf8("widget_16"));
        widget_16->setMinimumSize(QSize(0, 35));
        widget_16->setMaximumSize(QSize(16777215, 35));
        gridLayout_17 = new QGridLayout(widget_16);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        gridLayout_17->setHorizontalSpacing(5);
        gridLayout_17->setVerticalSpacing(0);
        gridLayout_17->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(widget_16);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(70, 35));
        label_14->setMaximumSize(QSize(70, 16777215));
        label_14->setFont(font8);

        gridLayout_17->addWidget(label_14, 0, 0, 1, 1);

        book_name = new QLineEdit(widget_16);
        book_name->setObjectName(QString::fromUtf8("book_name"));
        book_name->setMinimumSize(QSize(0, 35));
        book_name->setMaximumSize(QSize(16777215, 35));
        book_name->setFont(font8);
        book_name->setFrame(false);
        book_name->setReadOnly(true);

        gridLayout_17->addWidget(book_name, 0, 1, 1, 1);


        gridLayout_26->addWidget(widget_16, 1, 0, 1, 2);

        widget_18 = new QWidget(page_bookInfo);
        widget_18->setObjectName(QString::fromUtf8("widget_18"));
        widget_18->setMinimumSize(QSize(0, 35));
        widget_18->setMaximumSize(QSize(16777215, 35));
        gridLayout_18 = new QGridLayout(widget_18);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        gridLayout_18->setHorizontalSpacing(5);
        gridLayout_18->setVerticalSpacing(0);
        gridLayout_18->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(widget_18);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMinimumSize(QSize(70, 35));
        label_16->setMaximumSize(QSize(70, 35));
        label_16->setFont(font8);

        gridLayout_18->addWidget(label_16, 0, 3, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(15, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_18->addItem(horizontalSpacer_9, 0, 2, 1, 1);

        label_18 = new QLabel(widget_18);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setMinimumSize(QSize(70, 35));
        label_18->setMaximumSize(QSize(70, 35));
        label_18->setFont(font8);

        gridLayout_18->addWidget(label_18, 0, 0, 1, 1);

        book_totalIncome = new QDoubleSpinBox(widget_18);
        book_totalIncome->setObjectName(QString::fromUtf8("book_totalIncome"));
        book_totalIncome->setMinimumSize(QSize(160, 35));
        book_totalIncome->setFont(font8);
        book_totalIncome->setWrapping(false);
        book_totalIncome->setFrame(false);
        book_totalIncome->setReadOnly(true);
        book_totalIncome->setButtonSymbols(QAbstractSpinBox::NoButtons);
        book_totalIncome->setAccelerated(false);
        book_totalIncome->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        book_totalIncome->setKeyboardTracking(true);
        book_totalIncome->setProperty("showGroupSeparator", QVariant(true));
        book_totalIncome->setMaximum(99999999.989999994635582);
        book_totalIncome->setSingleStep(100.000000000000000);
        book_totalIncome->setValue(0.000000000000000);

        gridLayout_18->addWidget(book_totalIncome, 0, 1, 1, 1);

        book_totalExpend = new QDoubleSpinBox(widget_18);
        book_totalExpend->setObjectName(QString::fromUtf8("book_totalExpend"));
        book_totalExpend->setMinimumSize(QSize(160, 35));
        book_totalExpend->setFont(font8);
        book_totalExpend->setWrapping(false);
        book_totalExpend->setFrame(false);
        book_totalExpend->setReadOnly(true);
        book_totalExpend->setButtonSymbols(QAbstractSpinBox::NoButtons);
        book_totalExpend->setAccelerated(false);
        book_totalExpend->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        book_totalExpend->setKeyboardTracking(true);
        book_totalExpend->setProperty("showGroupSeparator", QVariant(true));
        book_totalExpend->setMaximum(99999999.989999994635582);
        book_totalExpend->setSingleStep(100.000000000000000);
        book_totalExpend->setValue(0.000000000000000);

        gridLayout_18->addWidget(book_totalExpend, 0, 4, 1, 1);


        gridLayout_26->addWidget(widget_18, 2, 0, 1, 1);

        stackedWidget_book->addWidget(page_bookInfo);

        gridLayout_24->addWidget(stackedWidget_book, 1, 0, 1, 1);


        gridLayout_28->addWidget(widget_29, 0, 1, 1, 1);

        stackedWidget_dock->addWidget(page_book);
        page_setting = new QWidget();
        page_setting->setObjectName(QString::fromUtf8("page_setting"));
        stackedWidget_dock->addWidget(page_setting);
        page_borrowReturn = new QWidget();
        page_borrowReturn->setObjectName(QString::fromUtf8("page_borrowReturn"));
        stackedWidget_dock->addWidget(page_borrowReturn);

        gridLayout_3->addWidget(stackedWidget_dock, 2, 2, 1, 1);


        gridLayout->addWidget(widget_background, 1, 0, 1, 1);

        MainWin->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWin->setStatusBar(statusbar);

        retranslateUi(MainWin);

        stackedWidget_dock->setCurrentIndex(0);
        stackedWidget_record->setCurrentIndex(0);
        stackedWidget_record_analysis->setCurrentIndex(1);
        stackedWidget_account_name->setCurrentIndex(0);
        stackedWidget_book->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWin);
    } // setupUi

    void retranslateUi(QMainWindow *MainWin)
    {
        MainWin->setWindowTitle(QCoreApplication::translate("MainWin", "MainWin", nullptr));
        label_3->setText(QString());
        dock_totalFund_hide->setText(QString());
        label_15->setText(QCoreApplication::translate("MainWin", "\346\200\273\347\232\204\350\265\204\344\272\247", nullptr));
        dock_totalFund_num->setText(QCoreApplication::translate("MainWin", "0.00", nullptr));
        label_5->setText(QString());
        dock_monthIncome_hide->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWin", "\346\234\254\346\234\210\346\224\266\345\205\245", nullptr));
        dock_monthIncome_num->setText(QCoreApplication::translate("MainWin", "0.00", nullptr));
        label_10->setText(QCoreApplication::translate("MainWin", "\346\234\254\346\234\210\346\224\257\345\207\272", nullptr));
        dock_monthExpend_hide->setText(QString());
        label_9->setText(QString());
        dock_monthExpend_num->setText(QCoreApplication::translate("MainWin", "0.00", nullptr));
        dock_addRecord->setText(QCoreApplication::translate("MainWin", "\350\256\260\344\270\200\347\254\224", nullptr));
        label->setText(QCoreApplication::translate("MainWin", "\345\230\237\345\230\237\350\256\260\350\264\246v1.0\n"
"2023\345\271\26411\346\234\21028\346\227\245", nullptr));
        dock_classify->setText(QCoreApplication::translate("MainWin", "\345\210\206\347\261\273\347\256\241\347\220\206", nullptr));
        dock_analysis->setText(QCoreApplication::translate("MainWin", "\350\264\246\347\233\256\347\273\237\350\256\241", nullptr));
        dock_borrowReturn->setText(QCoreApplication::translate("MainWin", "\345\200\237\350\277\230\350\256\260\345\275\225/", nullptr));
        dock_account->setText(QCoreApplication::translate("MainWin", "\350\264\246\346\210\267\347\256\241\347\220\206", nullptr));
        dock_record->setText(QCoreApplication::translate("MainWin", "\346\265\201\346\260\264\350\264\246\347\233\256", nullptr));
        dock_book->setText(QCoreApplication::translate("MainWin", "\350\264\246\346\234\254\347\256\241\347\220\206", nullptr));
        dock_setting->setText(QCoreApplication::translate("MainWin", "\350\256\276       \347\275\256/", nullptr));
        record_pageRecordNum->setItemText(0, QCoreApplication::translate("MainWin", "50\346\235\241/\351\241\265", nullptr));
        record_pageRecordNum->setItemText(1, QCoreApplication::translate("MainWin", "100\346\235\241/\351\241\265", nullptr));
        record_pageRecordNum->setItemText(2, QCoreApplication::translate("MainWin", "150\346\235\241/\351\241\265", nullptr));

        record_pageInfo->setText(QCoreApplication::translate("MainWin", "\345\205\26146532\346\235\241\350\256\260\345\275\225\357\274\214\345\205\261466\351\241\265\343\200\202", nullptr));
        record_pageIndex->setSuffix(QCoreApplication::translate("MainWin", " \351\241\265", nullptr));
        record_pageIndex->setPrefix(QCoreApplication::translate("MainWin", "\347\254\254 ", nullptr));
        record_pageNext->setText(QCoreApplication::translate("MainWin", ">", nullptr));
        record_pagePrevious->setText(QCoreApplication::translate("MainWin", "<", nullptr));
        record_output_all->setText(QCoreApplication::translate("MainWin", "\345\257\274\345\207\272\345\205\250\351\203\250", nullptr));
        record_output->setText(QCoreApplication::translate("MainWin", "\345\257\274\345\207\272\346\255\244\351\241\265", nullptr));
        record_collapse->setText(QCoreApplication::translate("MainWin", "\345\205\250\351\203\250\346\212\230\345\217\240", nullptr));
        record_expand->setText(QCoreApplication::translate("MainWin", "\345\205\250\351\203\250\345\261\225\345\274\200", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = record_tree->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWin", "1", nullptr));
        record_loading->setText(QString());
        record_input->setPlaceholderText(QCoreApplication::translate("MainWin", "\346\250\241\347\263\212\346\237\245\350\257\242", nullptr));
        label_4->setText(QCoreApplication::translate("MainWin", "\346\224\266\346\224\257\347\261\273\345\236\213", nullptr));
        record_flowType->setItemText(0, QCoreApplication::translate("MainWin", "\345\205\250\351\203\250", nullptr));
        record_flowType->setItemText(1, QCoreApplication::translate("MainWin", "\346\224\257\345\207\272", nullptr));
        record_flowType->setItemText(2, QCoreApplication::translate("MainWin", "\346\224\266\345\205\245", nullptr));
        record_flowType->setItemText(3, QCoreApplication::translate("MainWin", "\350\275\254\350\264\246", nullptr));

        record_filter->setItemText(0, QCoreApplication::translate("MainWin", "\345\277\275\347\225\245\346\227\245\346\234\237", nullptr));
        record_filter->setItemText(1, QCoreApplication::translate("MainWin", "\345\277\275\347\225\245\346\227\245", nullptr));
        record_filter->setItemText(2, QCoreApplication::translate("MainWin", "\345\277\275\347\225\245\346\234\210", nullptr));
        record_filter->setItemText(3, QCoreApplication::translate("MainWin", "\344\277\235\347\225\231\346\227\245\346\234\237", nullptr));

        record_reset->setText(QCoreApplication::translate("MainWin", "\351\207\215\347\275\256\350\277\207\346\273\244", nullptr));
        record_flush->setText(QCoreApplication::translate("MainWin", "\345\210\267\346\226\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWin", "\351\200\211\346\213\251\346\227\245\346\234\237", nullptr));
        record_date->setDisplayFormat(QCoreApplication::translate("MainWin", "yyyy\345\271\264MM\346\234\210dd\346\227\245", nullptr));
        analysis_reset->setText(QCoreApplication::translate("MainWin", "\351\207\215\347\275\256\346\226\207\346\234\254", nullptr));
        analysis_flush->setText(QCoreApplication::translate("MainWin", "\345\210\267\346\226\260", nullptr));
        analysis_startDate->setDisplayFormat(QCoreApplication::translate("MainWin", "yyyy\345\271\264MM\346\234\210dd\346\227\245", nullptr));
        label_11->setText(QCoreApplication::translate("MainWin", "\342\206\222", nullptr));
        analysis_endDate->setDisplayFormat(QCoreApplication::translate("MainWin", "yyyy\345\271\264MM\346\234\210dd\346\227\245", nullptr));
        label_8->setText(QCoreApplication::translate("MainWin", "\346\227\245       \346\234\237", nullptr));
        cBox_analysisDate->setText(QCoreApplication::translate("MainWin", "\345\214\205\346\213\254\346\227\245\346\234\237", nullptr));
        cBox_analysisText->setText(QCoreApplication::translate("MainWin", "\345\214\205\346\213\254\346\226\207\346\234\254", nullptr));
        label_34->setText(QCoreApplication::translate("MainWin", "\345\270\220       \346\234\254", nullptr));
        analysis_book->setText(QString());
        analysis_book->setPlaceholderText(QCoreApplication::translate("MainWin", "\350\264\246\346\234\254\345\220\215\347\247\260", nullptr));
        label_31->setText(QCoreApplication::translate("MainWin", "\346\265\201       \345\220\221", nullptr));
        analysis_flowType->setText(QString());
        analysis_flowType->setPlaceholderText(QCoreApplication::translate("MainWin", "\350\265\204\351\207\221\346\265\201\345\220\221", nullptr));
        label_24->setText(QCoreApplication::translate("MainWin", "\350\264\246       \346\210\267", nullptr));
        analysis_account->setText(QString());
        analysis_account->setPlaceholderText(QCoreApplication::translate("MainWin", "\350\264\246\346\210\267\345\220\215\347\247\260", nullptr));
        analysis_firstClassify->setText(QString());
        analysis_firstClassify->setPlaceholderText(QCoreApplication::translate("MainWin", "\344\270\200\347\272\247\345\210\206\347\261\273", nullptr));
        lab_firstClassify->setText(QCoreApplication::translate("MainWin", "\344\270\200\347\272\247\345\210\206\347\261\273", nullptr));
        analysis_secondClassify->setText(QString());
        analysis_secondClassify->setPlaceholderText(QCoreApplication::translate("MainWin", "\344\270\200\347\272\247\345\210\206\347\261\273", nullptr));
        lab_secondClassify->setText(QCoreApplication::translate("MainWin", "\344\272\214\347\272\247\345\210\206\347\261\273", nullptr));
        label_25->setText(QCoreApplication::translate("MainWin", "\350\275\254\345\205\245\350\264\246\346\210\267", nullptr));
        analysis_account_in->setText(QString());
        analysis_account_in->setPlaceholderText(QCoreApplication::translate("MainWin", "\350\275\254\345\205\245\350\264\246\346\210\267", nullptr));
        analysis_chart->setText(QCoreApplication::translate("MainWin", "\345\233\276\345\275\242\345\210\206\346\236\220", nullptr));
        label_19->setText(QCoreApplication::translate("MainWin", "\345\205\261\350\275\254\350\264\246", nullptr));
        analysis_totalExpend->setSuffix(QCoreApplication::translate("MainWin", " \345\205\203", nullptr));
        label_13->setText(QCoreApplication::translate("MainWin", "\345\205\261\346\224\266\345\205\245", nullptr));
        label_17->setText(QCoreApplication::translate("MainWin", "\345\205\261\346\224\257\345\207\272", nullptr));
        analysis_totalIncome->setSuffix(QCoreApplication::translate("MainWin", " \345\205\203", nullptr));
        analysis_totalTransfer->setSuffix(QCoreApplication::translate("MainWin", " \345\205\203", nullptr));
        account_up->setText(QCoreApplication::translate("MainWin", "\344\270\212\347\247\273", nullptr));
        account_add->setText(QCoreApplication::translate("MainWin", "\346\226\260\345\242\236", nullptr));
        account_down->setText(QCoreApplication::translate("MainWin", "\344\270\213\347\247\273", nullptr));
        account_top->setText(QCoreApplication::translate("MainWin", "\347\275\256\351\241\266\350\264\246\346\210\267", nullptr));
        account_loading->setText(QString());
        account_delete->setText(QCoreApplication::translate("MainWin", "\345\210\240\351\231\244", nullptr));
        account_return->setText(QCoreApplication::translate("MainWin", "\350\277\224\345\233\236", nullptr));
        account_save->setText(QCoreApplication::translate("MainWin", "\344\277\235\345\255\230", nullptr));
        label_23->setText(QCoreApplication::translate("MainWin", "\350\264\246\346\210\267\345\220\215\347\247\260", nullptr));
        account_name->setText(QString());
        account_name->setPlaceholderText(QCoreApplication::translate("MainWin", "\350\264\246\346\210\267\345\220\215\347\247\260", nullptr));
        label_29->setText(QCoreApplication::translate("MainWin", "\350\264\246\346\210\267\350\265\204\344\272\247", nullptr));
        account_fund->setSuffix(QCoreApplication::translate("MainWin", " \345\205\203", nullptr));
        label_30->setText(QCoreApplication::translate("MainWin", "\350\264\246\346\210\267\345\210\253\347\247\260", nullptr));
        account_nickname->setText(QString());
        account_nickname->setPlaceholderText(QCoreApplication::translate("MainWin", "\345\270\256\345\212\251\347\224\250\346\210\267\345\277\253\351\200\237\350\257\206\345\210\253(\351\235\236\345\277\205\345\241\253)", nullptr));
        label_28->setText(QCoreApplication::translate("MainWin", "\350\264\246\346\210\267\345\215\241\345\217\267", nullptr));
        account_card->setText(QString());
        account_card->setPlaceholderText(QCoreApplication::translate("MainWin", "\346\227\240\345\215\241\345\217\267\345\277\275\347\225\245\345\215\263\345\217\257(\351\235\236\345\277\205\345\241\253)", nullptr));
        label_27->setText(QCoreApplication::translate("MainWin", "\350\264\246\346\210\267\346\217\217\350\277\260", nullptr));
        account_remark->setPlainText(QString());
        account_remark->setPlaceholderText(QCoreApplication::translate("MainWin", "\347\256\200\350\246\201\346\217\217\350\277\260(\351\235\236\345\277\205\345\241\253)", nullptr));
        label_26->setText(QCoreApplication::translate("MainWin", "\346\230\257\345\220\246\350\256\241\345\205\245\346\200\273\350\265\204\344\272\247", nullptr));
        account_enable->setText(QString());
        book_top->setText(QCoreApplication::translate("MainWin", "\347\275\256\351\241\266\350\264\246\346\234\254", nullptr));
        book_down->setText(QCoreApplication::translate("MainWin", "\344\270\213\347\247\273", nullptr));
        book_add->setText(QCoreApplication::translate("MainWin", "\346\226\260\345\242\236", nullptr));
        book_up->setText(QCoreApplication::translate("MainWin", "\344\270\212\347\247\273", nullptr));
        book_save->setText(QCoreApplication::translate("MainWin", "\344\277\235\345\255\230", nullptr));
        book_delete->setText(QCoreApplication::translate("MainWin", "\345\210\240\351\231\244", nullptr));
        book_return->setText(QCoreApplication::translate("MainWin", "\350\277\224\345\233\236", nullptr));
        book_loading->setText(QString());
        book_newRemark->setPlainText(QString());
        book_newRemark->setPlaceholderText(QCoreApplication::translate("MainWin", "\347\256\200\350\246\201\346\217\217\350\277\260", nullptr));
        book_newName->setPlaceholderText(QCoreApplication::translate("MainWin", "\350\264\246\346\234\254\345\220\215\347\247\260", nullptr));
        label_12->setText(QCoreApplication::translate("MainWin", "\350\264\246\346\234\254\346\217\217\350\277\260", nullptr));
        book_remark->setPlainText(QString());
        book_remark->setPlaceholderText(QCoreApplication::translate("MainWin", "\347\256\200\350\246\201\346\217\217\350\277\260(\351\235\236\345\277\205\345\241\253)", nullptr));
        book_info->setText(QString());
        label_14->setText(QCoreApplication::translate("MainWin", "\350\264\246\346\234\254\345\220\215\347\247\260", nullptr));
        book_name->setText(QString());
        book_name->setPlaceholderText(QCoreApplication::translate("MainWin", "\350\264\246\346\234\254\345\220\215\347\247\260", nullptr));
        label_16->setText(QCoreApplication::translate("MainWin", "\345\205\261\350\256\241\346\224\257\345\207\272", nullptr));
        label_18->setText(QCoreApplication::translate("MainWin", "\345\205\261\350\256\241\346\224\266\345\205\245", nullptr));
        book_totalIncome->setSpecialValueText(QString());
        book_totalIncome->setSuffix(QCoreApplication::translate("MainWin", " \345\205\203", nullptr));
        book_totalExpend->setSpecialValueText(QString());
        book_totalExpend->setSuffix(QCoreApplication::translate("MainWin", " \345\205\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWin: public Ui_MainWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIN_H
