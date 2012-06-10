#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pile.h"

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

    private:
        Ui::MainWindow *ui;
        Pile* pile;

        void EntrerVerif(QString& s); // Vérifie que les constantes entrées correspondent aux modes choisis par l'utilisateur
        //Constante* DecideDepile();
        //Constante* ToMode(Constante* c);

        void Afficher(Pile* p,int x=6)const;

    private slots:

      //Pavé numérique
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

    //    void EnterPressed();
    //    void RetablirPressed();
    //    void AnnulerPressed();
};

#endif // MAINWINDOW_H
