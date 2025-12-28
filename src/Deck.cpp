#include "../include/Deck.h"

#include <algorithm>
#include <iterator>
#include <random>
#include <iostream>


static constexpr Suit suits[] = { Suit::Heart, Suit::Diamond, Suit::Club, Suit::Spade };
static constexpr Rank ranks[] = {
    Rank::Ace, Rank::Two, Rank::Three, Rank::Four, Rank::Five, Rank::Six,
    Rank::Seven, Rank::Eight, Rank::Nine, Rank::Ten, Rank::Jack, Rank::Queen, Rank::King
};

int Deck::size(){
    return deckIncrement*deckNumber;
}

void Deck::setArray() {
    deckArray.clear();
    for (int i = 0; i < deckNumber; ++i) {
        for (Suit s : suits) {
            for (Rank r : ranks) {
                deckArray.push_back(new Card(s, r));
            }
        }
    }
}

void Deck::shuffle(){
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deckArray.begin(),deckArray.end(),g);
}

void Deck::resetCardCount(){
    cardCount = 0;
}

void Deck::updateCardCount(){
    cardCount++;
}

Card* Deck::nextCard(){
    return deckArray[cardCount+1];
}