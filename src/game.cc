#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "player.h"
#include "monster.h"
#include "model.h"
#include "spellfunctions.h"
#include "ASCIIdisplay.h"


using namespace std;


bool cmdRead(string s, bool testing, Model *m, ASCII_Disp *d) {
    istringstream iss{s};
    iss >> s;
    if (s == "help") {
        cout << "Usable Commands: " << endl;
        cout << "- help: view this blurb" << endl;
        cout << "- end: end your turn" << endl;
        cout << "- quit: end the game" << endl;
        cout << "- attack i j: attack your opponent's j-th monster using your ith monster" << endl;
        cout << "- attack i: attack your opponent using your i-th monster (only when they have no monsters)" << endl;
        cout << "- play i [playernum] [targetnum]: play the i-th card in your hand. Optionally target a player and a monster" << endl;
        cout << "- use i [playernum] [targetnum]: use the i-th monster's ability on the (optional) player and monster" << endl;
        cout << "- inpect i playernum: view the i-th monster's modifiers on the playernum team" << endl;
        cout << "- hand: view your hand" << endl;
        cout << "- board: view the board" << endl;
        cout << "NOTE: i, j and targetnum start at 0 and go to a max of 4" << endl;
        cout << "NOTE: playernum is either 1 or 2. Check board to see who is which!" << endl;

    } else if (s == "end") {
        m->nextTurn();
    } else if (s == "quit") {
        return true;
    } else if (s == "draw") {
        if (testing) {
            m->draw(m->aPlayer());
        } 
    } else if (s == "discard") {
        cout << "Which card (starting from 0)" << endl;
        int i;
        iss >> i;
        m->discard(m->aPlayer(), i);
    } else if (s == "attack") {
        int i, j;
        iss >> i;
        if (iss >> j) {
            m->attack(i, j);
        } else {
            m->attack(i);
        }
    } else if (s == "use") {
        cout << "use" << endl;
    } else if (s == "play") {
        try {
            int handpos, player, fieldpos;
            iss >> handpos;
            if (iss >> player) {
                if (iss >> fieldpos) {
                    //cout << handpos << " " << player << " " << fieldpos << endl;
                    m->Play(player, handpos, fieldpos);
                } else {
                    m->Play(player, handpos, -1);
                }
            } else {
                m->Play(m->aPlayer(), handpos, -1);
            }
        } catch (string reason) {
            cout << reason << endl;
        } catch (...) {
            cout << "Something went wrong" << endl;
        }
    } else if (s == "inspect") {
        cout << "inspect" << endl;
    } else if (s == "hand") {
        d->printHand(m->aPlayer());
    } else if (s == "board") {
        d->printBoard();
    } else if (s == "testing") {

    }
    return false;
}

int main() {
    bool status = false;
    string p1;
    string p2;
    if (status == false) {
        cout << "Welcome to CardGame! Enter Two Names (first is player 1 and the second is player 2)" << endl;
        cin >> p1;
        cin >> p2;

        Model *m = new Model(p1, p2);

        ASCII_Disp *d = new ASCII_Disp(m);

        string deck1 = "starter.deck";
        string deck2 = "starter.deck";

        m->setUp(deck1, deck2, true);

        string s;
        while (getline(cin, s)) {
            if (cmdRead(s, false, m, d)) break; // end the game
        }
    }
}