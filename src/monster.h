#ifndef MONSTER
#define MONSTER

#include "card.h"
#include <string>
#include <vector>

class Player;
class Model;


class Monster: public Card {
    protected:
        int atk;
        int def;

    public:
        Monster(std::string name, int atk, int def);
        virtual ~Monster();

        virtual void getAttacked(Card &v) = 0; // visitor
        virtual void attack(Card &v) = 0; // visitor
        virtual void attack(Player &p) = 0; // visitor

        virtual int getAtk() = 0; // decorator
        virtual int getDef() = 0; // decorator
        virtual void setAtk(int x) = 0;
        virtual void setDef(int x) = 0;
        virtual void use(Model *m, int playernum, int pos) = 0; // decorator
        virtual std::vector<std::string> getCardInfo() = 0;

        virtual void setComponent(Card *c) = 0;
        virtual void removeComponent() = 0;

};



#endif