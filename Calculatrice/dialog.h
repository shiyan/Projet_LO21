#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    int GetX();
    int GetY();
    
private:
    Ui::Dialog *ui;

    int x;
    int y;
private slots:
    void OkPressed();
};

#endif // DIALOG_H
