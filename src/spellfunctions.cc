#include "spellfunctions.h"
#include "model.h"
#include "player.h"
#include "monster.h"

void Destroy(Model *m, int i) {
    int a = m->aPlayer();
    Player *p = m->getOpp(a);
    p->sendToGraveyard(i);
}

void SacrificialDraw(Model *m, int i) {
    int a = m->aPlayer();
    Player *p = m->getPlayer(a);

    p->discard(i); // get rid of the ith card
    p->draw(); // draw a card from the deck 
}

void Recall(Model *m, int i) {
    int a = m->aPlayer();
    Player *p = m->getPlayer(a);

    p->unsummon(i);
}

void MedicalMiracle(Model *m) {
    int a = m->aPlayer();
    Player *p = m->getPlayer(a);

    p->revive();
}

void Potion(Model *m, int i) {
    int a = m->aPlayer();
    Player *p = m->getPlayer(a);

    p->editCard(i, true, 2);
}