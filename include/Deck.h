#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck{
    private:
        const int deckIncrement = 52;
        int deckNumber;
        int cardCount = 0;
        std::vector<Card*> deckArray = {};

    public:
        Deck(int n) : deckNumber(n) {};
        int size();
        void setArray();
        void shuffle();
        void resetCardCount();
        void updateCardCount();
        Card* nextCard();

};

#endif
