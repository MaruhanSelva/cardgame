#ifndef SPELL
#define SPELL

#include "card.h"
#include <string>
#include <vector>

class Model;

class Spell: public Card {
    public:
        Spell(std::string name, int cost);
        ~Spell();

        void virtual use(Model *m, int playernum, int pos) = 0;
        virtual std::vector<std::string> getCardInfo() = 0;

        virtual void getAttacked(Card &v) = 0; // visitor
        virtual void attack(Card &v) = 0; // visitor
        virtual void attack(Player &p) = 0; // visitor

        virtual int getAtk() = 0; // decorator
        virtual int getDef() = 0; // decorator
        virtual void setAtk(int x) = 0;
        virtual void setDef(int x) = 0;

        virtual void setComponent(Card *c) = 0;
        virtual void removeComponent() = 0;
};


#endif