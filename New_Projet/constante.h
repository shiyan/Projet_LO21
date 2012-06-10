#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <iostream>
#include <qmath.h>
#include <string>
#include <QString>
#include <QStringList>

using namespace std;

static const double Pi = 3.14159265358979323846264338327950288419717;

class Constante;
class Rationnel;
class Complexe;
class Expression;

// Messages
class LogMessage{
   private :
       string info;
       int degre; // degré d'importance du message. 3 étant le degré le plus fort

   public:
       LogMessage(const std::string& i):info(i){}
       const char* what() const{return info.c_str();}
};

class LogSystem {};

// Constante
class Constante{
    protected:
        string type;

    public:
        string GetType()const{return type;}

        virtual QString Afficher() const=0;

     //Conversion
        virtual float ToReel()=0;
        virtual Rationnel* ToRationnel()=0;
        virtual Constante* ToDegre()=0;

     //Opération
        virtual Constante* Sin()=0;
        virtual Constante* Sqrt()=0;

};

class Rationnel:public Constante{
    protected:
        int num;
        int den;
    public:
        Rationnel(int n,int d):num(n),den(d),type("rationnelle"){Simplifier();}
        int Pgcd(int a, int b) const;
        void Simplifier();
        float ToReel();
        Rationnel* ToRationnel();

        QString Afficher() const;
};

class Complexe:public Constante{
    private:
        float re;
        float im;

    public:
        Complexe(float r,float i):re(r),im(i),type("complexe"){}

        float GetRe() const{return re;}
        float GetIm() const{return im;}

        QString Afficher() const;

        float ToReel();
        Rationnel* ToRationnel();
        Constante* ToDegre();

        Constante* Sin();
        Constante* Sqrt();

};

class Expression:public Constante{
    private:
        QString str;

    public:
        Expression(QString& s):str(s),type("expression"){}

        QString GetStr() const{return str;}
        QString Afficher() const;

        float ToReel();
        Rationnel* ToRationnel();
        Constante* ToDegre();

        Constante* Sin();
        Constante* Sqrt();

        Constante* Eval();
};

#endif // CONSTANTE_H
