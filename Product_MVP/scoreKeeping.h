// For tracking wins, losses, and displaying scores.


#define GAMESETUP_H

#include <string>
#include <vector>

void determineWinner(int playerHandValue, int dealerHandValue)
{
    std::cout << "Final Hand Values:\n";
    std::cout << "Player's Hand Value: " << playerHandValue << "\n";
    std::cout << "Dealer's Hand Value: " << dealerHandValue << "\n";

    if (playerHandValue > 21)
    {
        std::cout << "Player busts! Dealer wins.\n";
    }
    else if (dealerHandValue > 21)
    {
        std::cout << "Dealer busts! Player wins.\n";
    }
    else if (playerHandValue > dealerHandValue)
    {
        std::cout << "Player wins!\n";
    }
    else if (dealerHandValue > playerHandValue)
    {
        std::cout << "Dealer wins!\n";
    }
    else
    {
        std::cout << "Dealer wins!\n";
    }
}
#endif
