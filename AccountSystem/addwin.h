#ifndef ADDWIN_H
#define ADDWIN_H

#include <QMainWindow>

namespace Ui {
class AddWin;
}

class AddWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddWin(QWidget *parent = nullptr);
    ~AddWin();

private:
    Ui::AddWin *ui;
};

#endif // ADDWIN_H
