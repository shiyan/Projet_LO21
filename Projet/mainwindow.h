#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fonction.h"

namespace Ui {
class MainWindow;
}

class CalculeException{
private:
    std::string info;
public:
    CalculeException(const std::string& i):info(i){}
    const char* what() const{return info.c_str();}
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();




    //int test(Constante* c){return c->GetType();}

private:
    Ui::MainWindow *ui;
    Pile* pile;
    //Pile tmp;
    //int preciseReel;
    void EntrerVerif(QString& s);
    Nombre* CheckEntreReelOuRatio(QString& s) const;
    Constante* DecideDepile();
    Constante* ToMode(Constante* c);
    void Afficher(Pile* p,int x=6)const;

private slots:
    void Num0Pressed();
    void Num1Pressed();
    void Num2Pressed();
    void Num3Pressed();
    void Num4Pressed();
    void Num5Pressed();
    void Num6Pressed();
    void Num7Pressed();
    void Num8Pressed();
    void Num9Pressed();

    void EnterPressed();
//    void RetablirPressed();
//    void AnnulerPressed();
};

#endif // MAINWINDOW_H
