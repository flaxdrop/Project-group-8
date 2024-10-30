#include <iostream>
#include <string>

#define MAX_CARDS 10

// Typedef for reference to Card and Player structs
typedef struct Card &CardRef;
typedef struct Player &PlayerRef;

struct Card
{
    std::string rank;
    std::string suit;
};

struct Player
{
    std::string name;
    Card hand[MAX_CARDS];
    int card_count = 0;
};

void add_card(PlayerRef player, const std::string &rank, const std::string &suit)
{
    if (player.card_count < MAX_CARDS)
    {
        player.hand[player.card_count].rank = rank;
        player.hand[player.card_count].suit = suit;
        player.card_count++;
    }
    else
    {
        std::cout << "The hand is full!" << std::endl;
    }
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

int main()
{
    Player player;
    player.name = "Player 1";
    add_card(player, "Ace", "Hearts");
    show_hand(player);

    add_card(player, "10", "Clubs");
    show_hand(player);

    return 0;
}
