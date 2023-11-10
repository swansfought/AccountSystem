/********************************************************************************
** Form generated from reading UI file 'addwin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDWIN_H
#define UI_ADDWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddWin
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AddWin)
    {
        if (AddWin->objectName().isEmpty())
            AddWin->setObjectName(QString::fromUtf8("AddWin"));
        AddWin->resize(800, 600);
        menubar = new QMenuBar(AddWin);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        AddWin->setMenuBar(menubar);
        centralwidget = new QWidget(AddWin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        AddWin->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(AddWin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AddWin->setStatusBar(statusbar);

        retranslateUi(AddWin);

        QMetaObject::connectSlotsByName(AddWin);
    } // setupUi

    void retranslateUi(QMainWindow *AddWin)
    {
        AddWin->setWindowTitle(QCoreApplication::translate("AddWin", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddWin: public Ui_AddWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDWIN_H
