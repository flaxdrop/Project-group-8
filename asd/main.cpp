
#include <iostream>
#include <vector>
#include <algorithm>
#include <random> // Include for std::random_device and std::default_random_engine
#include <string> // Include for std::string

using namespace std;

// Card structure to store card value and suit
struct Card
{
    string suit;
    int value;
};

// Deck class to initialize, shuffle, and draw cards
class Deck
{
    vector<Card> cards;

public:
    Deck()
    {
        string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
        for (const string &suit : suits)
        {
            for (int value = 1; value <= 13; ++value)
            {
                cards.push_back({suit, value});
            }
        }
        shuffleDeck();
    }

    void shuffleDeck()
    {
        random_device rd;

        default_random_engine eng(rd());

        shuffle(cards.begin(), cards.end(), eng);
    }

    Card drawCard()
    {
        Card card = cards.back();
        cards.pop_back();
        return card;
    }
};

// Function to calculate hand value, treating Ace as 1 or 11
int calculateScore(const vector<Card> &hand)
{
    int score = 0, aces = 0;
    for (const Card &card : hand)
    {
        if (card.value >= 10)
            score += 10; // Face cards (J, Q, K)
        else if (card.value == 1)
        { // Ace
            score += 11;
            aces++;
        }
        else
            score += card.value;

        // Adjust if score > 21 and there are aces counted as 11
        while (score > 21 && aces > 0)
        {
            score -= 10;
            aces--;
        }
    }
    return score;
}

// Display hand function for player and dealer
void displayHand(const vector<Card> &hand, const string &name)
{
    cout << name << "'s hand: ";
    for (const Card &card : hand)
    {
        cout << (card.value == 1 ? "A" : (card.value > 10 ? "10" : to_string(card.value)))
             << " of " << card.suit << ", ";
    }
    cout << " (Score: " << calculateScore(hand) << ")\n";
}

// ... (other parts of your code remain unchanged)

int main()
{
    Deck deck;
    vector<Card> playerHand, dealerHand;
    char choice;
    int bet, balance = 1000; // Starting balance for player

    while (true)
    {
        // Start a new round
        playerHand.clear();
        dealerHand.clear();
        cout << "Balance: $" << balance << "\nPlace your bet: ";
        cin >> bet;

        if (bet > balance)
        {
            cout << "You don't have enough money to bet that amount!\n";
            continue;
        }

        // Initial deal: two cards for player and dealer
        playerHand.push_back(deck.drawCard());
        playerHand.push_back(deck.drawCard());
        dealerHand.push_back(deck.drawCard());
        dealerHand.push_back(deck.drawCard());

        // Display the dealer's first card
        cout << "Dealer's visible card: "
             << (dealerHand[0].value == 1 ? "A" : (dealerHand[0].value > 10 ? "10" : to_string(dealerHand[0].value)))
             << " of " << dealerHand[0].suit << "\n";

        // Player's turn
        while (true)
        {
            displayHand(playerHand, "Player");
            if (calculateScore(playerHand) > 21)
            {
                cout << "You bust! You lose $" << bet << "\n";
                balance -= bet;
                break;
            }
            cout << "Do you want to (H)it or (S)tand? ";
            cin >> choice;
            if (choice == 'S' || choice == 's')
                break;
            playerHand.push_back(deck.drawCard());
        }

        // Dealer's turn (only if player didn't bust)
        if (calculateScore(playerHand) <= 21)
        {
            // Show the dealer's visible card
            cout << "Dealer's visible card: "
                 << (dealerHand[0].value == 1 ? "A" : (dealerHand[0].value > 10 ? "10" : to_string(dealerHand[0].value)))
                 << " of " << dealerHand[0].suit << "\n";

            // The dealer will draw cards until reaching a score of 17 or higher
            while (calculateScore(dealerHand) < 17)
            {
                dealerHand.push_back(deck.drawCard());
            }

            // Show the dealer's full hand after drawing
            cout << "Dealer's full hand: ";
            displayHand(dealerHand, "Dealer");

            // Determine outcome
            int playerScore = calculateScore(playerHand);
            int dealerScore = calculateScore(dealerHand);
            if (dealerScore > 21 || playerScore > dealerScore)
            {
                cout << "You win! You gain $" << bet << "\n";
                balance += bet;
            }
            else if (playerScore < dealerScore)
            {
                cout << "Dealer wins. You lose $" << bet << "\n";
                balance -= bet;
            }
            else
            {
                cout << "It's a tie! No money lost or won.\n";
            }
        }

        // Check if player wants to continue
        if (balance <= 0)
        {
            cout << "You're out of money! Game over.\n";
            break;
        }
        cout << "Play another round? (Y/N): ";
        cin >> choice;
        if (choice == 'N' || choice == 'n')
            break;
    }
    return 0;
}
