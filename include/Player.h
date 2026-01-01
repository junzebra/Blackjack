#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include "Deck.h"
#include "Dealer.h"

class Player{
    protected:
        int money;
        int initBet;
        int betPlaced;
        Hand hand;
        Hand handSplit;
    public:
        bool isPlaying = true;
        Player(int m, int b) : money(m),initBet(b) {};
        void play();
        void hit(Hand& h,Deck& deck);
        void stand();
        void split();
        void doubleDown(Hand& h,Deck& deck);
        void reset();
        void placeBet(int b);
        int getBetPlaced();
        void payout(int p);
        void printMoney();
        Hand& getHand();
        Hand& getHandSplit(){ return handSplit; }
        virtual void decideMove(Hand& h,Deck& deck,Dealer& dealer) = 0;
        virtual ~Player() = default;

};

class Amateur : public Player{
    public:
        Amateur(int m, int b) : Player(m,b) {};
        void decideMove(Hand& h,Deck& deck,Dealer& dealer)override;
};

//rules from online guidebook
class Textbook : public Player{
    public:
        Textbook(int m, int b) : Player(m,b) {};
        void decideMove(Hand& h,Deck& deck,Dealer& dealer) override;
};

class CardCounter : public Player{
    public:
        CardCounter(int m, int b) : Player(m,b) {};
        void decideMove(Hand& h,Deck& deck,Dealer& dealer) override;
};

#endif
