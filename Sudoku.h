#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
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
    private:
        int map[81];
        int compare[81];
        int copy[81];
        int candidate[9];
};
