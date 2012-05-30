#ifndef FONCTION_H
#define FONCTION_H

#include <iostream>
#include <qmath.h>
#include <string>
#include <QString>
#include <QStringList>

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

class ConstanteException{
    std::string info;
public:
    ConstanteException(const std::string& i):info(i){}
    const char* what() const{return info.c_str();}
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

    virtual Constante* Sin()=0;
    virtual Constante* Sqrt()=0;

};

class Nombre:public Constante{
public:
    //virtual Reel* ToReel()=0;
    //virtual Rationnel* ToRationnel()=0;
    //virtual Constante* ToDegre()=0;
};

class Reel:public Nombre{
protected:
    float reel;
    //TypeConstante type;
public:
    Reel(float f);
    float GetReel() const{ return reel;}
   // TypeConstante GetType()const;
    bool IsEntier()const;
    QString Afficher() const;
    Reel* ToReel();
    Rationnel* ToRationnel();
    Constante* ToDegre();

    Constante* Sin();
    Constante* Sqrt();


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

    QString Afficher() const;
};

class Expression:public Constante{
private:
    QString str;
   // Constante* eval;
public:
    Expression(QString& s):str(s){type=expression; }
    bool IsEntier() const;
    QString Afficher() const;
    QString GetStr() const{return str;}

    Reel* ToReel();
    Rationnel* ToRationnel();
    Constante* ToDegre();

    Constante* Sin();
    Constante* Sqrt();

    Nombre* CheckReOuRa(QString& s);
    Constante* Eval(bool isDegre);
};

class Complexe:public Constante{
private:
    Nombre* re;
    Nombre* im;
    //TypeConstante type;
public:
    Complexe(Nombre* r,Nombre* i):re(r),im(i){type=complexe;}
   // TypeConstante GetType()const;
    Nombre* GetRe() const{return re;}
    Nombre* GetIm() const{return im;}
    bool IsEntier() const;
    QString Afficher() const;

    Reel* ToReel();
    Rationnel* ToRationnel();
    Constante* ToDegre();

    Constante* Sin();
    Constante* Sqrt();

};

class Operateur{
public:
   // Constante* Plus(C)
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
    Constante* GetConstante(int i) const{return constants[i];}
    //void SetConstante(int i,Constante* c){constants[i]=c;}

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
    //void Swap(int x,int y);
    //Constante* Sum(int x=2);
    //Constante* Mean(int x=2);
    //void Clear();
    //void Dup();
    //void Drop();

    void Enpiler(Constante& c);
    Constante* Depiler();
};
/*class Constante;
class Complexe;
class Expression;
class Operation;
class Pile;

enum TypeConstante{entier,rationnelle,reelle,complexe,expression};

class Constante{
public:
    virtual TypeConstante GetType()=0;
    virtual QString Afficher() const=0;
};

class Complexe:public Constante{
private:
    float re;
    float im;
    TypeConstante type;
public:
    Complexe(float r=0,float i=0):re(r),im(i){DetermineType();}
    float GetRe() const{return re;}
    float GetIm() const{return im;}
    void SetRe(float f){re=f;}
    void SetIm(float f){im=f;}
    void SetType(TypeConstante t){type=t;}
    Complexe* operator =(Complexe*);

    int Pgcd(int a, int b) const;
    void DetermineType();
    QString ToRationnelle(int precise);
    QString ToReelle();
    TypeConstante GetType();
    QString Afficher() const;

    Complexe* operator+(Complexe* c);

};
class Test:public Complexe{
public:
    Test(float r=0,float i=0):Complexe(r,i){}
};

class Expression:public Constante{


};

class Operation{
public:
    //Complexe* operator+(Complexe* c1,Complexe* c2);
};

class PileException{
private:
    std::string info;
public:
    PileException(const std::string& i):info(i){}
    const char* what() const{return info.c_str();}
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

   // void Afficher(std::ostream& f=std::cout, int x=6) const;

            class Iterateur{
        private:
            Constante* constant;
        public:
            const Constante& operator*() const { return *constant; }
            bool operator!=(const Iterateur& it) { return constant!=it.constant; }
            bool operator==(const Iterateur& it) { return constant==it.constant; }
            void operator++() { ++constant; }
           // Iterateur(const Constante* p):constant(p){}
    };

    void Swap(int x,int y);
    Constante* Sum(int x=2);
    Constante* Mean(int x=2);
    void Clear();
    void Dup();
    void Drop();

    void Enpiler(Constante& c);
 //   Constante* Dernier();
    Constante* Depiler();
    Constante* operator[](int i);


};*/

#endif // FONCTION_H
