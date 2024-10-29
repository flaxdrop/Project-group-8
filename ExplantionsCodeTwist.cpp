#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CARDS 10

// Structure for a card
typedef struct {
    char rank[10];
    char suit[10];
} Card;

// Structure for the player
typedef struct {
    char name[20];
    Card hand[MAX_CARDS];
    int card_count;
} Player;

// Function to draw a card (simulates card drawing)
Card draw_card() {
    char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    Card card;
    strcpy(card.rank, ranks[rand() % 13]);
    strcpy(card.suit, suits[rand() % 4]);
    return card;
}

// Add a card to the player's hand
void add_card(Player *player, Card card) {
    if (player->card_count < MAX_CARDS) {
        player->hand[player->card_count++] = card;
    }
}

// Display the player's hand
void show_hand(Player *player) {
    printf("%s's current hand:\n", player->name);
    for (int i = 0; i < player->card_count; i++) {
        printf("%s of %s\n", player->hand[i].rank, player->hand[i].suit);
    }
    printf("\n");
}

// Double or Nothing: Doubles the player's bet and gives them only one more card
void double_or_nothing(Player *player, int *bet) {
    *bet *= 2;
    add_card(player, draw_card());
    show_hand(player);
    printf("Double or Nothing chosen! Only one additional card.\n");
}

// Split: Splits the hand if the first two cards have the same rank
void split_hand(Player *player, Player *new_hand) {
    if (strcmp(player->hand[0].rank, player->hand[1].rank) == 0) {
        strcpy(new_hand->name, "Split Hand");
        new_hand->hand[0] = player->hand[1];
        player->card_count = 1;
        player->hand[1] = draw_card();
        new_hand->hand[1] = draw_card();
        new_hand->card_count = 2;
        printf("Hand has been split!\n");
        show_hand(player);
        show_hand(new_hand);
    } else {
        printf("Splitting not possible!\n");
    }
}

// Insurance: Allows insurance if the dealer shows an Ace
void insurance(Player *player, int *bet, int dealer_has_blackjack) {
    int insurance_bet = *bet / 2;
    if (dealer_has_blackjack) {
        printf("Insurance paid out! You receive 2:1 on your insurance.\n");
        *bet += insurance_bet * 2;
    } else {
        printf("No blackjack for dealer, insurance bet lost.\n");
        *bet -= insurance_bet;
    }
}

// Surrender: Gives up the hand and loses half the bet
void surrender(Player *player, int *bet) {
    *bet /= 2;
    printf("You have chosen to surrender and lose half your bet.\n");
    player->card_count = 0; // Clears the hand
}

// Push: Checks if the player and dealer scores are tied
int check_push(int player_score, int dealer_score) {
    if (player_score == dealer_score) {
        printf("Push! Bet is returned.\n");
        return 1; // Indicates push
    }
    return 0;
}

// Calculate the player's score based on their cards
int calculate_score(Player *player) {
    int score = 0;
    for (int i = 0; i < player->card_count; i++) {
        if (strcmp(player->hand[i].rank, "Ace") == 0) {
            score += 11;
        } else if (strcmp(player->hand[i].rank, "King") == 0 || strcmp(player->hand[i].rank, "Queen") == 0 || strcmp(player->hand[i].rank, "Jack") == 0) {
            score += 10;
        } else {
            score += atoi(player->hand[i].rank);
        }
    }
    return score;
}

// Main game program
int main() {
    srand(time(0));  // Random seed for card drawing

    Player player, split_player;
    strcpy(player.name, "Player 1");
    player.card_count = 0;
    split_player.card_count = 0;

    int bet = 100;
    printf("Starting bet: %d\n", bet);

    // Draw initial cards and display the player's hand
    add_card(&player, draw_card());
    add_card(&player, draw_card());
    show_hand(&player);

    // Example usage of twist features
    double_or_nothing(&player, &bet);
    show_hand(&player);

    // Add a card to test split
    add_card(&player, draw_card());
    split_hand(&player, &split_player);

    // Simulate insurance (dealer does not have blackjack)
    int dealer_has_blackjack = 0;
    insurance(&player, &bet, dealer_has_blackjack);

    // Surrender example
    surrender(&player, &bet);

    // Calculate final score and check for push
    int player_score = calculate_score(&player);
    int dealer_score = 20;  // Example dealer score
    check_push(player_score, dealer_score);

    // Display final bet and score
    printf("Final bet: %d\n", bet);
    printf("Player's final score: %d\n", player_score);

    return 0;
}
