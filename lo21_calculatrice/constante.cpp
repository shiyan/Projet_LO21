#include "mainwindow.h"
#include "ui_mainwindow.h"

//--------------------------------------------------------------------//
//                             Rationnel                              //
//--------------------------------------------------------------------//
// Calcule le PGCD de 2 nombres
int Rationnel::Pgcd(int a, int b) const{
    if (a==0||b==0) return 0;
        if (a<0) a=-a;
        if (b<0) b=-b;
        while(a!=b){
            if (a>b) a=a-b; else b=b-a;
        }
        return a;
}

//Simplifie un rationnel en fraction irréductible
void Rationnel::Simplifier(){
    if (num==0) { den=1; return; }
    if (den==0) throw LogMessage("Impossible de diviser par 0 !",3);

    //Division par le PGCG
    int div = Pgcd(num,den);
    num /= div;
    den /= div;

    if (den<0) {
        den=-den;
        num=-num;
    }
    if(den==1)
        type="entier";
}

QString Rationnel::Afficher()const{
    if (this->den == 1) return (QString::number(num));

    return (QString::number(num) + "/" + QString::number(den));
}

//!Multiplication de deux rationnels
Rationnel* operator*(Rationnel* A, Rationnel* B){
    Rationnel* tmp =  new Rationnel(A->getNum()*B->getNum(), A->getDen()*B->getDen());
    tmp.Simplifier();
    return tmp;
}

//Fonction Unaires
Rationnel* Rationnel::Sqr(){
    Rationnel* tmp = this;
    return tmp * tmp;
}

//--------------------------------------------------------------------//
//                             Complexe                               //
//--------------------------------------------------------------------//

QString Complexe::Afficher()const{ return (re->Afficher() + "$" + im->Afficher());}

/*!Multiplication de deux complexes selon la formule : z1= a1 + ib1, z2 = a2 + ib2
z1*z2= a1.a2 - b1.b2 + i.( a1.b2 + a2.b1 )*/
Complexe* operator*(Complexe* A, Complexe* B){
   return new Complexe(A->getRe()*B->getRe() - A->getIm()*B->getIm(), A->getRe()*B->getIm()+A->getIm()*B->getRe());
}

//Fonction Unaires
Complexe* Complexe::Sqr(){
    return this * this;
}

