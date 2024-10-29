#include <iostream>
#include <string>

// Task Display the current hand value and status messages
void displayHandValue(const std::string &player, int handValue, bool isDealer) 
{
    std::cout << (isDealer ? "Dealer's" : "Player's") << " Hand Value: " << handValue << std::endl;
    if (handValue > 21) 
    {
        std::cout << (isDealer ? "Dealer" : "Player") << " has busted!" << std::endl;
    } else if (handValue == 21) 
    {
        std::cout << (isDealer ? "Dealer" : "Player") << " has Blackjack!" << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;
}
