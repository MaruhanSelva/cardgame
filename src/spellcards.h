#ifndef SPELLCARDS
#define SPELLCARDS

#include "spell.h"
#include "spellfunctions.h"

class Model;

// this is a file for all of the spell cards that are in the game

class DestroyCard: public Spell {
    public:
        DestroyCard();
        ~DestroyCard();
        void use(Model *m, int playernum, int pos) override;
        std::vector<std::string> getCardInfo() override;

        void attack(Player &p) override;
        void attack(Card &c) override;
        void getAttacked(Card &v) override;

        int getAtk() override; // decorator
        int getDef() override; // decorator
        void setAtk(int x) override;
        void setDef(int x) override;

        void setComponent(Card *c) override;
        void removeComponent() override;
};


class SacrificialDrawCard: public Spell {
    public:
        SacrificialDrawCard();
        ~SacrificialDrawCard();
        void use(Model *m, int playernum, int pos) override;
        std::vector<std::string> getCardInfo() override;

        void attack(Player &p) override;
        void attack(Card &c) override;
        void getAttacked(Card &v) override;

        int getAtk() override; // decorator
        int getDef() override; // decorator
        void setAtk(int x) override;
        void setDef(int x) override;

        void setComponent(Card *c) override;
        void removeComponent() override;
};

class RecallCard: public Spell {
    public:
        RecallCard();
        ~RecallCard();
        void use(Model *m, int playernum, int pos) override;
        std::vector<std::string> getCardInfo() override;

        void attack(Player &p) override;
        void attack(Card &c) override;
        void getAttacked(Card &v) override;

        int getAtk() override; // decorator
        int getDef() override; // decorator
        void setAtk(int x) override;
        void setDef(int x) override;

        void setComponent(Card *c) override;
        void removeComponent() override;
};

class MMiracleCard: public Spell {
    public:
        MMiracleCard();
        ~MMiracleCard();
        void use(Model *m, int playernum, int pos) override;
        std::vector<std::string> getCardInfo() override;

        void attack(Player &p) override;
        void attack(Card &c) override;
        void getAttacked(Card &v) override;

        int getAtk() override; // decorator
        int getDef() override; // decorator
        void setAtk(int x) override;
        void setDef(int x) override;

        void setComponent(Card *c) override;
        void removeComponent() override;
};

class PotionCard: public Spell {
    public:
        PotionCard();
        ~PotionCard();
        void use(Model *m, int playernum, int pos) override;
        std::vector<std::string> getCardInfo() override;

        void attack(Player &p) override;
        void attack(Card &c) override;
        void getAttacked(Card &v) override;

        int getAtk() override; // decorator
        int getDef() override; // decorator
        void setAtk(int x) override;
        void setDef(int x) override;

        void setComponent(Card *c) override;
        void removeComponent() override;
};



#endif