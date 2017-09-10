
#ifndef SUDOKU_H
#define SUDOKU_H

bool Sudoku_Row(int arr[9][9], int row, int num);
bool Sudoku_Col(int arr[9][9], int col, int num);
bool Sudoku_Square(int arr[9][9], int row, int col, int num);
void print_sudoku(int arr[9][9]);
bool makeSquare(int arr[9][9],int num);

#endif 
