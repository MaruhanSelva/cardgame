#include "ASCIIdisplay.h"
#include "ascii_graphics.h"
#include "model.h"

#include <sstream>

using namespace std;

ASCII_Disp::ASCII_Disp(Model *m): m{m} {}

ASCII_Disp::~ASCII_Disp() {
    unlink();
}

void ASCII_Disp::unlink() {
    m = nullptr;
}

vector<string> getMonsterString(vector<string> fc) {
    stringstream ss;
    ss << fc[2];
    int cost;
    ss >> cost;

    ss.clear();

    ss << fc[4];
    int atk;
    ss >> atk;

    ss.clear();

    ss << fc[5];
    int def;
    ss >> def;

    return display_minion_no_ability(fc[0], cost, atk, def);
}

vector<string> getSpellString(vector<string> fc) {
    stringstream ss;

    ss << fc[2];
    int cost;
    ss >> cost;
    
    return display_spell(fc[0], cost, fc[3]);

}

vector<string> getModifierString(vector<string> fc) {
    stringstream ss;

    ss << fc[2];
    int cost;
    ss >> cost;
    ss.clear();

    string atkval;
    if (fc[6] == "0") {
        atkval = "+" + fc[4];
    } else {
        atkval = "*" + fc[4];
    }
    string defval;
    if (fc[7] == "0") {
        defval = "+" + fc[5];
    } else {
        defval = "*" + fc[5];
    }

    return display_enchantment_attack_defence(fc[0], cost, fc[3], atkval, defval);
}

void ASCII_Disp::printFieldCard(int player, int fieldpos) {
    vector<vector<string>> fieldinfo = m->getFieldInfo(player);
    vector<string> fc = fieldinfo[fieldpos];

    vector<string> s = getMonsterString(fc);

    for (auto i: s) {
        cout << i << endl;
    }
}

void printCardRow(vector<vector<string>> cards) {
    for (int row = 0; row < CARD_TEMPLATE_EMPTY.size(); ++row) {
        string s;
        for (auto i: cards) {
            s = s + i[row];
        }
        cout << s << endl;
    }
}

void ASCII_Disp::printField(int player) {
    vector<vector<string>> fieldinfo = m->getFieldInfo(player);

    int s = fieldinfo.size();
    vector<vector<string>> cards;
    for (int i = 0; i < s; i++) {
        vector<string> card = fieldinfo[i];
        if (card[1] == "M") {
            cards.push_back(getMonsterString(card));
        } else if (card[1] == "S") {
            cards.push_back(getSpellString(card));
        } else if (card[1] == "E") {
            cards.push_back(getModifierString(card));
        }
    }

    if (s < 5) {
        int diff = 5 - s;
        for (int j = 0; j < diff; ++j) {
            cards.push_back(CARD_TEMPLATE_BORDER);
        }
    }

    printCardRow(cards);


}


void ASCII_Disp::printHand(int player) {
    vector<vector<string>> handinfo = m->getHandInfo(player);
    int s = handinfo.size();
    vector<vector<string>> cards;
    for (int i = 0; i < s; i++) {
        vector<string> card = handinfo[i];
        if (card[1] == "M") {
            cards.push_back(getMonsterString(card));
        } else if (card[1] == "S") {
            cards.push_back(getSpellString(card));
        } else if (card[1] == "E") {
            cards.push_back(getModifierString(card));
        }
    }

    printCardRow(cards);

}

void ASCII_Disp::printGraveyard(int player) {
    vector<vector<string>> graveinfo = m->getGraveyardInfo(player);
    int s = graveinfo.size();

    vector<vector<string>> cards;
    for (int i = 0; i < s; i++) {
        vector<string> card = graveinfo[i];
        if (card[1] == "M") {
            cards.push_back(getMonsterString(card));
        } else if (card[1] == "S") {
            cards.push_back(getSpellString(card));
        } else if (card[1] == "E") {
            cards.push_back(getModifierString(card));
        }
    }

    printCardRow(cards);
}

void ASCII_Disp::printBoard() {
    vector<string> p1Info = m->getPlayerInfo(1);
    vector<string> p2Info = m->getPlayerInfo(2);

    stringstream ss;

    ss << p1Info[1];
    int hp;
    ss >> hp;
    ss.clear();   

    ss << p1Info[2];
    int mp;
    ss >> mp;
    ss.clear();

    vector<string> player1 = display_player_card(1, p1Info[0], hp, mp);
    for (auto i: player1) {
        cout << i << endl;
    }


    printField(1);
    for (auto i: CENTRE_GRAPHIC) {
        cout << i << endl;
    }
    printField(2);

    ss << p2Info[1];
    ss >> hp;
    ss.clear();
    ss << p2Info[2];
    ss >> mp;
    ss.clear();

    vector<string> player2 = display_player_card(1, p2Info[0], hp, mp);
    for (auto i: player2) {
        cout << i << endl;
    }

}