#include "monstercards.h"
#include "model.h"
#include "player.h"

using namespace std;
// Simple Monster Class

SimpleMonster::SimpleMonster(std::string name, int atk, int def): Monster(name, atk, def) {}

SimpleMonster::~SimpleMonster() {}

int SimpleMonster::getAtk() {
    return atk;
}

int SimpleMonster::getDef() {
    return def;
}

void SimpleMonster::setAtk(int x) {
    atk = x;
}

void SimpleMonster::setDef(int x) {
    def = x;
}

void SimpleMonster::use(Model *m, int playernum, int pos) {}

void SimpleMonster::getAttacked(Card &v) {
    v.attack(*this);
}

void SimpleMonster::attack(Card &v) {
    v.setDef(v.getDef() -  atk);
    def = def - v.getAtk();
}

void SimpleMonster::attack(Player &p) {
    p.setHP(p.getHP() - atk);
}

void SimpleMonster::setComponent(Card *c) {}

void SimpleMonster::removeComponent() {}

vector<string> SimpleMonster::getCardInfo() {
    vector<string> info;

    // card general
    info.push_back(name);
    info.push_back(type);
    info.push_back(to_string(cost));
    info.push_back(""); // no description
    
    // monster specific
    info.push_back(to_string(atk));
    info.push_back(to_string(def));

    return info;
}
