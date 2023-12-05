#include "player.h"
#include "deckLoad.h"
#include "model.h"

using namespace std;

Player::Player(string name): name{name}, hp{20}, mp{0} {}

Player::~Player() {
}

vector<string> Player::printPlayer() {
    vector<string> info;

    info.push_back(name);
    info.push_back(to_string(hp));
    info.push_back(to_string(mp));

    return info;
}

void Player::setHP(int x) {
    hp = x;
} 

void Player::setMP(int x) {
    mp = x;
}

int Player::getHP() {
    return hp;
}

int Player::getMP() {
    return mp;
}

void Player::addCard(Card *x) {
    hand.push_back(x);
}

void Player::removeCard(int x) {
    hand.erase(hand.begin() + x);
}

void Player::sendToGraveyard(int i) {
    graveyard.push_back(field[i]);
    field.erase(field.begin() + i);
}

void Player::attack(int i, Player& p) {
    Card *v = field.at(i);
    v->attack(p);
}

void Player::getAttacked(int j, Card &v) {
    Card *m = field.at(j);
    m->attack(v);
}

void Player::attack(int i, int j, Player &p) {
    Card *v = field.at(i);
    p.getAttacked(j, *v);
}


void Player::addToField(Card *c) {
    field.push_back(c);
}

void Player::draw() {
    if (hand.size() != 5 && deck.size() > 0) {
        // add first card to hand and remove from deck
        hand.push_back(deck[0]);
        deck.erase(deck.begin());
    }
}

void Player::summon(int i) {
    if (field.size() != 5) {
        field.push_back(hand[i]);
        hand.erase(hand.begin() + i);
    }
}

void Player::unsummon(int i) {
    hand.push_back(field[i]);
    field.erase(field.begin() + i);
}


void Player::discard(int i) {
    graveyard.push_back(hand[i]);

    // delete it from the hand
    hand.erase(hand.begin() + i);
}

void Player::editCard(int i, bool hp, int val) {
    if (hp == true) {
        field[i]->setDef(field[i]->getDef() + val);
    } else {
        field[i]->setAtk(field[i]->getAtk() + val);
    }
}

void Player::revive() {
    field.push_back(graveyard[0]);
    graveyard.erase(graveyard.begin());
    graveyard.back()->setDef(1);
}


void Player::loadDeck(const string &deckname, bool testing) {
    deckLoad(deckname, deck, !testing);
}

bool Player::checkStatus() {
    // used to update the field parameters and see if the player is dead or not
    // returns true if the current player is dead, otherwise returns false
    if (hp <= 0) {
        return true;
    } else {
        int length = field.size();
        for (int i = 0; i < length; i++) {
            if (field[i]->getDef() <= 0) {
                sendToGraveyard(i);
                break; // only one monster can die per checkStatus()
            }
        }
    }
    return false;
}

void Player::play(Model *m, int playernum, int handpos, int fieldpos) {
    int cost = hand[handpos]->getCost();
    if (mp < cost) {
        string reason = "Not enough MP";
        throw(reason);
    } else {
        string type = hand[handpos]->getType();
        if (type == "M") {
            summon(handpos);
        } else if (type == "S") {
            Card *c = hand[handpos];
            try {
                c->use(m, playernum, fieldpos);
                sendToGraveyard(handpos);
            } catch (...) {
                string reason = "SPELL MISTAKE, CHECK INPUT AGAIN";
                throw reason;
            }
            
        } else if (type == "E") {
            try {
                Card *c = hand[handpos]; // enchantment card
                if (fieldpos < field.size()) {
                    Card *d = field[fieldpos];
                    c->setComponent(d);
                    field[fieldpos] = c;
                } else {
                    throw("ERROR");
                }
            } catch (...) {
                string reason = "MODIFIER MISTAKE, CHECK INPUT AGAIN";
                throw reason;
            }
            
        }
    }
}

vector<vector<string>> Player::getFieldInfo() {
    vector<vector<string>> cards;
    for (auto i: field) {
        vector<string> monsterInfo = i->getCardInfo();
        cards.push_back(monsterInfo);
    }
    return cards;
}

vector<vector<string>> Player::getDeckInfo() {
    vector<vector<string>> cards;
    for (auto i: deck) {
        vector<string> monsterInfo = i->getCardInfo();
        cards.push_back(monsterInfo);
    }
    return cards;
}

vector<vector<string>> Player::getGraveyardInfo() {
    vector<vector<string>> cards;
    for (auto i: graveyard) {
        vector<string> cardInfo = i->getCardInfo();
        cards.push_back(cardInfo);
    }
    return cards;
}

vector<vector<string>> Player::getHandInfo() {
    vector<vector<string>> cards;
    for (auto i: hand) {
        vector<string> monsterInfo = i->getCardInfo();
        cards.push_back(monsterInfo);
    }
    return cards;
}

