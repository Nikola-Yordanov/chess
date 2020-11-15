#include <stdbool.h>

#define SIZE 8
#define PEICE 6

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


#define PON_P 1
#define ROOK_P 5
#define BISHOP_P 3 
#define KNIGHT_P 3
#define QUEEN_P 9


//----------------------------------------------------------------------------------------------------
void get_moves_for_peice(int x, int y, bool(*avl_moves)[SIZE], const char(*board)[SIZE], char piece, char a, char b);

//----------------------------------------------------------------------------------------------------
void print_avl_moves(bool(*avl_moves)[SIZE][SIZE])
{
	for (int p = 0; p < PEICE; p++)
		for (int y = 0; y < SIZE; y++)
			for (int x = 0; x < SIZE; x++)
				if (avl_moves[p][y][x])
					print("%d,  %d, &d", p, x, y);
}


//------------------------------------------------------------------------------------------------------
int get_index(char peice)
{
	if (peice == B_KING || peice == W_KING) return 0;
	if (peice == B_QUEEN || peice == W_QUEEN) return 1;
	if (peice == B_ROOK || peice == W_ROOK) return 2;
	if (peice == B_BISHOP || peice == W_BISHOP) return 3;
	if (peice == B_KNIGHT || peice == W_KNIGHT) return 4;
	if (peice == B_PON || peice == W_PON) return 5;
}

//-------------------------------------------------------------------------------------------------------
//*******************************************************************************************************
void get_all_posible_moves(int color, bool(*avl_moves)[SIZE][SIZE], const char(*board)[SIZE])
{
	char a, b;
	if (color)
		a = 'a', b = 'z';
	else
		a = 'A', b = 'Z';

	for (int y = 0; y < SIZE; y++)
		for (int x = 0; x < SIZE; x++)
			if (board[y][x] >= a && board[y][x] <= b)
				get_moves_for_peice(y, x, avl_moves[get_index(board[y][x])], board, board[y][x], a, b);
}

//------------------------------------------------------------------------------------------------------
int peice_points(char peice) 
{
	if (peice == B_QUEEN || peice == W_QUEEN) return QUEEN_P;
	if (peice == B_ROOK || peice == W_ROOK) return ROOK_P;
	if (peice == B_BISHOP || peice == W_BISHOP) return BISHOP_P;
	if (peice == B_KNIGHT || peice == W_KNIGHT) return KNIGHT_P;
	if (peice == B_PON || peice == W_PON) return PON_P;
}

//*******************************************************************************************************
int evaluate_move(const char (*board)[SIZE], int color)
{
	char a, b;
	if (color)
		a = 'a', b = 'z';
	else
		a = 'A', b = 'Z';

	int value = 0;
	for (int y = 0; y < SIZE; y++)
		for (int x = 0; x < SIZE; x++)
			if (board[y][x] >= a && board[y][x] <= b)
				value += peice_points(board[y][x]);
	return value;
}
