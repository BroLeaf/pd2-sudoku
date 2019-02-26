#include"Sudoku.h"

using namespace std;

int Sudoku::check(int arr[]){
	int i,j,num,r,c;
	for(num=0;num<81;num++){

		for(i=num/9,j=0;j<9;j++){		
			if(i*9+j==num||map[i*9+j]==0)continue;

			if(map[i*9+j]==arr[num])return 0;	
		}

		for(i=num%9,j=0;j<9;j++){
			if(i+j*9==num||map[i+j*9]==0)continue;

			if(map[i+j*9]==arr[num])return 0;
		}	

		for(r=num/27,c=(num/3)%3,i=0;i<3;i++){
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

void Sudoku::printOut(int arr[]){
	int i;
	for(i=0;i<81;i++){
		cout<<arr[i]<<((i+1)%9?' ':'\n');
	}
	return;
}

void Sudoku::giveQuestion(){
	int	map2[81]={
		8,0,0,0,0,0,0,0,0,
		0,0,3,6,0,0,0,0,0,
		0,7,0,0,9,0,2,0,0,
		0,5,0,0,0,7,0,0,0,
		0,0,0,0,4,5,7,0,0,
		0,0,0,1,0,0,0,3,0,
		0,0,1,0,0,0,0,6,8,
		0,0,8,5,0,0,0,1,0,
		0,9,0,0,0,0,4,0,0};

	printOut(map2);
	return;
}

void Sudoku::solve(){
	comparision();
	if(check(map)==0||check(map)==2){		//??????????????,???? 
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
			while(compare[i]){		//??????? 
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
				for(j=0;j<81;j++){copy[j]=map[j];}		//??????,?????copy? 
				map[i]=0;
				i--;
				while(compare[i]){		//??????? 
					i--;
				}
				map[i]++;
				correct++;		//???? 
				if(correct>1){		//??????,??print2 
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

int Sudoku::getBlank(){		//?????????? 
	int i=0;
	while(map[i]>0&&i<81){
		i++;		
	}
	return i;
}

int Sudoku::checkRow(int num){		//???,????9??,????1 
	int i=num/9,j;
	for(j=0;j<9;j++){		
		if(i*9+j==num)continue;

		if(map[i*9+j]==map[num])return 0;	
	}
	return 1;
}

int Sudoku::checkColumn(int num){		//???,????9??,????1 
	int i=num%9,j;
	for(j=0;j<9;j++){
		if(i+j*9==num)continue;

		if(map[i+j*9]==map[num])return 0;
	}	
	return 1;
}

int Sudoku::checkSquare(int num){		//?????,??(r)???(c)??????,????1 
	int r=num/27,c=(num/3)%3,i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(r*27+c*3+i*9+j==num)continue;

			if(map[r*27+c*3+i*9+j]==map[num])return 0;
		}
	}
	return 1;
}

void Sudoku::comparision(){		//???????????????? 
	int i,j,r,c,num,count,pos,ele,times,k;
	while(1){
		k=0;	
		for(num=0;num<81;num++){
			if(map[num]!=0)continue;
			for(i=1;i<10;i++){
				candidate[i]=0;
			}
			for(i=num/9,j=0;j<9;j++){		//row??,?????++ 
				if(i*9+j==num||map[i*9+j]==0){continue;}
				if(map[i*9+j]!=0){
					ele=map[i*9+j];
					candidate[ele]++;
				}
			}
			for(i=num%9,j=0;j<9;j++){		//column??,?????++ 
				if(i+j*9==num||map[i+j*9]==0){continue;}		
				if(map[i+j*9]!=0){
					ele=map[i+j*9];
					candidate[ele]++;
				}
			}
			for(r=num/27,c=(num/3)%3,i=0;i<3;i++){		//?????,?????++ 
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
		if(a>=72){      //????????,?????????
			a=a-71;
			b=b-71;
			continue;
		}
		a=a+9;b=b+9;
	}
	//	printOut(map);
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
		for(i=0;i<4;i++){		//????,???? 
			for(j=0;j<9;j++){
				temp		 =map[j+i*9];
				map[j+i*9]	 =map[72+j-i*9];
				map[72+j-i*9]=temp;    
			}
		}
	}
	if(n==1){
		i=0;j=0;
		for(i=0;i<4;i++){		//????,???? 
			for(j=0;j<9;j++){
				temp		=map[j*9+i];
				map[j*9+i]	=map[8+j*9-i];
				map[8+j*9-i]=temp;
			}
		}
		//printOut(map);
	}
	return;
}

void Sudoku::transform(){
	srand(time(NULL));
	changeNum(2,3);
	changeRow(0,1);
	changeCol(0,1);
	rotate(79);
	flip(0);
	printOut(map);
}
