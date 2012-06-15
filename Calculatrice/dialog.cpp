#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    x=1;
    y=2;
    QString s;
    ui->lineEditX->setText(s.setNum(x));
    ui->lineEditY->setText(s.setNum(y));
    connect(ui->buttonOk,SIGNAL(clicked()),this,SLOT(OkPressed()));
    connect(ui->buttonCancel,SIGNAL(clicked()),this,SLOT(close()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::OkPressed(){
    x=ui->lineEditX->text().toInt();
    y=ui->lineEditY->text().toInt();
    this->close();
}


