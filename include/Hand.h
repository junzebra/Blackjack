#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

class Hand{
    private:
    std::vector<Card*> cards = {};
    public:
    int add();
    int size();
    void reset();
    void append(Card* k);
    void pop();
    bool isEmpty();
    Card* getCard(int n);
    
};

#endif
