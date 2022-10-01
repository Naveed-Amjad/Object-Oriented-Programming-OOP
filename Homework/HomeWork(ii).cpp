/*
File Name       : BITF19M541.cpp
Name : Naveed Amjad
Date            : 2020-10-18
Description     : This is Program related Connect 4 Game.
*/
#include<iostream>
using namespace std;

class Connect4Game
{
	int turn;
	int** board;
private:
	void showBoard()
	{
		cout << "    1   2   3   4   5   6   7" << endl;
		cout << "    =========================" << endl;
		for (int i = 1; i <= 7; i++)
		{
			cout << i << "   ";
			for (int j = 1; j <= 7; j++)
			{
				cout << board[i - 1][j - 1] << "   ";
			}
			cout << endl;
		}
	}
	void switchTurn()
	{
		if (turn == 1)
			turn = 2;
		else if (turn == 2)
			turn = 1;
	}
	bool isWon(int turn)
	{

		for (int i = 6; i >= 0; i--)
		{
			for (int j = 0; j < 4; j++)
			{
				if (board[j][i] == turn && board[j + 1][i] == turn && board[j + 2][i] == turn && board[j + 3][i] == turn)
					return true; //for vertical
			}
		}
		for (int i = 6; i > 2; i--)
		{
			for (int j = 0; j < 7; j++)
			{
				if (board[j][i] == turn && board[j][i - 1] == turn && board[j][i - 2] == turn && board[j][i - 3] == turn)
					return true; //for horizontal
			}
		}
		for (int i = 6; i > 2; i--)
		{
			for (int j = 0; j < 4; j++)
			{
				if (board[j][i] == turn && board[j + 1][i - 1] == turn && board[j + 2][i - 2] == turn && board[j + 3][i - 3] == turn)
					return true; //for diagonally up right
			}
			for (int j = 6; j > 2; j--)
			{
				if (board[j][i] == turn && board[j - 1][i - 1] == turn && board[j - 2][i - 2] == turn && board[j - 3][i - 3] == turn)
					return true; //for diagonally up left
			}
		}
		return false;
	}
	bool isBoardFull()
	{
		int full = 49;
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (board[i][j] != 0)
				{
					full--;
				}
			}
		}
		if (full != 0)
			return false;
		else
			return true;
	}
	bool dropcolour(int col, int turn)
	{
		int isColFull = 0;
		for (int i = 6; i >= 0; i--)
		{
			if (board[i][col - 1] == 0)
			{
				board[i][col - 1] = turn;
				isColFull = 1;
				break;
			}
		}
		if (isColFull == 0)
		{
			cout << "Can\'t drop in this column it is already fill try other column\n";
			return false;
		}
		return true;
	}
public:
	Connect4Game()
	{
		turn = 2;
		board = new int* [7];
		for (int i = 0; i < 7; i++)
		{
			board[i] = new int[7];
		}
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				board[i][j] = 0;
			}
		}
	}
	void start()
	{
		cout << "\t\t\tCONNECT 4 GAME" << endl;
		showBoard();
		do
		{
			switchTurn();
			int col;
			if (turn == 1)
				cout << "\t\t\tPlayer 1's turn\n";
			else if (turn == 2)
				cout << "\t\t\tPlayer 2's turn\n";
			cout << "\nEnter column no. in range of 1 to 7\t";
			cin >> col;
			while ((col < 1 || col>7) || (dropcolour(col, turn) == false))
			{
				cout << "\nEnter column no. in range of 1 to 7\t";
				cin >> col;
			}


			showBoard();
		} while (!((isWon(turn)) || (isBoardFull())));

		if ((isWon(turn)))
		{
		
			cout << "\t\t\t\tPLAYER " << turn << "has WON.";
		}
		else
		{

			cout << "\t\t\t\tDRAW" << endl;
		}
	}
};

int main()
{
	Connect4Game Game;
	Game.start();
	return 0;
}
