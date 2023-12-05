#ifndef VISITOR
#define VISITOR

#include <string>

#include "card.h"

class Player;


class Visitor: public Card {
    public: 
        Visitor(std::string name);
        virtual ~Visitor();

        virtual void getAttacked(Visitor &v) = 0;
        virtual void attack(Visitor &v) = 0;
        virtual void attack(Player &p) = 0;

        virtual int getAtk() = 0; // decorator
        virtual int getDef() = 0; // decorator
        virtual void setAtk(int x) = 0;
        virtual void setDef(int x) = 0;
        virtual void use(Model *m, int playernum, int pos) = 0;

};


#endif