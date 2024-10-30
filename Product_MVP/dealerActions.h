// For handling dealer's actions and automated decision-making.

#include <string>
#include <vector>

void dealerTurn(std::vector<Card> &dealerHand, std::vector<Card> &deck, int &deckIndex)
{
    std::cout << "Dealer's turn:\n";

    while (true)
    {
        int handValue = calculateHandValue(dealerHand);

        if (handValue >= 17)
        {
            break;
        }

        dealerHand.push_back(deck[deckIndex]);
        deckIndex++;

        std::cout << "Dealer draws a card: " << dealerHand.back().value << " (Total: " << handValue << ")\n";
        Sleep(2000);
    }

    std::cout << "Dealer has a total of " << calculateHandValue(dealerHand) << ".\n";
}
