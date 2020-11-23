#include <stdbool.h>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//---------------------------------------------------------------------------------------
#define SIZE 8

#define B_KING 'K'
#define B_QUEEN 'Q'
#define B_ROOK 'R'
#define B_BISHOP 'B'
#define B_KNIGHT 'H'
#define B_PAWN 'P'

#define W_KING 'k'
#define W_QUEEN 'q'
#define W_ROOK 'r'
#define W_BISHOP 'b'
#define W_KNIGHT 'h'
#define W_PAWN 'p'

//--------------------------------------------------------------------------------------------------------------------------------------------------------
void knight_avl_moves(int x, int y, bool(*avl_moves)[SIZE], const char(*board)[SIZE], char a, char b)
{
    if (x + 1 < SIZE && y + 2 < SIZE && (board[y + 2][x + 1] == ' ' || board[y + 2][x + 1] < a || board[y + 2][x + 1] > b))
        avl_moves[y + 2][x + 1] = 1;

    if (x + 1 < SIZE && y - 2 >= 0 && (board[y - 2][x + 1] == ' ' || board[y - 2][x + 1] < a || board[y - 2][x + 1] > b))
        avl_moves[y - 2][x + 1] = 1;

    if (x - 1 >= 0 && y + 2 < SIZE && (board[y + 2][x - 1] == ' ' || board[y + 2][x - 1] < a || board[y + 2][x - 1] > b))
        avl_moves[y + 2][x - 1] = 1;

    if (x - 1 >= 0 && y - 2 >= 0 && (board[y - 2][x - 1] == ' ' || board[y - 2][x - 1] < a || board[y - 2][x - 1] > b))
        avl_moves[y - 2][x - 1] = 1;

    if (x + 2 < SIZE && y + 1 < SIZE && (board[y + 1][x + 2] == ' ' || board[y + 1][x + 2] < a || board[y + 1][x + 2] > b))
        avl_moves[y + 1][x + 2] = 1;

    if (x + 2 < SIZE && y - 1 >= 0 && (board[y - 1][x + 2] == ' ' || board[y - 1][x + 2] < a || board[y - 1][x + 2] > b))
        avl_moves[y - 1][x + 2] = 1;

    if (x - 2 >= 0 && y + 1 < SIZE && (board[y + 1][x - 2] == ' ' || board[y + 1][x - 2] < a || board[y + 1][x - 2] > b))
        avl_moves[y + 1][x - 2] = 1;

    if (x - 2 >= 0 && y - 1 >= 0 && (board[y - 1][x - 2] == ' ' || board[y - 1][x - 2] < a || board[y - 1][x - 2] > b))
        avl_moves[y - 1][x - 2] = 1;
}

void bishop_avl_moves(int x, int y, bool(*avl_moves)[SIZE], const char(*board)[SIZE], char a, char b)
{
    int i = 1;
    while (x + i < SIZE && y + i < SIZE)
    {
        if (board[y + i][x + i] == ' ')
            avl_moves[y + i][x + i] = 1;

        else if (board[y + i][x + i] < a || board[y + i][x + i] > b)
        {
            avl_moves[y + i][x + i] = 1;
            break;
        }
        else break;
        i++;
    }i = 0;

    while (x - i >= 0 && y - i >= 0)
    {
        if (board[y - i][x - i] == ' ')
            avl_moves[y - i][x - i] = 1;

        else if (board[y - i][x - i] < a || board[y - i][x - i] > b)
        {
            avl_moves[y - i][x - i] = 1;
            break;
        }
        else break;
        i++;
    }i = 0;

    while (x + i < SIZE && y - i >= 0)
    {
        if (board[y - i][x + i] == ' ')
            avl_moves[y - i][x + i] = 1;

        else if (board[y - i][x + i] < a || board[y - i][x + i] > b)
        {
            avl_moves[y - i][x + i] = 1;
            break;
        }
        else break;
        i++;
    }i = 0;

    while (x - i >= 0 && y + i < SIZE)
    {
        if (board[y + i][x - i] == ' ')
            avl_moves[y + i][x - i] = 1;

        else if (board[y + i][x - i] < a || board[y + i][x - i] > b)
        {
            avl_moves[y + i][x - i] = 1;
            break;
        }
        else break;
        i++;
    }
}

void rook_avl_moves(int x, int y, bool(*avl_moves)[SIZE], const char(*board)[SIZE], char a, char b)
{
    int i = 0;
    while (x + i < SIZE)
    {
        if (board[y][x + i] == ' ')
            avl_moves[y][x + i] = 1;
        else if (board[y][x + i] < a || board[y][x + i] > b)
        {
            avl_moves[y][x + i] = 1;
            break;
        }
        else break;
        i++;
    }
    i = 0;
    while (x - i >= 0)
    {
        if (board[y][x - i] == ' ')
            avl_moves[y][x - i] = 1;
        else if (board[y][x - i] < a || board[y][x - i] > b)
        {
            avl_moves[y][x - i] = 1;
            break;
        }
        else break;
        i++;
    }
    i = 0;
    while (y + i < SIZE)
    {
        if (board[y + i][x] == ' ')
            avl_moves[y + i][x] = 1;
        else if (board[y + i][x] < a || board[y + i][x] > b)
        {
            avl_moves[y + i][x] = 1;
            break;
        }
        else break;
        i++;
    }
    i = 0;
    while (y - i >= 0)
    {
        if (board[y - i][x] == ' ')
            avl_moves[y - i][x] = 1;
        else if (board[y - i][x] < a || board[y - i][x] > b)
        {
            avl_moves[y - i][x] = 1;
            break;
        }
        else break;
        i++;
    }
}

void queen_avl_moves(int x, int y, bool(*avl_moves)[SIZE], const char(*board)[SIZE], char a, char b)
{
    rook_avl_moves(x, y, avl_moves, board, a, b);
    bishop_avl_moves(x, y, avl_moves, board, a, b);
}


void pon_avl_moves(int x, int y, bool(*avl_moves)[SIZE], const char(*board)[SIZE], char Pon)
{
    if (Pon == B_PAWN)
        for (int i = 0; i < SIZE; i++)
        {
            if (y == 1 && board[y + 2][i] == ' ')
            {
                avl_moves[y + 2][i] = 1;
                avl_moves[y + 1][i] = 1;
            }
            else if (y + 1 < SIZE && board[y + 1][i] == ' ')
                avl_moves[y + 1][i] = 1;

            if (y + 1 < SIZE && x + 1 < SIZE && (board[y + 1][x + 1] < 'A' || board[y + 1][x + 1] > 'Z'))
                avl_moves[y + 1][x + 1] = 1;

            if (y + 1 < SIZE && x - 1 >= 0 && (board[y + 1][x - 1] < 'A' || board[y + 1][x - 1] > 'Z'))
                avl_moves[y + 1][x - 1] = 1;
        }

    else
        for (int i = 0; i < SIZE; i++)
        {
            if (y == 6 && board[y - 2][i] == ' ')
            {
                avl_moves[y - 2][i] = 1;
                avl_moves[y - 1][i] = 1;
            }
            else if (y - 1 >= 0 && board[y - 1][i] == ' ')
                avl_moves[y - 1][i] = 1;

            if (y - 1 >= 0 && x + 1 < SIZE && (board[y - 1][x + 1] < 'A' || board[y - 1][x + 1] > 'Z'))
                avl_moves[y - 1][x + 1] = 1;

            if (y - 1 >= 0 && x - 1 >= 0 && (board[y - 1][x - 1] < 'A' || board[y - 1][x - 1] > 'Z'))
                avl_moves[y - 1][x - 1] = 1;
        }
}

void piece_avl_positions(char piece, int x, int y, bool(*avl_moves)[SIZE], const char(*board)[SIZE], char a, char b)
{
    if (board[y][x] == B_QUEEN || board[y][x] == W_QUEEN)
        queen_avl_moves(x, y, avl_moves, board, a, b);

    if (board[y][x] == B_ROOK || board[y][x] == W_ROOK)
        rook_avl_moves(x, y, avl_moves, board, a, b);

    if (board[y][x] == B_BISHOP || board[y][x] == W_BISHOP)
        bishop_avl_moves(x, y, avl_moves, board, a, b);

    if (board[y][x] == B_KNIGHT || board[y][x] == W_KNIGHT)
        knight_avl_moves(x, y, avl_moves, board, a, b);

    if (board[y][x] == B_PAWN || board[y][x] == W_PAWN)
        pon_avl_moves(x, y, avl_moves, board, board[y][x]);
}

int isCheck(int x, int y, const char(*board)[SIZE], char King)
{
    char a, b, a1, b1;

    if (King == W_KING) a = 'A', b = 'Z', a1 = 'a', b1 = 'z';

    else a = 'a', b = 'z', a1 = 'A', b1 = 'Z';

    bool avl_moves[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            avl_moves[i][j] = 0;

    for (int py = 0; py < SIZE; py++)
        for (int px = 0; px < SIZE; px++)
            if (board[py][px] >= a && board[py][px] <= b)
                piece_avl_positions(board[py][px], px, py, avl_moves, board, a1, b1);

    if (avl_moves[y][x])
        return 0;
    return 1;
}

void king_avl_moves(int x, int y, bool(*avl_moves)[SIZE], const char(*board)[SIZE], char King)
{
    if (x + 1 < SIZE && !isCheck(x + 1, y, board, King)) 
        avl_moves[y][x + 1] = 1;

    if (x - 1 >= 0 && !isCheck(x - 1, y, board, King)) 
        avl_moves[y][x - 1] = 1;

    if (y + 1 < SIZE && !isCheck(x, y + 1, board, King)) 
        avl_moves[y + 1][x] = 1;

    if (y - 1 >= 0 && !isCheck(x, y - 1, board, King)) 
        avl_moves[y - 1][x] = 1;

    if (x + 1 < SIZE && y + 1 < SIZE && !isCheck(x + 1, y + 1, board, King)) 
        avl_moves[y + 1][y + 1] = 1;

    if (x - 1 >= 0 && y - 1 >= 0 && !isCheck(x - 1, y - 1, board, King)) 
        avl_moves[y - 1][x - 1] = 1;

    if (y + 1 < SIZE && x - 1 >= 0 && !isCheck(x - 1, y + 1, board, King)) 
        avl_moves[y + 1][x - 1] = 1;

    if (y - 1 >= 0 && x + 1 < SIZE && !isCheck(x + 1, y - 1, board, King)) 
        avl_moves[y - 1][x + 1] = 1;
}


void get_moves_for_peice(int x, int y, bool(*avl_moves)[SIZE], const char(*board)[SIZE], char piece, char a, char b)
{
    if (piece == B_KNIGHT || piece == W_KNIGHT)
        knight_avl_moves(x, y, avl_moves, board, a, b);

    if (piece == B_BISHOP || piece == W_BISHOP)
        bishop_avl_moves(x, y, avl_moves, board, a, b);

    if (piece == B_ROOK || piece == W_ROOK)
        rook_avl_moves(x, y, avl_moves, board, a, b);

    if (piece == B_QUEEN || piece == W_QUEEN)
        queen_avl_moves(x, y, avl_moves, board, a, b);

    if (piece == B_KING || piece == W_KING)
        king_avl_moves(x, y, avl_moves, board, piece);

    if (piece == B_PAWN || piece == W_PAWN)
        pon_avl_moves(x, y, avl_moves, board, piece);
}



void promotion(char* board[SIZE], char piece, char chosen_piece) {

    for (int x1 = 0; x1 < 8; x1++) {
        if (board[7][x1] == W_PAWN) {
        beginning1:
            print("Choose promoted piece");
            scanf_s("%c", chosen_piece);

            if (chosen_piece == 'q')
                board[7][x1] == W_QUEEN;
            else if (chosen_piece == 'r')
                board[7][x1] == W_ROOK;
            else if (chosen_piece == 'b')
                board[7][x1] == W_BISHOP;
            else if (chosen_piece == 'h')
                board[7][x1] == W_KNIGHT;
            else {
                print("Invalid input, try again!");
                goto beginning1;
            }
        }
    }

    for (int x2 = 0; x2 < 8; x2++) {
        if (board[7][x2] == B_PAWN) {
        beginning2:
            print("Choose promoted piece");
            scanf_s("%c", chosen_piece);

            if (chosen_piece == 'Q')
                board[0][x2] == B_QUEEN;
            else if (chosen_piece == 'R')
                board[0][x2] == B_ROOK;
            else if (chosen_piece == 'B')
                board[0][x2] == B_BISHOP;
            else if (chosen_piece == 'H')
                board[0][x2] == B_KNIGHT;
            else {
                print("Invalid input, try again!");
                goto beginning2;
            }
        }
    }

}

//TO DO:
//pin ,en passant, mat, pat, castle, shah li si 
