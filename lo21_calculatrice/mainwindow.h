#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "logMessage.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private:
        Ui::MainWindow *ui;
        Pile* pile_stockage;
        Pile* pile_affichage;

        void EntrerVerif(QString& s); // Vérifie que les constantes entrées correspondent aux modes choisis par l'utilisateur
        Constante* DecideDepile();
        Constante* verifMode(Complexe* c); // Avant d'empiler une constante dans une pile, on vérifie qu'elle est conforme aux modes choisis par l'utilisateur
        Constante* verifMode(Rationnel* c);

        void Afficher(Pile* p,int x=6)const;

    private slots:

       //Pavé numérique
        void on_button0_clicked();
        void on_button1_clicked();
        void on_button2_clicked();
        void on_button3_clicked();
        void on_button4_clicked();
        void on_button5_clicked();
        void on_button6_clicked();
        void on_button7_clicked();
        void on_button8_clicked();
        void on_button9_clicked();

       //Affichage clavier
        void on_show_keyboard_clicked();
        void on_hide_button_clicked();

        //Fonctions Binaires
        void on_mulButton_clicked();
        void on_addButton_clicked();
        void on_divButton_clicked();
        void on_subButton_clicked();
        void on_buttonMod_clicked();
        void on_buttonPow_clicked();

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

        //Autres fonctions
        void on_spaceButton_clicked();
        void on_buttonEval_clicked();
        void on_buttonEntrer_clicked();
        void on_buttonPi_clicked();
        void on_buttonSign_clicked();
        void on_buttonExp_clicked();
        void on_supprButton_clicked();
        void on_buttonVirgule_clicked();

       /* void RetablirPressed();
        void AnnulerPressed();*/


};

#endif // MAINWINDOW_H
