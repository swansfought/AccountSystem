/********************************************************************************
** Form generated from reading UI file 'addwin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDWIN_H
#define UI_ADDWIN_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddWin
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *widget_21;
    QGridLayout *gridLayout_5;
    QWidget *widget_2;
    QGridLayout *gridLayout_3;
    QWidget *widget_5;
    QGridLayout *gridLayout_21;
    QWidget *widget_11;
    QGridLayout *gridLayout_15;
    QComboBox *account;
    QLabel *label_23;
    QWidget *widget_6;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *money;
    QLabel *label_28;
    QWidget *widget_transfer_in;
    QGridLayout *gridLayout_19;
    QLabel *label_24;
    QComboBox *account_in;
    QWidget *widget_10;
    QGridLayout *gridLayout_14;
    QComboBox *flowType;
    QLabel *label_29;
    QWidget *widget_second;
    QGridLayout *gridLayout_17;
    QLabel *lab_secondClassify;
    QComboBox *secondClassify;
    QWidget *widget_first;
    QGridLayout *gridLayout_16;
    QLabel *lab_firstClassify;
    QComboBox *firstClassify;
    QWidget *widget_12;
    QGridLayout *gridLayout_24;
    QComboBox *book;
    QLabel *label_34;
    QWidget *widget_23;
    QGridLayout *gridLayout_45;
    QPlainTextEdit *remark;
    QLabel *label_27;
    QWidget *widget;
    QGridLayout *gridLayout_8;
    QWidget *widget_24;
    QGridLayout *gridLayout_7;
    QWidget *widget_3;
    QGridLayout *gridLayout_4;
    QPushButton *deleteImage;
    QPushButton *selectImage;
    QLabel *label_2;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_6;
    QLabel *image;
    QWidget *widget_241;
    QGridLayout *gridLayout_11;
    QPushButton *save;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *save_again;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *close;
    QWidget *widget_7;
    QGridLayout *gridLayout_10;
    QDateEdit *dateEdit;
    QLabel *label_3;
    QLabel *loading;
    QFrame *line;

    void setupUi(QMainWindow *AddWin)
    {
        if (AddWin->objectName().isEmpty())
            AddWin->setObjectName(QString::fromUtf8("AddWin"));
        AddWin->resize(700, 520);
        AddWin->setMinimumSize(QSize(700, 520));
        AddWin->setMaximumSize(QSize(700, 520));
        centralwidget = new QWidget(AddWin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(5);
        gridLayout->setContentsMargins(15, 0, 15, 12);
        widget_21 = new QWidget(centralwidget);
        widget_21->setObjectName(QString::fromUtf8("widget_21"));
        widget_21->setMinimumSize(QSize(0, 0));
        widget_21->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_5 = new QGridLayout(widget_21);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setHorizontalSpacing(6);
        gridLayout_5->setVerticalSpacing(0);
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget_21);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(230, 0));
        widget_2->setMaximumSize(QSize(230, 16777215));
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setVerticalSpacing(0);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setMinimumSize(QSize(0, 0));
        widget_5->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_21 = new QGridLayout(widget_5);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        gridLayout_21->setHorizontalSpacing(5);
        gridLayout_21->setVerticalSpacing(10);
        gridLayout_21->setContentsMargins(0, 0, 0, 0);
        widget_11 = new QWidget(widget_5);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        gridLayout_15 = new QGridLayout(widget_11);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_15->setHorizontalSpacing(5);
        gridLayout_15->setVerticalSpacing(0);
        gridLayout_15->setContentsMargins(0, 0, 0, 0);
        account = new QComboBox(widget_11);
        account->setObjectName(QString::fromUtf8("account"));
        account->setMinimumSize(QSize(0, 35));
        account->setMaximumSize(QSize(16777215, 35));
        QFont font;
        font.setPointSize(10);
        account->setFont(font);

        gridLayout_15->addWidget(account, 0, 1, 1, 1);

        label_23 = new QLabel(widget_11);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setMinimumSize(QSize(70, 35));
        label_23->setMaximumSize(QSize(70, 16777215));
        label_23->setFont(font);

        gridLayout_15->addWidget(label_23, 0, 0, 1, 1);


        gridLayout_21->addWidget(widget_11, 2, 0, 1, 1);

        widget_6 = new QWidget(widget_5);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        gridLayout_2 = new QGridLayout(widget_6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(5);
        gridLayout_2->setVerticalSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        money = new QDoubleSpinBox(widget_6);
        money->setObjectName(QString::fromUtf8("money"));
        money->setMinimumSize(QSize(0, 35));
        money->setMaximumSize(QSize(16777215, 35));
        money->setFont(font);
        money->setContextMenuPolicy(Qt::NoContextMenu);
        money->setFrame(false);
        money->setButtonSymbols(QAbstractSpinBox::NoButtons);
        money->setProperty("showGroupSeparator", QVariant(true));
        money->setMaximum(99999999.989999994635582);
        money->setSingleStep(100.000000000000000);

        gridLayout_2->addWidget(money, 0, 1, 1, 1);

        label_28 = new QLabel(widget_6);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setMinimumSize(QSize(70, 35));
        label_28->setMaximumSize(QSize(70, 16777215));
        label_28->setFont(font);

        gridLayout_2->addWidget(label_28, 0, 0, 1, 1);


        gridLayout_21->addWidget(widget_6, 6, 0, 1, 1);

        widget_transfer_in = new QWidget(widget_5);
        widget_transfer_in->setObjectName(QString::fromUtf8("widget_transfer_in"));
        gridLayout_19 = new QGridLayout(widget_transfer_in);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        gridLayout_19->setHorizontalSpacing(5);
        gridLayout_19->setVerticalSpacing(0);
        gridLayout_19->setContentsMargins(0, 0, 0, 0);
        label_24 = new QLabel(widget_transfer_in);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setMinimumSize(QSize(70, 35));
        label_24->setMaximumSize(QSize(70, 16777215));
        label_24->setFont(font);

        gridLayout_19->addWidget(label_24, 0, 0, 1, 1);

        account_in = new QComboBox(widget_transfer_in);
        account_in->setObjectName(QString::fromUtf8("account_in"));
        account_in->setMinimumSize(QSize(0, 35));
        account_in->setMaximumSize(QSize(16777215, 35));
        account_in->setFont(font);

        gridLayout_19->addWidget(account_in, 0, 1, 1, 1);


        gridLayout_21->addWidget(widget_transfer_in, 5, 0, 1, 1);

        widget_10 = new QWidget(widget_5);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        gridLayout_14 = new QGridLayout(widget_10);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_14->setHorizontalSpacing(5);
        gridLayout_14->setVerticalSpacing(0);
        gridLayout_14->setContentsMargins(0, 0, 0, 0);
        flowType = new QComboBox(widget_10);
        flowType->setObjectName(QString::fromUtf8("flowType"));
        flowType->setMinimumSize(QSize(0, 35));
        flowType->setMaximumSize(QSize(16777215, 35));
        flowType->setFont(font);

        gridLayout_14->addWidget(flowType, 0, 1, 1, 1);

        label_29 = new QLabel(widget_10);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setMinimumSize(QSize(70, 35));
        label_29->setMaximumSize(QSize(70, 35));
        label_29->setFont(font);

        gridLayout_14->addWidget(label_29, 0, 0, 1, 1);


        gridLayout_21->addWidget(widget_10, 1, 0, 1, 1);

        widget_second = new QWidget(widget_5);
        widget_second->setObjectName(QString::fromUtf8("widget_second"));
        gridLayout_17 = new QGridLayout(widget_second);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        gridLayout_17->setHorizontalSpacing(5);
        gridLayout_17->setVerticalSpacing(0);
        gridLayout_17->setContentsMargins(0, 0, 0, 0);
        lab_secondClassify = new QLabel(widget_second);
        lab_secondClassify->setObjectName(QString::fromUtf8("lab_secondClassify"));
        lab_secondClassify->setMinimumSize(QSize(70, 35));
        lab_secondClassify->setMaximumSize(QSize(70, 16777215));
        lab_secondClassify->setFont(font);

        gridLayout_17->addWidget(lab_secondClassify, 0, 0, 1, 1);

        secondClassify = new QComboBox(widget_second);
        secondClassify->setObjectName(QString::fromUtf8("secondClassify"));
        secondClassify->setMinimumSize(QSize(0, 35));
        secondClassify->setMaximumSize(QSize(16777215, 35));
        secondClassify->setFont(font);

        gridLayout_17->addWidget(secondClassify, 0, 1, 1, 1);


        gridLayout_21->addWidget(widget_second, 4, 0, 1, 1);

        widget_first = new QWidget(widget_5);
        widget_first->setObjectName(QString::fromUtf8("widget_first"));
        gridLayout_16 = new QGridLayout(widget_first);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setHorizontalSpacing(5);
        gridLayout_16->setVerticalSpacing(0);
        gridLayout_16->setContentsMargins(0, 0, 0, 0);
        lab_firstClassify = new QLabel(widget_first);
        lab_firstClassify->setObjectName(QString::fromUtf8("lab_firstClassify"));
        lab_firstClassify->setMinimumSize(QSize(70, 35));
        lab_firstClassify->setMaximumSize(QSize(70, 16777215));
        lab_firstClassify->setFont(font);

        gridLayout_16->addWidget(lab_firstClassify, 0, 0, 1, 1);

        firstClassify = new QComboBox(widget_first);
        firstClassify->setObjectName(QString::fromUtf8("firstClassify"));
        firstClassify->setMinimumSize(QSize(0, 35));
        firstClassify->setMaximumSize(QSize(16777215, 35));
        firstClassify->setFont(font);

        gridLayout_16->addWidget(firstClassify, 0, 1, 1, 1);


        gridLayout_21->addWidget(widget_first, 3, 0, 1, 1);

        widget_12 = new QWidget(widget_5);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        gridLayout_24 = new QGridLayout(widget_12);
        gridLayout_24->setObjectName(QString::fromUtf8("gridLayout_24"));
        gridLayout_24->setHorizontalSpacing(5);
        gridLayout_24->setVerticalSpacing(0);
        gridLayout_24->setContentsMargins(0, 0, 0, 0);
        book = new QComboBox(widget_12);
        book->setObjectName(QString::fromUtf8("book"));
        book->setMinimumSize(QSize(0, 35));
        book->setMaximumSize(QSize(16777215, 35));
        book->setFont(font);

        gridLayout_24->addWidget(book, 0, 1, 1, 1);

        label_34 = new QLabel(widget_12);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setMinimumSize(QSize(70, 35));
        label_34->setMaximumSize(QSize(70, 35));
        label_34->setFont(font);

        gridLayout_24->addWidget(label_34, 0, 0, 1, 1);


        gridLayout_21->addWidget(widget_12, 0, 0, 1, 1);


        gridLayout_3->addWidget(widget_5, 0, 0, 1, 1);

        widget_23 = new QWidget(widget_2);
        widget_23->setObjectName(QString::fromUtf8("widget_23"));
        gridLayout_45 = new QGridLayout(widget_23);
        gridLayout_45->setSpacing(0);
        gridLayout_45->setObjectName(QString::fromUtf8("gridLayout_45"));
        gridLayout_45->setContentsMargins(0, 0, 0, 0);
        remark = new QPlainTextEdit(widget_23);
        remark->setObjectName(QString::fromUtf8("remark"));
        remark->setFont(font);
        remark->setContextMenuPolicy(Qt::NoContextMenu);
        remark->setFrameShape(QFrame::NoFrame);
        remark->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        remark->setTabChangesFocus(false);
        remark->setBackgroundVisible(false);

        gridLayout_45->addWidget(remark, 1, 0, 1, 1);

        label_27 = new QLabel(widget_23);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setMinimumSize(QSize(0, 35));
        label_27->setMaximumSize(QSize(16777215, 35));
        label_27->setFont(font);

        gridLayout_45->addWidget(label_27, 0, 0, 1, 1);


        gridLayout_3->addWidget(widget_23, 1, 0, 1, 1);


        gridLayout_5->addWidget(widget_2, 0, 0, 1, 1);

        widget = new QWidget(widget_21);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_8 = new QGridLayout(widget);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setHorizontalSpacing(0);
        gridLayout_8->setVerticalSpacing(10);
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        widget_24 = new QWidget(widget);
        widget_24->setObjectName(QString::fromUtf8("widget_24"));
        gridLayout_7 = new QGridLayout(widget_24);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setHorizontalSpacing(0);
        gridLayout_7->setVerticalSpacing(5);
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget_24);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(0, 35));
        widget_3->setMaximumSize(QSize(16777215, 35));
        gridLayout_4 = new QGridLayout(widget_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(4);
        gridLayout_4->setVerticalSpacing(0);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        deleteImage = new QPushButton(widget_3);
        deleteImage->setObjectName(QString::fromUtf8("deleteImage"));
        deleteImage->setMinimumSize(QSize(55, 35));
        deleteImage->setMaximumSize(QSize(55, 35));
        QFont font1;
        font1.setPointSize(9);
        deleteImage->setFont(font1);

        gridLayout_4->addWidget(deleteImage, 0, 1, 1, 1);

        selectImage = new QPushButton(widget_3);
        selectImage->setObjectName(QString::fromUtf8("selectImage"));
        selectImage->setMinimumSize(QSize(90, 35));
        selectImage->setMaximumSize(QSize(55, 35));
        selectImage->setFont(font1);

        gridLayout_4->addWidget(selectImage, 0, 0, 1, 1);

        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setPointSize(8);
        label_2->setFont(font2);

        gridLayout_4->addWidget(label_2, 0, 2, 1, 1);


        gridLayout_7->addWidget(widget_3, 0, 0, 1, 1);

        groupBox_6 = new QGroupBox(widget_24);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_6 = new QGridLayout(groupBox_6);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        image = new QLabel(groupBox_6);
        image->setObjectName(QString::fromUtf8("image"));
        image->setMinimumSize(QSize(0, 0));
        image->setStyleSheet(QString::fromUtf8(""));
        image->setScaledContents(true);

        gridLayout_6->addWidget(image, 0, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_6, 1, 0, 1, 1);


        gridLayout_8->addWidget(widget_24, 1, 0, 1, 1);

        widget_241 = new QWidget(widget);
        widget_241->setObjectName(QString::fromUtf8("widget_241"));
        widget_241->setMinimumSize(QSize(0, 35));
        widget_241->setMaximumSize(QSize(16777215, 35));
        gridLayout_11 = new QGridLayout(widget_241);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setHorizontalSpacing(4);
        gridLayout_11->setVerticalSpacing(0);
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        save = new QPushButton(widget_241);
        save->setObjectName(QString::fromUtf8("save"));
        save->setEnabled(true);
        save->setMinimumSize(QSize(55, 35));
        save->setMaximumSize(QSize(55, 35));
        save->setFont(font1);
        save->setAutoDefault(false);

        gridLayout_11->addWidget(save, 0, 10, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_4, 0, 7, 1, 2);

        save_again = new QPushButton(widget_241);
        save_again->setObjectName(QString::fromUtf8("save_again"));
        save_again->setEnabled(true);
        save_again->setMinimumSize(QSize(55, 35));
        save_again->setMaximumSize(QSize(55, 35));
        save_again->setFont(font1);
        save_again->setAutoDefault(false);

        gridLayout_11->addWidget(save_again, 0, 9, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_3, 0, 6, 1, 1);

        close = new QPushButton(widget_241);
        close->setObjectName(QString::fromUtf8("close"));
        close->setEnabled(true);
        close->setMinimumSize(QSize(55, 35));
        close->setMaximumSize(QSize(55, 35));
        close->setFont(font1);
        close->setAutoDefault(false);

        gridLayout_11->addWidget(close, 0, 12, 1, 1);

        widget_7 = new QWidget(widget_241);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setMinimumSize(QSize(210, 35));
        widget_7->setMaximumSize(QSize(210, 35));
        gridLayout_10 = new QGridLayout(widget_7);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setHorizontalSpacing(4);
        gridLayout_10->setVerticalSpacing(0);
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        dateEdit = new QDateEdit(widget_7);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setMinimumSize(QSize(170, 35));
        dateEdit->setMaximumSize(QSize(170, 35));
        dateEdit->setFont(font);
        dateEdit->setCalendarPopup(true);
        dateEdit->setDate(QDate(2023, 11, 8));

        gridLayout_10->addWidget(dateEdit, 0, 1, 1, 1);

        label_3 = new QLabel(widget_7);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(35, 0));
        label_3->setMaximumSize(QSize(35, 16777215));
        label_3->setFont(font);

        gridLayout_10->addWidget(label_3, 0, 0, 1, 1);


        gridLayout_11->addWidget(widget_7, 0, 4, 1, 1);

        loading = new QLabel(widget_241);
        loading->setObjectName(QString::fromUtf8("loading"));
        loading->setMinimumSize(QSize(30, 30));
        loading->setMaximumSize(QSize(30, 30));
        loading->setFont(font);

        gridLayout_11->addWidget(loading, 0, 5, 1, 1);


        gridLayout_8->addWidget(widget_241, 0, 0, 1, 1);


        gridLayout_5->addWidget(widget, 0, 1, 1, 1);


        gridLayout->addWidget(widget_21, 1, 0, 1, 1);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(0, 2));
        line->setMaximumSize(QSize(16777215, 2));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 0, 1, 1);

        AddWin->setCentralWidget(centralwidget);

        retranslateUi(AddWin);

        QMetaObject::connectSlotsByName(AddWin);
    } // setupUi

    void retranslateUi(QMainWindow *AddWin)
    {
        AddWin->setWindowTitle(QCoreApplication::translate("AddWin", "MainWindow", nullptr));
        label_23->setText(QCoreApplication::translate("AddWin", "\350\264\246       \346\210\267", nullptr));
        money->setSuffix(QCoreApplication::translate("AddWin", " \345\205\203", nullptr));
        label_28->setText(QCoreApplication::translate("AddWin", "\351\207\221       \351\242\235", nullptr));
        label_24->setText(QCoreApplication::translate("AddWin", "\350\275\254\345\205\245\350\264\246\346\210\267", nullptr));
        label_29->setText(QCoreApplication::translate("AddWin", "\346\265\201       \345\220\221", nullptr));
        lab_secondClassify->setText(QCoreApplication::translate("AddWin", "\344\272\214\347\272\247\345\210\206\347\261\273", nullptr));
        lab_firstClassify->setText(QCoreApplication::translate("AddWin", "\344\270\200\347\272\247\345\210\206\347\261\273", nullptr));
        label_34->setText(QCoreApplication::translate("AddWin", "\345\270\220       \346\234\254", nullptr));
        remark->setPlainText(QString());
        remark->setPlaceholderText(QCoreApplication::translate("AddWin", "\347\256\200\350\246\201\346\217\217\350\277\260(\351\235\236\345\277\205\345\241\253)", nullptr));
        label_27->setText(QCoreApplication::translate("AddWin", "\345\244\207       \346\263\250", nullptr));
        deleteImage->setText(QCoreApplication::translate("AddWin", "\346\270\205\351\231\244", nullptr));
        selectImage->setText(QCoreApplication::translate("AddWin", "\351\200\211\346\213\251\345\233\276\347\211\207", nullptr));
        label_2->setText(QCoreApplication::translate("AddWin", "\347\255\211\346\257\224\347\274\251\345\260\217\345\261\225\347\244\272\357\274\214\345\271\266\344\270\215\345\275\261\345\223\215\345\256\236\351\231\205\345\244\247\345\260\217", nullptr));
        image->setText(QString());
        save->setText(QCoreApplication::translate("AddWin", "\347\241\256\345\256\232", nullptr));
        save_again->setText(QCoreApplication::translate("AddWin", "\345\206\215\350\256\260", nullptr));
        close->setText(QCoreApplication::translate("AddWin", "\345\205\263\351\227\255", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("AddWin", "yyyy\345\271\264MM\346\234\210dd\346\227\245", nullptr));
        label_3->setText(QCoreApplication::translate("AddWin", "\346\227\245\346\234\237", nullptr));
        loading->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddWin: public Ui_AddWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDWIN_H
