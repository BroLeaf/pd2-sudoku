#include"Sudoku.h"
using namespace std;

int Sudoku::check(int arr[]){
	int i,j,num,r,c;
	for(num=0;num<81;num++){

		for(i=num/9,j=0;j<9;j++){       
			if(i*9+j==num||map[i*9+j]==0)continue;

			if(map[i*9+j]==arr[num])return 0;   
		}
		i=num%9;
		for(j=0;j<9;j++){
			if(i+j*9==num||map[i+j*9]==0)continue;

			if(map[i+j*9]==arr[num])return 0;
		}   
		r=num/27;c=(num/3)%3;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(r*27+c*3+i*9+j==num||map[r*27+c*3+i*9+j]==0)continue;

				if(map[r*27+c*3+i*9+j]==arr[num])return 0;
			}
		}
	}
	num=0;
	for(i=0;i<81;i++){
		if(arr[i]!=0)num++;
	}
	if(num<17)return 2;
	if(num==81)return 3;
	return 1;
}

void Sudoku::solve(){
	comparision();
	if(check(map)==0||check(map)==2){       //測驗是否是無解或很明瞭的多解，節省時間 
		cout<<check(map)<<endl;
		return;
	}
	if(check(map)==3){
		cout<<"1"<<endl;
		printOut(map);
		return;
	}
	int i=getBlank(),j,correct=0;
	for(j=0;j<81;j++){
		compare[j]=map[j];
	}
	while(i<81){
		if(i<0)break;
		if(map[i]==0)map[i]++;

		if(map[i]>9) {
			map[i]=0;
			i--;
			while(compare[i]){      //避免改到原題目 
				i--;
			}

			map[i]++;
			continue;
		}
		//cout<<i<<" "<<checkRow(i)<<checkColumn(i)<<checkSquare(i)<<" "<<map[i]<<endl;
		if( checkRow(i)&&checkColumn(i)&&checkSquare(i) ){
			i++;
			while(compare[i]&&i!=80){
				i++;
			}
			if(i>80){
				for(j=0;j<81;j++){copy[j]=map[j];}      //完成第一次解，把結果存入copy中 
				map[i]=0;
				i--;
				while(compare[i]){      //避免改到原題目 
					i--;
				}
				map[i]++;
				correct++;      //正解次數 
				if(correct>1){      //有兩個以上解，直接print2 
					cout<<"2"<<endl;
					return;
					//break;
				}
			}
		}
		else{
			map[i]++;
		}
	}
	if(correct==0){
		cout<<"0"<<endl;
		return;
	}
	cout<<"1"<<endl;
	printOut(copy);
	return;
}

int Sudoku::getBlank(){     //一開始取得第一個空白 
	int i=0;
	while(map[i]>0&&i<81){
		i++;        
	}
	return i;
}

int Sudoku::checkRow(int num){      //行檢查，水平分成9等分，無誤回傳1 
	int i=num/9,j;
	for(j=0;j<9;j++){       
		if(i*9+j==num)continue;

		if(map[i*9+j]==map[num])return 0;   
	}
	return 1;
}

int Sudoku::checkColumn(int num){       //列檢查，垂直分成9等分，無誤回傳1 
	int i=num%9,j;
	for(j=0;j<9;j++){
		if(i+j*9==num)continue;

		if(map[i+j*9]==map[num])return 0;
	}   
	return 1;
}

int Sudoku::checkSquare(int num){       //九宮格檢查，水平(r)、垂直(c)各分成三等份，無誤回傳1 
	int r=num/27,c=(num/3)%3,i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(r*27+c*3+i*9+j==num)continue;

			if(map[r*27+c*3+i*9+j]==map[num])return 0;
		}
	}
	return 1;
}

void Sudoku::comparision(){		//當某格只有唯一可能時直接填入答案 
	int i,j,r,c,num,count,pos,ele,times,k;
	while(1){
		k=0;	
		for(num=0;num<81;num++){
			if(map[num]!=0)continue;
			for(i=1;i<10;i++){
				candidate[i]=0;
			}
			for(i=num/9,j=0;j<9;j++){		//row檢查，若有數字則++ 
				if(i*9+j==num||map[i*9+j]==0){continue;}
				if(map[i*9+j]!=0){
					ele=map[i*9+j];
					candidate[ele]++;
				}
			}
			for(i=num%9,j=0;j<9;j++){		//column檢查，若有數字則++ 
				if(i+j*9==num||map[i+j*9]==0){continue;}		
				if(map[i+j*9]!=0){
					ele=map[i+j*9];
					candidate[ele]++;
				}
			}
			for(r=num/27,c=(num/3)%3,i=0;i<3;i++){		//九宮格檢查，若有數字則++ 
				for(j=0;j<3;j++){
					if(r*27+c*3+i*9+j==num||map[r*27+c*3+i*9+j]==0){continue;}
					if(map[r*27+c*3+i*9+j]!=0){
						ele=map[r*27+c*3+i*9+j];
						candidate[ele]++;
					}
				}
			}
			count=0;pos=0;
			for(i=1;i<10;i++){
				if(candidate[i]==0){
					count++;
					pos=i;
				}
			}
			k=0;
			if(count==1){
				map[num]=pos;
				k++;
			}
		}
		if(k==0)return;	
	}
	//	printOut(map);
}


