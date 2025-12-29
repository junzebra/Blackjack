#include "../include/Card.h"

Suit Card::getSuit() {
    return suit;
}

Rank Card::getRank() {
    return rank;
}

int Card::getVal() {
    if (rank >= Rank::Two && rank <= Rank::Ten) {
        return static_cast<int>(rank);
    } else if (rank >= Rank::Jack && rank <= Rank::King) {
        return 10;
    } else if (rank == Rank::Ace) {
        return 11;
    }
    return 0; // Default case, should not reach here
}