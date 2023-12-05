#ifndef MODEL
#define MODEL

#include "player.h"
#include <string>
#include <vector>


class Model {
    Player* p1;
    Player* p2;
    int activePlayer;
    int turn; 

    public:
        Model(std::string n1, std::string n2);
        ~Model();

        std::vector<std::string> getPlayerInfo(int player); 

        void nextTurn();
        void attack(int i);
        void attack(int i, int j);
        void currentPlayer();
        int aPlayer();
        Player* getPlayer(int i);
        Player* getOpp(int i);

        void setUp(const std::string &deckname1, const std::string &deckname2, bool testing);

        void Play(int playernum, int handpos, int fieldpos);

        void draw(int player);
        void discard(int player, int handpos);

        void LoadDecks(const std::string &deckname1, const std::string &deckname2, bool testing);

        // updates the board after every action
        int checkStatus();

        // get a vector of strings for the minions of a player
        std::vector<std::vector<std::string>> getFieldInfo(int player);
        std::vector<std::vector<std::string>> getHandInfo(int player);
        std::vector<std::vector<std::string>> getGraveyardInfo(int player);
        

};



#endif