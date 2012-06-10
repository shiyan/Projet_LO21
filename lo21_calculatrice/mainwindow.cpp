#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextEdit>
#include <qmath.h>
#include <QString>
#include <QRegExp>
#include <QTextEdit>
#include <string>
#include <stdexcept>

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);

    pile_affichage=new Pile(10);
    pile_stockage=new Pile(10);

    QPalette palette = ui->labelException->palette();
    palette.setColor(ui->labelException->foregroundRole(), Qt::red);
    ui->labelException->setPalette(palette);

    //Pour afficher le clavier par défaut
    ui->show_keyboard->hide();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_buttonEntrer_clicked(){

   //On efface les messages d'erreur
    ui->labelException->clear();

   //Récupération des entrées dans la ligne de commande
    QString s = ui->lineEdit->text().trimmed();

    try{
       //Ligne vide
            if (s.isEmpty())throw LogMessage("Ligne de commande vide !",0);

       //Expression
            if (s.startsWith("'")){
                if (s.endsWith("'")){
                    pile_affichage->Empiler(new Expression(s));
                    pile_stockage->Empiler(new Expression(s));
                }
                else throw LogMessage("Vous devez terminer votre expression par une quote",0);
            }
            else{
                Expression exp = *(new Expression(s));
                exp.Eval(pile_affichage, pile_stockage);
            }
    }
    catch(LogMessage e1){
        ui->labelException->setText(e1.what());

    }
    ui->lineEdit->clear();
    Afficher(pile_affichage);
}

//Affiche les X derniers éléments de la pile
void MainWindow::Afficher(Pile* p,int x)const{
    ui->textEdit->clear();

    if(p->GetNb()<x) x=p->GetNb();

    for(int i=p->GetNb()-x;i<p->GetNb();i++){
        ui->textEdit->append(p->GetConstante(i)->Afficher());
        ui->labelException->setText(p->GetConstante(i)->Afficher());
    }
}
