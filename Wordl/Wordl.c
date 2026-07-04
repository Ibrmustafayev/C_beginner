#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int wordl(char word[], const char target[]);

int main() {
    srand(time(NULL));

    const char *word_list[100] = {"apple", "beach", "chief", "dance", "eagle", "flame", "giant", "house", "index", "juice", "knife", "lemon", "magic", "night", "ocean", "paper",
        "queen", "radio", "snake", "table", "uncle", "voice", "water", "young", "zebra", "about", "bread", "candy", "dream", "earth", "frost", "green", "heavy", "irony", "joker",
        "light", "march", "never", "onion", "pilot", "quite", "river", "smart", "train", "under", "vivid", "whale", "yield", "agent", "brave", "crane", "dirty", "early", "focus",
        "grace", "hotel", "image", "joint", "knock", "laugh", "match", "novel", "order", "phase", "range", "scale", "tiger", "unity", "value", "world", "actor", "blind", "cloud",
        "draft", "exact", "frame", "graph", "heart", "ivory", "judge", "layer", "metal", "noble", "outer", "print", "rough", "stage", "trace", "urban", "vocal", "watch", "zones",
        "basic", "clerk", "dairy", "event", "fluid", "grand", "honey", "ideal"};
    char current[] = "_____";
    const char *target = word_list[rand() % 100];
    while (1) {
        int stop = wordl(current, target);
        if (stop) {printf("\n\033[0;32m!!!WIN!!!\033[0m"); break;}
    }

    return 0;
}

int wordl(char current[], const char target[]) {
    char guess[50];

    while (1) {
        printf("\n[ %s ] \n> ", current);
        scanf("%50s", guess);
        if (strlen(guess) != 5) {printf("<!> The length must be 5.\n");}
        else {break;}
    }
    for (int i = 0; i < 5; i++) {guess[i] = tolower(guess[i]);}

    int target_used[5] = {0, 0, 0, 0, 0}, guess_status[5] = {0};

    for (int i = 0; i < 5; i++) {
        if (guess[i] == target[i]) {
            guess_status[i] = 2;
            target_used[i] = 1;
            current[i] = guess[i];
        }
    }

    for (int i = 0; i < 5; i++) {
        if (guess_status[i] == 2) {continue;}
        for (int j = 0; j < 5; j++) {
            if (!target_used[j] && guess[i] == target[j]) {
                target_used[j] = 1;
                guess_status[i] = 1;
                break;
            }
        }
    }

    printf("[ ");
    for (int i = 0; i < strlen(guess); i++) {
        if (guess_status[i] == 1) {
            printf("\033[0;33m%c\033[0m", guess[i]);
        } else if (guess_status[i] == 2) {
            printf("\033[0;32m%c\033[0m", guess[i]);
        } else {
            printf("%c", guess[i]);
        }
    }
    printf(" ]\n");

    if (strcmp(guess, target) == 0) {return 1;}
    return 0;
}
