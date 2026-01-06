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

void Player::split(Hand& h,Deck& deck){

    handSplit.append(hand.getCard(1));
    hand.pop();
    hit(hand,deck);
    hit(handSplit,deck);
    
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


void Player::placeBet(){
    money -= newBet;
    betPlaced = newBet;
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

void Player::setWinner(winnerStatus w){
    winner = w;
}

std::string Player::getWinnerString(){
    switch(winner){
        case winnerStatus::WIN:
            return "WIN";
        case winnerStatus::LOSE:
            return "LOSE";
        case winnerStatus::PUSH:
            return "PUSH";
        case winnerStatus::BLACKJACK:
            return "BLACKJACK";
        default:
            return "UNKNOWN";
    }
}

void Amateur::newBetAmount(){
    newBet = initBet;
}

void CardCounter::newBetAmount(){
    newBet = initBet;
}

void Textbook::newBetAmount(){
    newBet = initBet;
}

void MartinGale::newBetAmount(){
    if(winner == winnerStatus::WIN){
        newBet = initBet;
    }
    else if (winner == winnerStatus::LOSE){
        newBet = betPlaced * 2;
    }
    else {
        newBet = betPlaced;
    }
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

void MartinGale::decideMove(Hand& h, Deck& deck,Dealer& dealer){
    if(hand.add()<16){
        hit(h,deck);
    }
    else{
        stand();
    }
}

void Textbook::decideMove(Hand& h, Deck& deck,Dealer& dealer){
    int upCard = dealer.upCard() -> getVal();


    if(h.size()<2){
        hit(h,deck);
        return;
    }
    //splits
    if(h.getCard(0)->getRank()==h.getCard(1)->getRank() && handSplit.isEmpty()){
        Rank n = hand.getCard(0)->getRank();
        switch(n){
            case Rank::Ace:
                split(h,deck);
                return;
            case Rank::Eight:
                split(h,deck);
                return;
            case Rank::Two:
            case Rank::Three:
                if(upCard>=2 && upCard<=7){ 
                    split(h,deck);
                    return;
                }
                else{
                    hit(h,deck);
                    return;
                }
            case Rank::Four:
                if(upCard==5 || upCard==6){
                    split(h,deck);
                    return;
                }
                else{
                    hit(h,deck);
                    return;
                }
            case Rank::Six:
                if(upCard>=2 && upCard<=6){
                    split(h,deck);
                    return;
                }
                else{
                    hit(h,deck);
                    return;
                }
            case Rank::Seven:
                if(upCard>=2 && upCard<=7){
                    split(h,deck);
                    return;
                }
                else{
                    hit(h,deck);
                    return;
                }
            case Rank::Nine:
                if(upCard>=2 && upCard<=6 || upCard==8 || upCard==9){
                    split(h,deck);
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
    else if(h.getCard(0)->getRank()==Rank::Ace || h.getCard(1)->getRank()==Rank::Ace){
        int hand_val = h.add();

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
        int hand_val = h.add();

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