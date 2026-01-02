#include "../include/Game.h"
#include <iostream>

void Game::initPlayers(){
    players.push_back(new Amateur(100000,50,"Amateur"));
    players.push_back(new MartinGale(100000,50,"MartinGale"));
    players.push_back(new CardCounter(100000,50,"CardCounter"));
}

void Game::initShoe(){
    shoe = deck.size();
}

void Game::clearPlayers(){
    for(Player* p : players){
        delete p;
    }
    players.clear();
}

void Game::setShuffle(){
    shuffleAt = shoe / 4;
}

void Game::run(int runs) {
    // Initialize game components
    initPlayers();
    initShoe();
    setShuffle();
    deck.setArray();
    deck.shuffle();
    int runCount = 0;


    // Main game loop
    while (runCount < runs) {
        runCount++;

        // Check if shuffle is needed
        if (deck.size() - deck.getCardCount() <= shuffleAt) {
            deck.shuffle();
            deck.resetCardCount();
        }

        //dealer initial deal
        dealer.reset();
        dealer.hit(deck);
        dealer.hit(deck);


        for(Player* player : players){
            player->reset();

            // Each player places their bet
            player->newBetAmount();
            player->placeBet();
            // Player initial deal
            player->hit(player->getHand(),deck);
            player->hit(player->getHand(),deck);


            // Player's turn
            while(player->isPlaying){
                
                /*
                //print hands for debugging
                std::cout << "Dealer's Up Card: " << dealer.upCard()->toString() << std::endl;
                std::cout << "Player's Hand: ";
                Hand& pHand = player->getHand();
                for(int i = 0; i < pHand.size(); i++){
                    std::cout << pHand.getCard(i)->toString() << " ";
                }
                std::cout << " | Total: " << pHand.add() << std::endl;

                Hand& splitHand = player->getHandSplit();
                if(!splitHand.isEmpty()){
                    std::cout << "Player's Split Hand: ";
                    for(int i = 0; i < splitHand.size(); i++){
                        std::cout << splitHand.getCard(i)->toString() << " ";
                    }
                    std::cout << " | Total: " << splitHand.add() << std::endl;
                }
                */
                player->decideMove(player->getHand(),deck,dealer);
            }

            //split hand
            if(!player->getHandSplit().isEmpty()){
                player->isPlaying = true;
                while(player->isPlaying){
                    player->decideMove(player->getHandSplit(),deck,dealer);
                }
            }
        }

        // Dealer's turn
        while(dealer.wantsHit()){
            dealer.hit(deck);
        }
        
    
        // Payouts
        for(Player* player : players){
            Hand& pHand = player->getHand();
            Hand& dHand = dealer.getHand();
            int pHandTotal = pHand.add();
            int dHandTotal = dHand.add();

            if(pHandTotal == 21 && pHand.size() == 2){
                player -> payout(player->getBetPlaced()*3); // Example payout amount
                player -> setWinner(winnerStatus::BLACKJACK);
            }
            else if(pHandTotal > 21 || (dHandTotal <= 21 && dHandTotal > pHandTotal)){
                player -> setWinner(winnerStatus::LOSE);
                continue;
            }
            else if(pHandTotal == dHandTotal){
                player -> setWinner(winnerStatus::PUSH);
                player -> payout(player->getBetPlaced());
            }
            else if(pHandTotal > dHandTotal || dHandTotal > 21){
                player -> setWinner(winnerStatus::WIN);
                player -> payout(player->getBetPlaced()*2);
            }
            else{
                continue;
            }

        }

                // Print Hands
        std::cout << "Dealer's Hand: ";
        for(int i = 0; i < dealer.getHand().size(); i++){
            std::cout << dealer.getHand().getCard(i)->toString() << " ";
        }
        std::cout << " | Total: " << dealer.getHand().add() << std::endl;
        for(Player* player : players){
            std::cout << "Player's Hand: ";
            Hand& pHand = player->getHand();
            for(int i = 0; i < pHand.size(); i++){
                std::cout << pHand.getCard(i)->toString() << " ";
            }
            std::cout << " | Total: " << pHand.add() << " " << player->getWinnerString() << std::endl;
            //split hand printout
            if(!player->getHandSplit().isEmpty()){
                std::cout << "Player's Split Hand: ";
                Hand& psHand = player->getHandSplit();
                for(int i = 0; i < psHand.size(); i++){
                    std::cout << psHand.getCard(i)->toString() << " ";
                }
                std::cout << " | Total: " << psHand.add() << " " << player->getWinnerString() << std::endl;
            }
        }
            
}
//Balance printout after all runs
    std::cout << "Final Balances after " << runs << " runs:" << std::endl;
    for(Player* player : players){
        std::cout << player->getName() << ": ";
        player->printMoney();
    }
clearPlayers();
}