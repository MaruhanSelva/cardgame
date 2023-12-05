#ifndef MODIFIERC
#define MODIFIERC

#include <string>
#include "modifier.h"

class Model;

// Simple Modifier for attack and defence
class SimpleModifier: public Modifier {
    public:
        SimpleModifier(std::string name, int v1, int v2, bool m1, bool m2);
        ~SimpleModifier();

        void use(Model *m, int player, int pos) override;
        std::vector<std::string> getCardInfo() override;

        void getAttacked(Card &v) override;
        void attack(Card &v) override;
        void attack(Player &p) override;

        int getAtk() override;
        int getDef() override;
        void setAtk(int x) override;
        void setDef(int x) override;

        void setComponent(Card *c) override;
        void removeComponent() override;
};



#endif