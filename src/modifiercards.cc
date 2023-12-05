#include "modifiercards.h"
#include "model.h"

using namespace std;

// Simple Modifier Cards

SimpleModifier::SimpleModifier(string name, int v1, int v2, bool m1, bool m2): Modifier(name,v1, v2, m1, m2) {}

SimpleModifier::~SimpleModifier() {}

void SimpleModifier::use(Model *m, int player, int pos) {}

void SimpleModifier::getAttacked(Card &v) {
    v.attack(*this);
}

void SimpleModifier::attack(Card &v) {
    int atk = getAtk();
    v.setDef(v.getDef() - atk);
    int def = getDef();
    setDef(def - v.getAtk());
}

void SimpleModifier::attack(Player &p) {
    p.setHP(p.getHP() - getAtk());
}

void SimpleModifier::setAtk(int x) {
    component->setAtk(x);
}

void SimpleModifier::setDef(int x) {
    component->setDef(x);
}

int SimpleModifier::getAtk() {
    int a = component->getAtk();
    if (mult1 == true) {
        a = a * valAtk;
    } else {
        a = a + valAtk;
    }

    return a;
}

int SimpleModifier::getDef() {
    int d = component->getDef();
    if (mult2 == true) {
        d = d * valDef;
    } else {
        d = d + valDef;
    }

    return d;
}

void SimpleModifier::setComponent(Card *c) {
    //Card *current = component;
    component = c;
}

void SimpleModifier::removeComponent() {
    component = nullptr;
}

vector<string> SimpleModifier::getCardInfo() {
    vector<string> info;
    info.push_back(name);
    info.push_back(type);
    info.push_back(to_string(cost));
    info.push_back("");

    info.push_back(to_string(valAtk));
    info.push_back(to_string(valDef));
    info.push_back(to_string(mult1));
    info.push_back(to_string(mult2));

    // component info(?)

    return info;
}






