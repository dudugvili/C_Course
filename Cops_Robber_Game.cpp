/*        -- An assignment I got in C coding course --
   first game is a cops and robbers game, the player choose the size of the board
   then he decides how many copes he wants to have on the board and where
   to place them.
   the robber is placed in the middle and in each turn the player controlls his movement 
   and the player goal is to escape from the cops while they are getting closer each turn!
   
   second game is a 3x3 board with 2 White Knights and 2 Black Knights (Chess)
   The goal is to block the rival and the player has 30 turns to do so.*/

#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 30
#define MIN_SIZE 5

// print names function with an option to say goodbye
void printNames(int bye)
{
	static char fName[10], lName[10];
	if(!bye)
	{
	scanf("%s", fName);
	scanf("%s", lName);
	printf("Hello %s %s, welcome to our app!\n", fName, lName);
	}
	else
			printf("Bye, %s %s.", fName, lName);

}

//scan and check rows
int rowsNum()
{
	int row;
	scanf("%d", &row);
	if (row > MAX_SIZE)
		row = MAX_SIZE;
	else
		row = (row < MIN_SIZE ? MIN_SIZE : row);
	return row;
}

//scan and check columns
int columnsNum(int row)
{
	int column;
	scanf("%d", &column);
	if (column == -1)
		column = row;
	else if (column > MAX_SIZE)
		column = MAX_SIZE;
	else
		column = (column < MIN_SIZE ? MIN_SIZE : column);
	return column;
}

//valid moves for cops
void validMoves(char gameBoard[MAX_SIZE][MAX_SIZE], int copsQty, int copPosC[5], int copPosR[5],int rowTot,int columnTot)
{
	int temp;
	int copOrganized[5];
	for (int i = 0; i < copsQty; i++)
	{
		temp = copsQty - 1;
		for (int j = 0; j < copsQty; j++)
		{
			if (copPosC[i] < copPosC[j])
				temp--;
			else if (copPosC[i] == copPosC[j])
				if (copPosR[i] < copPosR[j])
					temp--;
		}
		copOrganized[temp] = i;
	}
	//going through all cops and printing available moves
	for (int i = 0; i < copsQty; i++)
	{
		int tempRow = copPosR[copOrganized[i]];
		int tempCol = copPosC[copOrganized[i]];
		if(tempRow == 0)
			if (tempCol == 0)
			{
				if(!(gameBoard[1][0] == 'C'))
					printf("[0,0] -> [1,0]\n"); // down
				if (!(gameBoard[0][1] == 'C'))
					printf("[0,0] -> [0,1]\n"); // left
			}
			else if (tempCol == columnTot - 1)
			{
				if (!(gameBoard[1][tempCol] == 'C'))
					printf("[0,%d] -> [1,%d]\n", tempCol, tempCol); // down
				if (!(gameBoard[0][tempCol -1] == 'C'))
					printf("[0,%d] -> [0,%d]\n", tempCol, tempCol - 1); // left
			}
			else
			{
				if (!(gameBoard[1][tempCol] == 'C'))
					printf("[0,%d] -> [1,%d]\n", tempCol, tempCol); // down
				if (!(gameBoard[0][tempCol + 1] == 'C'))
					printf("[0,%d] -> [0,%d]\n", tempCol, tempCol + 1); // right
				if (!(gameBoard[0][tempCol - 1] == 'C'))
					printf("[0,%d] -> [0,%d]\n", tempCol, tempCol - 1); // left
			}
		else if (tempCol == 0)
		{
			if (tempRow == rowTot -1)
			{
				if (!(gameBoard[tempRow - 1][0] == 'C'))
					printf("[%d,0] -> [%d,0]\n", tempRow, tempRow - 1); // up
				if (!(gameBoard[tempRow][1] == 'C'))
					printf("[%d,0] -> [%d,1]\n", tempRow, tempRow); // right
			}
			else
			{
				if (!(gameBoard[tempRow + 1][0] == 'C'))
					printf("[%d,0] -> [%d,0]\n", tempRow, tempRow + 1); // down
				if (!(gameBoard[tempRow - 1][0] == 'C'))
					printf("[%d,0] -> [%d,0]\n", tempRow, tempRow - 1); // up
				if (!(gameBoard[tempRow][1] == 'C'))
					printf("[%d,0] -> [%d,1]\n", tempRow, tempRow); // right
			}
		}
		else if (tempCol == columnTot -1)
		{
			if (tempRow == rowTot -1)
			{
				if (!(gameBoard[tempRow - 1][tempCol] == 'C'))
					printf("[%d,%d] -> [%d,%d]\n", tempRow, tempCol, tempRow - 1, tempCol); // up
				if (!(gameBoard[tempRow][tempCol - 1] == 'C'))
					printf("[%d,%d] -> [%d,%d]\n", tempRow, tempCol, tempRow, tempCol - 1); // left
			}
			else
			{
				if (!(gameBoard[tempRow + 1][tempCol] == 'C'))
					printf("[%d,%d] -> [%d,%d]\n", tempRow, tempCol, tempRow + 1, tempCol); // down
				if (!(gameBoard[tempRow - 1][tempCol] == 'C'))
					printf("[%d,%d] -> [%d,%d]\n", tempRow, tempCol, tempRow - 1, tempCol); // up
				if (!(gameBoard[tempRow][tempCol - 1] == 'C'))
					printf("[%d,%d] -> [%d,%d]\n", tempRow, tempCol, tempRow, tempCol -1); // left
			}
		}
		else if (tempRow == rowTot - 1)
		{
			if (!(gameBoard[tempRow + 1][tempCol] == 'C'))
				printf("[%d,%d] -> [%d,%d]\n", tempRow, tempCol, tempRow + 1, tempCol); // down
			if (!(gameBoard[tempRow][tempCol + 1] == 'C'))
				printf("[%d,%d] -> [%d,%d]\n", tempRow, tempCol, tempRow, tempCol + 1); // right
			if (!(gameBoard[tempRow][tempCol - 1] == 'C'))
				printf("[%d,%d] -> [%d,%d]\n", tempRow, tempCol, tempRow, tempCol - 1); // left
		}
		else
		{
			if (!(gameBoard[tempRow + 1][tempCol] == 'C'))
				printf("[%d,%d] -> [%d,%d]\n", tempRow, tempCol, tempRow + 1, tempCol); // down
			if (!(gameBoard[tempRow - 1][tempCol] == 'C'))
				printf("[%d,%d] -> [%d,%d]\n", tempRow, tempCol, tempRow - 1, tempCol); // up
			if (!(gameBoard[tempRow][tempCol + 1] == 'C'))
				printf("[%d,%d] -> [%d,%d]\n", tempRow, tempCol, tempRow, tempCol +1); // right
			if (!(gameBoard[tempRow][tempCol - 1] == 'C'))
				printf("[%d,%d] -> [%d,%d]\n", tempRow, tempCol, tempRow, tempCol - 1); // left
		}
		
	}
}

//printing the whole playboard
void boardPrint(char gameTable[MAX_SIZE][MAX_SIZE], int rowTot, int columnTot)
{
	for (int i = 0; i < rowTot; i++)
	{
		for (int j = 0; j < columnTot; j++)
		{
			printf("%c", gameTable[i][j]);
		}
		printf("\n");
	}
}

//finding cop index by position on board
int copIndexFinder(int posR[5], int posC[5], int copQty, int row, int col)
{
	for (int i = 0; i < copQty; i++)
	{
		if (posR[i] == row)
			if (posC[i] == col)
				return i;
	}
	return 0;
}

//finding the nearest cop to the robber
int closestCop(int robRC[2], int posR[5], int posC[5], int copQty)
{
	int closestCop = 0, minRow = 0, minCol = 0;
	float dist = 0, minDist = 100, x, y;
	for (int i = 0; i < copQty; i++)
	{
		x = float(pow(float(posR[i]) - float(robRC[0]), 2));
		y = float(pow(float(posC[i]) - float(robRC[1]), 2));
		dist = float(pow(float(x)+float(y), 0.5));
		if (dist < minDist)
		{
			minDist = dist;
			minRow = posR[i];
			minCol = posC[i];
			closestCop = i;
		}
		else if (dist == minDist)
		{
			if (posR[i] < minRow)
			{
				minDist = dist;
				minRow = posR[i];
				minCol = posC[i];
				closestCop = i;
			}
			else if (posR[i] == minRow)
				if (posC[i] < minCol)
				{
					minDist = dist;
					minRow = posR[i];
					minCol = posC[i];
					closestCop = i;
				}
		}
	} // for minDist check
	return closestCop;
}

//cops game functions
void copsGame(int columnTot, int rowTot)
{
	char gameTable[MAX_SIZE][MAX_SIZE];
	int copRow = 0, copColumn = 0, turn = 0, playFlag = 1, colMove = 0, rowMove = 0;
	int copsQty, copIndex, robRC[2], closeCop;
	int copPosR[5], copPosC[5];
	for (int i = 0; i < rowTot; i++)
		for (int j = 0; j < columnTot; j++)
			gameTable[i][j] = '-';
	robRC[0] = (rowTot - 1) / 2;
	robRC[1] = (columnTot - 1) / 2;
	gameTable[robRC[0]][robRC[1]] = 'R';
	printf("How many cops (1-5)?\n");
	scanf("%d", &copsQty);
	for (int i = 0; i < copsQty; i++)
	{
		printf("Let's choose a cell:\n");
		scanf("%d", &copRow);
		scanf("%d", &copColumn); 
		if (gameTable[copRow][copColumn] == 'C')
			i--;
		else
		{
			gameTable[copRow][copColumn] = 'C';
			copPosR[i] = copRow;
			copPosC[i] = copColumn;
		}
	}
	printf("Well, Let's play!\nInitial states:\n");
	boardPrint(gameTable, rowTot, columnTot);
	if (copsQty == 1)
		if ((robRC[0] + robRC[1] + copRow + copColumn) % 2 == 0)
			turn = 30;
		// if special case
	while (playFlag && turn < 30)
	{
		if (turn % 2 == 0)
		{
			printf("Cops:\n");
			validMoves(gameTable, copsQty, copPosC, copPosR, rowTot, columnTot);
			scanf("%d", &copRow);
			scanf("%d", &copColumn);
			scanf("%d", &rowMove);
			scanf("%d", &colMove);
			copIndex = copIndexFinder(copPosR, copPosC, copsQty, copRow, copColumn);
			gameTable[copPosR[copIndex]][copPosC[copIndex]] = '-';
			copPosR[copIndex] = rowMove;
			copPosC[copIndex] = colMove;
			gameTable[rowMove][colMove] = 'C';
			boardPrint(gameTable, rowTot, columnTot);
			if (robRC[0] == rowMove && robRC[1] == colMove)
			{
				playFlag = 0;
				printf("The cops won!\n");
			}
			turn++;
		} //if cops turn
		else
		{
			printf("Rob:\n");
			closeCop = closestCop(robRC, copPosC, copPosR, copsQty);
			if (copPosR[closeCop] < robRC[0])
			{
				if (!(robRC[0] == (rowTot - 1)))
				{
					if (gameTable[robRC[0] + 1][robRC[1]] == '-')
					{
						gameTable[robRC[0]][robRC[1]] = '-';
						robRC[0] += 1;
						gameTable[robRC[0]][robRC[1]] = 'R';
					}
				}
			} // if cop is above robber

			else if (copPosR[closeCop] > robRC[0])
			{
				if (!(robRC[0] == 0))
				{
					if (gameTable[robRC[0] - 1][robRC[1]] == '-')
					{
						gameTable[robRC[0]][robRC[1]] = '-';
						robRC[0] -= 1;
						gameTable[robRC[0]][robRC[1]] = 'R';
					}
				}
			} // if cop is below robber

			else if (copPosR[closeCop] == robRC[0])
			{
				if (copPosC[closeCop] < robRC[1])
				{
					if (!(robRC[1] == (columnTot - 1)))
					{
						if (gameTable[robRC[0]][robRC[1] + 1] == '-')
						{
							gameTable[robRC[0]][robRC[1]] = '-';
							robRC[1] += 1;
							gameTable[robRC[0]][robRC[1]] = 'R';
						}
					}
				} // if the robber is on the right of the cop
				else if (copPosC[closeCop] > robRC[1])
				{
					if (!(robRC[1] == 0))
					{
						if (gameTable[robRC[0]][robRC[1] - 1] == '-')
						{
							gameTable[robRC[0]][robRC[1]] = '-';
							robRC[1] -= 1;
							gameTable[robRC[0]][robRC[1]] = 'R';
						}
					}
				} // if the robber is on the left of the cop
			} // if cop is on the same row with robber
			turn++;
			boardPrint(gameTable, rowTot, columnTot);
		}
	} // while playFlag
	if (playFlag)
		printf("The rob managed to escape!\n");
}

//initializing the playboard for a new game
void initBoard(char gameBoard[3][3])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			gameBoard[i][j] = '-';
	gameBoard[0][0] = 'W';
	gameBoard[0][2] = 'W';
	gameBoard[2][0] = 'B';
	gameBoard[2][2] = 'B';
}

// chess game - check valid moves
int validMoves(char gameBoard[3][3], char player)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (gameBoard[i][j] == player)
			{
				// check 2 up and right
				if (i - 2 > -1 && j + 1 < 3)
					if (gameBoard[i - 2][j + 1] == '-')
						return 1;
				// check 2 up and left
				if (i - 2 > -1 && j - 1 > -1)
					if (gameBoard[i - 2][j - 1] == '-')
						return 1;
				// check 2 down and right
				if (i + 2 < 3 && j + 1 < 3)
					if (gameBoard[i + 2][j + 1] == '-')
						return 1;
				// check 2 down and left
				if (i + 2 < 3 && j - 1 > -1)
					if (gameBoard[i + 2][j - 1] == '-')
						return 1;
				// check 2 left and up 
				if (i - 1 > -1 && j - 2 > -1)
					if (gameBoard[i - 1][j - 2] == '-')
						return 1;
				// check 2 left and down
				if (i + 1 < 3 && j - 2 > -1)
					if (gameBoard[i + 1][j - 2] == '-')
						return 1;
				// check 2 right and up
				if (i - 1 > -1 && j + 2 < 3)
					if (gameBoard[i - 1][j + 2] == '-')
						return 1;
				// check 2 right and down
				if (i + 1 < 3 && j + 2 < 3)
					if (gameBoard[i + 1][j + 2] == '-')
						return 1;
			}
	return 0;
}

//chess game print board
void boardPrint(char gameBoard[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%c", gameBoard[i][j]);
		printf("\n");
	}
}

//four horseman game
void fourHorseman()
{
	int turn = 0, winFlag = 1, curRow, curCol, newRow, newCol;
	char gameBoard[3][3];
	initBoard(gameBoard);
	boardPrint(gameBoard);
	while (winFlag && turn < 30)
	{
		if (!(turn % 2))
		{
			if (validMoves(gameBoard, 'W'))
			{
				printf("W:\n");
				scanf("%d", &curRow);
				scanf("%d", &curCol);
				scanf("%d", &newRow);
				scanf("%d", &newCol);
				gameBoard[curRow][curCol] = '-';
				gameBoard[newRow][newCol] = 'W';
				boardPrint(gameBoard);
			} // moves are available
			else
			{
				printf("The blacks won!\n");
				winFlag = 0;
			} // no moves available

		} // white's turn
		else
		{
			if (validMoves(gameBoard, 'B'))
			{
				printf("B:\n");
				scanf("%d", &curRow);
				scanf("%d", &curCol);
				scanf("%d", &newRow);
				scanf("%d", &newCol);
				gameBoard[curRow][curCol] = '-';
				gameBoard[newRow][newCol] = 'B';
				boardPrint(gameBoard);
			} // moves are available
			else
			{
				printf("The whites won!\n");
				winFlag = 0;
			} // no moves available
		} // black's turn
		turn++;
	} // while playing
	if (winFlag)
		printf("Tie\n");
}

void ourApp()
{
	int rowTot, columnTot;
	char play = 'y';
	printNames(0);
	printf("Let's choose the size:\n");
	rowTot = rowsNum();
	columnTot = columnsNum(rowTot);
	while(play == 'y')
	{
		printf("Do you want to play [y/n]?\n");
		scanf(" %c", &play);
		if (play == 'n')
			printNames(1);
		else
		{
			copsGame(columnTot, rowTot);
			fourHorseman();
		}
	}
}

int main()
{
	ourApp();
	return 0;
}


