#include <iostream>
#include <string>
#include <vector>
#include "deck.h"
#include "dealerActions.h"
#include "gameSetup.h"
#include "persistence.h"
#include "playerActions.h"
#include "scoreKeeping.h"
#include "twistMechanics.h"
#include "userInterface.h"

int main()
{
    std::vector<cardInfo> dealerHand;
    std::vector<cardInfo> playerHand;

    displayBlackjackRules();
    displayTwistRules();
    cardInfo card;
    std::string playerName = getPlayerName();
    std::vector<cardInfo> playerCards = {};

    playerHand.push_back(card = DrawCard()); // Draw first card for player
    playerHand.push_back(card = DrawCard()); // Draw second card for player

    // Simulating the dealer's turn
    dealerHand.push_back(dealerTurn(dealerHand));

    // Calculate hand values
    int playerHandValue = calculateHandValue(playerHand); // Calculate player's hand value
    int dealerHandValue = calculateHandValue(dealerHand); // Calculate dealer's hand value

    // Determine the winner
    determineWinner(playerHandValue, dealerHandValue);

    return 0;
}