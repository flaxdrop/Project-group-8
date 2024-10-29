#include <iostream>
#include <vector>
#include <string>

int randomCard();

struct cardInfo // Storing card Value
{
    int cardValue;              // The value to use when calc
    std::string cardInfomation; // String to display card
};
class Deck
{
public:
    // All cards in deck
    std::vector<std::string> color = {"♥", "♦", "♠", "♣"};
    std::vector<int> value = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
};
cardInfo DrawCard()
{
    // Draw new card to CardInfo
    Deck deck;
    srand(time(0));
    int cardDrawnValue = deck.value.at(0 + rand() % 12); // Draw a random card
    std::string cardInfo = deck.color.at(0 + rand() % 3) + " ";
    switch (cardDrawnValue) // Sets name for all clothing cards
    {
    case 1:
        cardInfo += "Ace";
        break;
    case 11:
        cardInfo += "Queen";
        break;
    case 12:
        cardInfo += "King";
        break;
    default:
        cardInfo += std::to_string(cardDrawnValue);
        break;
    }
    if (cardDrawnValue > 10)
    {
        cardDrawnValue = 10;
    }
    return {cardDrawnValue, cardInfo};
}