#include <iostream>
#include <vector>
#include <windows.h>

struct Card
{
    int value;
};

// Function to calculate the total value of a dealer's hand
int calculateDealersHandValue(const std::vector<Card> &hand)
{
    int total = 0;
    int acesCount = 0;

    for (const Card &card : hand)
    {
        total += card.value;
        if (card.value == 1)
        {
            acesCount++;
        }
    }

    // Adjust for Aces: if total is 11 or less, count Ace as 11
    while (total <= 11 && acesCount > 0)
    {
        total += 10;
        acesCount--;
    }

    return total;
}

// Function to calculate the total value of a player's hand, change with Fabians code
int calculatePlayersHandValue(const std::vector<Card> &hand)
{
    int total = 0;
    int acesCount = 0;

    for (const Card &card : hand)
    {
        total += card.value;
        if (card.value == 1)
        {
            acesCount++;
        }
    }

    while (total <= 11 && acesCount > 0)
    {
        total += 10;
        acesCount--;
    }

    return total;
}

void dealerTurn(std::vector<Card> &dealerHand, std::vector<Card> &deck, int &deckIndex)
{
    std::cout << "Dealer's turn:\n";

    while (true)
    {
        int handValue = calculateDealersHandValue(dealerHand);

        if (handValue >= 17)
        {
            break;
        }

        dealerHand.push_back(deck[deckIndex]);
        deckIndex++;

        std::cout << "Dealer draws a card: " << dealerHand.back().value << " (Total: " << handValue << ")\n";
        Sleep(2000);
    }

    std::cout << "Dealer has a total of " << calculateDealersHandValue(dealerHand) << ".\n";
}

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

int main()
{
    // Example setup (for demonstration purposes)
    std::vector<Card> deck = {{10}, {11}, {10}, {5}, {7}, {8}, {6}, {11}};
    std::vector<Card> dealerHand;
    std::vector<Card> playerHand;
    int deckIndex = 0;

    playerHand.push_back(deck[deckIndex++]); // Draw first card for player
    playerHand.push_back(deck[deckIndex++]); // Draw second card for player

    // Simulating the dealer's turn
    dealerTurn(dealerHand, deck, deckIndex);

    // Calculate hand values
    int playerHandValue = calculatePlayersHandValue(playerHand); // Calculate player's hand value
    int dealerHandValue = calculateDealersHandValue(dealerHand); // Calculate dealer's hand value

    // Determine the winner
    determineWinner(playerHandValue, dealerHandValue);

    return 0;
}
