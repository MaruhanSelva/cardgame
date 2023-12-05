#include "spellcards.h"
#include "model.h"

using namespace std;

// Destroy Card Class

DestroyCard::DestroyCard(): Spell("Destroy", 1) {}

DestroyCard::~DestroyCard() {}

void DestroyCard::use(Model *m, int playernum, int pos) {
    Destroy(m, pos);
}

void DestroyCard::attack(Player &p) {}

void DestroyCard::attack(Card &c) {}

void DestroyCard::getAttacked(Card &c) {}

int DestroyCard::getAtk() {
    return 0;
}

int DestroyCard::getDef() {
    return 0;
}

void DestroyCard::setAtk(int x) {}

void DestroyCard::setDef(int x) {}

void DestroyCard::setComponent(Card *c) {}

void DestroyCard::removeComponent() {}

vector<string> DestroyCard::getCardInfo() {
    vector<string> info;
    info.push_back(name);
    info.push_back(type);
    info.push_back(to_string(cost));
    info.push_back("Send a Monster to the Graveyard");

    return info;
}


// Sacrificial Draw Card Class

SacrificialDrawCard::SacrificialDrawCard(): Spell("Sacrificial Draw", 1) {}

SacrificialDrawCard::~SacrificialDrawCard() {}

void SacrificialDrawCard::use(Model *m, int playernum, int pos) {
    SacrificialDraw(m, pos);
}

void SacrificialDrawCard::attack(Player &p) {}

void SacrificialDrawCard::attack(Card &c) {}

void SacrificialDrawCard::getAttacked(Card &c) {}

int SacrificialDrawCard::getAtk() {
    return 0;
}

int SacrificialDrawCard::getDef() {
    return 0;
}

void SacrificialDrawCard::setAtk(int x) {}

void SacrificialDrawCard::setDef(int x) {}

void SacrificialDrawCard::setComponent(Card *c) {}

void SacrificialDrawCard::removeComponent() {}

vector<string> SacrificialDrawCard::getCardInfo() {
    vector<string> info;
    info.push_back(name);
    info.push_back(type);
    info.push_back(to_string(cost));
    info.push_back("Send a card from your hand to the Graveyard and then draw.");

    return info;
}

// Recall Card Class

RecallCard::RecallCard(): Spell("Recall", 1) {}

RecallCard::~RecallCard() {}

void RecallCard::use(Model *m, int playernum, int pos) {
    Recall(m, pos);
}

void RecallCard::attack(Player &p) {}

void RecallCard::attack(Card &c) {}

void RecallCard::getAttacked(Card &c) {}

int RecallCard::getAtk() {
    return 0;
}

int RecallCard::getDef() {
    return 0;
}

void RecallCard::setAtk(int x) {}

void RecallCard::setDef(int x) {}

void RecallCard::setComponent(Card *c) {}

void RecallCard::removeComponent() {}

vector<string> RecallCard::getCardInfo() {
    vector<string> info;
    info.push_back(name);
    info.push_back(type);
    info.push_back(to_string(cost));
    info.push_back("Send a monster from the field to your hand.");

    return info;
}

// Medical Miracle Card Class

MMiracleCard::MMiracleCard(): Spell("Medical Miracle", 1) {}

MMiracleCard::~MMiracleCard() {}

void MMiracleCard::use(Model *m, int playernum, int pos) {
    MedicalMiracle(m);
}

void MMiracleCard::attack(Player &p) {}

void MMiracleCard::attack(Card &c) {}

void MMiracleCard::getAttacked(Card &c) {}

int MMiracleCard::getAtk() {
    return 0;
}

int MMiracleCard::getDef() {
    return 0;
}

void MMiracleCard::setAtk(int x) {}

void MMiracleCard::setDef(int x) {}

void MMiracleCard::setComponent(Card *c) {}

void MMiracleCard::removeComponent() {}

vector<string> MMiracleCard::getCardInfo() {
    vector<string> info;
    info.push_back(name);
    info.push_back(type);
    info.push_back(to_string(cost));
    info.push_back("Revive the top-most Monster from the field and revive it with 1 DEF.");

    return info;
}

// Potion Card Class
PotionCard::PotionCard(): Spell("Potion", 1) {}

PotionCard::~PotionCard() {}

void PotionCard::use(Model *m, int playernum, int pos) {
    Potion(m, pos);
}

void PotionCard::attack(Player &p) {}

void PotionCard::attack(Card &c) {}

void PotionCard::getAttacked(Card &c) {}

int PotionCard::getAtk() {
    return 0;
}

int PotionCard::getDef() {
    return 0;
}

void PotionCard::setAtk(int x) {}

void PotionCard::setDef(int x) {}

void PotionCard::setComponent(Card *c) {}

void PotionCard::removeComponent() {}

vector<string> PotionCard::getCardInfo() {
    vector<string> info;
    info.push_back(name);
    info.push_back(type);
    info.push_back(to_string(cost));
    info.push_back("Heal a minion by a small amount.");

    return info;
}





