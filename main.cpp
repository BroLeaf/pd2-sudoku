#include"Sudoku.h"
using namespace std;

int main(){
    Sudoku ss;
    //giveQuestion();
    ss.readIn();    
    //ss.rotate(0);
    //ss.flip(1);
    //ss.changeNum(3,9);
    //ss.changeRow(0,3);
    //ss.changeCol(0,2);
    ss.solve();
    //ss.transform();
    //ss.printOut();
    return 0;
}
