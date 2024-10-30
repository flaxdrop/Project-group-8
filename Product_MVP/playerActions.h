// For implementing player actions (hit, stand, bust).

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Card
{
public:
    int value;
    Card(int v) : value(v) {}
};

class Player
{
private:
    std::vector<Card> hand;
    int totalValue;

public:
    Player() : totalValue(0) {}

    void addCard(Card card)
    {
        hand.push_back(card);
        totalValue += card.value;
        std::cout << "You drew a card with value: " << card.value << std::endl;
        checkBust();
    }
    int getTotalValue() const
    {
        return totalValue;
    }

    void checkBust()
    {
        if (totalValue > 21)
        {
            std::cout << "Bust! Your total is: " << totalValue << "You lose your turn. " << std::endl;
        }
    }
    void displayHand() const
    {
        std::cout << "Your hand total: " << totalValue << std::endl;
    }
    bool hasBusted()
    {
        return totalValue > 21;
    }
};

class Game
{
public:
    void play()
    {
        Player player;
        bool playerTurn = true;

        while (playerTurn)
        {
            player.displayHand();
            std::cout << "Chose an action: (1) Hit (2) Stand" << std::endl;
            int choice;
            std::cin >> choice;

            if (choice == 1)
            {
                Card newCard(rand() % 11 + 1);
                player.addCard(newCard);
                if (player.hasBusted())
                {
                    playerTurn = false;
                }
            }
            else if (choice == 2)
            {
                std::cout << "You chose to stand, end of turn." << std::endl;
                playerTurn = false;
            }
            else
            {
                std::cout << "Invalid choice. Choose 1 or 2." << std::endl;
            }
        }
    }
};
