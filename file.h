#ifndef _FILE_H
#define _FILE_H

#include "general.h"
#include "chessPosList.h"

void saveListToBinFile(char* file_Name, chessPosList* pos_List);
BYTE createByte(char* str);
BYTE* createBinStr(char position, char* str, BYTE* bytearr, int* strindex, int* byteindex, int* physize);
void writeToFile(FILE* f, char* bitOfChar, int sizeOfBitChar, short int nPositions);
int checkAndDisplayPathFromFile(char* file_name);
int createListFromFile(chessPosList* lst, char* str, int numOfPos, int* count);
int getSize(int numOfPos);
BYTE* getByte(FILE* f, int size);
char* toString(BYTE* arr, int size);
int checkIfValidPosition(chessPos position, chessPos next);
char getPos(char* str);
int checkFile(FILE* f);


#endif // !_FILE_H

