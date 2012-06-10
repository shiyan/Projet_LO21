#include "mainwindow.h"
#include "ui_mainwindow.h"

//Pavé Numérique
void MainWindow::on_button0_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+"0");}
void MainWindow::on_button1_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+"1");}
void MainWindow::on_button2_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+"2");}
void MainWindow::on_button3_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+"3");}
void MainWindow::on_button4_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+"4");}
void MainWindow::on_button5_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+"5");}
void MainWindow::on_button6_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+"6");}
void MainWindow::on_button7_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+"7");}
void MainWindow::on_button8_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+"8");}
void MainWindow::on_button9_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+"9");}

//Pour cacher le clavier
void MainWindow::on_hide_button_clicked(){
       ui->keyBoard->hide();
       this->setFixedHeight(328);
       ui->show_keyboard->show();
       ui->hide_button->hide();
}
void MainWindow::on_show_keyboard_clicked(){
       ui->keyBoard->show();
       ui->hide_button->show();
       this->setFixedHeight(639);
       ui->show_keyboard->hide();
}

//Fonctions Binaires
void MainWindow::on_mulButton_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" * ");}
void MainWindow::on_addButton_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" + ");}
void MainWindow::on_divButton_clicked(){
    if (ui->radioButtonRationnelle->isChecked())
        ui->lineEdit->setText(ui->lineEdit->text()+"/");
    else
        ui->lineEdit->setText(ui->lineEdit->text()+" / ");
}
void MainWindow::on_subButton_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" - ");}
void MainWindow::on_buttonMod_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" Mod ");}
void MainWindow::on_buttonPow_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" Pow ");}
void MainWindow::on_buttonSign_clicked(){ui->lineEdit->setText(ui->lineEdit->text()+" -1 * ");}
void MainWindow::on_buttonExp_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" ' ");}

//Fonction unaires
void MainWindow::on_buttonSin_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" Sin ");}
void MainWindow::on_buttonSinh_clicked(){ui->lineEdit->setText(ui->lineEdit->text()+" Sinh ");}
void MainWindow::on_buttonCos_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" Cos ");}
void MainWindow::on_buttonCosh_clicked(){ui->lineEdit->setText(ui->lineEdit->text()+" Cosh ");}
void MainWindow::on_buttonTan_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" Tan ");}
void MainWindow::on_buttonTanh_clicked(){ui->lineEdit->setText(ui->lineEdit->text()+" Tanh ");
}
void MainWindow::on_buttonLn_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" Ln ");}
void MainWindow::on_buttonLog_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" Log ");}
void MainWindow::on_buttonInv_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" Inv ");}
void MainWindow::on_buttonSqrt_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" Sqrt ");}
void MainWindow::on_buttonSqr_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" Sqr ");}
void MainWindow::on_buttonCube_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" Cube ");}
void MainWindow::on_buttonFacto_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" ! ");}

//Autres fonctions
void MainWindow::on_spaceButton_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" ");}
void MainWindow::on_buttonEval_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" Eval ");}
void MainWindow::on_buttonPi_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+ " Pi ");}

void MainWindow::on_buttonVirgule_clicked(){
    if (!ui->radioButtonEntiere->isChecked()){
        //Si le dernier élément est un chiffre
        if( ui->lineEdit->text().right(1).contains(QRegExp("^[0-9]{1,1}$")))
             ui->lineEdit->setText(ui->lineEdit->text()+ ".");
        else
            ui->labelException->setText("Vous devez entrer au moins un chiffre.");
    }
    else
        ui->labelException->setText("Le mode réel n'est pas sélectionné !");
}

void MainWindow::on_supprButton_clicked(){
    QString txt = ui->lineEdit->text();

    //Suppresion du dernier caractère
    txt.chop(1);
    //Dans le cas ou l'on cherche à supprimer un opérateur. Si après avoir supprimer le dernier caractère, on a encore une lettre, on supprime tous les caractères lu jusqu'à tomber sur un espace
    while (txt.right(1).contains(QRegExp("^[a-zA-Z]{1,1}$")) )
        txt.chop(1);

    ui->lineEdit->setText(txt);

}
