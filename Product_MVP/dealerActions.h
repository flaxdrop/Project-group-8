//For handling dealer's actions and automated decision-making.


#include <windows.h>
#include <iostream>
#include <string>
#include <vector>

void dealerTurn(std::vector<cardInfo> &dealerHand)
{
    std::cout << "Dealer's turn:\n";

    while (true)
    {
        int handValue = calculateHandValue(dealerHand);

        if (handValue >= 17)
        {
            break;
        }

        dealerHand.push_back(DrawCard());
    
        std::cout << "Dealer draws a card: " << dealerHand << " (Total: " << handValue << ")\n";
        Sleep(2000);
    }

    std::cout << "Dealer has a total of " << calculateHandValue(dealerHand) << ".\n";
}






