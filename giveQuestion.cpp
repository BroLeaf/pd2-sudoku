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
    srand(time(NULL));
    changeNum(rand()%9+1,rand()%9+1);
    changeRow(rand()%3,rand()%3);
    changeCol(rand()%3,rand()%3);
    rotate(rand()%101);
    flip(rand()%2);  
    printOut(map2);
    return;
}
