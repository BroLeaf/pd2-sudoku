#include"Sudoku.h"
using namespace std;

void Sudoku::printOut(int arr[]){
    int i;
    for(i=0;i<81;i++){
        cout<<arr[i]<<((i+1)%9?' ':'\n');
    }
    return;
}

void Sudoku::giveQuestion(){
	//for(int i=0;i<81;i++)map2[i]=0;
	int	map2[81]={8,0,0,0,0,0,0,0,0,0,0,3,6,0,0,0,0,0,0,7,0,0,9,0,2,0,0,0,5,0,0,0,7,0,0,0,0,0,0,0,4,5,7,0,0,0,0,0,1,0,0,0,3,0,0,0,1,0,0,0,0,6,8,0,0,8,5,0,0,0,1,0,0,9,0,0,0,0,4,0,0};
	srand(time(NULL));
    changeNum(rand()%9+1,rand()%9+1);
    changeRow(rand()%3,rand()%3);
    changeCol(rand()%3,rand()%3);
    rotate(rand()%101);
    flip(rand()%2);  
	for(int i=0;i<81;i++)cout<<map2[i]<<((i+1)%9?' ':'\n');
	//    printOut(map2);
    return;
}
