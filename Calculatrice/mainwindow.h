#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fonction.h"
#include <exception>
#include <QFile>
#include <QTextStream>
#include "fonction.h"

namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();




    //int test(Constante* c){return c->GetType();}

private:
    Ui::MainWindow *ui;

    static QFile file;  //pour le pile affichage, utilite a redemarrage

    Pile* pile;
    Pile* pile_Stock;
    int pointeurPile;
    void EntrerVerif(QString& s);
    Nombre* CheckEntreReelOuRatio(QString s) ;
    Constante* DecideDepile();
    Constante* ToMode(Constante* c);
    void Afficher(Pile* p,int x=6)const;

    bool WriteFilePile();
    bool ReadFilePile();

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
    void SpacePressed();

    void on_buttonDollar_clicked();
    void on_buttonVirgule_clicked();
    void on_buttonEval_clicked();
    void on_buttonExc_clicked();

   //Affichage clavier
    void hideKeyboard();
    void displayKeyboard();

   //Fonctions binaires
    void MulPressed();
    void AddPressed();
    void SubPressed();
    void ModPressed();
    void PowPressed();
    void SignPressed();
    void ExpPressed();
    void DivPressed();

    void EnterPressed();
    void RetablirPressed();
    void AnnulerPressed();

    //Fonction unaires
    void on_buttonSin_clicked();
    void on_buttonSinh_clicked();
    void on_buttonCos_clicked();
    void on_buttonCosh_clicked();
    void on_buttonTan_clicked();
    void on_buttonTanh_clicked();
    void on_buttonLn_clicked();
    void on_buttonLog_clicked();
    void on_buttonInv_clicked();
    void on_buttonSqrt_clicked();
    void on_buttonSqr_clicked();
    void on_buttonCube_clicked();
    void on_buttonFacto_clicked();

    //Fonction de pile
    void on_buttonSwap_clicked();
    void on_buttonSum_clicked();
    void on_buttonMean_clicked();
    void on_buttonClear_clicked();
    void on_buttonDrop_clicked();
    void on_buttonDup_clicked();
};

#endif // MAINWINDOW_H
