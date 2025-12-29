#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Dealer.h"
#include "Player.h"
#include "Hand.h"

class Game{
    private:
        std::vector<Player*> players = {};
        Dealer dealer;
        Deck deck = Deck(6);
        int turn = 0;
        int shoe;
        int shuffleAt;
    public:
        void initPlayers();
        void initShoe();
        void clearPlayers();
        void setShuffle();
        Hand getHand(Player* p);
        void run();

};

#endif
