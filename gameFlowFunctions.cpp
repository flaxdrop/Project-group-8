#include <iostream>
#include <vector>
#include <algorithm> // For shuffle
#include <random>    // For random_device and mt19937

struct Card 
{
    int value;
};

using Deck = std::vector<Card>;


void shuffleDeck(Deck& deck);
void startNewRound(Deck& deck, std::vector<Card>& playerHand, std::vector<Card>& dealerHand);
bool promptNewRoundOrQuit();

// Main function with example deck/functions to test the code
int main() {
    Deck deck = { {10}, {2}, {1}, {5}, {7}, {8}, {6}, {10} }; 
    std::vector<Card> playerHand;
    std::vector<Card> dealerHand;

    bool playing = true;
    
    while (playing) 
    {
        if (promptNewRoundOrQuit()) 
        {
            startNewRound(deck, playerHand, dealerHand);  
        } else 
        {
            playing = false;
        }
    }

    return 0;
}

// Function to shuffle the deck
void shuffleDeck(Deck& deck) {
    std::random_device rd; // Seed for random number generator
    std::mt19937 g(rd());  // engine for shuffling
    std::shuffle(deck.begin(), deck.end(), g);
}

void startNewRound(Deck& deck, std::vector<Card>& playerHand, std::vector<Card>& dealerHand) 
{
    playerHand.clear();
    dealerHand.clear();

    shuffleDeck(deck);

    std::cout << "New round starting! The deck has been shuffled.\n";
}


// Function to prompt player to start a new round or quit
bool promptNewRoundOrQuit() 
{
    char choice;
    std::cout << "Would you like to start a new round or quit? (n for new round / q for quit): ";
    std::cin >> choice;

    if (choice == 'n' || choice == 'N') 
    {
        return true;
    } else 
    {
        std::cout << "Thanks for playing! Goodbye.\n";
        return false; 
    }
}
