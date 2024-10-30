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

    displayBlackjackRules();
    displayTwistRules();
    cardInfo card;
    std::string playerName = getPlayerName();
    std::vector<cardInfo> playerCards = {};
    playerCards.push_back(card = DrawCard());
    for (cardInfo card : playerCards)
    {
        std::cout << card.cardValue << " " << card.cardInfomation;
    }
}