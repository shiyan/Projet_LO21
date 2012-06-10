#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <iostream>
#include <qmath.h>
#include <QString>
#include <QApplication>
#include <QStringList>
#include <QPushButton>
#include <QMessageBox>

using namespace std;

static const double Pi = 3.14159265358979323846264338327950288419717;

class Constante;
class Rationnel;
class Complexe;

// Constante
class Constante{
    protected:
        QString type;

    public:
        Constante(QString t): type(t){}
        QString getType()const{return type;}

        virtual QString Afficher() const=0;
        //Fonction Unaires
        virtual Constante* Sqr()=0;
};

class Rationnel:public Constante{

        int num;
        int den;

    public:
        Rationnel(int n,int d):Constante("Rationnel"),num(n),den(d){
            if (d==1)type = "Entier";
            else type= "Rationnel";

            Simplifier();
        }
        int getNum(){return num;}
        int getDen(){return den;}
        int Pgcd(int a, int b) const;
        void Simplifier();

        QString Afficher() const;

        //Fonction Unaires
        Rationnel* Sqr();
};


class Complexe:public Constante{

        Rationnel* re;
        Rationnel* im;

    public:
        Complexe(Rationnel* r,Rationnel* i):Constante("Complexe"),re(r),im(i){}

        Rationnel* getRe() const{return re;}
        Rationnel* getIm() const{return im;}

        QString Afficher() const;

        //Fonction Unaires
        Complexe* Sqr();

};
Complexe* operator*(Complexe*, Complexe* );
Rationnel* operator*(Rationnel* , Rationnel*);

#endif // CONSTANTE_H
