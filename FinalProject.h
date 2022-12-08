#include "general.h"
#include "pathTree.h"
#include "chessPosList.h"
#include "file.h"

void runAllFunctions();
void runMenu();
chessPosList createList();
void enterPositon(char* row, char* col);
pathTree runOption2(chessPos* position);
chessPosList* runOption3(chessPos* position, pathTree* tr);
void runOption4(pathTree* tr, chessPosList* lst, chessPos* position);
void runOption5();
