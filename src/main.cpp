
#include "../include/Game.h"
#include <iostream>

int main() {
    Game game;

    std::cout<<"Enter number of rounds to simulate: ";
    int n;
    std::cin>>n;
    game.run(n);
    return 0;
}
