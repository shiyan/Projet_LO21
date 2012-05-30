#include "mainwindow.h"
#include "fonction.h"
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


    //preciseReel=3;
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



}

MainWindow::~MainWindow()
{
    delete ui;
   // delete pile;
}

Nombre* MainWindow::CheckEntreReelOuRatio(QString& s)const{
    if(s.contains(QRegExp("^-?[0-9]+\\.?[0-9]*$"))){
        if(ui->radioButtonRationnelle->isChecked()){
            return (new Reel(s.toFloat()))->ToRationnel();
        }
        return new Reel(s.toFloat());
    }
    else if(s.contains(QRegExp("^-?[0-9]+\\/-?[0-9]+$"))){
        if(ui->radioButtonReelle->isChecked())
            return (new Rationnel(s.section('/',0,0).toInt(),s.section('/',1,1).toInt()))->ToReel();
        return new Rationnel(s.section('/',0,0).toInt(),s.section('/',1,1).toInt());
    }
    else
        throw CalculeException("Les entree ne correspond pas aux modes choisis.");
}

void MainWindow::EntrerVerif(QString& s){
    //TODO:expression
    if(s.contains(QRegExp("^-?[0-9]+$"))){
        Constante* c=new Reel(s.toFloat());
        pile->Enpiler(*c);
    }
    else if(s.contains(QRegExp("^-?[0-9]+\\.?[0-9]*$"))||s.contains(QRegExp("^-?[0-9]+\\/-?[0-9]+$"))){
        if(!(ui->radioButtonEntiere->isChecked())){
            pile->Enpiler(*(CheckEntreReelOuRatio(s)));
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

void MainWindow::Afficher(Pile* p, int x) const{
    ui->textEdit->clear();
    if(p->GetNbConstants()<x)
        x=p->GetNbConstants();
    for(int i=p->GetNbConstants()-x;i<p->GetNbConstants();i++){
        ui->textEdit->append(p->GetConstante(i)->Afficher());
    }
/*    for(Pile::Iterateur it=pile->Index(pile->GetNbConstants()-x);it!=pile->End();++it)
        *(it.operator *())->Afficher();*/

}

void MainWindow::EnterPressed(){
    ui->labelException->clear();
    try{

        QString s=ui->lineEdit->text();
        if(s.contains(QRegExp("^-?[0-9]+(\\.|\\/-?)?[0-9]*(\\$-?[0-9]+(\\.|\\/-?)?[0-9]*)?$"))){
             EntrerVerif(s);
             //Constante* c=pile->Depiler();
            //ui->textEdit->setText(c->Afficher());

        }
        else if(s.contains(QRegExp("^\\'.*\\'$"))){
            pile->Enpiler(*(new Expression(s)));
        }

    ////////////////////////////////////

        else if(_stricmp(s.toStdString().c_str(),"sin")==0){
            Constante* depile;
            if(pile->GetConstante(pile->GetNbConstants()-1)->GetType()==expression)
                pile->Enpiler(*(pile->Depiler()->Sin()));
            else{
                depile=DecideDepile();
                if(ui->radioButtonRationnelle->isChecked()){pile->Enpiler(*(depile->Sin()->ToRationnel()));}
                if(ui->radioButtonReelle->isChecked()||ui->radioButtonEntiere->isChecked()){pile->Enpiler(*(depile->Sin()->ToReel()));}
            }
        }
        else if(_stricmp(s.toStdString().c_str(),"sqrt")==0){
            if(pile->GetConstante(pile->GetNbConstants()-1)->GetType()==expression)
                pile->Enpiler(*(pile->Depiler()->Sqrt()));
            else{
                if(ui->radioButtonEntiere->isChecked()){
                    if(pile->GetConstante(pile->GetNbConstants()-1)->GetType()!=entier)
                        throw CalculeException("Le operande ne correspond pas aux modes choisis.");
                }
                if(pile->GetConstante(pile->GetNbConstants()-1)->GetType()==complexe)
                    throw CalculeException("Le operande ne correspond pas aux modes choisis.");
                else if(dynamic_cast<Reel*>(pile->GetConstante(pile->GetNbConstants()-1))->GetReel()<0){
                    if(ui->radioButtonNonComplexe->isChecked())
                        throw CalculeException("Le operande ne peut pas etre negatif.");
                }
                pile->Enpiler(*(ToMode(pile->Depiler()->Sqrt())));
            }
        }
        else if(_stricmp(s.toStdString().c_str(),"eval")==0){
           // Pile tmp=*pile;
            if(pile->GetConstante(pile->GetNbConstants()-1)->GetType()==expression){
                Constante* depile=pile->Depiler();
                ui->lineEdit->setText(depile->Afficher());
                Constante* aEnpiler=ui->radioButtonDegre->isChecked()?dynamic_cast<Expression*>(depile)->Eval(true):dynamic_cast<Expression*>(depile)->Eval(false);
                pile->Enpiler(*(ToMode(aEnpiler)));
            }
            else
                throw CalculeException("Eval est utilise pour evaluer une expression");
        }
        else if(s.contains(QRegExp(" +"))){
            s.push_front('\'');
            s.push_back('\'');
            Expression *exp=new Expression(s);
            Constante* aEnpiler=ui->radioButtonDegre->isChecked()?dynamic_cast<Expression*>(exp)->Eval(true):dynamic_cast<Expression*>(exp)->Eval(false);
            pile->Enpiler(*(ToMode(aEnpiler)));
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


Constante* MainWindow::DecideDepile(){
    Constante* depiler;
    if(pile->GetConstante(pile->GetNbConstants()-1)->GetType()==complexe)
        throw CalculeException("Cette operateur ne peut pas etre utilise par complexe.");
    else{
        if(ui->radioButtonEntiere->isChecked()){
            if(pile->GetConstante(pile->GetNbConstants()-1)->GetType()==entier)
                depiler=ui->radioButtonRadiant->isChecked()?pile->Depiler():pile->Depiler()->ToDegre();
            else
                throw CalculeException("Le operande ne correspond pas aux modes choisis.");
        }
        else
            depiler=ui->radioButtonRadiant->isChecked()?pile->Depiler():pile->Depiler()->ToDegre();
    }
    return depiler;
}

Constante* MainWindow::ToMode(Constante* c){
    if(c->GetType()!=complexe)
        return ui->radioButtonRationnelle->isChecked()?c->ToRationnel():c->ToReel();
    else{
        Complexe* com=dynamic_cast<Complexe*>(c);
        return ui->radioButtonRationnelle->isChecked()?new Complexe(com->GetRe()->ToRationnel(),com->GetIm()->ToRationnel()):
                                                       new Complexe(com->GetRe()->ToReel(),com->GetIm()->ToReel());
    }
}
  /*  QString s=ui->lineEdit->text();
    if(s.contains(QRegExp("^[0-9]+$"))){
        Constante* c=new Complexe(s.toInt(),0);
        pile->Enpiler(*c);
    }
    else if(s=="+"){
        if(pile->GetNbConstants()>=2){
            Constante* c1=pile->Depiler();
            Constante* c2=pile->Depiler();
            if(c1->GetType()!=expression && c2->GetType()!=expression){
                Constante* s=dynamic_cast<Complexe*>(c1)->operator +(dynamic_cast<Complexe*>(c2));
                pile->Enpiler(*s);
            }
        }
        else
            throw PileException("Pas assez de elements dans la pile.");

    }
    Afficher(pile);
    ui->lineEdit->setText("");*/
/*    Constante* c=new Complexe((new Reel(3.4))->ToRationnel(),new Rationnel(4,2));
    QString s="-9.8";
    ui->lineEdit->setText(s.setNum(s.toFloat()));*/
//}

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

