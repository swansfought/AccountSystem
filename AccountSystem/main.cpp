#include "mainwin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWin w;

    QFont font;
    font.setFamily("微软雅黑");
    w.setFont(font);

    w.show();
    return a.exec();
}
