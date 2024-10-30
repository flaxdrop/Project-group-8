#include <iostream>
#include <string>
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
    cardInfo card;
    card = DrawCard();
    std::string playerName = getPlayerName();
    std::cout << playerName;
}