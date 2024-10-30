// For displaying prompts, game status, and notifications.

#include <string>
#include <vector>

void displayHandValue(const std::vector<Card> &hand, const std::string &playerName)
{
    int totalValue = calculateHandValue(hand);

    std::cout << playerName << "'s hand value" << totalValue << "\n";

    if (totalValue > 21)
    {
        std::cout << playerName << "BUUUUSTED!!\n";
    }
}

int calculateHandValue(const std::vector<Card> &hand)
{

    int totalValue = 0;
    int acesCount = 0;

    for (const Card &card : hand)
    {
        if (card.value == 1) // ace
        {
            acesCount++;
            totalValue += 11; // räknar först ace som 11
        }
        else if (card.value > 10) // ansikts kort
        {
            totalValue += 10;
        }
        else
        {
            totalValue += card.value; // vanliga kort
        }
    }
    while (totalValue > 21 && acesCount > 0) // denna kollar ifall det blir över 21 med ace
    {
        totalValue -= 10; // denna ändrar ace till 1 om det behövs.
        acesCount--;
    }

    return totalValue;
}

void show_hand(const PlayerRef player)
{
    std::cout << player.name << "'s current hand:" << std::endl;
    for (int i = 0; i < player.card_count; i++)
    {
        std::cout << player.hand[i].rank << " of " << player.hand[i].suit << std::endl;
    }
    std::cout << std::endl;
}
