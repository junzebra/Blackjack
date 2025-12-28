#include "../include/Dealer.h"

void Dealer::hit(Deck& deck){
    hand.append(deck.nextCard());
    deck.updateCardCount();
}

void Dealer::stand(){
    isPlaying = false;
}

void Dealer::reset(){
    isPlaying = true;
    hand.reset();
}

bool Dealer::wantsHit(){
    return!(hand.add() >= 17);
}

Card* Dealer::upCard(){
    return hand.getCard(0);
}