#include "../include/Player.h"

void Player::play(){
    money -= initBet;
}

void Player::hit(Hand& h,Deck& deck){
    h.append(deck.nextCard());
    deck.updateCardCount();
}

void Player::stand(){
    isPlaying = false;
}

void Player::split(){
    handSplit.append(hand.getCard(1));
    hand.pop();
}

void Player::doubleDown(Hand& h,Deck& deck){
    play();
    hit(h,deck);
    stand();
}

void Player::reset(){
    isPlaying = true;
    hand.reset();
    handSplit.reset();
}

void Player::payout(int p){
    money += p;
}

void Amateur::decideMove(Hand& h, Deck& deck,Dealer& dealer){
    if(hand.add()<16){
        hit(h,deck);
    }
    else{
        stand();
    }
}

void CardCounter::decideMove(Hand& h, Deck& deck,Dealer& dealer){
    if(hand.add()<16){
        hit(h,deck);
    }
    else{
        stand();
    }
}

void Textbook::decideMove(Hand& h, Deck& deck,Dealer& dealer){
    int upCard = dealer.upCard() -> getVal();

    //splits
    if(hand.getCard(0)==hand.getCard(1) && handSplit.isEmpty()){
        
    }
}