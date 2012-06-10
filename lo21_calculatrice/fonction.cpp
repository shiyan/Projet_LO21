#include "mainwindow.h"


//!fonction.cpp, contient les fonctions annexes n'appartenant pas à une classe

Rationnel* convertToRationnel(QString elt){

    if(elt.contains(QRegExp("^-?[0-9]+$")))
        return (new Rationnel(elt.toInt(),1));

    else if (elt.contains(QRegExp("^-?[0-9]+\\.[0-9]+$"))){
        int tmp = elt.toFloat();
        int den=1;
        while((tmp - floor(tmp)) != 0){
            tmp *=10;
            den *=10;
        }
        return (new Rationnel(tmp, den));
    }
}
