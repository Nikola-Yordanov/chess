#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdbool.h>

#define SIZE 8

#define B_KING 'K'
#define B_QUEEN 'Q'
#define B_ROOK 'R'
#define B_BISHOP 'B'
#define B_KNIGHT 'H'
#define B_PON 'P'

#define W_KING 'k'
#define W_QUEEN 'q'
#define W_ROOK 'r'
#define W_BISHOP 'b'
#define W_KNIGHT 'h'
#define W_PON 'p'

char board[SIZE][SIZE];

//--------------------------------------------------------------------------------------
void fill_board()
{
    for (int y = 0; y < SIZE; y++)
        for (int x = 0; x < SIZE; x++)
            board[y][x] = ' ';

    board[0][0] = board[0][SIZE - 1] = B_ROOK;
    board[0][1] = board[0][SIZE - 2] = B_KNIGHT;
    board[0][2] = board[0][SIZE - 3] = B_BISHOP;
    board[0][3] = B_QUEEN;
    board[0][SIZE - 4] = B_KING;
    for (int i = 0; i < 8; i++)
        board[1][i] = B_PON;

    board[SIZE - 1][0] = board[SIZE - 1][SIZE - 1] = W_ROOK;
    board[SIZE - 1][1] = board[SIZE - 1][SIZE - 2] = W_KNIGHT;
    board[SIZE - 1][2] = board[SIZE - 1][SIZE - 3] = W_BISHOP;
    board[SIZE - 1][3] = W_QUEEN;
    board[SIZE - 1][SIZE - 4] = W_KING;
    for (int i = 0; i < 8; i++)
        board[SIZE - 2][i] = W_PON;
}

void print_board()
{
    for (int y = 0; y < SIZE; y++)
    {
        for (int x = 0; x < SIZE; x++)
            printf("%c ", board[y][x]);
        printf("\n");
    }
}

//--------------------------------------------------------------------------------------
void get_moves_for_peice(int x, int y, bool(*avl_moves)[SIZE], char(*board)[SIZE], char piece, char a, char b);


void move_piece(int step)
{
    char v1, v2, v3, v4;
    if (step)
        v1 = 'A', v2 = 'Z';
    else
        v1 = 'a', v2 = 'z';

    int x = 0, y = 0;
    printf("enter cords of the piece you want to move\n");
    scanf("%d", &x);
    scanf("%d", &y);
    while (board[y][x] < v1 || board[y][x] > v2)
    {
        printf("wrong cords try agayn\n");
        scanf("%d", &x);
        scanf("%d", &y);
    }

    bool avl_moves[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            avl_moves[i][j] = 0;

    get_moves_for_peice(x, y, avl_moves, board, board[y][x], v1, v2);

    int px, py;
    printf("enter were you want to move the piece\n");
    scanf("%d", &px);
    scanf("%d", &py);
    while (!avl_moves[py][px])
    {
        printf("wrong cords try agayn\n");
        scanf("%d", &px);
        scanf("%d", &py);
    }

    board[py][px] = board[y][x];
    board[y][x] = ' ';
}
//---------------------------------------------------------------------------------------

int main()
{
    fill_board();
    for (int i = 0;; i++)
    {
        print_board();
        if (i % 2 == 0)
        {
            printf("White\n");
            move_piece(1);
        }
        else
        {
            printf("Black\n");
            move_piece(0);
        }
    }
    return 0;
}