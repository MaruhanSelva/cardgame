#ifndef DLOAD
#define DLOAD

#include <string>
#include <vector>

class Card;

void deckLoad(const std::string &deckName, std::vector<Card *> &deck, bool sh);

#endif