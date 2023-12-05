#include "model.h"

using namespace std;

Model::Model(string n1, string n2): p1(new Player(n1)), p2(new Player(n2)), activePlayer(1), turn(1) {}

Model::~Model() {
    delete p1;
    delete p2;
}

vector<string> Model::getPlayerInfo(int player) {
    if (player == 1) {
        return p1->printPlayer();
    } else {
        return p2->printPlayer();
    }
}

void Model::nextTurn() {
    turn = turn + 1;
    if (activePlayer == 1) {
        activePlayer = 2;
        p2->draw();
        p2->setMP(p2->getMP() + 1);
    } else {
        activePlayer = 1;
        p1->draw();
        p1->setMP(p1->getMP() + 1);
    }
}

void Model::currentPlayer() {
    if (activePlayer == 1) {
        p1->printPlayer();
    } else {
        p2->printPlayer();
    }
}

int Model::aPlayer() {
    return activePlayer;
}

void Model::attack(int i) {
    if (activePlayer == 1) {
        p1->attack(i, *p2);
    } else {
        p2->attack(i, *p1);
    }
}

void Model::attack(int i, int j) {
    if (activePlayer == 1) {
        p1->attack(i, j, *p2);
    } else {
        p2->attack(i, j, *p1);
    }
}

Player* Model::getPlayer(int i) {
    if (i == 1) {
        return p1;
    } else if (i == 2) {
        return p2;
    } else {
        return nullptr;
    }
}

Player* Model::getOpp(int i) {
    if (i == 1) {
        return p2;
    } else if (i == 2) {
        return p1;
    } else {
        return nullptr;
    }
}

void Model::draw(int player) {
    if (player == 1) {
        p1->draw();
    } else {
        p2->draw();
    }
}

void Model::discard(int player, int handpos) {
    if (player == 1) {
        p1->discard(handpos);
    } else {
        p2->discard(handpos);
    }

}

int Model::checkStatus() {
    bool victoryp1 = p2->checkStatus();
    bool victoryp2 = p1->checkStatus();
    if (victoryp1) {
        return 1;
    } else if (victoryp2) {
        return 2;
    } else {
        return 0;
    }
}

void Model::LoadDecks(const string &deckname1, const string &deckname2, bool testing) {
    p1->loadDeck(deckname1, testing);
    p2->loadDeck(deckname2, testing);
}

void Model::Play(int playernum, int handpos, int fieldpos) {
    int a = aPlayer();
    Player *p = getPlayer(a);
    try {
        p->play(this, playernum, handpos, fieldpos);
    } catch (string reason) {
        throw std::move(reason);
    }
    
}

void Model::setUp(const std::string &deckname1, const std::string &deckname2, bool testing) {
    LoadDecks(deckname1, deckname2, testing);
    p1->draw();
    p1->draw();
    p1->draw();
    p1->draw();
    p1->draw();

    p2->draw();
    p2->draw();
    p2->draw();
    p2->draw();
    p2->draw();
}

vector<vector<string>> Model::getFieldInfo(int player) {
    Player *p = getPlayer(player);
    return p->getFieldInfo();
}

vector<vector<string>> Model::getHandInfo(int player) {
    Player *p = getPlayer(player);
    return p->getHandInfo();
}

vector<vector<string>> Model::getGraveyardInfo(int player) {
    Player *p = getPlayer(player);
    return p->getGraveyardInfo();
}
