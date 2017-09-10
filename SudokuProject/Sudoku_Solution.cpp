#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "sudoku.h"
using namespace std;
#define Random(x) (rand()%x) //指定范围的随机数
bool flag = false;
void print_sudoku(int arr[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

bool makeSquare(int arr[9][9],int num)
{
	int square_row = (num / 3) * 3;
	int square_col = (num % 3) * 3;
	int x, y;
	int temp;
	if (num == 0)
	{
		for (int i = 1; i < 9; i++)
		{
			x = square_row + i / 3;
			y = square_col + i % 3;
			temp = Random(8) + 2;
			if (!Sudoku_Square(arr, x, y, temp) && !Sudoku_Col(arr, y, temp) && !Sudoku_Row(arr, x, temp))
			{
				arr[x][y] = temp;
			}
			else i--;
		}
	}
	else
	{
		int try_count = 0;
		temp = Random(9)+1;
		for (int i = 0; i < 9; i++)
		{
			x = square_row + i / 3;
			y = square_col + i % 3;
			temp++;
			temp = temp % 10;
			if (!Sudoku_Square(arr, x, y, temp) && !Sudoku_Col(arr, y, temp) && !Sudoku_Row(arr, x, temp)&&temp!=0)
			{
				arr[x][y] = temp;
				try_count = 0;
			}
			else
			{
				i--;
				try_count++;
			}
			if (try_count > 10)
			{
				return false;
				break;
			}
		}
	}
	return true;
}