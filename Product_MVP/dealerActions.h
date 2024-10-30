// For handling dealer's actions and automated decision-making.

#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "userInterface.h"

cardInfo dealerTurn(std::vector<cardInfo> &dealerHand)
{
    cardInfo card;
    int value = 0;
    std::cout << "Dealer's turn:\n";
    while (true)
    {
        value = calculateHandValue(dealerHand);
        if (value >= 17)
        {
            break;
        }

        dealerHand.push_back(card = DrawCard());

        std::cout << "Dealer draws a card: " << card.cardInfomation << " (Total: " << card.cardValue << ")\n";
        Sleep(2000);
    }

    std::cout << "Dealer has a total of " << value << ".\n";
}
