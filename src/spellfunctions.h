#ifndef SPELL_FUNC
#define SPELL_FUNC

class Model;

// This file contains functions that have 

// Send a minion at pos i to the Graveyard
void Destroy(Model *m, int i);

// Send a card in your hand to the Graveyard and then Draw a new card
void SacrificialDraw(Model *m, int i);

// Send a Monster back to their player's hand
void Recall(Model *m, int i);

// Revive the first Monster back to the field with 1 DEF
void MedicalMiracle(Model *m);

// Heal a Monster by a set amount of HP
void Potion(Model *m, int i);

// Deal Damage to all Monsters on the Field (on the opponent's side)
//void Disaster(Model *m, int i);

#endif