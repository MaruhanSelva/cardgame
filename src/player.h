#ifndef PLAYER
#define PLAYER

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "card.h"


class Player {
    protected:
        std::string name;
        int hp;
        int mp;
        std::vector<Card *> hand;
        std::vector<Card *> field;
        std::vector<Card *> graveyard;
        std::vector<Card *> deck;

    public:
        Player(std::string name);
        ~Player();

        std::vector<std::string> printPlayer();

        void setHP(int x);
        void setMP(int x);
        int getHP();
        int getMP();

        void addCard(Card *x);
        void removeCard(int i);
        void sendToGraveyard(int i);

        void attack(int i, Player &p);
        void attack(int i, int j, Player &p);

        void getAttacked(int j, Card &m);

        void summon(int i);
        void unsummon(int i);
        void draw();
        void discard(int i);

        void revive();

        void loadDeck(const std::string &deckname, bool testing);
        bool checkStatus();

        void play(Model *m, int playernum, int handpos, int fieldpos);

        // used to add/subtract to hp/attk
        void editCard(int i, bool hp, int val);

        // testing purposes
        void addToField(Card *c);
        std::vector<std::vector<std::string>> getGraveyardInfo();
        std::vector<std::vector<std::string>> getFieldInfo();
        std::vector<std::vector<std::string>> getDeckInfo();
        std::vector<std::vector<std::string>> getHandInfo();


};





#endif