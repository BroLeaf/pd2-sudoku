#include"Sudoku.h"
using namespace std;

void Sudoku::transform(){
    srand(time(NULL));
    changeNum(2,3);
    changeRow(0,1);
    changeCol(0,1);
    rotate(79);
    flip(0);
    printOut(map);
}
