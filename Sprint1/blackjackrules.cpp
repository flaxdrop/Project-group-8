#include <iostream>

void displayBlackjackRules()
{

    std::cout << "Welcome to Blackjack!\n";
    std::cout << "Rules!\n";
    std::cout << "1. The goal of the game is to get as close to 21 as possible without going over.\n";
    std::cout << "2. The number cards are worth their face value.\n";
    std::cout << "3. Face cards (Jack, Queen and King) Are worth 10.\n";
    std::cout << "4. Aces are either 1 or 11 depending on whats more favorable.\n";
    std::cout << "5. You can either hit (draw a card) or stand (End your turn).\n";
    std::cout << "6. If your hand exceeds 21, you bust and lose the round.\n";
    std::cout << "7. The dealer must hit until their total is atleast 17.\n";
    std::cout << "8. Whoever is closest to 21 without busting wins the round!\n";
    std::cout << "Good luck!\n";
}