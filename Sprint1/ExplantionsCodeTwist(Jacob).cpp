#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#define MAX_CARDS 10

// Structure for a card
struct Card
{
    std::string rank;
    std::string suit;
};

// Structure for the player
struct Player
{
    std::string name;
    Card hand[MAX_CARDS];
    int card_count = 0;
};

// Function to draw a card (simulates card drawing)
Card draw_card()
{
    std::string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    std::string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    Card card;
    card.rank = ranks[rand() % 13];
    card.suit = suits[rand() % 4];
    return card;
}

// Add a card to the player's hand
void add_card(Player &player, const Card &card)
{
    if (player.card_count < MAX_CARDS)
    {
        player.hand[player.card_count++] = card;
    }
}

// Display the player's hand
void show_hand(const Player &player)
{
    std::cout << player.name << "'s current hand:\n";
    for (int i = 0; i < player.card_count; i++)
    {
        std::cout << player.hand[i].rank << " of " << player.hand[i].suit << std::endl;
    }
    std::cout << std::endl;
}

// Double or Nothing: Doubles the player's bet and gives them only one more card
void double_or_nothing(Player &player, int &bet)
{
    bet *= 2;
    add_card(player, draw_card());
    show_hand(player);
    std::cout << "Double or Nothing chosen! Only one additional card.\n";
}

// Split: Splits the hand if the first two cards have the same rank
void split_hand(Player &player, Player &new_hand)
{
    if (player.card_count >= 2 && player.hand[0].rank == player.hand[1].rank)
    {
        new_hand.name = "Split Hand";
        new_hand.hand[0] = player.hand[1];
        player.card_count = 1;
        player.hand[1] = draw_card();
        new_hand.hand[1] = draw_card();
        new_hand.card_count = 2;
        std::cout << "Hand has been split!\n";
        show_hand(player);
        show_hand(new_hand);
    }
    else
    {
        std::cout << "Splitting not possible!\n";
    }
}

// Insurance: Allows insurance if the dealer shows an Ace
void insurance(Player &player, int &bet, bool dealer_has_blackjack)
{
    int insurance_bet = bet / 2;
    if (dealer_has_blackjack)
    {
        std::cout << "Insurance paid out! You receive 2:1 on your insurance.\n";
        bet += insurance_bet * 2;
    }
    else
    {
        std::cout << "No blackjack for dealer, insurance bet lost.\n";
        bet -= insurance_bet;
    }
}

// Surrender: Gives up the hand and loses half the bet
void surrender(Player &player, int &bet)
{
    bet /= 2;
    std::cout << "You have chosen to surrender and lose half your bet.\n";
    player.card_count = 0; // Clears the hand
}

// Push: Checks if the player and dealer scores are tied
bool check_push(int player_score, int dealer_score)
{
    if (player_score == dealer_score)
    {
        std::cout << "Push! Bet is returned.\n";
        return true; // Indicates push
    }
    return false;
}

// Calculate the player's score based on their cards
int calculate_score(const Player &player)
{
    int score = 0;
    for (int i = 0; i < player.card_count; i++)
    {
        if (player.hand[i].rank == "Ace")
        {
            score += 11;
        }
        else if (player.hand[i].rank == "King" || player.hand[i].rank == "Queen" || player.hand[i].rank == "Jack")
        {
            score += 10;
        }
        else
        {
            score += std::stoi(player.hand[i].rank);
        }
    }
    return score;
}

// Main game program
int main()
{
    srand(static_cast<unsigned>(time(0))); // Random seed for card drawing

    Player player, split_player;
    player.name = "Player 1";

    int bet = 100;
    std::cout << "Starting bet: " << bet << "\n";

    // Draw initial cards and display the player's hand
    add_card(player, draw_card());
    add_card(player, draw_card());
    show_hand(player);

    // Example usage of twist features
    double_or_nothing(player, bet);
    show_hand(player);

    // Add a card to test split
    add_card(player, draw_card());
    split_hand(player, split_player);

    // Simulate insurance (dealer does not have blackjack)
    bool dealer_has_blackjack = false;
    insurance(player, bet, dealer_has_blackjack);

    // Surrender example
    surrender(player, bet);

    // Calculate final score and check for push
    int player_score = calculate_score(player);
    int dealer_score = 20; // Example dealer score
    check_push(player_score, dealer_score);

    // Display final bet and score
    std::cout << "Final bet: " << bet << "\n";
    std::cout << "Player's final score: " << player_score << "\n";

    return 0;
}
