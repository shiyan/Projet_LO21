#include "pile.h"

//Rajoute un �l�ment dans la pile
void Pile::Empiler(Constante& c){
    if(nbElt==taille_max) // Si la pile est pleine, augmentation de sa taille
    {
        Constante** tmp = new Constante*[taille_max+=10];
        for(int i=0; i<nbElt; i++)
            tmp[i] = ptr_pile[i];
        delete[] ptr_pile;
        ptr_pile = tmp;
    }
    ptr_pile[nbElt]=&c; //Insertion dans la pile
    nbElt++; //Incr�mentation du nombre d'�l�ment dans la pile
}

//Supprime un �l�ment de la pile
Constante* Pile::Depiler(){
    if(nb==0)
        throw LogMessage("Impossible de depiler: La pile est vide !");
    else{
        Constante* tmp = ptr_pile[nbElt-1];
        delete ptr_pile[nbElt-1];
        nbElt--;
        return tmp;
    }
}
