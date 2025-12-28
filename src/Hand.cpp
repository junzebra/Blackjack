#include "../include/Hand.h"

int Hand::add(){
    int sum = 0;
    for(Card* n : cards){
        if(n->getRank() == Rank::Ace){
            int temp = sum + 11;
            if(temp > 21){
                sum += 1;
            }
        }
        else{
        sum += n->getVal();
        }
    }
}

void Hand::reset(){
    cards.clear();
}

void Hand::append(Card* k){
    cards.push_back(k);
}

void Hand::pop(){
    cards.pop_back();
}

bool Hand::isEmpty(){
    return cards.empty();
}

Card* Hand::getCard(int n){
    return cards[n];
}