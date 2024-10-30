#include <iostream>
#include <vector>
#include <string>

void displayHandValue(const std::vector<Card> &hand, const std::string &playerName)
{
    int totalValue = calculateHandValue(hand);

    std::cout << playerName << "'s hand value" << totalValue << "\n";

    if (totalValue > 21)
    {
        std::cout << playerName << "BUUUUSTED!!\n";
    }
}