#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>

#include "deckLoad.h"
#include "monstercards.h"
#include "card.h"
#include "spellcards.h"
#include "modifiercards.h"

using namespace std;


void deckLoad(const string &deckName, vector<Card *> &deck, bool sh) {
    ifstream cards{deckName};
    string cardName;
    while(getline(cards, cardName)) {
        if (cardName == "Fire Monster") {
            deck.push_back(new SimpleMonster("Fire Minion", 2, 3));
        } else if (cardName == "Water Monster") {
            deck.push_back(new SimpleMonster("Water Minion", 2, 3));
        } else if (cardName == "Nature Monster") {
            deck.push_back(new SimpleMonster("Nature Minion", 2, 3));
        } else if (cardName == "Destroy") {
            deck.push_back(new DestroyCard());
        } else if (cardName == "Sacrificial Draw") {
            deck.push_back(new SacrificialDrawCard());
        } else if (cardName == "Recall") {
            deck.push_back(new RecallCard());
        } else if (cardName == "Medical Miracle") {
            deck.push_back(new MMiracleCard());
        } else if (cardName == "Potion") {
            deck.push_back(new PotionCard());
        } else if (cardName == "Strength Pendant") {
            deck.push_back(new SimpleModifier(cardName, 1, 1, false, true));
        }
    }
    if (sh) {
        shuffle(deck.begin(), deck.end(), default_random_engine(time(NULL)));
    }
        



}