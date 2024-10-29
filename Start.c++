#include <iostream>
#include "Deck.h"

int main()
{
    Deck card;
    cardInfo drawnCard = DrawCard();
    std::cout << drawnCard.cardValue << " " << drawnCard.cardInfomation;
}