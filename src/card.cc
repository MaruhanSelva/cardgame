#include "card.h"

using namespace std;

Card::Card(string name, string type): name{name}, cost{1}, type{type} {}

Card::~Card() {}

string Card::getType() {
    return type;
}

int Card::getCost() {
    return cost;
}