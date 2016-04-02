#include"Sudoku.h"
using namespace std;

void Sudoku::readIn(){
    int i;
    for(i=0;i<81;i++){
        map[i]=0;
        cin>>map[i];
    }
    return;
}

void Sudoku::changeNum(int a,int b){
    if(a<1||a>9||b<1||b>9){
        return;
    }
    int i;
    for(i=0;i<81;i++){
        if(map[i]==a){map[i]=b;continue;}

        if(map[i]==b){map[i]=a;continue;}
    }
    //printOut(map);
    return;
}

void Sudoku::changeRow(int a,int b){
    if(a<0||a>2||b<0||b>2){
        return;
    }
    int i,temp;
    a = a*27;
    b = b*27;
    for(i=0;i<27;i++){
        temp=map[a];
        map[a]=map[b];
        map[b]=temp;
        a++;b++;
    }
    // printOut(map);
    return;
}

void Sudoku::changeCol(int a,int b){
    if(a<0||a>2||b<0||b>2){
        return;
    }
    int i,temp;
    a=a*3;b=b*3;
    for(i=0;i<27;i++){
        temp   = map[a];
        map[a] = map[b];
        map[b] = temp;
        if(a>=72){      //執行到最下面一列，換行且回到最上面。
            a=a-71;
            b=b-71;
            continue;
        }
        a=a+9;b=b+9;
    }
    //  printOut(map);
    return;

}

void Sudoku::rotate(int n){
    if(n>100||n<0){
        return;
    }
    n=n%4;
    if(n==0){return;}

    int temp[81],i,m;
    for(i=0;i<81;i++){temp[i]=map[i];}
    i=0;m=72;
    for(i=0;i<81;i++){ 
        map[i]=temp[m-(i%9)*9];
        if((i+1)%9==0)m++;      
    }

    if(n==2)rotate(1);
    if(n==3)rotate(2);
    return;
}

void Sudoku::flip(int n){
    int i,j,temp;
    if(n<0||n>1){
        return;
    }
    if(n==0){
        for(i=0;i<4;i++){       //執行四次，中間不用 
            for(j=0;j<9;j++){
                temp         =map[j+i*9];
                map[j+i*9]   =map[72+j-i*9];
                map[72+j-i*9]=temp;    
            }
        }
    }
    if(n==1){
        i=0;j=0;
        for(i=0;i<4;i++){       //執行四次，中間不用 
            for(j=0;j<9;j++){
                temp        =map[j*9+i];
                map[j*9+i]  =map[8+j*9-i];
                map[8+j*9-i]=temp;
            }
        }
        //printOut(map);
    }
//    return;
}

