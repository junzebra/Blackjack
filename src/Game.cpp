#include "../include/Game.h"
#include <iostream>

void Game::initPlayers(){
    players.push_back(new Amateur(1000,50));
    players.push_back(new Textbook(1000,50));
    players.push_back(new CardCounter(1000,50));
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

void Game::run() {
    initPlayers();
    deck.setArray();
    deck.shuffle();
    deck.resetCardCount();
    clearPlayers();
}