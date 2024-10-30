// For handling dealer's actions and automated decision-making.

#include <windows.h>
#include <iostream>
#include <string>
#include <vector>

void dealerTurn(std::vector<cardInfo> &dealerHand)
{
    cardInfo card;
    std::cout << "Dealer's turn:\n";
    while (true)
    {
        if (calculateHandValue(dealerHand) >= 17)
        {
            break;
        }

        dealerHand.push_back(card = DrawCard());

        std::cout << "Dealer draws a card: " << card.cardInfomation << " (Total: " << card.cardValue << ")\n";
        Sleep(2000);
    }

    std::cout << "Dealer has a total of " << calculateHandValue(dealerHand) << ".\n";
}
