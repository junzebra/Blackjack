#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include "Deck.h"
#include "Dealer.h"

enum class winnerStatus { WIN, LOSE, PUSH,BLACKJACK };

class Player{
    protected:
        std::string name;
        int money;
        winnerStatus winner = winnerStatus::PUSH;
        int initBet;
        int newBet;
        int betPlaced;
        Hand hand;
        Hand handSplit;
    public:
        bool isPlaying = true;
        Player(int m, int b, std::string n) : money(m),initBet(b), name(n) {};
        std::string getName(){ return name; };
        void play();
        void hit(Hand& h,Deck& deck);
        void stand();
        void split(Hand& h,Deck& deck);
        void doubleDown(Hand& h,Deck& deck);
        void reset();
        void placeBet();
        int getBetPlaced();
        void setWinner(winnerStatus w);
        std::string getWinnerString();
        void payout(int p);
        void printMoney();
        Hand& getHand();
        Hand& getHandSplit(){ return handSplit; }
        virtual void newBetAmount() = 0;
        virtual void decideMove(Hand& h,Deck& deck,Dealer& dealer) = 0;
        virtual ~Player() = default;

};

class Amateur : public Player{
    public:
        Amateur(int m, int b, std::string n) : Player(m,b,n) {};
        void newBetAmount() override;
        void decideMove(Hand& h,Deck& deck,Dealer& dealer)override;
};

//rules from online guidebook
class Textbook : public Player{
    public:
        Textbook(int m, int b, std::string n) : Player(m,b,n) {};
        void newBetAmount() override;
        void decideMove(Hand& h,Deck& deck,Dealer& dealer) override;
};

class MartinGale : public Player{
    public:
        MartinGale(int m, int b, std::string n) : Player(m,b,n) {};
        void newBetAmount() override;
        void decideMove(Hand& h,Deck& deck,Dealer& dealer) override;
};

class CardCounter : public Player{
    public:
        CardCounter(int m, int b, std::string n) : Player(m,b,n) {};
        void newBetAmount() override;
        void decideMove(Hand& h,Deck& deck,Dealer& dealer) override;
};

#endif
