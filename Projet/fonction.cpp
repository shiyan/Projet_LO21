#include "fonction.h"

//TypeConstante Reel::GetType()const{return type;}
Reel::Reel(float f):reel(f){
    type=reelle;
    if(IsEntier()){type=entier;}
    if(reel<pow((float)10,-6)&&reel>-pow((float)10,-6))
        reel=0;
}
bool Reel::IsEntier() const{
    int partieEn=(int)reel;
    float partieRe=reel-float(partieEn);
    return partieRe==0;
}

Reel* Reel::ToReel(){ return this;}
QString Reel::Afficher() const{
    QString s;
    return s.setNum(reel);
}


Rationnel* Reel::ToRationnel(){
    return new Rationnel(reel*1000000,1000000);
}

Constante* Reel::ToDegre(){
    reel=Pi*reel/180;
    return this;
}

Constante* Reel::Sin(){ return new Reel(sin(reel));}
Constante* Reel::Sqrt(){
    if(reel<0)
        return new Complexe(new Reel(0),new Reel(sqrt(-reel)));
    return new Reel(sqrt(reel));
}


int Rationnel::Pgcd(int a, int b) const{
    if (a==0||b==0) return 0;
        if (a<0) a=-a;
        if (b<0) b=-b;
        while(a!=b){
            if (a>b) a=a-b; else b=b-a;
        }
        return a;
}
void Rationnel::Simplifier(){
    if (num==0) { den=1; return; }
    if (den==0) throw ConstanteException("Illegale de divese par 0;");
    int p=Pgcd(num,den);
    num/=p;
    den/=p;
    if (den<0) {
        den=-den;
        num=-num;
    }
    if(den==1)
        type=entier;
}

Reel* Rationnel::ToReel(){return new Reel((float)num/den);}

Rationnel* Rationnel::ToRationnel(){ return this;}

QString Rationnel::Afficher() const{
    QString s;
    QString ss;
    if(den!=1){
        return s.setNum(num)+"/"+ss.setNum(den);
    }
    return s.setNum(num);
}

//TypeConstante Complexe::GetType()const{return type;}

Reel* Complexe::ToReel(){return 0;}
Rationnel* Complexe::ToRationnel(){return 0;}
Constante* Complexe::ToDegre(){return 0;}

bool Complexe::IsEntier() const{ return (re->IsEntier()&&im->IsEntier());}

QString Complexe::Afficher() const{
    if((*im).ToReel()->GetReel()!=0)
        return re->Afficher()+"$"+im->Afficher();
    return re->Afficher();
}

/*Complexe* Complexe::ToReel(){
    return new Complexe(re->ToRationnel(),im->ToReel());
}

Rationnel* Complexe::ToRationnel(){}*/

Constante* Complexe::Sin(){throw ConstanteException("la parametre de Sin ne peut pas etre complexe;");}
Constante* Complexe::Sqrt(){throw ConstanteException("la parametre de Sqrt ne peut pas etre complexe;");}

Pile::~Pile(){
    for(int i=0;i<nb;i++)
        delete constants[i];
    delete[] constants;
}


bool Expression::IsEntier() const{return 0;}
QString Expression::Afficher() const{return str;}

Reel* Expression::ToReel(){return 0;}
Rationnel* Expression::ToRationnel(){return 0;}
Constante* Expression::ToDegre(){return 0;}

Constante* Expression::Sin(){return new Expression(str.remove(str.size()-1,1).append(" sin\'"));}
Constante* Expression::Sqrt(){return new Expression(str.remove(str.size()-1,1).append(" sqrt\'"));}

Nombre* Expression::CheckReOuRa(QString& sect){
    if(sect.contains(QRegExp("^-?[0-9]+\\.?[0-9]*$")))
        return new Reel(sect.toFloat());
    else if(sect.contains(QRegExp("^-?[0-9]+\\/-?[0-9]+$")))
        return new Rationnel(sect.section('/',0,0).toInt(),sect.section('/',1,1).toInt());
    else throw ConstanteException("Erreur.");
}

Constante* Expression::Eval(bool isDegre){
    Pile *p=new Pile(10);
    QString s=str.section('\'',1,1);
    QStringList list=s.split(" ",QString::SkipEmptyParts);
    try{
        for(int i=0;i<list.count();i++){
            QString sect=list.at(i);
            if(sect.contains(QRegExp("^-?[0-9]+\\.?[0-9]*$"))||sect.contains(QRegExp("^-?[0-9]+\\/-?[0-9]+$")))
                p->Enpiler(*(CheckReOuRa(sect)));
            else if(sect.contains(QRegExp("^-?[0-9]+(\\.|\\/-?)?[0-9]*\\$-?[0-9]+(\\.|\\/-?)?[0-9]*$"))){
                p->Enpiler(*(new Complexe(CheckReOuRa(sect.section('$',0,0)),CheckReOuRa(sect.section('$',1,1)))));
            }
            else if(_stricmp(sect.toStdString().c_str(),"sin")==0)
                isDegre==true?p->Enpiler(*(p->Depiler()->ToDegre()->Sin())):p->Enpiler(*(p->Depiler()->Sin()));
        }
        if(p->GetNbConstants()!=1)
            throw ConstanteException("Une erreur de la forme expression.");
        return p->Depiler();
    }
    catch(ConstanteException e){
        throw ConstanteException("Le expression ne peut pas etre evalue. Verifiez la forme.");
    }
}



Pile::Pile(const Pile& p):constants(new Constante*[p.taille]),taille(p.taille),nb(p.nb){
    for(int i=0;i<nb;i++)
        constants[i]=p.constants[i];
}

Pile& Pile::operator=(const Pile& p){
    if(this!=&p){
        delete[] constants;
        constants=new Constante*[p.taille];
        taille=p.taille;
        nb=p.nb;
        for(int i=0;i<nb;i++)
            constants[i]=p.constants[i];
    }
    return *this;
}

void Pile::Enpiler(Constante& c){
    if(this->nb==taille)
    {
        Constante** tmp=new Constante*[taille+10];
        for(int i=0;i<nb;i++)
            tmp[i]=constants[i];
        delete[] constants;
        constants=tmp;
        taille+=10;
    }
    constants[nb]=&c;
    nb++;
}

Constante* Pile::Depiler(){
    if(nb==0)
        throw ConstanteException("La pile est vide, impossible de depiler.");
    else{
        Constante* tmp=constants[nb-1];
        nb--;
        return tmp;
    }
}
//TypeConstante Constante::GetType(){return constant;}
//TypeConstante Test::GetType(){ return expression;}
/*TypeConstante Complexe::GetType(){return type;}

QString Complexe::Afficher() const{
    return "aaaaaaaaa";
}

Complexe* Complexe::operator =(Complexe* c){
    if(this!=c){
        re=c->re;
        im=c->im;
        type=c->type;
    }
    return this;
}

int Complexe::Pgcd(int a, int b) const{
    if (a==0||b==0) return 0;
        if (a<0) a=-a;
        if (b<0) b=-b;
        while(a!=b){
            if (a>b) a=a-b; else b=b-a;
        }
        return a;
}
QString Complexe::ToRationnelle(int precise){
    QString s;
    if(this->GetType()==rationnelle||this->GetType()==reelle){
        int pgcd=Pgcd(re*pow(float(10),precise),pow(float(10),precise));
        return s.setNum(re*pow(float(10),precise)/pgcd)+"/"+s.setNum(pow(float(10),precise)/pgcd);
    }
    if(this->GetType()==entier)
        return s.setNum(re);
    else{
        int pgcdRe=Pgcd(re*pow(float(10),precise),pow(float(10),precise));
        int pgcdIm=Pgcd(re*pow(float(10),precise),pow(float(10),precise));
        return s.setNum(re*pow(float(10),precise)/pgcdRe)+(pow(float(10),precise)/pgcdRe==1?"":("/"+s.setNum(pow(float(10),precise)/pgcdRe)))
                +s.setNum(re*pow(float(10),precise)/pgcdIm)+(pow(float(10),precise)/pgcdIm==1?"":("/"+s.setNum(pow(float(10),precise)/pgcdIm)));
    }

}

QString Complexe::ToReelle(){
    QString s;
    if(this->GetType()==rationnelle||this->GetType()==reelle){
        int partieEn=(int)re;
        float partieRe=re-float(partieEn);
        return s.setNum(partieEn)+","+s.setNum(partieRe);
    }
    if(this->GetType()==entier)
        return s.setNum(re);
    else{
        int partieEn=(int)re;
        float partieRe=re-float(partieEn);
        int partieEn2=(int)im;
        float partieRe2=im-float(partieEn2);
        return s.setNum(partieEn)+(partieRe==0?"":(","+s.setNum(partieRe)))
                +s.setNum(partieEn2)+(partieRe2==0?"":(","+s.setNum(partieRe2)));
    }
}

void Complexe::DetermineType(){
    if(this->GetIm()==0){
        int a=(int)re;
        float b=re-float(a);
        if(b==0)
            this->SetType(entier);
        else
            this->SetType(reelle);
    }
    else
        this->SetType(complexe);
}

Complexe* Complexe::operator+(Complexe* c){    
    this->SetRe(this->GetRe()+c->GetRe());
    this->SetIm(this->GetIm()+c->GetIm());
    DetermineType();
    return this;
}*/

/*Complexe* operator+(Complexe* c1,Complexe* c2){
    if(c1->GetType()!=entier||c2->GetType()!=entier){
        c1->SetRe(c1->GetRe()+c2->GetRe());
        c1->SetIm(c1->GetIm()+c2->GetIm());
        if(c1->GetIm()==0)
            c1->SetType(reelle);
        else
            c1->SetType(complexe);
    }
    else
    {
        c1->SetRe(c1->GetRe()+c2->GetRe());
        c1->SetIm(0);
        c1->SetType(entier);
    }
    return c1;
}*/

/*Pile::~Pile(){
    for(int i=0;i<nb;i++)
        delete constants[i];
    delete[] constants;
}

void Pile::Enpiler(Constante& c){
    if(this->nb==taille)
    {
        Constante** tmp=new Constante*[taille+10];
        for(int i=0;i<nb;i++)
            tmp[i]=constants[i];
        delete[] constants;
        constants=tmp;
        taille+=10;
    }
    constants[nb]=&c;
    nb++;
}*/

/*Constante* Pile::Dernier(){
    if(nb==0)
        throw PileException("La pile est vide.");
    else
        return constants[nb-1];
}*/

/*Constante* Pile::Depiler(){
    if(nb==0)
        throw PileException("La pile est vide, impossible de depiler.");
    else{
        Constante* tmp=constants[nb-1];
        nb--;
        return tmp;
    }
}

Pile::Pile(const Pile& p):constants(new Constante*[p.taille]),taille(p.taille),nb(p.nb){
    for(int i=0;i<nb;i++)
        constants[i]=p.constants[i];
}

Pile& Pile::operator=(const Pile& p){
    if(this!=&p){
        delete[] constants;
        constants=new Constante*[p.taille];
        taille=p.taille;
        nb=p.nb;
        for(int i=0;i<nb;i++)
            constants[i]=p.constants[i];
    }
    return *this;
}

Constante* Pile::operator[](int i){
    if(i>=0&&i<nb)
        return constants[i];
    else
        throw PileException("Argument est plus grand que la taille.");
}*/

/*void Pile::Swap(int x,int y){
    Constante* tmp=constants+x;
    constants[x]=constants[y];
    constants[y]=*tmp;

}

Constante Pile::Sum(int x){
    Constante somme=0;
    for(int i=1;i<=x;i++)
        somme+=constants[nb-i];       //TODO:exception
    return somme;
}

Constante Pile::Mean(int x){
    if(x>0)
        return Sum(x)/x;
    else
        //TODO:Exception
        ;
}*/
