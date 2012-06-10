#ifndef PILE_H
#define PILE_H

#include "constante.h"

class Pile{

    private:
        Constante** ptr_pile; // Pointeur sur une liste de constante
        int taille_max;  // Taille maximale de la pile
        int nbElt; // Nombre d'éléments dans la pile

    public:
        explicit Pile(int t=10):ptr_pile(new Constante*[t]),taille_max(t),nbElt(0){}//ptr_pile(new Constante*[t]),
        ~Pile();
        Pile(const Pile&);
        Pile& operator=(const Pile&);

        int GetTaille()const {return taille_max;}
        int GetNb()const {return nbElt;}

        Constante* GetConstante(int i) const{return ptr_pile[i];}
        //void SetConstante(int i,Constante* c){ptr_pile[i]=c;}

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
        Iterateur Begin() const{return Iterateur(ptr_pile);}
        Iterateur End()const{return Iterateur(ptr_pile+nbElt);}
        Iterateur Index(int i){return Iterateur(ptr_pile+i);}
        //void Swap(int x,int y);
        //Constante* Sum(int x=2);
        //Constante* Mean(int x=2);
        //void Clear();
        //void Dup();
        //void Drop();

        void Empiler(Constante& c);
        Constante* Depiler();
};

#endif // PILE_H
