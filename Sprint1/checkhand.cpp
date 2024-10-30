#include <vector>
#include <string>

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