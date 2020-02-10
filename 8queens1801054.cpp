//State Space : 8*8 matrix precence of queen is represented by q1
//State transition operator: addition of new queen on each throw
//initial state: all entries on matrix is 0(i.e no queen has been placed)
//Goal state: All rows are filled such that no queens are at attacking positions


#include<iostream>
#include<queue>

using namespace std;

bool solved=false;
int cost=0;
struct chessboard{
 int array[8][8]; 
 int queens;
};
queue<chessboard> q1;

void print(chessboard &tt){
	cout<<"temp"<<endl;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cout<<tt.array[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
}



bool validity(chessboard &tt){
	int q=tt.queens,p=0,i,i2;
	for(i=0;i<8;i++){
		if(tt.array[q-1][i]==1) 
			break;
	}
	for(int j=q-2;j>=0;j--){
		if(tt.array[j][i]==1){
			return false;
		}
	}
	i2=i-1;
	for(int j=q-2;j>=0;j--){
		if(j<0||i2<0) 
			break;
		if(tt.array[j][i2]==1) 
			return false;
		i2--;
	}
	i2=i+1;
	for(int j=q-2;j>=0;j--){
		if(j<0||i2>7) 
			break;
		if(tt.array[j][i2]==1) 
			return false;
		i2++;
	}
	return true;
}



void findstate(queue<chessboard> &q1){
	chessboard tt;
	bool oc=true;
	tt=q1.front();
	q1.pop();
	int q=tt.queens;
        if(tt.queens==8) {
    	print(tt);
    	cout<<"Got the solution\n"<<endl;
    	cout<<"Cost: "<<cost<<endl;
    	solved=true;
    	return;
	}
	for(int i=0;i<8;i++){
		tt.array[q][i]=1;
		tt.queens++;
		if(q==0||validity(tt)){
			print(tt);
			q1.push(tt);
			cost++;
		}
		tt.queens--;
		tt.array[q][i]=0;
	}
}


int main(){
	chessboard cb;
    for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cb.array[i][j]=0;
		}
	}
	cb.queens=0;
	q1.push(cb);
    while(!q1.empty()&&solved==false){
    	findstate(q1);
}
return 0;
}
    	


