#include "../include/Player.h"

#include <iostream>

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


void Player::placeBet(int b){
    money -= b;
    betPlaced = b;
}

int Player::getBetPlaced(){
    return betPlaced;
}

Hand& Player::getHand(){
    return hand;
}

void Player::printMoney(){
    std::cout<< money << std::endl;
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


    if(hand.size()<2){
        hit(h,deck);
        return;
    }
    //splits
    if(hand.getCard(0)->getRank()==hand.getCard(1)->getRank() && handSplit.isEmpty()){
        Rank n = hand.getCard(0)->getRank();
        switch(n){
            case Rank::Ace:
                split();
                return;
            case Rank::Eight:
                split();
                return;
            case Rank::Two:
            case Rank::Three:
                if(upCard>=2 && upCard<=7){ 
                    split();
                    return;
                }
                else{
                    hit(h,deck);
                    return;
                }
            case Rank::Four:
                if(upCard==5 || upCard==6){
                    split();
                    return;
                }
                else{
                    hit(h,deck);
                    return;
                }
            case Rank::Six:
                if(upCard>=2 && upCard<=6){
                    split();
                    return;
                }
                else{
                    hit(h,deck);
                    return;
                }
            case Rank::Seven:
                if(upCard>=2 && upCard<=7){
                    split();
                    return;
                }
            case Rank::Nine:
                if(upCard>=2 && upCard<=6 || upCard==8 || upCard==9){
                    split();
                    return;
                }
                else{
                    stand();
                    return;
                }
            case Rank::Five:
                if(upCard>=2 && upCard<=9){
                    doubleDown(h,deck);
                    return;
                }
                else{
                    hit(h,deck);
                    return;
                }
            case Rank::Ten:
            case Rank::Jack:
            case Rank::Queen:
            case Rank::King: 
                stand();
                return;
            default:
                break;
        }
    }
    //soft totals
    else if(hand.getCard(0)->getRank()==Rank::Ace || hand.getCard(1)->getRank()==Rank::Ace){
        int hand_val = hand.add();

        switch(hand_val){
            case 20:
                stand();
                return;
            case 19:
                if(upCard == 6){
                    doubleDown(h,deck);
                    return;
                }
                else{
                    hit(h,deck);
                    return;
                }
            case 18:
                if(upCard>=2 && upCard<=6){
                    doubleDown(h,deck);
                    return;
                }
                else if(upCard==7 || upCard==8){
                    stand();
                    return;
                }
                else{
                    hit(h,deck);
                    return;
                }
            case 17:
                if(upCard>=3 && upCard<=6){
                    doubleDown(h,deck);
                    return;
                }
                else{
                    hit(h,deck);
                    return;
                }
            case 16:
            case 15:
                if(upCard>=4 && upCard<=6){
                    doubleDown(h,deck);
                    return;
                }
                else{
                    hit(h,deck);
                    return;
                }
            case 14:
            case 13:
                if(upCard>=5 && upCard<=6){
                    doubleDown(h,deck);
                    return;
                }
                else{
                    hit(h,deck);
                    return;
                }
            default:
                break;
        }
    }

    //hard totals
    else{
        int hand_val = hand.add();

        if(hand_val>=17){
            stand();
            return;
        }
        else if(hand_val>=13 && hand_val<=16){
            if(upCard>=2 && upCard<=6){
                stand();
                return;
            }
            else{
                hit(h,deck);
                return;
            }
        }
        else if(hand_val==12){
            if(upCard>=4 && upCard<=6){
                stand();
                return;
            }
            else{
                hit(h,deck);
                return;
            }
        }
        else if(hand_val==11){
            doubleDown(h,deck);
            return;
        }
        else if(hand_val==10){
            if(upCard>=2 && upCard<=9){
                doubleDown(h,deck);
                return;
            }
            else{
                hit(h,deck);
                return;
            }
        }
        else if(hand_val==9){
            if(upCard>=3 && upCard<=6){
                doubleDown(h,deck);
                return;
            }
            else{
                hit(h,deck);
                return;
            }
        }
        else{
            hit(h,deck);
            return;
        }
    }
}