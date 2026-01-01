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

std::string Card::toString() {
    std::string rankStr;
    switch (rank) {
        case Rank::Ace: rankStr = "A"; break;
        case Rank::Two: rankStr = "2"; break;
        case Rank::Three: rankStr = "3"; break;
        case Rank::Four: rankStr = "4"; break;
        case Rank::Five: rankStr = "5"; break;
        case Rank::Six: rankStr = "6"; break;
        case Rank::Seven: rankStr = "7"; break;
        case Rank::Eight: rankStr = "8"; break;
        case Rank::Nine: rankStr = "9"; break;
        case Rank::Ten: rankStr = "10"; break;
        case Rank::Jack: rankStr = "J"; break;
        case Rank::Queen: rankStr = "Q"; break;
        case Rank::King: rankStr = "K"; break;
    }

    std::string suitStr;
    switch (suit) {
        case Suit::Heart: suitStr = "♥"; break;
        case Suit::Diamond: suitStr = "♦"; break;
        case Suit::Club: suitStr = "♣"; break;
        case Suit::Spade: suitStr = "♠"; break;
    }

    return rankStr + suitStr;
}