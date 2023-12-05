#ifndef CARD
#define CARD

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

class Model;
class Player;

class Card {
    protected:
        std::string name;
        int cost;
        // Type can be: M - Monster, S - Spell, E - Modifier/Enhancement
        std::string type;

    public:
        Card(std::string name, std::string type);
        virtual ~Card();

        virtual std::vector<std::string> getCardInfo() = 0;
        virtual void use(Model *m, int playernum, int pos) = 0;

        std::string getType();
        int getCost();


        // Monster Card Virtual Methods
        virtual void attack(Player &p) = 0;
        virtual void attack(Card &c) = 0;
        virtual void getAttacked(Card &v) = 0;

        virtual int getAtk() = 0; 
        virtual int getDef() = 0; 
        virtual void setAtk(int x) = 0;
        virtual void setDef(int x) = 0;

        // Enchantment Virtual Methods
        virtual void setComponent(Card *c) = 0;
        virtual void removeComponent() = 0;



};





#endif