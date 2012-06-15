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

QFile MainWindow::file( "E:\\Qt\\Calculatrice\\Pile.text" );
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pile=new Pile(10);

    pile_Stock=new Pile(10);
    pointeurPile=-1;

    QPalette palette = ui->labelException->palette();
    palette.setColor(ui->labelException->foregroundRole(), Qt::red);
    ui->labelException->setPalette(palette);

    ReadFilePile();
    //preciseReel=3;
    connect(ui->buttonEntrer,SIGNAL(clicked()),this,SLOT(EnterPressed()));
    connect(ui->buttonRetablir,SIGNAL(clicked()),this,SLOT(RetablirPressed()));
    connect(ui->buttonAnnuler,SIGNAL(clicked()),this,SLOT(AnnulerPressed()));
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
bool MainWindow::WriteFilePile(){
    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return false;
    QTextStream s(&file);
    for(int i=0;i<pile->GetNbConstants();i++){
        s<<pile->GetConstante(i)->Afficher()<<endl;
    }
    file.close();
    return true;
}
bool MainWindow::ReadFilePile(){
    if(!file.open(QIODevice::ReadWrite))
        return false;
    QTextStream in(&file);
    QString line = in.readLine();
    while (!line.isNull()) {
        if(line.contains(QRegExp("^-?[0-9]+(\\.|\\/-?)?[0-9]*(\\$-?[0-9]+(\\.|\\/-?)?[0-9]*)?$"))){
             EntrerVerif(line);

        }
        //expression
        else if(line.contains(QRegExp("^\\'.*\\'$"))){
            pile->Enpiler(*(new Expression(line)));
            pile_Stock->Enpiler(*(new Expression(line)));
        }
        line = in.readLine();
    }
    Afficher(pile,6);
    file.close();
    return true;
}
MainWindow::~MainWindow()
{
    WriteFilePile();
    delete ui;
   // delete pile;
}

Nombre* MainWindow::CheckEntreReelOuRatio(QString s){
    if(s.contains(QRegExp("^-?[0-9]+\\.?[0-9]*$"))){
       /* if(ui->radioButtonRationnelle->isChecked()){
            return (new Reel(s.toFloat()))->ToRationnel();
        }*/
        return new Reel(s.toFloat());
    }
    else if(s.contains(QRegExp("^-?[0-9]+\\/-?[0-9]+$"))){
       /* if(ui->radioButtonReelle->isChecked())
            return (new Rationnel(s.section('/',0,0).toInt(),s.section('/',1,1).toInt()))->ToReel();*/
        return new Rationnel(s.section('/',0,0).toInt(),s.section('/',1,1).toInt());
    }
    else
        throw LogMessage("Les entree ne correspond pas aux modes choisis.",2);
}

void MainWindow::EntrerVerif(QString& s){
    //TODO:expression
    Constante* c;
    if(s.contains(QRegExp("^-?[0-9]+$"))||s.contains(QRegExp("^-?[0-9]+\\.?[0-9]*$"))){
        c=new Reel(s.toFloat());
    }
    else if(s.contains(QRegExp("^-?[0-9]+\\/-?[0-9]+$"))){        //s.contains(QRegExp("^-?[0-9]+\\.?[0-9]*$"))

        c=new Rationnel(s.section('/',0,0).toInt(),s.section('/',1,1).toInt());

    }
    else if(s.contains(QRegExp("^-?[0-9]+(\\.|\\/-?)?[0-9]*\\$-?[0-9]+(\\.|\\/-?)?[0-9]*$"))){

        c=new Complexe(CheckEntreReelOuRatio(s.section('$',0,0)),CheckEntreReelOuRatio(s.section('$',1,1)));

    }
    else
        throw LogMessage("Les entree ne correspond pas aux modes choisis.",2);
    pile->Enpiler(*c);
    pile_Stock->Enpiler(*c);
}

void MainWindow::Afficher(Pile* p, int x) const{
    ui->textEdit->clear();
    if(p->GetNbConstants()<x)
        x=p->GetNbConstants();
    for(int i=p->GetNbConstants()-x;i<p->GetNbConstants();i++){
        ui->textEdit->append(p->GetConstante(i)->Afficher());
    }


}

void MainWindow::EnterPressed(){
    ui->labelException->clear();
    pile_Stock->SetNbConstants(pointeurPile+1);
    try{

        QString s=ui->lineEdit->text();
        if(s.contains(QRegExp("^-?[0-9]+(\\.|\\/-?)?[0-9]*(\\$-?[0-9]+(\\.|\\/-?)?[0-9]*)?$"))){
             EntrerVerif(s);


        }
        //expression
        else if(s.contains(QRegExp("^\\'.*\\'$"))){
            pile->Enpiler(*(new Expression(s)));
            pile_Stock->Enpiler(*(new Expression(s)));
        }



        else if(_stricmp(s.toStdString().c_str(),"sin")==0){
            Constante* depile;
            if(pile->GetConstante(pile->GetNbConstants()-1)->GetType()==expression)
                pile->Enpiler(*(pile->Depiler()->Sin()));
            else{
                depile=DecideDepile();
                if(ui->radioButtonRationnelle->isChecked()){pile->Enpiler(*(depile->Sin()->ToRationnel()));}
                if(ui->radioButtonReelle->isChecked()){pile->Enpiler(*(depile->Sin()->ToReel()));}//||ui->radioButtonEntiere->isChecked()
                if(ui->radioButtonEntiere->isChecked()){
                    Constante* r=depile->Sin();
                    if(r->GetType()!=entier)
                        ui->labelException->setText("Warning: Perte de precision!");
                    pile->Enpiler(*(r->ToEntier()));
                }
            }
            pile_Stock->Enpiler(*(new Expression(QString("sin"))));
            pile_Stock->Enpiler(*(pile->GetConstante(pile->GetNbConstants()-1)));
        }
        else if(_stricmp(s.toStdString().c_str(),"cos")==0){
            Constante* depile;
            if(pile->GetConstante(pile->GetNbConstants()-1)->GetType()==expression)
                pile->Enpiler(*(pile->Depiler()->Cos()));
            else{
                depile=DecideDepile();
                if(ui->radioButtonRationnelle->isChecked()){pile->Enpiler(*(depile->Cos()->ToRationnel()));}
                if(ui->radioButtonReelle->isChecked()){pile->Enpiler(*(depile->Cos()->ToReel()));}//||ui->radioButtonEntiere->isChecked()
                if(ui->radioButtonEntiere->isChecked()){
                    Constante* r=depile->Cos();
                    if(r->GetType()!=entier)
                        ui->labelException->setText("Warning: Perte de precision!");
                    pile->Enpiler(*(r->ToEntier()));
                }
            }
            pile_Stock->Enpiler(*(new Expression(QString("cos"))));
            pile_Stock->Enpiler(*(pile->GetConstante(pile->GetNbConstants()-1)));
        }
        else if(_stricmp(s.toStdString().c_str(),"tan")==0){
            Constante* depile;
            if(pile->GetConstante(pile->GetNbConstants()-1)->GetType()==expression)
                pile->Enpiler(*(pile->Depiler()->Tan()));
            else{
                depile=DecideDepile();
                if(ui->radioButtonRationnelle->isChecked()){pile->Enpiler(*(depile->Tan()->ToRationnel()));}
                if(ui->radioButtonReelle->isChecked()){pile->Enpiler(*(depile->Tan()->ToReel()));}//||ui->radioButtonEntiere->isChecked()
                if(ui->radioButtonEntiere->isChecked()){
                    Constante* r=depile->Tan();
                    if(r->GetType()!=entier)
                        ui->labelException->setText("Warning: Perte de precision!");
                    pile->Enpiler(*(r->ToEntier()));
                }
            }
            pile_Stock->Enpiler(*(new Expression(QString("tan"))));
            pile_Stock->Enpiler(*(pile->GetConstante(pile->GetNbConstants()-1)));
        }
        else if(_stricmp(s.toStdString().c_str(),"sinh")==0){
            Constante* depile;
            if(pile->GetConstante(pile->GetNbConstants()-1)->GetType()==expression)
                pile->Enpiler(*(pile->Depiler()->Sinh()));
            else{
                depile=DecideDepile();
                if(ui->radioButtonRationnelle->isChecked()){pile->Enpiler(*(depile->Sinh()->ToRationnel()));}
                if(ui->radioButtonReelle->isChecked()){pile->Enpiler(*(depile->Sinh()->ToReel()));}//||ui->radioButtonEntiere->isChecked()
                if(ui->radioButtonEntiere->isChecked()){
                    Constante* r=depile->Sinh();
                    if(r->GetType()!=entier)
                        ui->labelException->setText("Warning: Perte de precision!");
                    pile->Enpiler(*(r->ToEntier()));
                }
            }
            pile_Stock->Enpiler(*(new Expression(QString("sinh"))));
            pile_Stock->Enpiler(*(pile->GetConstante(pile->GetNbConstants()-1)));
        }
        else if(_stricmp(s.toStdString().c_str(),"cosh")==0){
            Constante* depile;
            if(pile->GetConstante(pile->GetNbConstants()-1)->GetType()==expression)
                pile->Enpiler(*(pile->Depiler()->Cosh()));
            else{
                depile=DecideDepile();
                if(ui->radioButtonRationnelle->isChecked()){pile->Enpiler(*(depile->Cosh()->ToRationnel()));}
                if(ui->radioButtonReelle->isChecked()){pile->Enpiler(*(depile->Cosh()->ToReel()));}//||ui->radioButtonEntiere->isChecked()
                if(ui->radioButtonEntiere->isChecked()){
                    Constante* r=depile->Cosh();
                    if(r->GetType()!=entier)
                        ui->labelException->setText("Warning: Perte de precision!");
                    pile->Enpiler(*(r->ToEntier()));
                }
            }
            pile_Stock->Enpiler(*(new Expression(QString("cosh"))));
            pile_Stock->Enpiler(*(pile->GetConstante(pile->GetNbConstants()-1)));
        }
        else if(_stricmp(s.toStdString().c_str(),"tanh")==0){
            Constante* depile;
            if(pile->GetConstante(pile->GetNbConstants()-1)->GetType()==expression)
                pile->Enpiler(*(pile->Depiler()->Tanh()));
            else{
                depile=DecideDepile();
                if(ui->radioButtonRationnelle->isChecked()){pile->Enpiler(*(depile->Tanh()->ToRationnel()));}
                if(ui->radioButtonReelle->isChecked()){pile->Enpiler(*(depile->Tanh()->ToReel()));}//||ui->radioButtonEntiere->isChecked()
                if(ui->radioButtonEntiere->isChecked()){
                    Constante* r=depile->Tanh();
                    if(r->GetType()!=entier)
                        ui->labelException->setText("Warning: Perte de precision!");
                    pile->Enpiler(*(r->ToEntier()));
                }
            }
            pile_Stock->Enpiler(*(new Expression(QString("tanh"))));
            pile_Stock->Enpiler(*(pile->GetConstante(pile->GetNbConstants()-1)));
        }
        else if(_stricmp(s.toStdString().c_str(),"ln")==0){
            Constante* depile;
            if(pile->GetConstante(pile->GetNbConstants()-1)->GetType()==expression)
                pile->Enpiler(*(pile->Depiler()->Ln()));
            else{
                depile=DecideDepile();
                if(ui->radioButtonRationnelle->isChecked()){pile->Enpiler(*(depile->Ln()->ToRationnel()));}
                if(ui->radioButtonReelle->isChecked()){pile->Enpiler(*(depile->Ln()->ToReel()));}//||ui->radioButtonEntiere->isChecked()
                if(ui->radioButtonEntiere->isChecked()){
                    Constante* r=depile->Ln();
                    if(r->GetType()!=entier)
                        ui->labelException->setText("Warning: Perte de precision!");
                    pile->Enpiler(*(r->ToEntier()));
                }
            }
            pile_Stock->Enpiler(*(new Expression(QString("ln"))));
            pile_Stock->Enpiler(*(pile->GetConstante(pile->GetNbConstants()-1)));
        }
        else if(_stricmp(s.toStdString().c_str(),"log")==0){
            Constante* depile;
            if(pile->GetConstante(pile->GetNbConstants()-1)->GetType()==expression)
                pile->Enpiler(*(pile->Depiler()->Log()));
            else{
                depile=DecideDepile();
                if(ui->radioButtonRationnelle->isChecked()){pile->Enpiler(*(depile->Log()->ToRationnel()));}
                if(ui->radioButtonReelle->isChecked()){pile->Enpiler(*(depile->Log()->ToReel()));}//||ui->radioButtonEntiere->isChecked()
                if(ui->radioButtonEntiere->isChecked()){
                    Constante* r=depile->Log();
                    if(r->GetType()!=entier)
                        ui->labelException->setText("Warning: Perte de precision!");
                    pile->Enpiler(*(r->ToEntier()));
                }
            }
            pile_Stock->Enpiler(*(new Expression(QString("log"))));
            pile_Stock->Enpiler(*(pile->GetConstante(pile->GetNbConstants()-1)));
        }
        else if(_stricmp(s.toStdString().c_str(),"sign")==0){
            //Constante* depile;
            pile->Enpiler(*(pile->Depiler()->Sign()));

            pile_Stock->Enpiler(*(new Expression(QString("sign"))));
            pile_Stock->Enpiler(*(pile->GetConstante(pile->GetNbConstants()-1)));
        }
        else if(_stricmp(s.toStdString().c_str(),"inv")==0){
            Constante* depile;
            if(pile->GetConstante(pile->GetNbConstants()-1)->GetType()==expression)
                pile->Enpiler(*(pile->Depiler()->Inv()));
            else{
                depile=DecideDepile();
                if(ui->radioButtonRationnelle->isChecked()){pile->Enpiler(*(depile->Inv()->ToRationnel()));}
                if(ui->radioButtonReelle->isChecked()){pile->Enpiler(*(depile->Inv()->ToReel()));}
                if(ui->radioButtonEntiere->isChecked()){
                    Constante* r=depile->Inv();
                    if(r->GetType()!=entier)
                        ui->labelException->setText("Warning: Perte de precision!");
                    pile->Enpiler(*(r->ToEntier()));
                }
            }
            pile_Stock->Enpiler(*(new Expression(QString("inv"))));
            pile_Stock->Enpiler(*(pile->GetConstante(pile->GetNbConstants()-1)));
        }

        else if(_stricmp(s.toStdString().c_str(),"sqr")==0){
            Constante* depile;
            if(pile->GetConstante(pile->GetNbConstants()-1)->GetType()==expression)
                pile->Enpiler(*(pile->Depiler()->Sqr()));
            else{
                depile=pile->GetConstante(pile->GetNbConstants()-1);
                if(ui->radioButtonRationnelle->isChecked()){pile->Enpiler(*(depile->Sqr()->ToRationnel()));}
                if(ui->radioButtonReelle->isChecked()){pile->Enpiler(*(depile->Sqr()->ToReel()));}
                if(ui->radioButtonEntiere->isChecked()){
                    Constante* r=depile->Sqr();
                    if(r->GetType()!=entier)
                        ui->labelException->setText("Warning: Perte de precision!");
                    pile->Enpiler(*(r->ToEntier()));
                }
            }
            pile_Stock->Enpiler(*(new Expression(QString("sqr"))));
            pile_Stock->Enpiler(*(pile->GetConstante(pile->GetNbConstants()-1)));
        }
        else if(_stricmp(s.toStdString().c_str(),"cube")==0){
            Constante* depile;
            if(pile->GetConstante(pile->GetNbConstants()-1)->GetType()==expression)
                pile->Enpiler(*(pile->Depiler()->Cube()));
            else{
                depile=pile->GetConstante(pile->GetNbConstants()-1);
                if(ui->radioButtonRationnelle->isChecked()){pile->Enpiler(*(depile->Cube()->ToRationnel()));}
                if(ui->radioButtonReelle->isChecked()){pile->Enpiler(*(depile->Cube()->ToReel()));}
                if(ui->radioButtonEntiere->isChecked()){
                    Constante* r=depile->Cube();
                    if(r->GetType()!=entier)
                        ui->labelException->setText("Warning: Perte de precision!");
                    pile->Enpiler(*(r->ToEntier()));
                }
            }
            pile_Stock->Enpiler(*(new Expression(QString("cube"))));
            pile_Stock->Enpiler(*(pile->GetConstante(pile->GetNbConstants()-1)));
        }
        else if(s.contains(QRegExp("^\\!$"))){
            Constante* depile;
            if(pile->GetConstante(pile->GetNbConstants()-1)->GetType()==expression)
                pile->Enpiler(*(pile->Depiler()->Fact()));
            else{
                depile=DecideDepile();
                pile->Enpiler(*(depile->Fact()));
            }
            pile_Stock->Enpiler(*(new Expression(QString("!"))));
            pile_Stock->Enpiler(*(pile->GetConstante(pile->GetNbConstants()-1)));
        }
        else if(_stricmp(s.toStdString().c_str(),"sqrt")==0){
            if(pile->GetConstante(pile->GetNbConstants()-1)->GetType()==expression)
                pile->Enpiler(*(pile->Depiler()->Sqrt()));
            else{

                if(pile->GetConstante(pile->GetNbConstants()-1)->GetType()==complexe)
                    throw LogMessage("Le operande ne correspond pas aux modes choisis.",2);
                else if(dynamic_cast<Reel*>(pile->GetConstante(pile->GetNbConstants()-1))->GetReel()<0){
                    if(ui->radioButtonNonComplexe->isChecked())
                        throw LogMessage("Le operande ne peut pas etre negatif.",3);
                }
                pile->Enpiler(*(ToMode(pile->Depiler()->Sqrt())));
            }
            pile_Stock->Enpiler(*(new Expression(QString("sqrt"))));
            pile_Stock->Enpiler(*(pile->GetConstante(pile->GetNbConstants()-1)));
        }
        else if(_stricmp(s.toStdString().c_str(),"pow")==0){
            if(pile->GetNbConstants()>=2){
                Constante* p2=pile->GetConstante(pile->GetNbConstants()-1);
                Constante* p1=pile->GetConstante(pile->GetNbConstants()-2);
                Constante* aEnpile=p1->Pow(p2);
                pile->Depiler();pile->Depiler();
                if(aEnpile->GetType()!=expression&&aEnpile->GetType()!=complexe){
                    if(ui->radioButtonRationnelle->isChecked()) {pile->Enpiler(*(aEnpile->ToRationnel()));}
                    if(ui->radioButtonReelle->isChecked()){pile->Enpiler(*(aEnpile->ToReel()));}
                    if(ui->radioButtonEntiere->isChecked()){
                        if(aEnpile->GetType()!=entier)
                            ui->labelException->setText("Warning: Perte de precision!");
                        pile->Enpiler(*(aEnpile->ToEntier()));
                    }
                }
                else pile->Enpiler(*aEnpile);
            }
            else
                throw LogMessage("Pas assez de operand pour une operation.",3);
            pile_Stock->Enpiler(*(new Expression(QString("pow"))));
            pile_Stock->Enpiler(*(pile->GetConstante(pile->GetNbConstants()-1)));
        }
        else if(_stricmp(s.toStdString().c_str(),"modulo")==0){
            Constante* p2=pile->GetConstante(pile->GetNbConstants()-1);
            Constante* p1=pile->GetConstante(pile->GetNbConstants()-2);
            Constante* aEnpile=p1->Modulo(p2);
            pile->Depiler();pile->Depiler();
            pile->Enpiler(*(aEnpile));
            pile_Stock->Enpiler(*(new Expression(QString("modulo"))));
            pile_Stock->Enpiler(*(pile->GetConstante(pile->GetNbConstants()-1)));
        }
        else if(s=="+"||s=="-"||s=="*"||s=="/"){
            if(pile->GetNbConstants()>=2){
                Constante* p2=pile->Depiler();
                Constante* p1=pile->Depiler();
                Constante* aEnpile;
                if(s=="+"){ aEnpile=p1->Add(p2);pile_Stock->Enpiler(*(new Expression(QString("+"))));}
                else if(s=="-") {aEnpile=p1->Sub(p2);pile_Stock->Enpiler(*(new Expression(QString("-"))));}
                else if(s=="*") {aEnpile=p1->Multiple(p2);pile_Stock->Enpiler(*(new Expression(QString("*"))));}
                else {aEnpile=p1->Division(p2);pile_Stock->Enpiler(*(new Expression(QString("/"))));}

                if(aEnpile->GetType()!=expression&&aEnpile->GetType()!=complexe){
                    if(ui->radioButtonRationnelle->isChecked()) {pile->Enpiler(*(aEnpile->ToRationnel()));}
                    if(ui->radioButtonReelle->isChecked()){pile->Enpiler(*(aEnpile->ToReel()));}
                    if(ui->radioButtonEntiere->isChecked()){
                        if(aEnpile->GetType()!=entier)
                            ui->labelException->setText("Warning: Perte de precision!");
                        pile->Enpiler(*(aEnpile->ToEntier()));
                    }
                }
                else if(aEnpile->GetType()==complexe){
                    //QString s=aEnpile->Afficher();
                    //ui->labelException->setText(s);return;
                    Complexe* a=dynamic_cast<Complexe*>(aEnpile);
                    if(ui->radioButtonRationnelle->isChecked()) {pile->Enpiler(*(new Complexe(a->GetRe()->ToRationnel(),a->GetIm()->ToRationnel())));}
                    if(ui->radioButtonReelle->isChecked()){pile->Enpiler(*(new Complexe(a->GetRe()->ToReel(),a->GetIm()->ToReel())));}
                    if(ui->radioButtonEntiere->isChecked()){
                        if(a->GetRe()->GetType()!=entier||a->GetIm()->GetType()!=entier)
                            ui->labelException->setText("Warning: Perte de precision!");
                        pile->Enpiler(*(new Complexe(a->GetRe()->ToEntier(),a->GetIm()->ToEntier())));
                    }
                }
                else pile->Enpiler(*aEnpile);
            }
            else
                throw LogMessage("Pas assez de operand pour une operation.",3);
            pile_Stock->Enpiler(*(pile->GetConstante(pile->GetNbConstants()-1)));
        }


        else if(_stricmp(s.toStdString().c_str()," swap")==0||_stricmp(s.toStdString().c_str(),"swap")==0){
            if(pile->GetConstante(pile->GetNbConstants()-1)->GetType()==entier&&pile->GetConstante(pile->GetNbConstants()-2)->GetType()==entier){
                pile->Swap(dynamic_cast<Reel*>(pile->Depiler())->GetReel(),dynamic_cast<Reel*>(pile->Depiler())->GetReel());
                pile_Stock->Enpiler(*(new Expression(QString("swap"))));
            }
            else
                throw LogMessage("Invalide Index.",3);
        }
        else if(_stricmp(s.toStdString().c_str()," clear")==0||_stricmp(s.toStdString().c_str(),"clear")==0){
            pile->Clear();
           // pile_Stock->Clear();
        }
        else if(_stricmp(s.toStdString().c_str()," dup")==0||_stricmp(s.toStdString().c_str(),"dup")==0){
            pile->Dup();
            pile_Stock->Enpiler(*(new Expression(QString("dup"))));
            pile_Stock->Enpiler(*(pile->GetConstante(pile->GetNbConstants()-1)));
        }
        else if(_stricmp(s.toStdString().c_str()," drop")==0||_stricmp(s.toStdString().c_str(),"drop")==0){
            pile_Stock->Enpiler(*(new Expression(QString("drop"))));
            pile_Stock->Enpiler(*(pile->GetConstante(pile->GetNbConstants()-1)));
            pile->Drop();
        }
        else if(_stricmp(s.toStdString().c_str()," sum")==0||_stricmp(s.toStdString().c_str(),"sum")==0){
            pile_Stock->Enpiler(*(new Expression(QString("sum"))));
            pile->Sum();
            pile_Stock->Enpiler(*(pile->GetConstante(pile->GetNbConstants()-1)));
        }
        else if(_stricmp(s.toStdString().c_str()," mean")==0||_stricmp(s.toStdString().c_str(),"mean")==0){
            pile_Stock->Enpiler(*(new Expression(QString("mean"))));
            pile->Mean();
            pile_Stock->Enpiler(*(pile->GetConstante(pile->GetNbConstants()-1)));
        }
        else if(_stricmp(s.toStdString().c_str(),"eval")==0){
           // Pile tmp=*pile;
            if(pile->GetConstante(pile->GetNbConstants()-1)->GetType()==expression){
                Constante* depile=pile->Depiler();
                ui->lineEdit->setText(depile->Afficher());
                //Constante* aEnpiler=
                QString rest=ui->radioButtonDegre->isChecked()?dynamic_cast<Expression*>(depile)->Eval(pile,true):dynamic_cast<Expression*>(depile)->Eval(pile,false);
                pile->Enpiler(*(ToMode(pile->Depiler())));
                if(rest!=""){
                    ui->lineEdit->setText(dynamic_cast<Expression*>(depile)->GetStr());
                    throw LogMessage("Le expression ne peut pas etre evalue. Verifiez la forme.",3);
                }
                //pile->Enpiler(*(ToMode(aEnpiler)));
                pile_Stock->Enpiler(*(new Expression(QString("eval"))));
                pile_Stock->Enpiler(*(pile->GetConstante(pile->GetNbConstants()-1)));
            }
            else
                throw LogMessage("Eval est utilise pour evaluer une expression",1);
        }
        else if(s.contains(QRegExp(" +"))){
            s.push_front('\'');
            s.push_back('\'');
            Expression *exp=new Expression(s);

            QString rest=ui->radioButtonDegre->isChecked()?dynamic_cast<Expression*>(exp)->Eval(pile,true):dynamic_cast<Expression*>(exp)->Eval(pile,false);

            pile->Enpiler(*(ToMode(pile->Depiler())));
            if(rest!=""){
                ui->lineEdit->setText(dynamic_cast<Expression*>(exp)->GetStr());
                throw LogMessage("Le expression ne peut pas etre evalue. Verifiez la forme.",3);
            }
            pile_Stock->Enpiler(*(pile->GetConstante(pile->GetNbConstants()-1)));
        }

        ui->lineEdit->clear();
    }
    catch(LogMessage e1){
        ui->labelException->setText(e1.what());
        LogSystem ls=LogSystem(e1);
        ls.LogWrite();
    }

    pointeurPile=pile_Stock->GetNbConstants()-1;
    Afficher(pile,6);


}


Constante* MainWindow::DecideDepile(){
    Constante* depiler;
    if(pile->GetConstante(pile->GetNbConstants()-1)->GetType()==complexe)
        throw LogMessage("Cette operateur ne peut pas etre utilise par complexe.",2);
    else{

            depiler=ui->radioButtonRadiant->isChecked()?pile->Depiler():pile->Depiler()->ToDegre();
    }
    return depiler;
}

Constante* MainWindow::ToMode(Constante* c){
    if(c->GetType()!=complexe){
        if(ui->radioButtonEntiere->isChecked()){
            if(c->GetType()!=entier)
                ui->labelException->setText("Warning: Perte de precision!");
            return c->ToEntier();
        }
        return ui->radioButtonRationnelle->isChecked()?c->ToRationnel():c->ToReel();
    }
    else{
        Complexe* com=dynamic_cast<Complexe*>(c);
        if(ui->radioButtonEntiere->isChecked()){
            if(com->GetRe()->GetType()!=entier||com->GetIm()->GetType()!=entier)
                ui->labelException->setText("Warning: Perte de precision!");
            return new Complexe(com->GetRe()->ToEntier(),com->GetIm()->ToEntier());//r->ToEntier()));
        }
        return ui->radioButtonRationnelle->isChecked()?new Complexe(com->GetRe()->ToRationnel(),com->GetIm()->ToRationnel()):
                                                       new Complexe(com->GetRe()->ToReel(),com->GetIm()->ToReel());
    }
}

void MainWindow::AnnulerPressed(){

    ui->labelException->clear();
    pointeurPile=pointeurPile-1;

    try{
        if(pointeurPile<0){
            pointeurPile=0;
            throw LogMessage("Pas plus de annuler, vous pouvez faire reset.",1);
        }

        if(pile_Stock->GetConstante(pointeurPile)->GetType()==expression){
            QString s=dynamic_cast<Expression*>(pile_Stock->GetConstante(pointeurPile))->GetStr();

            if(s.contains(QRegExp("^[^\\']"))){//(s=="sin"||s=="cos"||s=="tan"||s=="sinh"||s=="cosh"||s=="tanh"||s=="ln"||s="log"||s=="sqrt"||s=="eval"){
                if(pile_Stock->GetConstante(pointeurPile-1)->GetType()==expression||s=="swap"){
                    pointeurPile++;
                    throw LogMessage("Renconter un swap, impossible de annuler.",1);
                }
                else if(s=="*"){
                    pointeurPile--;
                    pile->Enpiler(*(pile->Depiler()->Division(pile_Stock->GetConstante(pointeurPile))));
                    pile->Enpiler(*(pile_Stock->GetConstante(pointeurPile)));
                }
                else if(s=="/"){
                    pointeurPile--;
                    pile->Enpiler(*(pile->Depiler()->Multiple(pile_Stock->GetConstante(pointeurPile))));
                    pile->Enpiler(*(pile_Stock->GetConstante(pointeurPile)));
                }
                else if(s=="+"){
                    pointeurPile--;
                    pile->Enpiler(*(pile->Depiler()->Sub(pile_Stock->GetConstante(pointeurPile))));
                    pile->Enpiler(*(pile_Stock->GetConstante(pointeurPile)));
                }
                else if(s=="-"){
                    pointeurPile--;
                    pile->Enpiler(*(pile->Depiler()->Add(pile_Stock->GetConstante(pointeurPile))));
                    pile->Enpiler(*(pile_Stock->GetConstante(pointeurPile)));
                }
                else if(s=="dup"){
                    pointeurPile--;
                    pile->Depiler();
                }
                else if(s=="drop"){
                    pointeurPile--;
                    pile->Enpiler(*(pile_Stock->GetConstante(pointeurPile)));
                }
                else{
                    pointeurPile--;
                    pile->Depiler();
                    pile->Enpiler(*(pile_Stock->GetConstante(pointeurPile)));
                }
              //  pile_Stock->SetNbConstants(pointeurPile+1);
            }
            else{
                pile->Depiler();
             //   pile_Stock->SetNbConstants(pointeurPile+1);
            }
        }
        else{
            pile->Depiler();
          //  pile_Stock->SetNbConstants(pointeurPile+1);
        }
    }
    catch(LogMessage e1){
        ui->labelException->setText(e1.what());
        LogSystem ls=LogSystem(e1);
        ls.LogWrite();
    }

    Afficher(pile,6);
}

void MainWindow::RetablirPressed(){

    ui->labelException->clear();
     pointeurPile++;

     try{
         if(pointeurPile>=pile_Stock->GetNbConstants()){
             pointeurPile=pile_Stock->GetNbConstants()-1;
             throw LogMessage("Pas plus de retablir.",1);
         }
         if(pile_Stock->GetConstante(pointeurPile)->GetType()==expression){
             QString s=dynamic_cast<Expression*>(pile_Stock->GetConstante(pointeurPile))->GetStr();
             /*if(s=="swap"){
                 pile->Swap(dynamic_cast<Reel*>(pile->Depiler())->GetReel(),dynamic_cast<Reel*>(pile->Depiler())->GetReel());
             }*/
             if(s.contains(QRegExp("^[^\\']"))){//(s=="sin"||s=="cos"||s=="tan"||s=="sinh"||s=="cosh"||s=="tanh"||s=="ln"||s="log"||s=="sqrt"||s=="eval"){
                 if(s=="dup"){
                     pointeurPile++;
                     pile->Enpiler(*(pile_Stock->GetConstante(pointeurPile)));
                 }
                 else if(s=="drop"){
                     pointeurPile++;
                     pile->Drop();
                 }
                 else if(s=="+"||s=="-"||s=="*"||s=="/"){
                     pointeurPile++;
                     pile->Depiler();pile->Depiler();
                     pile->Enpiler(*(pile_Stock->GetConstante(pointeurPile)));
                 }
                 else{
                     pointeurPile++;
                     pile->Depiler();
                     pile->Enpiler(*(pile_Stock->GetConstante(pointeurPile)));
                 }

             }
             else{
                 pile->Enpiler(*(pile_Stock->GetConstante(pointeurPile)));

             }
         }
         else{
             pile->Enpiler(*(pile_Stock->GetConstante(pointeurPile)));

         }
     }
     catch(LogMessage e1){
         ui->labelException->setText(e1.what());
         LogSystem ls=LogSystem(e1);
         ls.LogWrite();
     }

     catch(std::exception& e){
         ui->labelException->setText(e.what());
     }


     Afficher(pile,6);
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
void MainWindow::SignPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" sign");}
void MainWindow::ExpPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" '");}
void MainWindow::on_buttonSin_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" sin");}
void MainWindow::on_buttonSinh_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" sinh");}
void MainWindow::on_buttonCos_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" cos");}
void MainWindow::on_buttonCosh_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" cosh");}
void MainWindow::on_buttonTan_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" tan");}
void MainWindow::on_buttonTanh_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" tanh");}
void MainWindow::on_buttonLn_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" ln");}
void MainWindow::on_buttonLog_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" log");}
void MainWindow::on_buttonInv_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" inv");}
void MainWindow::on_buttonSqrt_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" sqrt");}
void MainWindow::on_buttonSqr_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" sqr");}
void MainWindow::on_buttonCube_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" cube");}
void MainWindow::on_buttonFacto_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" !");}

void MainWindow::on_buttonDollar_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+"$");}
void MainWindow::on_buttonVirgule_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+".");}
void MainWindow::on_buttonEval_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" eval");}
void MainWindow::on_buttonExc_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" !");}

void MainWindow::on_buttonSwap_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" swap");}
void MainWindow::on_buttonSum_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" sum");}
void MainWindow::on_buttonMean_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" mean");}
void MainWindow::on_buttonClear_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" clear");}
void MainWindow::on_buttonDup_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" dup");}
void MainWindow::on_buttonDrop_clicked(){ ui->lineEdit->setText(ui->lineEdit->text()+" drop");}
