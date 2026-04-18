#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Card {
    char suit[20];
    int value;
};

void add_full_cards(struct Card *cards);
void shuffle(struct Card *cards);
void deal(struct Card *deal_cards, struct Card *cards, int deal_count);

int main() {
    srand(time(NULL));

    struct Card cards[52];
    add_full_cards(cards);
    shuffle(cards);

    int deal_count;
    while (1) {
        printf("How many cards to deal? ");
        scanf("%d", &deal_count);
        if (deal_count > 0 && deal_count <= 52) {
            break;
        }
    }

    struct Card deal_cards[deal_count];
    deal(deal_cards, cards, deal_count);

    int hand_value = 0;
    printf("\nYour hand:\n");
    for (int i = 0; i < deal_count; i++) {
        printf("  %s\n", deal_cards[i].suit);
        hand_value += deal_cards[i].value;
    }

    printf("\nHand value: %d", hand_value);

    return 0;
}

void add_full_cards(struct Card *cards) {
    const char *part1[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    const char *part2[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            int index = i * 4 + j;
            snprintf(cards[index].suit, sizeof(cards[index].suit), "%s of %s", part1[i], part2[j]);
            if (i > 0 && i <= 9) {
                cards[index].value = i + 1;
            } else if (i == 0) {
                cards[index].value = 11;
            } else {
                cards[index].value = 10;
            }
        }
    }
}

void shuffle(struct Card *cards) {
    for (int i = 51; i > 0; i--) {
        int j = rand() % (i + 1);

        struct Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void deal(struct Card *deal_cards, struct Card *cards, int deal_count) {
    for (int i = 0; i < deal_count; i++) {
        deal_cards[i] = cards[i];
    }
}
