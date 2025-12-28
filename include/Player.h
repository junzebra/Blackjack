#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include "Deck.h"
#include "Dealer.h"

class Player{
    protected:
        int money;
        int initBet;
        Hand hand;
        Hand handSplit;
        bool isPlaying = true;
    public:
        Player(int m, int b) : money(m),initBet(b) {};
        void play();
        void hit(Hand& h,Deck& deck);
        void stand();
        void split();
        void doubleDown(Hand& h,Deck& deck);
        void reset();
        void payout(int p);
        virtual void decideMove(Hand& h,Deck& deck,Dealer& dealer);
};

class Amateur : Player{
    public:
        Amateur(int m, int b) : Player(m,b) {};
        void decideMove(Hand& h,Deck& deck,Dealer& dealer)override;
};

//rules from online guidebook
class Textbook : Player{
    public:
        Textbook(int m, int b) : Player(m,b) {};
        void decideMove(Hand& h,Deck& deck,Dealer& dealer) override;
};

class CardCounter : Player{
    public:
        CardCounter(int m, int b) : Player(m,b) {};
        void decideMove(Hand& h,Deck& deck,Dealer& dealer) override;
};

#endif
