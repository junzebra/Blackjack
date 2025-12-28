#ifndef CARD_H
#define CARD_H

#include <string>

enum class Suit{
    Heart,Diamond,Club,Spade
};

enum class Rank{
    Ace = 1,Two,Three,Four,Five,Six,Seven,Eight,Nine,Ten,Jack,Queen,King
};


class Card {
    private:
        Suit suit;
        Rank rank;

    public:
        Card(Suit s, Rank r) : suit(s), rank(r) {};
        Suit getSuit();
        Rank getRank();
        int getVal();
};

#endif
