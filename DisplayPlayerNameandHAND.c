#include <stdio.h>
#include <string.h>

#define MAX_CARDS 10


typedef struct {
    char rank[10];
    char suit[10];
} Card;


typedef struct {
    char name[20];
    Card hand[MAX_CARDS];
    int card_count;
} Player;


void add_card(Player *player, char *rank, char *suit) {
    if (player->card_count < MAX_CARDS) {
        strcpy(player->hand[player->card_count].rank, rank);
        strcpy(player->hand[player->card_count].suit, suit);
        player->card_count++;
    } else {
        printf("Handen är full!\n");
    }
}

void show_hand(Player *player) {
    printf("%s's aktuella hand:\n", player->name);
    for (int i = 0; i < player->card_count; i++) {
        printf("%s of %s\n", player->hand[i].rank, player->hand[i].suit);
    }
    printf("\n");
}

int main() {
    Player player;
    strcpy(player.name, "Spelare 1");
    player.card_count = 0;
    add_card(&player, "Ess", "Hjärter");
    show_hand(&player);

    add_card(&player, "10", "Klöver");
    show_hand(&player);

    return 0;
}
