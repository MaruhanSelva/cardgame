#include "modifier.h"
#include "player.h"

using namespace std;

Modifier::Modifier(string name, int vA, int vD, bool m1, bool m2): Card(name, "E"), valAtk{vA}, valDef{vA}, mult1{m1}, mult2{m2}, component{nullptr}  {}

Modifier::~Modifier() {}