#include "fonction.h"

QFile LogSystem::file("E:\\Qt\\Calculatrice\\LogMessage.txt");
//TypeConstante Reel::GetType()const{return type;}
Reel::Reel(float f):reel(f){
    type=reelle;
    if(reel<pow((float)10,-6)&&reel>-pow((float)10,-6))
        reel=0;
    if(IsEntier()){type=entier;}
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
    float re=Pi*reel/180;
    return new Reel(re);
}

Reel* Reel::ToEntier(){
    return new Reel(int(reel));
}


Constante* Reel::Sin(){ return new Reel(sin(reel));}
Constante* Reel::Cos(){ return new Reel(cos(reel));}
Constante* Reel::Tan(){ return new Reel(tan(reel));}
Constante* Reel::Sinh(){return new Reel(sinh(reel));}
Constante* Reel::Cosh(){return new Reel(cosh(reel));}
Constante* Reel::Tanh(){return new Reel(tanh(reel));}
Constante* Reel::Ln(){return new Reel(log(reel));}
Constante* Reel::Log(){return new Reel(log10(reel));}
Constante* Reel::Sign(){return new Reel(0-reel);}
Constante* Reel::Inv(){return new Reel(1/reel);}
Constante* Reel::Sqr(){return new Reel(pow(reel,2));}
Constante* Reel::Cube(){return new Reel(pow(reel,3));}
Constante* Reel::Fact(){
    if(this->GetType()==entier){
        int f=int(reel);
        for(int i=int(reel)-1;i>0;i--)
            f=f*i;
        return new Reel(f);
    }
    else
        throw LogMessage("Il n y a pas de factorialle pour les nombre non entier.",2);
}

Constante* Reel::Sqrt(){
    if(reel<0)
        return new Complexe(new Reel(0),new Reel(sqrt(-reel)));
    return new Reel(sqrt(reel));
}

Constante* Reel::Multiple(Constante* c){
    if(c->GetType()==reelle||c->GetType()==entier)
        return new Reel(reel*(dynamic_cast<Reel*>(c)->GetReel()));
    if(c->GetType()==rationnelle){
        Rationnel* r=this->ToRationnel();
        return r->Multiple(dynamic_cast<Rationnel*>(c));
    }
    if(c->GetType()==complexe){
        Complexe* co=dynamic_cast<Complexe*>(c);
        return new Complexe(dynamic_cast<Nombre*>(this->Multiple(co->GetRe())),dynamic_cast<Nombre*>(this->Multiple(co->GetIm())));
    }
    else
        return dynamic_cast<Expression*>(c)->Multiple(this);
}

Constante* Reel::Sub(Constante* c){
    if(c->GetType()==reelle||c->GetType()==entier)
        return new Reel(reel-(dynamic_cast<Reel*>(c)->GetReel()));
    if(c->GetType()==rationnelle){
        Rationnel* r=this->ToRationnel();
        return r->Sub(dynamic_cast<Rationnel*>(c));
    }
    if(c->GetType()==complexe){
        Complexe* co=dynamic_cast<Complexe*>(c);
        return new Complexe(dynamic_cast<Nombre*>(this->Sub(co->GetRe())),dynamic_cast<Nombre*>(co->GetIm()->Sign()));
    }
    else
        return dynamic_cast<Expression*>(c)->Sub(this);
}

Constante* Reel::Add(Constante* c){
    if(c->GetType()==reelle||c->GetType()==entier)
        return new Reel(reel+(dynamic_cast<Reel*>(c)->GetReel()));
    if(c->GetType()==rationnelle){
        Rationnel* r=this->ToRationnel();
        return r->Add(dynamic_cast<Rationnel*>(c));
    }
    if(c->GetType()==complexe){
        Complexe* co=dynamic_cast<Complexe*>(c);
        return new Complexe(dynamic_cast<Nombre*>(this->Add(co->GetRe())),co->GetIm());
    }
    else
        return dynamic_cast<Expression*>(c)->Add(this);
}

Constante* Reel::Division(Constante* c){
    if(c->GetType()==reelle||c->GetType()==entier)
        return new Reel(reel/(dynamic_cast<Reel*>(c)->GetReel()));
    if(c->GetType()==rationnelle){
        Rationnel* r=this->ToRationnel();
        return r->Division(dynamic_cast<Rationnel*>(c));
    }
    if(c->GetType()==complexe){
        Complexe* co=dynamic_cast<Complexe*>(c);
        Constante* d=co->GetRe()->Multiple(co->GetRe())->Add(co->GetIm()->Multiple(co->GetIm()));
       // float d=pow(dynamic_cast<Reel*>(co->GetRe())->GetReel(),2)+pow(dynamic_cast<Reel*>(co->GetIm())->GetReel(),2);
        return new Complexe(dynamic_cast<Nombre*>(this->Multiple(co->GetRe())->Division(d)),dynamic_cast<Nombre*>(this->Multiple(co->GetIm())->Sign()->Division(d)));
    }
    else
        return dynamic_cast<Expression*>(c)->Division(this);
}

Constante* Reel::Pow(Constante* c){
    if(c->GetType()==complexe)
        throw LogMessage("les parametres de Pow ne peut pas etre complexe;",2);
    if(c->GetType()==expression)
        return c->Pow(this);
    return new Reel(pow(reel,dynamic_cast<Reel*>(c)->GetReel()));
}

Constante* Reel::Modulo(Constante* c){
    if(this->GetType()==entier&&c->GetType()==entier)
        return new Reel(int(reel)/int(dynamic_cast<Reel*>(c)->GetReel()));
    else
        throw LogMessage("Modulo est utilise pour les entier",2);
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
    if (den==0) throw LogMessage("Illegale de divese par 0;",3);
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

Constante* Rationnel::Sign(){return new Rationnel(0-num,den);}
Constante* Rationnel::Inv(){return new Rationnel(den,num);}
Constante* Rationnel::Sqr(){return new Rationnel(pow(float(num),2),pow(float(den),2));}
Constante* Rationnel::Cube(){return new Rationnel(pow(float(num),3),pow(float(den),3));}

Constante* Rationnel::Multiple(Constante* c){
    if(c->GetType()==reelle||c->GetType()==entier)
        return dynamic_cast<Reel*>(c)->Multiple(this);
    if(c->GetType()==rationnelle){
        Rationnel* r=dynamic_cast<Rationnel*>(c);
        return new Rationnel(num*r->num,den*r->den);
    }
    if(c->GetType()==complexe){
        Complexe* co=dynamic_cast<Complexe*>(c);
        return new Complexe(dynamic_cast<Nombre*>(this->Multiple(co->GetRe())),dynamic_cast<Nombre*>(this->Multiple(co->GetIm())));
    }
    else
        return dynamic_cast<Expression*>(c)->Multiple(this);
}

Constante* Rationnel::Sub(Constante* c){
    if(c->GetType()==reelle||c->GetType()==entier)
        return dynamic_cast<Reel*>(c)->Sub(this);
    if(c->GetType()==rationnelle){
        Rationnel* r=dynamic_cast<Rationnel*>(c);
        return new Rationnel(num*r->den-r->num*den,den*r->den);
    }
    if(c->GetType()==complexe){
        Complexe* co=dynamic_cast<Complexe*>(c);
        return new Complexe(dynamic_cast<Nombre*>(this->Sub(co->GetRe())),dynamic_cast<Nombre*>(co->Sign()));
    }
    else
        return dynamic_cast<Expression*>(c)->Sub(this);
}
Constante* Rationnel::Add(Constante* c){
    if(c->GetType()==reelle||c->GetType()==entier)
        return dynamic_cast<Reel*>(c)->Add(this);
    if(c->GetType()==rationnelle){
        Rationnel* r=dynamic_cast<Rationnel*>(c);
        return new Rationnel(num*r->den+r->num*den,den*r->den);
    }
    if(c->GetType()==complexe){
        Complexe* co=dynamic_cast<Complexe*>(c);
        return new Complexe(dynamic_cast<Nombre*>(this->Add(co->GetRe())),dynamic_cast<Nombre*>(this->Add(co->GetIm())));
    }
    else
        return dynamic_cast<Expression*>(c)->Add(this);
}

Constante* Rationnel::Division(Constante* c){
    if(c->GetType()==reelle||c->GetType()==entier)
        return dynamic_cast<Reel*>(c)->Division(this);
    if(c->GetType()==rationnelle){
        Rationnel* r=dynamic_cast<Rationnel*>(c);
        return new Rationnel(num*r->den,den*r->num);
    }
    if(c->GetType()==complexe){
        Complexe* co=dynamic_cast<Complexe*>(c);
        Constante* d=co->GetRe()->Multiple(co->GetRe())->Add(co->GetIm()->Multiple(co->GetIm()));
        return new Complexe(dynamic_cast<Nombre*>(this->Multiple(co->GetRe())->Division(d)),dynamic_cast<Nombre*>(this->Multiple(co->GetIm())->Sign()->Division(d)));
    }
    else
        return dynamic_cast<Expression*>(c)->Division(this);
}
QString Rationnel::Afficher() const{
    QString s;
    QString ss;
    if(den!=1){
        return s.setNum(num)+"/"+ss.setNum(den);
    }
    return s.setNum(num);
}



Reel* Complexe::ToReel(){return 0;}
Rationnel* Complexe::ToRationnel(){return 0;}
Constante* Complexe::ToDegre(){return 0;}
Reel* Complexe::ToEntier(){return 0;}

bool Complexe::IsEntier() const{ return (re->IsEntier()&&im->IsEntier());}

QString Complexe::Afficher() const{
    if((*im).ToReel()->GetReel()!=0)
        return re->Afficher()+"$"+im->Afficher();
    return re->Afficher();
}



Constante* Complexe::Sin(){throw LogMessage("la parametre de Sin ne peut pas etre complexe;",2);}
Constante* Complexe::Cos(){throw LogMessage("la parametre de Cos ne peut pas etre complexe;",2);}
Constante* Complexe::Tan(){ throw LogMessage("la parametre de Tan ne peut pas etre complexe;",2);}
Constante* Complexe::Sinh(){throw LogMessage("la parametre de Sinh ne peut pas etre complexe;",2);}
Constante* Complexe::Cosh(){throw LogMessage("la parametre de Cosh ne peut pas etre complexe;",2);}
Constante* Complexe::Tanh(){throw LogMessage("la parametre de Tanh ne peut pas etre complexe;",2);}
Constante* Complexe::Ln(){throw LogMessage("la parametre de Ln ne peut pas etre complexe;",2);}
Constante* Complexe::Log(){throw LogMessage("la parametre de Log ne peut pas etre complexe;",2);}
Constante* Complexe::Sign(){return new Complexe(dynamic_cast<Nombre*>(re->Sign()),im);}
Constante* Complexe::Inv(){throw LogMessage("la parametre de Inv ne peut pas etre complexe;",2);}
Constante* Complexe::Sqr(){return this->Multiple(this);}
Constante* Complexe::Cube(){return this->Multiple(this)->Multiple(this);}
Constante* Complexe::Fact(){throw LogMessage("la parametre de factorielle ne peut pas etre complexe;",2);}

Constante* Complexe::Sqrt(){throw LogMessage("la parametre de Sqrt ne peut pas etre complexe;",2);}

Constante* Complexe::Multiple(Constante* c){
    if(c->GetType()==reelle||c->GetType()==entier)
        return dynamic_cast<Reel*>(c)->Multiple(this);
    if(c->GetType()==rationnelle){
        Rationnel* r=dynamic_cast<Rationnel*>(c);
        return r->Multiple(this);
    }
    if(c->GetType()==complexe){
        Complexe* co=dynamic_cast<Complexe*>(c);
        Constante* nre=re->Multiple(co->re)->Sub(im->Multiple(co->im));
        Constante* nim=re->Multiple(co->im)->Add(im->Multiple(co->re));
        return new Complexe(dynamic_cast<Nombre*>(nre),dynamic_cast<Nombre*>(nim));
    }
    else
        return dynamic_cast<Expression*>(c)->Multiple(this);

}

Constante* Complexe::Sub(Constante* c){
    if(c->GetType()==reelle||c->GetType()==entier||c->GetType()==rationnelle){
        //Reel* r=dynamic_cast<Reel*>(c);
        return new Complexe(dynamic_cast<Nombre*>(this->GetRe()->Sub(c)),this->GetIm());
    }
    if(c->GetType()==complexe){
        Complexe* co=dynamic_cast<Complexe*>(c);
        return new Complexe(dynamic_cast<Nombre*>(re->Sub(co->GetRe())),dynamic_cast<Nombre*>(im->Sub(co->GetIm())));
    }
    else
        return dynamic_cast<Expression*>(c)->Sub(this);
}

Constante* Complexe::Add(Constante* c){
    if(c->GetType()==reelle||c->GetType()==entier)
        return dynamic_cast<Reel*>(c)->Add(this);
    if(c->GetType()==rationnelle){
        Rationnel* r=dynamic_cast<Rationnel*>(c);
        return r->Add(this);
    }
    if(c->GetType()==complexe){
        Complexe* co=dynamic_cast<Complexe*>(c);
        return new Complexe(dynamic_cast<Nombre*>(re->Add(co->GetRe())),dynamic_cast<Nombre*>(im->Add(co->GetIm())));
    }
    else
        return dynamic_cast<Expression*>(c)->Add(this);

}

Constante* Complexe::Division(Constante* c){
    if(c->GetType()==reelle||c->GetType()==entier||c->GetType()==rationnelle){
        //Complexe* co=dynamic_cast<Complexe*>(c);
        Constante* d=c->Multiple(c);
        return new Complexe(dynamic_cast<Nombre*>(this->re->Multiple(c)->Division(d)),dynamic_cast<Nombre*>(this->im->Multiple(c)->Division(d)));
         }
    if(c->GetType()==complexe){
        Complexe* co=dynamic_cast<Complexe*>(c);
        Constante* d=co->re->Multiple(co->re)->Add(co->im->Multiple(co->im));
        return new Complexe(dynamic_cast<Nombre*>(re->Multiple(co->re)->Add(im->Multiple(co->im))->Division(d)),dynamic_cast<Nombre*>(im->Multiple(co->re)->Sub(re->Multiple(co->im))->Division(d)));
    }
    else
        return dynamic_cast<Expression*>(c)->Division(this);
}

Constante* Complexe::Pow(Constante* c){
        throw LogMessage("les parametres de Pow ne peut pas etre complexe;",2);
}
Constante* Complexe::Modulo(Constante *c){
    throw LogMessage("Modulo est utilise pour les entier",2);
}

bool Expression::IsEntier() const{return 0;}
QString Expression::Afficher() const{return str;}

Reel* Expression::ToReel(){return 0;}
Reel* Expression::ToEntier(){return 0;}
Rationnel* Expression::ToRationnel(){return 0;}
Constante* Expression::ToDegre(){return 0;}

Constante* Expression::Sin(){return new Expression(str.remove(str.size()-1,1).append(" sin\'"));}
Constante* Expression::Cos(){return new Expression(str.remove(str.size()-1,1).append(" cos\'"));}
Constante* Expression::Tan(){ return new Expression(str.remove(str.size()-1,1).append(" tan\'"));}
Constante* Expression::Sinh(){return new Expression(str.remove(str.size()-1,1).append(" sinh\'"));}
Constante* Expression::Cosh(){return new Expression(str.remove(str.size()-1,1).append(" cosh\'"));}
Constante* Expression::Tanh(){return new Expression(str.remove(str.size()-1,1).append(" tanh\'"));}
Constante* Expression::Ln(){return new Expression(str.remove(str.size()-1,1).append(" ln\'"));}
Constante* Expression::Log(){return new Expression(str.remove(str.size()-1,1).append(" log\'"));}
Constante* Expression::Sign(){return new Expression(str.remove(str.size()-1,1).append(" sign\'"));}
Constante* Expression::Inv(){return new Expression(str.remove(str.size()-1,1).append(" inv\'"));}
Constante* Expression::Sqr(){return new Expression(str.remove(str.size()-1,1).append(" sqr\'"));}
Constante* Expression::Cube(){return new Expression(str.remove(str.size()-1,1).append(" cube\'"));}
Constante* Expression::Fact(){return new Expression(str.remove(str.size()-1,1).append(" !\'"));}

Constante* Expression::Sqrt(){return new Expression(str.remove(str.size()-1,1).append(" sqrt\'"));}

Constante* Expression::Multiple(Constante* c){
        QString s=str;
        s.insert(1,c->Afficher()+" ");
        s.remove(s.size()-1,1).append(" *\'");
        return new Expression(s);
}

Constante* Expression::Sub(Constante* c){
        QString s=str;
        s.insert(1,c->Afficher()+" ");
        s.remove(s.size()-1,1).append(" -\'");
        return new Expression(s);
}

Constante* Expression::Add(Constante* c){
        QString s=str;
        s.insert(1,c->Afficher()+" ");
        s.remove(s.size()-1,1).append(" +\'");
        return new Expression(s);
}
Constante* Expression::Division(Constante* c){
        QString s=str;
        s.insert(1,c->Afficher()+" ");
        s.remove(s.size()-1,1).append(" /\'");
        return new Expression(s);
}

Constante* Expression::Pow(Constante* c){
    QString s=str;
    s.insert(1,c->Afficher()+" ");
    s.remove(s.size()-1,1).append(" pow\'");
    return new Expression(s);
}

Constante* Expression::Modulo(Constante* c){
    QString s=str;
    s.insert(1,c->Afficher()+" ");
    s.remove(s.size()-1,1).append(" modulo\'");
    return new Expression(s);
}
Nombre* Expression::CheckReOuRa(QString sect){
    if(sect.contains(QRegExp("^-?[0-9]+\\.?[0-9]*$")))
        return new Reel(sect.toFloat());
    else if(sect.contains(QRegExp("^-?[0-9]+\\/-?[0-9]+$")))
        return new Rationnel(sect.section('/',0,0).toInt(),sect.section('/',1,1).toInt());
    else throw LogMessage("Erreur.",3);
}

QString Expression::Eval(Pile* p,bool isDegre){
    QString s=str.section('\'',1,1);
    QString ret=s;
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
            else if(_stricmp(sect.toStdString().c_str(),"cos")==0)
                isDegre==true?p->Enpiler(*(p->Depiler()->ToDegre()->Cos())):p->Enpiler(*(p->Depiler()->Cos()));
            else if(_stricmp(sect.toStdString().c_str(),"tan")==0)
                isDegre==true?p->Enpiler(*(p->Depiler()->ToDegre()->Tan())):p->Enpiler(*(p->Depiler()->Tan()));
            else if(_stricmp(sect.toStdString().c_str(),"sinh")==0)
                isDegre==true?p->Enpiler(*(p->Depiler()->ToDegre()->Sinh())):p->Enpiler(*(p->Depiler()->Sinh()));
            else if(_stricmp(sect.toStdString().c_str(),"cosh")==0)
                isDegre==true?p->Enpiler(*(p->Depiler()->ToDegre()->Cosh())):p->Enpiler(*(p->Depiler()->Cosh()));
            else if(_stricmp(sect.toStdString().c_str(),"tanh")==0)
                isDegre==true?p->Enpiler(*(p->Depiler()->ToDegre()->Tanh())):p->Enpiler(*(p->Depiler()->Tanh()));
            else if(_stricmp(sect.toStdString().c_str(),"ln")==0)
                p->Enpiler(*(p->Depiler()->Ln()));
            else if(_stricmp(sect.toStdString().c_str(),"log")==0)
                p->Enpiler(*(p->Depiler()->Log()));
            else if(_stricmp(sect.toStdString().c_str(),"sign")==0)
                p->Enpiler(*(p->Depiler()->Sign()));
            else if(_stricmp(sect.toStdString().c_str(),"inv")==0)
                p->Enpiler(*(p->Depiler()->Inv()));
            else if(_stricmp(sect.toStdString().c_str(),"sqr")==0)
                p->Enpiler(*(p->Depiler()->Sqr()));
            else if(_stricmp(sect.toStdString().c_str(),"cube")==0)
                p->Enpiler(*(p->Depiler()->Cube()));
            else if(sect.contains(QRegExp("^\\!$")))
                p->Enpiler(*(p->Depiler()->Fact()));
            else if(_stricmp(sect.toStdString().c_str(),"sqrt")==0)
                p->Enpiler(*(p->Depiler()->Sqrt()));
            else if(_stricmp(sect.toStdString().c_str(),"+")==0){
                Constante* p2=p->Depiler();
                Constante* p1=p->Depiler();
                p->Enpiler(*(p1->Add(p2)));
            }
            else if(_stricmp(sect.toStdString().c_str(),"-")==0){
                Constante* p2=p->Depiler();
                Constante* p1=p->Depiler();
                p->Enpiler(*(p1->Sub(p2)));
            }
            else if(_stricmp(sect.toStdString().c_str(),"*")==0){
                Constante* p2=p->Depiler();
                Constante* p1=p->Depiler();
                p->Enpiler(*(p1->Multiple(p2)));
            }
            else if(_stricmp(sect.toStdString().c_str(),"/")==0){
                Constante* p2=p->Depiler();
                Constante* p1=p->Depiler();
                p->Enpiler(*(p1->Division(p2)));
            }
            else if(_stricmp(sect.toStdString().c_str(),"pow")==0){
                Constante* p2=p->Depiler();
                Constante* p1=p->Depiler();
                p->Enpiler(*(p1->Pow(p2)));
            }
            else if(_stricmp(sect.toStdString().c_str(),"modulo")==0){
                Constante* p2=p->Depiler();
                Constante* p1=p->Depiler();
                p->Enpiler(*(p1->Modulo(p2)));
            }
            if(i<list.count()-1)
                ret=s.section('&',i+1,list.count()-1);
        }
        ret="";
       // if(p->GetNbConstants()!=1)
       //     throw ConstanteException("Une erreur de la forme expression.");
        return ret;
    }
    catch(LogMessage e){
        return ret;
       // throw ConstanteException("Le expression ne peut pas etre evalue. Verifiez la forme.");
    }
}


Pile::~Pile(){
    for(int i=0;i<nb;i++)
        delete constants[i];
    delete[] constants;
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
        throw LogMessage("La pile est vide, impossible de depiler.",3);
    else{
        Constante* tmp=constants[nb-1];
        nb--;
        return tmp;
    }
}

void Pile::Swap(int x,int y){
    if(x>0&&x<=nb&&y>0&&y<=nb){
        Constante* tmp;
        tmp=constants[x-1];
        constants[x-1]=constants[y-1];
        constants[y-1]=tmp;
    }
    else
        throw LogMessage("Index not in range.",3);
}

void Pile::Clear(){
    for(int i=0;i<nb;i++)
        delete constants[i];
    nb=0;
}

void Pile::Dup(){
    this->Enpiler(*(this->GetConstante(nb-1)));
}

void Pile::Drop(){
    this->Depiler();
}

void Pile::Sum(){
    Constante* depile=this->Depiler();
    if(depile->GetType()!=entier)
        throw LogMessage("le operande n est pas de type entier",2);
    int i=int(dynamic_cast<Reel*>(depile)->GetReel());
    if(nb<i)
        throw LogMessage("Pas assez element dans la pile",3);

    if(i<=1)
        return;
    Constante* sum=Depiler();
    for(int j=2;j<=i;j++)
        sum=sum->Add(Depiler());
    Enpiler(*sum);
}

void Pile::Mean(){
    Constante* numero=this->GetConstante(nb-1);
    Sum();
    Enpiler(*(Depiler()->Division(numero)));
}

