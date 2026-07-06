#include <stdio.h>
#include <string.h>

void printBoard(const char board[3][3]);
int win(const char board[3][3]);

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int turn = 0;

    char player1[50], player2[50];
    printf("Welcome to Tic Tac Toe!!!\n\nEnter a name for 'Player 1': ");
    fgets(player1, 50,  stdin);
    player1[strcspn(player1, "\n")] = '\0';
    printf("Enter a name for 'Player 2': ");
    fgets(player2, 50, stdin);
    player2[strcspn(player2, "\n")] = '\0';
    printf("\n");

    while (1) {
        int position[2] = {-1, -1};

        printf("\n");
        printBoard(board);
        (turn % 2 == 0) ? printf("\n%s's turn: \n", player1) : printf("\n%s's turn: \n", player2);
        
        while (1) {
            printf("Enter the position (e.g. 2 2): ");
            scanf("%d %d", &position[0], &position[1]);

            if (position[0] > 0 && position[0] < 4 && position[1] > 0 && position[1] < 4) {
                if (board[position[0] - 1][position[1] - 1] == ' ') {
                    break;
                } else {
                    printf("Error: Already-taken spot!\n");
                }
            } else {
                printf("Error: Invalid postion! (0 < x < 4 | 0 < y < 4)\n");
            }
        }

        board[position[0] - 1][position[1] - 1] = (turn % 2 == 0) ? 'x' : 'o';

        if (win(board)) {
            printBoard(board);
            printf((turn % 2 == 0) ? "\n\n!!!WIN!!! Player 1 won!" : "\n\n!!!WIN!!! Player 2 won!");
            break;
        }

        if (turn == 8) {
            printBoard(board);
            printf("\n\n=== TIE === It's a tie game!");
            break;
        }

        turn++;
    }

    return 0;
}

void printBoard(const char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        (i != 2) ? printf(" %c | %c | %c \n___|___|___\n", board[i][0], board[i][1], board[i][2]) : printf(" %c | %c | %c \n   |   |   \n", board[i][0], board[i][1], board[i][2]);
    }
}

int win(const char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ' || board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }

    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[1][1] == board[2][0]) && board[1][1] != ' ') {return 1;}

    return 0;
}
