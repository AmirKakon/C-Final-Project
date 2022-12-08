//
///*****************************************Part 1***************************************
//* chessPosArray*** validKnightMoves()
//*
//* Returns a 2-dim array with all the possible moves the knight can make.
//* Each spot will hold an array of all the possible moves the knight can make from that spot. (using chessPos)
//*************************************************************************************/
//#include "general.h"
//#include "chessPosarr.h"
//#include "chessPosList.h"
//#include "pathTree.h"
//
//#define SIZE_OF_BYTE 8
//#define MAX_LENGTH(x) ((x)*(x))
//typedef unsigned char BYTE;
//
//void saveListToBinFile(char* file_Name, chessPosList* pos_List);
//void saveListToBinFile2(char* file_Name, chessPosList* pos_List);
//BYTE createByte(char* str);
//BYTE* createBinStr2(char position, char* str, BYTE* bytearr, int* strindex, int* byteindex, int* physize);
//void createBinStr(chessPos position, char* str, int* currIndex, int* sizeOfStr);
//void insertBinValues(char position, char* str, int* currIndex, int* sizeOfStr);
//void writeToFile(FILE* f, char* bitOfChar, int sizeOfBitChar, short int nPositions);
////void writToFile2(FILE* f, char* str, int sizeOfStr, short int nPositions);
//char* getpos();
//chessPosList getlist();
//int checkAndDisplayPathFromFile(char* file_name);
//int createListFromFile(chessPosList* lst, char* str, int numOfPos, int* count);
//void display(chessPosList* lst);
//int getSize(int numOfPos);
//BYTE* getByte(FILE* f, int size);
//char* toString(BYTE* arr, int size);
//int checkIfValidPosition(chessPos position, chessPos next);
//char getPos(char* str);
//chessPosList* findKnightPathCoveringAllBoard(pathTree* path_tree);
//void findKnightPathCoveringAllBoardRec(treeNode* root, chessPosList* res, int counter, bool* fullPath);
//
//void part4() {
//	//pathTree tr;
//	//chessPos starting;
//	//starting[0] = 'C';
//	//starting[1] = '3';
//	//tr = findAllpossibleknightpaths(&starting);
//	//chessPosList* res = findKnightPathCoveringAllBoard(&tr);
//	//freeTree(&tr);
//	//saveListToBinFile2("test.bin", res);
//	//freeList(res);
//	//free(res);
//
//	chessPosList lst = getlist();
//	saveListToBinFile2("test.bin", &lst);
//	freeList(&lst);
//	checkAndDisplayPathFromFile("test.bin");
//	
//}
//
//void saveListToBinFile(char* file_Name, chessPosList* pos_List) {
//	FILE* f;
//	f = fopen(file_Name, "wb");
//
//	short int nPositions = 0;
//	chessPosCell* curr = pos_List->head;
//	int sizeOfStr = SIZE_OF_BYTE;
//	char* str = (char*)malloc(sizeOfStr * sizeof(char));
//	int currIndex = 0, bitIndex = 0;
//	
//	char* bitOfChar;
//	int i;
//
//
//	while (curr != NULL) {
//		nPositions++;
//		createBinStr(curr->position, str, &currIndex, &sizeOfStr);
//		curr = curr->next;
//	}
//
//	printf("\n");
//
//	if (currIndex < sizeOfStr) {
//		for (currIndex; currIndex < sizeOfStr; currIndex++) {
//			str[currIndex] = '0';
//		}
//	}
//
//	bitOfChar = (char*)malloc((sizeOfStr / SIZE_OF_BYTE) * sizeof(char));
//	currIndex = 0;
//	BYTE temp = 0;
//
//	while (currIndex < sizeOfStr) {
//		for (i = 0; i < SIZE_OF_BYTE; i++) {
//			temp = temp << 1;
//			temp += (str[currIndex] == '1' ? 1 : 0);
//			currIndex++;
//		}
//		bitOfChar[bitIndex] = temp;
//		printf("%u\n", temp);
//		bitIndex++;
//		temp = 0;
//	}
//	writeToFile(f, bitOfChar, sizeOfStr / 8, nPositions);
//	fclose(f);
//
//	free(str);
//	free(bitOfChar);
//}
//void saveListToBinFile2(char* file_Name, chessPosList* pos_List) {
//	FILE* f;
//	f = fopen(file_Name, "wb");
//
//	short int nPositions = 0;
//	chessPosCell* curr = pos_List->head;
//	char bitstr[SIZE_OF_BYTE];
//	int currIndex = 0;
//	int strindex = 0;
//	int physize = 1;
//	char currpos;
//	BYTE* bitOfChar = (BYTE*)malloc(physize * sizeof(BYTE));
//	while (curr != NULL) {
//		nPositions++;
//		currpos = curr->position[0] - 'A';
//		bitOfChar = createBinStr2(currpos, bitstr, bitOfChar, &strindex, &currIndex, &physize);
//		currpos = curr->position[1] - '1';
//		bitOfChar = createBinStr2(currpos, bitstr, bitOfChar, &strindex, &currIndex, &physize);
//
//		curr = curr->next;
//	}
//	if (strindex != 0) {
//		if ((currIndex) == (physize)) {
//			physize *= 2;
//			bitOfChar = (BYTE*)realloc(bitOfChar, physize * sizeof(BYTE));
//		}
//		while (strindex < 8) {
//			bitstr[strindex] = '0';
//			printf("%c", bitstr[strindex]);
//			strindex++;
//		}
//
//		bitOfChar[currIndex] = createByte(bitstr);
//		currIndex++;
//	}
//	bitOfChar = (BYTE*)realloc(bitOfChar, currIndex * sizeof(BYTE));
//	printf("\n");
//	writeToFile(f, bitOfChar, currIndex, nPositions);
//	fclose(f);
//	free(bitOfChar);
//}
//void createBinStr(chessPos position, char* str, int* currIndex, int* sizeOfStr) {
//	int row = position[0] - 'A';
//	int col = position[1] - '1';
//
//	insertBinValues(row, str, currIndex, sizeOfStr);
//	//printf(" ");
//	insertBinValues(col, str, currIndex, sizeOfStr);
//}
//BYTE* createBinStr2(char position, char* str, BYTE* bytearr, int* strindex, int* byteindex, int* physize) {
//	int i, mask;
//	for (i = 2; i >= 0; i--) {
//		if ((*byteindex) == (*physize)) {
//			(*physize) *= 2;
//			bytearr = (BYTE*)realloc(bytearr, (*physize) * sizeof(BYTE));
//		}
//		mask = 1 << i;
//		str[*strindex] = ((position & mask) ? '1' : '0');
//		printf("%c", str[*strindex]);
//		(*strindex)++;
//		if (*strindex == SIZE_OF_BYTE) {
//			bytearr[*byteindex] = createByte(str);
//			(*byteindex)++;
//			(*strindex) = 0;
//		}
//	}
//	return bytearr;
//}
//BYTE createByte(char* str) {
//	BYTE res=0;
//	int i;
//	for (i = 0; i < SIZE_OF_BYTE; i++) {
//		res = res << 1;
//		res += (str[i] == '1' ? 1 : 0);
//	}
//	return res;
//}
//void insertBinValues(char position, char* str, int* currIndex, int* sizeOfStr) {
//	int i, mask;
//	
//	for (i = 2; i >= 0; i--) {
//		if (*currIndex == *sizeOfStr) {
//			(*sizeOfStr) += SIZE_OF_BYTE;
//			str = (char*)realloc(str, (*sizeOfStr) * sizeof(char));
//			checkMemoryAllocation(str);
//		}
//		mask = 1 << i;
//		str[*currIndex] = ((position & mask) ? '1' : '0');
//		//printf("%c", str[*currIndex]);
//		(*currIndex)++;
//	}
//}
//
//void writeToFile(FILE* f, char* bitOfChar, int sizeOfBitChar, short int nPositions) {
//	int i;
//	fwrite(&nPositions, sizeof(short int), 1, f);
//
//	for (i = 0; i< sizeOfBitChar; i++) {
//		fwrite(&bitOfChar[i], sizeof(char), 1, f);
//	}
//
//
//}
////void writToFile2(FILE* f, char* str, int sizeOfStr, short int nPositions) {
////	fwrite(&nPositions, sizeof(short int), 1, f);
////	int currIndex = 0, bitIndex = 0, i;
////	BYTE curByte;
////	while (currIndex < sizeOfStr) {
////		curByte = 0;
////		for (i = 0; i < SIZE_OF_BYTE; i++) {
////			curByte = curByte << 1;
////			curByte += (str[currIndex] == '1' ? 1 : 0);
////			currIndex++;
////		}
////		//printf("%u\n", curByte);
////		fwrite(&curByte, sizeof(char), 1, f);
////	}
////
////}
//char* getpos()
//{
//	int logSize = 0, phySize = 1;
//	char c;
//	char* pos = (char*)malloc(phySize * sizeof(char));
//	checkMemoryAllocation(pos);
//	c = getchar();
//
//	while (c != '\n')
//	{
//		if (logSize == phySize)
//		{
//			phySize *= 2;
//			pos = (char*)realloc(pos, sizeof(char) * phySize);
//		}
//
//		pos[logSize] = c;
//		logSize++;
//		c = getchar();
//	}
//
//	pos = (char*)realloc(pos, sizeof(char) * (logSize + 1));
//	pos[logSize] = '\0';
//	return pos;
//}
//chessPosList getlist()
//{
//	chessPosList res;
//	makeEmptyList(&res);
//	chessPos data;
//	char* pos = getpos();
//	char* token;
//	char seps[] = " ";
//	token = strtok(pos, seps);
//	while (token != NULL) {
//		data[0] = token[0];
//		data[1] = token[1];
//		insertDataToEndList(&res, data);
//		token = strtok(NULL, seps);
//	}
//	free(pos);
//	return res;
//	
//}
//
//int checkAndDisplayPathFromFile(char* file_name) {
//	FILE* f = fopen(file_name, "rb");
//
//
//	short int numOfPos;
//	int check, count = 0;
//	fread(&numOfPos, sizeof(short int), 1, f);
//
//	int sizeOfArr = getSize(numOfPos);
//	BYTE* arr = getByte(f, sizeOfArr);
//
//	char* str = toString(arr, sizeOfArr);
//
//	chessPosList lst;
//	check =createListFromFile(&lst, str, numOfPos, &count);
//	if (check == 2 || check == 3) {
//		display(&lst);
//	}
//	
//	fclose(f);
//	printf("%d", check);
//	return check;
//}
//
//int createListFromFile(chessPosList* lst, char* str, int numOfPos, int* count) {
//	makeEmptyList(lst);
//
//	int i, j = 0, check = 1;
//	chessPos position;
//	int arr[BOARD_SIZE][BOARD_SIZE] = { 0 };
//	for (i = 0; i < numOfPos && check == 1; i++) {
//		position[0] = getPos(str + j) + 'A';
//		j += 3;
//		position[1] = getPos(str + j) + '1';
//		j += 3;
//
//		if (arr[position[0] - 'A'][position[1] - '1'] == 0) {
//			arr[position[0] - 'A'][position[1] - '1'] = 1;
//			(*count)++;
//		}
//
//		if (i != 0) {
//			if (!checkIfValidPosition(lst->tail->position, position))
//				return 1;	
//		}
//
//		insertDataToEndList(lst, position);
//	}
//	if ((*count) == (BOARD_SIZE * BOARD_SIZE))
//		return 2;
//	else
//		return 3;
//}
//
//char getPos(char* str) {
//	char pos = 0;
//
//	int i;
//
//	for (i = 0; i < 3; i++) {
//		pos = pos << 1;
//		pos += (str[i] == '1' ? 1 : 0);
//	}
//
//	return pos;
//}
//
//int checkIfValidPosition(chessPos position, chessPos next) {
//	int i, j;
//	int row = position[0] - 'A';
//	int col = position[1] - '1';
//	int rowNext = next[0] - 'A';
//	int colNext = next[1] - '1';
//
//
//
//
//	for (i = row - 2; i <= row + 2; i++) {
//		if (i != row && i >= 0 && i < BOARD_SIZE)
//			for (j = col - 2; j <= col + 2; j = j++)
//				if (j != col && j >= 0 && j < BOARD_SIZE)
//					if (row - i != col - j && row - i != (col - j) * -1)
//						if (i == rowNext && j == colNext)
//							return 1;
//	}
//
//	return 0;
//}
//
//char* toString(BYTE* arr, int size) {
//	int i, j, index = 0;
//	BYTE mask;
//
//	char* str = (char*)malloc((size * 8) * sizeof(char));
//	checkMemoryAllocation(str);
//
//	for (i = 0; i < size; i++)
//		for (j = SIZE_OF_BYTE - 1; j >= 0; j--) {
//			mask = 1 << j;
//			str[index] = ((arr[i] & mask) ? '1' : '0');
//			printf("%c", str[index]);
//			index++;
//		}
//
//	return str;
//}
//
//BYTE* getByte(FILE* f, int size) {
//	int i, check;
//
//	BYTE* arr = (BYTE*)malloc(size * sizeof(BYTE));
//	checkMemoryAllocation(arr);
//
//	for (i = 0; i < size; i++)
//		check = fread(&arr[i], sizeof(BYTE), 1, f);
//
//	return arr;
//}
//
//int getSize(int numOfPos) {
//	int size;
//
//	size = numOfPos * 6;
//
//	while (size % 8 != 0)
//		size++;
//
//	return size / 8;
//}
//
//void display(chessPosList* lst) {
//	//build array for comparison + format to '0'
//
//	chessPosCell* curr = lst->head, * temp = NULL;
//	int board[BOARD_SIZE][BOARD_SIZE];
//	initboard(board);
//	int pos[2];
//	int i = 1;
//	while (curr != NULL) {
//
//		pos[0] = (int)(curr->position[0] - 'A');
//		pos[1] = (int)(curr->position[1] - '1');
//		if (board[pos[0]][pos[1]] > 0) {
//			if (lst->tail == curr)
//				lst->tail = temp;
//			curr = curr->next;
//			removeNode(temp);
//		}
//		else {
//			board[pos[0]][pos[1]] = i;
//			i++;
//			temp = curr;
//			curr = curr->next;
//		}
//
//	}
//	printBoard1(board);
//}
//chessPosList* findKnightPathCoveringAllBoard(pathTree* path_tree) {
//	chessPosList* res = (chessPosList*)malloc(sizeof(chessPosList));
//	checkMemoryAllocation(res);
//	makeEmptyList(res);
//	bool fullPath = false;
//	findKnightPathCoveringAllBoardRec(path_tree->root, res, 1, &fullPath);
//	return res;
//}
//
//void findKnightPathCoveringAllBoardRec(treeNode* root, chessPosList* res, int counter, bool* fullPath) {
//	if (root->next_possible_positions == NULL) {
//		if (counter == MAX_LENGTH(BOARD_SIZE)) {
//			*fullPath = true;
//			insertDataToStartList(res, root->position);
//		}
//		return;
//	}
//
//	treeNodeListCell* listNode = root->next_possible_positions;
//
//	while (listNode != NULL && *fullPath == false) {
//		findKnightPathCoveringAllBoardRec(listNode->node, res, counter + 1, fullPath);
//		//counter--;
//		listNode = listNode->next;
//	}
//
//	if (*fullPath == true) {
//		insertDataToStartList(res, root->position);
//	}
//}
//
//
//
//
//
//
//
//
