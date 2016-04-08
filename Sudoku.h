#include<iostream>
#include<stdlib.h>
#include<time.h>
#define sudokuSize 81;
using namespace std;
//static const int sudokuSize = 81;
class Sudoku{
    public:
        int check(int arr[]);
        void printOut(int a[]);
        void giveQuestion();
        void readIn();
        void solve();
        int getBlank();
        int checkRow(int num);
        int checkColumn(int num);
        int checkSquare(int num);
		void comparision();
        void changeNum(int a,int b);
        void changeRow(int a,int b);
        void changeCol(int a,int b);
        void rotate(int a);
        void flip(int a);
        void transform();
        int map[81];
	private:    
		int compare[81];
        int copy[81];
        int candidate[9];
};
