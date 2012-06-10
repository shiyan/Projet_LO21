#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H

#include "expression.h"

// Messages
class LogMessage{
   private :
       string info;
       int degre; // degré d'importance du message. 3 étant le degré le plus fort

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
