#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H

#include "expression.h"

// Messages
class LogMessage{
   private :
       string info;
       int degre; // degr� d'importance du message. 3 �tant le degr� le plus fort

   public:
       LogMessage(const string& i,int deg ):info(i),degre(deg){}
       const char* what() const{return info.c_str();}
       string getInfo()const{return info;}
       int getDegre()const{return degre;}
};

class LogSystem {
    private:
        LogMessage** pile_msg;

    public:
        LogSystem(LogMessage** pile):pile_msg(pile){}
};


#endif // LOGMESSAGE_H
