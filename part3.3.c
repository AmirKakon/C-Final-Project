//
///*****************************************Part 3***************************************
//* chessPosArray*** validKnightMoves()
//*
//* Returns a 2-dim array with all the possible moves the knight can make.
//* Each spot will hold an array of all the possible moves the knight can make from that spot. (using chessPos)
//*************************************************************************************/
//
//#include "general.h"
//#include "pathTree.h"
//#include "chessPosarr.h"
//
//void printTree(pathTree tr);
//void printTreeRec(treeNode* node, int* tab);
//
//
//void part3() {
//	//chessPosArray*** board = NULL;
//	//board = validKnightMoves();
//
//	pathTree tr;
//	chessPos starting;
//	starting[0] = 'A';
//	starting[1] = '1';
//	tr = findAllpossibleknightpaths(&starting);
//	//printBoard(board, BOARD_SIZE);
//	printTree(tr);
//	freeTree(&tr);
//	//freeAll(board, BOARD_SIZE);
//}
//
//chessPosArray*** validKnightMoves() {
//	int i, j;
//
//	//build 2-dim array
//	chessPosArray*** board = NULL;
//	board = newBoard(board, BOARD_SIZE);
//	printBoard(board, BOARD_SIZE);
//
//	//printf("\n\n");
//
//	//run on every cell in the "board"
//	for (i = 0; i < BOARD_SIZE; i++)
//		for (j = 0; j < BOARD_SIZE; j++)
//			addKnightMoveFromSpot(i, j, board);
//
//	printBoard(board, BOARD_SIZE);
//	return board;
//}
//
//pathTree findAllpossibleknightpaths(chessPos* startingposition)
//{
//	chessPosArray*** board = validKnightMoves();
//	int arr[BOARD_SIZE][BOARD_SIZE];
//	initboard(arr);
//	pathTree res;
//	res.root = findAllpossibleknightpathsRec(startingposition, board, arr);
//	freeAll(board, BOARD_SIZE);
//	return res;
//}
//
//treeNode* findAllpossibleknightpathsRec(chessPos* position, chessPosArray*** board, int countboard[][BOARD_SIZE])
//{
//
//	treeNode* res = createNewtreeNode(position);
//	int i;
//	int posA, pos1;
//	int curposA = position[0][0] - 'A', curpos1 = position[0][1] - '1';
//	int size = board[curposA][curpos1]->size;
//	countboard[curposA][curpos1] = 1;
//	//printf("%c%c ", position[0][0], position[0][1]);
//	for (i = size - 1; i >= 0; i--) {
//		posA = board[position[0][0] - 'A'][position[0][1] - '1']->position[i][0] - 'A';
//		pos1 = board[position[0][0] - 'A'][position[0][1] - '1']->position[i][1] - '1';
//		if (countboard[posA][pos1] == 0) {
//			insertdatatotreeNodeList(res);
//			res->next_possible_positions->node = findAllpossibleknightpathsRec(board[curposA][curpos1]->position[i], board, countboard);
//		}
//	}
//	countboard[curposA][curpos1] = 0;
//	return res;
//}
//
////updates cells value around a Knight.
//void addKnightMoveFromSpot(int row, int col, chessPosArray*** board) {
//	int i, j, counter = 0;
//
//	for (i = row - 2; i <= row + 2; i++)
//		if (i != row && i >= 0 && i < BOARD_SIZE)
//			for (j = col - 2; j <= col + 2; j = j++)
//				if (j != col && j >= 0 && j < BOARD_SIZE)
//					if (row - i != col - j && row - i != (col - j) * -1)
//						board = addKnightLocation(board, row, col, i, j);
//}
//
////adds current location to position array
//chessPosArray*** addKnightLocation(chessPosArray*** board, int krow, int kcol, int row, int col) {
//	int positionIndex;
//	board[krow][kcol]->size++;
//	positionIndex = board[krow][kcol]->size - 1;
//
//	board[krow][kcol]->position = (chessPos*)realloc(board[krow][kcol]->position, board[krow][kcol]->size * sizeof(chessPos));
//	checkMemoryAllocation(board[krow][kcol]->position);
//
//	board[krow][kcol]->position[positionIndex][0] = 'A' + row; //to get letters A-H
//	board[krow][kcol]->position[positionIndex][1] = (char)('0' + (col + 1));
//
//
//	return board;
//}
//
////builds new board
//chessPosArray*** newBoard(chessPosArray*** board, int size) {
//	int i, j;
//
//	board = (chessPosArray***)malloc(size * sizeof(chessPosArray**));
//	checkMemoryAllocation(board);
//
//	for (i = 0; i < size; i++) {
//		board[i] = (chessPosArray**)malloc(size * sizeof(chessPosArray*));
//		checkMemoryAllocation(board[i]);
//
//		for (j = 0; j < size; j++) {
//			board[i][j] = (chessPosArray*)malloc(sizeof(chessPosArray));
//			board[i][j]->size = 0;
//			board[i][j]->position = (chessPos*)malloc(sizeof(chessPos));
//			checkMemoryAllocation(board[i][j]->position);
//		}
//	}
//	return board;
//}
//
//void initboard(int board[][BOARD_SIZE])
//{
//	int i, j;
//	for (i = 0; i < BOARD_SIZE; i++)
//		for (j = 0; j < BOARD_SIZE; j++)
//			board[i][j] = 0;
//}
//
////prints line of numbers according to board size.
//void printNumLine(int col) {
//	int i = 1;
//
//	printf("|    |");
//	while (i <= col) {
//		printf("%3d |", i);
//		i++;
//	}
//	printf("\n");
//}
//
//void printDashLine(int row) {
//	int i;
//
//	printf("+");
//	for (i = 0; i <= row; i++)
//		printf("----+");
//	printf("\n");
//
//}
//
//void printBoard(chessPosArray*** board, int size) {
//	int i, j;
//	char place = 'A';
//
//	printDashLine(size);
//	printNumLine(size);
//	for (i = 0; i < size; i++) {
//		printDashLine(size);
//		printf("|  %c |", place);
//		place++;
//		for (j = 0; j < size; j++) {
//			printf("%3d |", board[i][j]->size);
//		}
//		printf("\n");
//	}
//	printDashLine(size);
//}
//
//void printTree(pathTree tr) {
//	int tab = 0;
//	printTreeRec(tr.root, &tab);
//}
//
//void printTreeRec(treeNode* node, int* tab) {
//	if (node->next_possible_positions == NULL) {
//		printTab(*tab);
//		printf("(%c,%c) \n", node->position[0], node->position[1]);
//		*tab = *tab - 1;
//	}
//	else
//	{
//		
//		if(node->next_possible_positions->next != NULL)
//			printTreeRec(node->next_possible_positions->next->node, tab);
//		*tab = *tab + 1;
//		printTreeRec(node->next_possible_positions->node, tab);
//		printTab(*tab);
//		printf("(%c,%c) \n", node->position[0], node->position[1]);
//		*tab = *tab - 1;
//	}
//
//}
//
//void printTab(int tab) {
//	int i;
//	for (i = 0; i <= tab; i++) {
//		printf("\t");
//	}
//}
//
//treeNode* createNewtreeNode(chessPos* position)
//{
//	treeNode* res = (treeNode*)malloc(sizeof(treeNode));
//	checkMemoryAllocation(res);
//	res->position[0] = position[0][0];
//	res->position[1] = position[0][1];
//	res->next_possible_positions = NULL;
//
//	return res;
//}
//
//int isEmptytreenodelist(treeNode* node)
//{
//	return (node->next_possible_positions == NULL);
//}
//
//treeNodeListCell* createNewtreeNodelistCell()
//{
//	treeNodeListCell* res = (treeNodeListCell*)malloc(sizeof(treeNodeListCell));
//	checkMemoryAllocation(res);
//	res->next = NULL;
//
//	return res;
//}
//
//void insertdatatotreeNodeList(treeNode* node)
//{
//	treeNodeListCell* newhead;
//	newhead = createNewtreeNodelistCell();
//	insertnodetotreeNodeList(node, newhead);
//}
//
//void insertnodetotreeNodeList(treeNode* node, treeNodeListCell* newhead)
//{
//	if (isEmptytreenodelist(node)) {
//		node->next_possible_positions = newhead;
//	}
//	else {
//		newhead->next = node->next_possible_positions;
//		node->next_possible_positions = newhead;
//	}
//}
//
//void freeAll(chessPosArray*** board, int size) {
//	int i, j;
//
//	for (i = 0; i < size; i++) {
//		for (j = 0; j < size; j++) {
//			free(board[i][j]->position);
//		}
//		free(board[i]);
//	}
//	free(board);
//}
//
//void freeTree(pathTree* tr)
//{
//	freeTreeRec(tr->root);
//	free(tr->root);
//}
//
//void freeTreeRec(treeNode* root)
//{
//	if (root->next_possible_positions == NULL) {
//		//free(root);
//		return;
//	}
//	else {
//		freetreelist(root);
//	}
//}
//
//void freetreelist(treeNode* node)
//{
//	if (node->next_possible_positions == NULL)
//		return;
//
//	treeNodeListCell* curr = node->next_possible_positions, * next;
//	while (curr != NULL) {
//		next = curr->next;
//		freeTreeRec(curr->node);
//		free(curr->node);
//		free(curr);
//		curr = next;
//	}
//}
//
//void checkMemoryAllocation(void* ptr) {
//	if (ptr == NULL) {
//		printf("Memory allocation failed!\n");
//		exit(1);
//	}
//}