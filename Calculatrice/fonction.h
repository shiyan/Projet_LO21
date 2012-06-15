#ifndef FONCTION_H
#define FONCTION_H

#include <iostream>
#include <qmath.h>
#include <string>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>

static const double Pi = 3.14159265358979323846264338327950288419717;
class Constante;
class Nombre;
class Reel;
class Rationnel;
class Complexe;
class Expression;
class Pile;
class Operateur;

enum TypeConstante{entier,rationnelle,reelle,complexe,expression};

class LogMessage{
   private :
       std::string info;
       int degre; // degr?d'importance du message. 3 étant le degr?le plus fort

   public:
       LogMessage(const std::string& i,int deg ):info(i),degre(deg){}
       int getDegre()const{return degre;}
       const char* what() const{return info.c_str();}
};

class LogSystem {
    private:
        LogMessage message;
        static QFile file;

    public:
        LogSystem(LogMessage m):message(m){}
        bool LogWrite(){
            if(!file.open(QFile::Append))
                return false;
            QTextStream s(&file);

            s<<message.what()<<endl;
            s<<message.getDegre()<<endl;

            file.close();
            return true;
        }
};


class Constante{
protected:
    TypeConstante type;
public:
    TypeConstante GetType()const{return type;}
    virtual bool IsEntier() const=0;
    virtual QString Afficher() const=0;

    virtual Reel* ToReel()=0;
    virtual Rationnel* ToRationnel()=0;
    virtual Constante* ToDegre()=0;
    virtual Reel* ToEntier()=0;

    virtual Constante* Sin()=0;
    virtual Constante* Cos()=0;
    virtual Constante* Tan()=0;
    virtual Constante* Sinh()=0;
    virtual Constante* Cosh()=0;
    virtual Constante* Tanh()=0;
    virtual Constante* Ln()=0;
    virtual Constante* Log()=0;
    virtual Constante* Sign()=0;
    virtual Constante* Inv()=0;
    virtual Constante* Sqr()=0;
    virtual Constante* Cube()=0;
    virtual Constante* Fact()=0;

    virtual Constante* Sqrt()=0;

    virtual Constante* Multiple(Constante*)=0;
    virtual Constante* Sub(Constante*)=0;
    virtual Constante* Add(Constante*)=0;
    virtual Constante* Division(Constante*)=0;
    virtual Constante* Pow(Constante*)=0;
    virtual Constante* Modulo(Constante*)=0;

};

class Nombre:public Constante{

};

class Reel:public Nombre{
protected:
    float reel;
public:
    Reel(float f);
    float GetReel() const{ return reel;}
    bool IsEntier()const;
    QString Afficher() const;
    Reel* ToReel();
    Rationnel* ToRationnel();
    Constante* ToDegre();
    Reel* ToEntier();

    Constante* Sin();
    Constante* Cos();
    Constante* Tan();
    Constante* Sinh();
    Constante* Cosh();
    Constante* Tanh();
    Constante* Ln();
    Constante* Log();
    Constante* Sign();
    Constante* Inv();
    Constante* Sqr();
    Constante* Cube();
    Constante* Fact();

    Constante* Sqrt();

    Constante* Multiple(Constante*);
    Constante* Sub(Constante*);
    Constante* Add(Constante*);
    Constante* Division(Constante*);
    Constante* Pow(Constante*);
    Constante* Modulo(Constante*);


};

class Rationnel:public Reel{
protected:
    int num;
    int den;
public:
    Rationnel(int n,int d):Reel((float)n/d),num(n),den(d){type=rationnelle; Simplifier();}
    int Pgcd(int a, int b) const;
    void Simplifier();
    Reel* ToReel();
    Rationnel* ToRationnel();
    int GetNum() {return num;}
    int GetDen(){return den;}
    void SetNum(int n){num =n;}
    void SetDen(int d){den=d;}

    Constante* Sign();
    Constante* Inv();
    Constante* Sqr();
    Constante* Cube();

    Constante* Multiple(Constante*);
    Constante* Sub(Constante*);
    Constante* Add(Constante*);
    Constante* Division(Constante*);

    QString Afficher() const;
};

class Expression:public Constante{
private:
    QString str;
public:
    Expression(QString& s):str(s){type=expression; }
    bool IsEntier() const;
    QString Afficher() const;
    QString GetStr() const{return str;}

    Reel* ToReel();
    Rationnel* ToRationnel();
    Constante* ToDegre();
    Reel* ToEntier();

    Constante* Sin();
    Constante* Cos();
    Constante* Sqrt();
    Constante* Tan();
    Constante* Sinh();
    Constante* Cosh();
    Constante* Tanh();
    Constante* Ln();
    Constante* Log();
    Constante* Sign();
    Constante* Inv();
    Constante* Sqr();
    Constante* Cube();
    Constante* Fact();

    Constante* Multiple(Constante*);
    Constante* Sub(Constante*);
    Constante* Add(Constante*);
    Constante* Division(Constante*);
    Constante* Pow(Constante*);
    Constante* Modulo(Constante*);

    Nombre* CheckReOuRa(QString s);
    QString Eval(Pile* p,bool isDegre);
};

class Complexe:public Constante{
private:
    Nombre* re;
    Nombre* im;
public:
    Complexe(Nombre* r,Nombre* i):re(r),im(i){type=complexe;}
    Nombre* GetRe() {return re;}
    Nombre* GetIm() {return im;}
    bool IsEntier() const;
    QString Afficher() const;

    Reel* ToReel();
    Rationnel* ToRationnel();
    Constante* ToDegre();
    Reel* ToEntier();

    Constante* Sin();
    Constante* Cos();
    Constante* Tan();
    Constante* Sinh();
    Constante* Cosh();
    Constante* Tanh();
    Constante* Ln();
    Constante* Log();
    Constante* Sign();
    Constante* Inv();
    Constante* Sqr();
    Constante* Cube();
    Constante* Fact();

    Constante* Sqrt();

    Constante* Multiple(Constante*);
    Constante* Sub(Constante*);
    Constante* Add(Constante*);
    Constante* Division(Constante*);
    Constante* Pow(Constante*);
    Constante* Modulo(Constante*);

};


class Pile{
private:
    Constante** constants;
    int taille;
    int nb;
public:
    explicit Pile(int t=0):constants(new Constante*[t]),taille(t),nb(0){}//constants(new Constante*[t]),
    ~Pile();
    Pile(const Pile&);
    Pile& operator=(const Pile&);
    int GetTaille()const {return taille;}
    int GetNbConstants()const {return nb;}
    void SetNbConstants(int i){nb=i;}
    Constante* GetConstante(int i) const{if(i<0) throw LogMessage("Pas assez de element dans la pile.",3); return constants[i];}


    class Iterateur{
    private:
        Constante** constant;
    public:
        const Constante& operator*() const { return **constant; }
        bool operator!=(const Iterateur& it) { return constant!=it.constant; }
        bool operator==(const Iterateur& it) { return constant==it.constant; }
        Iterateur& operator++() { constant++;return *this; }
        Iterateur(Constante** p):constant(p){}
    };
    Iterateur Begin() const{return Iterateur(constants);}
    Iterateur End()const{return Iterateur(constants+nb);}
    Iterateur Index(int i){return Iterateur(constants+i);}
    void Swap(int x,int y);

    void Clear();
    void Dup();
    void Drop();

    void Sum();
    void Mean();

    void Enpiler(Constante& c);
    Constante* Depiler();
};


#endif // FONCTION_H
