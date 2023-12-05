#ifndef MODIFIER
#define MODIFIER

#include "card.h"
#include <string>
#include <vector>

class Player;

class Modifier: public Card {
    protected:
        int valAtk;
        int valDef;
        bool mult1;
        bool mult2;
        Card *component; 
    public:
        Modifier(std::string name, int vA, int vD, bool m1, bool m2);
        virtual ~Modifier();

        virtual void use(Model *m, int player, int pos) = 0;
        virtual std::vector<std::string> getCardInfo() = 0;

        virtual void getAttacked(Card &v) = 0;
        virtual void attack(Card &v) = 0;
        virtual void attack(Player &p) = 0;

        virtual int getAtk() = 0;
        virtual int getDef() = 0;
        virtual void setAtk(int x) = 0;
        virtual void setDef(int x) = 0;

        virtual void setComponent(Card *c) = 0;
        virtual void removeComponent() = 0;
        

};


#endif