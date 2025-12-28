#ifndef DEALER_H
#define DEALER_H

#include "Hand.h"
#include "Deck.h"

class Dealer{
    private:
        Hand hand;
        bool isPlaying = true;
    public:
        void hit(Deck& deck);
        void stand();
        void reset();
        bool wantsHit();
        Card* upCard();
};

#endif
