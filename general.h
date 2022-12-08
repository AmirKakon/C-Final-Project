#ifndef _GENERAL_H
#define _GENERAL_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BOARD_SIZE 5
#define SIZE_OF_BYTE 8
#define MAX_LENGTH(x) ((x)*(x))
#define FILE_NAME "path_list.bin"

typedef char chessPos[2];
typedef unsigned char BYTE;

void initboard(int board[][BOARD_SIZE]);
void printNumLine(int col);
void printDashLine(int row);
void printBoard1(int gameboard[][BOARD_SIZE]);
void Printline();
void printTab(int tab);
void checkMemoryAllocation(void* ptr);

#endif 
