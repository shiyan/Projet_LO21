#include "mainwindow.h"
#include "pile.h"
#include "ui_mainwindow.h"

#include <QTextEdit>
#include <qmath.h>
#include <QString>
#include <QRegExp>
#include <QTextEdit>
#include <string>
#include <stdexcept>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pile=new Pile(10);

    QPalette palette = ui->labelException->palette();
    palette.setColor(ui->labelException->foregroundRole(), Qt::red);
    ui->labelException->setPalette(palette);


    //Pavé Numérique
    connect(ui->buttonEntrer,SIGNAL(clicked()),this,SLOT(EnterPressed()));
    connect(ui->button0,SIGNAL(clicked()),this,SLOT(Num0Pressed()));
    connect(ui->button1,SIGNAL(clicked()),this,SLOT(Num1Pressed()));
    connect(ui->button2,SIGNAL(clicked()),this,SLOT(Num2Pressed()));
    connect(ui->button3,SIGNAL(clicked()),this,SLOT(Num3Pressed()));
    connect(ui->button4,SIGNAL(clicked()),this,SLOT(Num4Pressed()));
    connect(ui->button5,SIGNAL(clicked()),this,SLOT(Num5Pressed()));
    connect(ui->button6,SIGNAL(clicked()),this,SLOT(Num6Pressed()));
    connect(ui->button7,SIGNAL(clicked()),this,SLOT(Num7Pressed()));
    connect(ui->button8,SIGNAL(clicked()),this,SLOT(Num8Pressed()));
    connect(ui->button9,SIGNAL(clicked()),this,SLOT(Num9Pressed()));
    connect(ui->spaceButton,SIGNAL(clicked()),this,SLOT(SpacePressed()));

    //Pour cacher le clavier
    ui->show_keyboard->hide(); //Par défaut, le clavier est affché.
    connect(ui->hide_button,SIGNAL(clicked()),this,SLOT(hideKeyboard()));
    connect(ui->show_keyboard,SIGNAL(clicked()),this,SLOT(displayKeyboard()));

    //Fonctions unaires

    //Fonctions binaires
    connect(ui->divButton,SIGNAL(clicked()),this,SLOT(DivPressed()));
    connect(ui->mulButton,SIGNAL(clicked()),this,SLOT(MulPressed()));
    connect(ui->addButton,SIGNAL(clicked()),this,SLOT(AddPressed()));
    connect(ui->subButton,SIGNAL(clicked()),this,SLOT(SubPressed()));

    connect(ui->buttonMod,SIGNAL(clicked()),this,SLOT(ModPressed()));
    connect(ui->buttonPow,SIGNAL(clicked()),this,SLOT(PowPressed()));
    connect(ui->buttonSign,SIGNAL(clicked()),this,SLOT(SignPressed()));
    connect(ui->buttonExp,SIGNAL(clicked()),this,SLOT(ExpPressed()));
}

void MainWindow::Num0Pressed(){ ui->lineEdit->setText(ui->lineEdit->text()+"0");}
void MainWindow::Num1Pressed(){ ui->lineEdit->setText(ui->lineEdit->text()+"1");}
void MainWindow::Num2Pressed(){ ui->lineEdit->setText(ui->lineEdit->text()+"2");}
void MainWindow::Num3Pressed(){ ui->lineEdit->setText(ui->lineEdit->text()+"3");}
void MainWindow::Num4Pressed(){ ui->lineEdit->setText(ui->lineEdit->text()+"4");}
void MainWindow::Num5Pressed(){ ui->lineEdit->setText(ui->lineEdit->text()+"5");}
void MainWindow::Num6Pressed(){ ui->lineEdit->setText(ui->lineEdit->text()+"6");}
void MainWindow::Num7Pressed(){ ui->lineEdit->setText(ui->lineEdit->text()+"7");}
void MainWindow::Num8Pressed(){ ui->lineEdit->setText(ui->lineEdit->text()+"8");}
void MainWindow::Num9Pressed(){ ui->lineEdit->setText(ui->lineEdit->text()+"9");}
void MainWindow::SpacePressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" ");}

//Pour cacher le clavier
void MainWindow::hideKeyboard(){
       ui->keyBoard->hide();
       ui->show_keyboard->show();
       ui->hide_button->hide();
}
void MainWindow::displayKeyboard(){
       ui->keyBoard->show();
       ui->hide_button->show();
       ui->show_keyboard->hide();
}

//Fonctions Binaires
void MainWindow::MulPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" *");}
void MainWindow::AddPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" +");}
void MainWindow::DivPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" /");}
void MainWindow::SubPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" -");}
void MainWindow::ModPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" mod");}
void MainWindow::PowPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" pow");}
void MainWindow::SignPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" -1 *");}
void MainWindow::ExpPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" '");}

MainWindow::~MainWindow(){
    delete ui;
}

/*
Constante* MainWindow::DecideDepile(){
    Constante* depiler;
    if(pile->GetConstante(pile->GetNb()-1)->GetType()==complexe)
        throw LogMessage("Cette operateur ne peut pas ëtre utilisé avec des complexes.");
    else{
        if(ui->radioButtonEntiere->isChecked()){
            if(pile->GetConstante(pile->GetNb()-1)->GetType()==entier)
                depiler=ui->radioButtonRadiant->isChecked()?pile->Depiler():pile->Depiler()->ToDegre();
            else
                throw LogMessage("L'operande ne correspond pas aux modes choisis.");
        }
        else
            depiler=ui->radioButtonRadiant->isChecked()?pile->Depiler():pile->Depiler()->ToDegre();
    }
    return depiler;
}
*/


void MainWindow::EntrerVerif(QString& s){

   //Mode entier
     if(ui->radioButtonEntiere->isChecked()){
       //Entier et Réel
       if(s.contains(QRegExp("^-?[0-9]+$"))||s.contains(QRegExp("^-?[0-9]+\.[0-9]+$"))){
        Constante* c = new Complexe(floot(s),0); //Sélection de la partie entière uniquement
        pile->Empiler(*c);
      }
       else if ()
     }
   //Rationel
    else if(s.contains(QRegExp("^-?[0-9]+\\.?[0-9]*$"))||s.contains(QRegExp("^-?[0-9]+\\/-?[0-9]+$"))){
        if(!(ui->radioButtonEntiere->isChecked())){
            pile->Empiler(*(CheckEntreReelOuRatio(s)));
        }
        else
            throw CalculeException("Les entree ne correspond pas aux modes choisis.");
    }
    else if(s.contains(QRegExp("^-?[0-9]+(\\.|\\/-?)?[0-9]*\\$-?[0-9]+(\\.|\\/-?)?[0-9]*$"))){
        if(ui->radioButtonNonComplexe->isChecked())
            throw CalculeException("Les entree ne correspond pas aux modes choisis.");
        if(s.contains(QRegExp("^-?[0-9]+\\$-?[0-9]+$"))){
            Constante* c=new Complexe(new Reel(s.section('$',0,0).toFloat()),new Reel(s.section('$',1,1).toFloat()));
            pile->Enpiler(*c);
        }
        else{
            if(ui->radioButtonEntiere->isChecked())
                throw CalculeException("Les entree ne correspond aux modes choisis.");
            Constante* c=new Complexe(CheckEntreReelOuRatio(s.section('$',0,0)),CheckEntreReelOuRatio(s.section('$',1,1)));
            pile->Enpiler(*c);
        }
    }
    else
        throw CalculeException("Les entree ne correspond pas aux modes choisis.");
}


void MainWindow::EnterPressed(){
    ui->labelException->clear(); // On efface les messages d'erreur

    try{

        QString s = ui->lineEdit->text();
   //Constante
        if(s.contains(QRegExp("^-?[0-9]+(\\.|\\/-?)?[0-9]*(\\$-?[0-9]+(\\.|\\/-?)?[0-9]*)?$"))){
             EntrerVerif(s);
        }
   //Expression ( entourée par le caractère <<'>> )
        else if(s.contains(QRegExp("^\\'.*\\'$"))){
            pile->Empiler(*(new Expression(s)));
        }
   //Opérateur
        else if(_stricmp(s.toStdString().c_str(),"sin")==0){
            Constante* depile;
            if(pile->GetConstante(pile->GetNb()-1)->GetType()==expression)
                pile->Empiler(*(pile->Depiler()->Sin()));
            else{
                depile=DecideDepile();
                if(ui->radioButtonRationnelle->isChecked()){pile->Empiler(*(depile->Sin()->ToRationnel()));}
                if(ui->radioButtonReelle->isChecked()||ui->radioButtonEntiere->isChecked()){pile->Empiler(*(depile->Sin()->ToReel()));}
            }
        }
        else if(_stricmp(s.toStdString().c_str(),"sqrt")==0){
            if(pile->GetConstante(pile->GetNb()-1)->GetType()==expression)
                pile->Empiler(*(pile->Depiler()->Sqrt()));
            else{
                if(ui->radioButtonEntiere->isChecked()){
                    if(pile->GetConstante(pile->GetNb()-1)->GetType()!=entier)
                        throw CalculeException("Le operande ne correspond pas aux modes choisis.");
                }
                if(pile->GetConstante(pile->GetNb()-1)->GetType()==complexe)
                    throw CalculeException("Le operande ne correspond pas aux modes choisis.");
                else if(dynamic_cast<Reel*>(pile->GetConstante(pile->GetNb()-1))->GetReel()<0){
                    if(ui->radioButtonNonComplexe->isChecked())
                        throw CalculeException("Le operande ne peut pas etre negatif.");
                }
                pile->Empiler(*(ToMode(pile->Depiler()->Sqrt())));
            }
        }
        else if(_stricmp(s.toStdString().c_str(),"eval")==0){
           // Pile tmp=*pile;
            if(pile->GetConstante(pile->GetNb()-1)->GetType()==expression){
                Constante* depile=pile->Depiler();
                ui->lineEdit->setText(depile->Afficher());
                Constante* aEmpiler=ui->radioButtonDegre->isChecked()?dynamic_cast<Expression*>(depile)->Eval(true):dynamic_cast<Expression*>(depile)->Eval(false);
                pile->Empiler(*(ToMode(aEmpiler)));
            }
            else
                throw CalculeException("Eval est utilise pour evaluer une expression");
        }
        else if(s.contains(QRegExp(" +"))){
            s.push_front('\'');
            s.push_back('\'');
            Expression *exp=new Expression(s);
            Constante* aEmpiler=ui->radioButtonDegre->isChecked()?dynamic_cast<Expression*>(exp)->Eval(true):dynamic_cast<Expression*>(exp)->Eval(false);
            pile->Empiler(*(ToMode(aEmpiler)));
        }

        ui->lineEdit->clear();
    }
    catch(CalculeException e1){
        ui->labelException->setText(e1.what());
    }
    catch(ConstanteException e2){
        ui->labelException->setText(e2.what());
    }
    Afficher(pile,6);
}
