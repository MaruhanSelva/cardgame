#include "player.h"

#include "monster.h"
#include "model.h"

using namespace std;

Monster::Monster(string name, int atk, int def): Card(name, "M"), atk{atk}, def{def} {}

Monster::~Monster() {}




