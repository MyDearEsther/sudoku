#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include "sudoku.h"
using namespace std;

void Init_Sudoku(int(*arr)[9])
{
	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
			arr[r][c] = 0;
	}
	arr[0][0] = 1;
}
void Init_Sudoku_part(int(*arr)[9])
{
	for (int r = 3; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
			arr[r][c] = 0;
	}
	for (int r = 0; r < 3; r++)
	{
		for (int c = 3; c < 9; c++)
			arr[r][c] = 0;
	}
}


int main(int argc,char *argv[])
{
	int N = atoi(argv[argc - 1]);

	//int N;
	//cin >> N;

	int(*sudoku)[9] = new int[9][9];

	ofstream outfile;
	outfile.open("sudoku.txt");

	if (N > 0 && N <= 1000000)
	{
		srand(unsigned int(time(NULL))); //初始化种子为当前时间
		bool retry;//重试
		int retry_count = 0;//重试次数
		for (int i = 0; i < N; )
		{
			retry = false;
			if (retry_count == 0)
			{
				Init_Sudoku(sudoku);
				makeSquare(sudoku, 0);
			}
			else Init_Sudoku_part(sudoku);
			for (int j = 1; j < 9; j++)
			{
				bool flag = makeSquare(sudoku, j);
				if (!flag)
				{ 
					retry = true;
					break;
				}
			}
			if (!retry)
			{
				//cout << "第"<<i+1<<"个矩阵"<<"重试" << retry_count << "次" << endl;
				//print_sudoku(sudoku);
				for (int x = 0; x < 9; x++)
				{
					for (int y = 0; y < 9; y++)
					{
						outfile << sudoku[x][y] << ' ';
					}
					outfile << endl;
				}//输出一个数独矩阵
				outfile << endl;
				retry_count = 0; 
				i++;
			}
			else
			{
				retry_count++;
			}//无解重试

			/*retry = false;
			if (i == 0)
			{
				Init_Sudoku(sudoku);
				makeSquare(sudoku, 0);
			}
			else
			{ 
				Init_Sudoku_part(sudoku);
			}
			for (int j = 1; j < 9; j++)
			{
				bool flag = makeSquare(sudoku, j);
				if (!flag)
				{
					retry = true;
					break;
				}
			}
			if (!retry)
			{
				cout << "第" << i + 1 << "个矩阵" << "重试" << retry_count << "次" << endl;
				Output_Sudoku(sudoku, outfile);
				retry_count = 0;
				i++;
			}
			else
			{
				retry_count++;
			}  */
		}
		outfile.close();
	}
	else cout << "Please give me a proper number" << endl;
	return 0;
}
