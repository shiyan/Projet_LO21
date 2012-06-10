#include "mainwindow.h"

//Prototypes des fonctions outils (fonction.cpp)
 Rationnel* convertToRationnel(QString elt);

void Expression::Eval(Pile *pile_affichage, Pile *pile_stockage){

 //Découpage de l'espression en fonction des espaces
   QStringList list = this->str.split(" ",QString::SkipEmptyParts);

   try{
       for(int i=0; i<list.count(); i++){ //Parcours de l'expression

           QString elt = list.at(i);

         //Entier ou Réel
           if(elt.contains(QRegExp("^-?[0-9]+$")) || elt.contains(QRegExp("^-?[0-9]+\\.[0-9]+$"))){
               pile_affichage->Empiler(convertToRationnel(elt));
               pile_stockage->Empiler(convertToRationnel(elt));
           }
        //Rationnel
           else if(elt.contains(QRegExp("^-?[0-9]+(\\.[0-9]+)?/-?[0-9]+(\\.[0-9]+)?$"))){
               pile_affichage->Empiler(new Rationnel(elt.section('/',0,0).toInt(),elt.section('/',1,1).toInt()));
               pile_stockage->Empiler(new Rationnel(elt.section('/',0,0).toInt(),elt.section('/',1,1).toInt()));
           }
         //Complexe
           else if(elt.contains(QRegExp("^.+\\$.+$"))){
               pile_affichage->Empiler(new Complexe(convertToRationnel(elt.section('$',0,0)),convertToRationnel(elt.section('$',1,1))));
               pile_stockage->Empiler(new Complexe(convertToRationnel(elt.section('$',0,0)),convertToRationnel(elt.section('$',1,1))));
           }
         //Opérateur
           else if (elt.contains(QRegExp("^[+-/*]{1,1}$"))){
               if (elt == "+"){

               }
               else if (elt == "/"){

               }
               else if (elt == "-"){

               }
               else if (elt == "*"){
                 //  Constante* c = pile_affichage->Depiler()*pile_affichage->Depiler();
                 //  pile_affichage->Empiler(c);
               }
               pile_stockage->Empiler(new Expression(elt));
           }
         //Fonction
           else if (elt.contains(QRegExp("^[a-z]{2,4}$"))){
                Constante* c;
                if (elt == "Sin") c = pile_affichage->Depiler()->Sqr();

                pile_affichage->Empiler(c);
                pile_stockage->Empiler(new Expression(elt));
                pile_stockage->Empiler(c);
           }
           else
               throw LogMessage("La saisie est incorrecte.",0);
      }//fin for
   }
   catch( LogMessage e){
       throw LogMessage("Le expression ne peut pas etre evalue. Verifiez la forme.",3);
   }
}
