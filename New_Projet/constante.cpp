#include "pile.h"

Constante* Expression::Eval(){

    Pile *p=new Pile(10);
    QString s = str.section('\'',1,1); // Suppression des quotes autour de l'expression
    QStringList list=s.split(" ",QString::SkipEmptyParts);//Découpage de l'espression en fonction des espaces

    try{
        for(int i=0;i<list.count();i++){
            QString sect=list.at(i);
          //Entier ou réel
            if(sect.contains(QRegExp("^-?[0-9]+\.?[0-9]*$")))
                p->Empiler(*(new Complexe(sect,0));
          //Rationel
            else if(sect.contains(QRegExp("^-?[0-9]+/-?[0-9]+$"))){
                    QStringList ratio = sect.split("/",QString::SkipEmptyParts);
                    p->Empiler(*(new Rationnel(ratio.at(0),ratio.at(1))));
            }
          //Complexe
            else if(sect.contains(QRegExp("^-?[0-9]+(\\.|\\/-?)?[0-9]*\\$-?[0-9]+(\\.|\\/-?)?[0-9]*$"))){
                p->Empiler(*(new Complexe(sect.section('$',0,0),sect.section('$',1,1))));
            }
          //Opérateur
            else if (sect.contains(QRegExp("^[+-/*]+$"))){
                selectOp(sect);
            }
          //Fonction
            else if (sect.contains(QRegExp("^[a-z]+$"))){
                selectFct(sect);
            }
        return p->Depiler();
       }
     }//fin try
    }//fin for
    catch(LogMessage e){
        throw LogMessage("Le expression ne peut pas etre evalue. Verifiez la forme.");
    }
}

void selectFct(string s){}
void selectOp(string s){}
