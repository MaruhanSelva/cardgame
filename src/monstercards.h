 #ifndef MONSTERC
#define MONSTERC

#include "monster.h"
#include <string>

class Model;
class Player;

// Holds classes for Concrete Monster Classes

class SimpleMonster: public Monster {
    public:
        SimpleMonster(std::string name, int atk, int def);
        ~SimpleMonster();

        void use(Model *m, int playernum, int pos) override; // decorator
        std::vector<std::string> getCardInfo() override;

        void getAttacked(Card &v) override; // visitor
        void attack(Card &v) override; // visitor
        void attack(Player &p) override; // visitor

        int getAtk() override; // decorator
        int getDef() override; // decorator
        void setAtk(int x) override;
        void setDef(int x) override;
        
        void setComponent(Card *c) override;
        void removeComponent() override;

};



#endif