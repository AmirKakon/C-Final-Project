/*****************************************General***************************************
* need to fix this file with correct printing function. and only have 1 printing function
****************************************************************************************/

#include "general.h"

//sets board to be of value 0 in all spots.
void initboard(int board[][BOARD_SIZE])
{
	int i, j;
	for (i = 0; i < BOARD_SIZE; i++)
		for (j = 0; j < BOARD_SIZE; j++)
			board[i][j] = 0;
}

//prints line of numbers according to board size.
void printNumLine(int col) {
	int i = 1;

	printf("|    |");
	while (i <= col) {
		printf("%3d |", i);
		i++;
	}
	printf("\n");
}

//prints lineof dashes according to board size.
void printDashLine(int row) {
	int i;

	printf("+");
	for (i = 0; i <= row; i++)
		printf("----+");
	printf("\n");

}

//prints a board
void printBoard1(int gameboard[][BOARD_SIZE])
{
	int i, j;

	printf("\n\n      ");
	for (i = 0; i < BOARD_SIZE; i++)
		printf("%2d  ", i + 1);
	printf("\n");
	Printline();

	for (i = 0; i < BOARD_SIZE; i++) {
		printf("  %2c |", (char)('A' + i));
		for (j = 0; j < BOARD_SIZE; j++) {
			if (gameboard[i][j] == 0)
				printf("   |");
			if (gameboard[i][j] >= 1)
				printf(" %d |", gameboard[i][j]);
		}

		printf("\n");
	}
	Printline();
}

void Printline()
{
	int i;
	printf("      ");
	for (i = 0; i <= 4 * BOARD_SIZE - 1; i++)
		printf("_");
	printf("\n");
}

void printTab(int tab) {
	int i;
	for (i = 0; i <= tab; i++) {
		printf("\t");
	}
}

//checks if memory of pointers and dynamic arrays exist
void checkMemoryAllocation(void* ptr) {
	if (ptr == NULL) {
		printf("Memory allocation failed!\n");
		exit(1);
	}
}
