#include <stdio.h>

int main() {
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    int choice, player = 1;
    char mark;

    for (int turn = 0; turn < 9; turn++) {
        printf("\n");
        printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
        printf("---|---|---\n");
        printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
        printf("---|---|---\n");
        printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);

        mark = (player == 1) ? 'X' : 'O';

        printf("\nPlayer %d (%c), enter position: ", player, mark);
        scanf("%d", &choice);

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Invalid move! Try again.\n");
            turn--;
            continue;
        }

        board[row][col] = mark;

        // Check rows and columns
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) ||
                (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)) {
                printf("\nPlayer %d wins!\n", player);
                return 0;
            }
        }

        // Check diagonals
        if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
            (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)) {
            printf("\nPlayer %d wins!\n", player);
            return 0;
        }

        player = (player == 1) ? 2 : 1;
    }

    printf("\nIt's a draw!\n");

    return 0;
}
