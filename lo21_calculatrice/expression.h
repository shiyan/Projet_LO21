#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "pile.h"

class Expression:public Constante{

        QString str;

    public:
        Expression(QString s):Constante("Expression"),str(s){}

        QString Afficher() const{return str;}

        //!Evalue une expression.
        void Eval(Pile*, Pile*);

        //Fonction Unaires
        Expression* Sqr();

};


#endif // EXPRESSION_H
