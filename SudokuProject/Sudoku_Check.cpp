#include "sudoku.h"

bool check_arr(int arr[9])
{
	int temp;
	for (int i = 0; i<9; i++) 
	{
		temp = arr[i];
		for (int j = i + 1; j<9; j++) 
		{ 
			if (arr[j] == temp)
			return false;
		}
	}
	return true;
}

bool Sudoku_Row(int arr[9][9],int row, int num)
{
	bool flag = false;
	for (int i = 0; i < 9; i++)
	{
		if (arr[row][i] == num) 
		{
			flag = true;
			break;
		}
	}
	return flag;
}
bool Sudoku_Col(int arr[9][9],int col, int num)
{
	bool flag = false;
	for (int i = 0; i < 9; i++)
	{
		if (arr[i][col] == num)
		{
			flag = true;
			break;
		}
	}
	return flag;
}
bool Sudoku_Square(int arr[9][9],int row, int col, int num)
{
	bool flag = false;
	int Square_Row = (row / 3) * 3;
	int Square_Col = (col / 3) * 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[Square_Row + i][Square_Col + j] == num)
			{
				flag = true;
				break;
			}
		}
	}
	return flag;
}