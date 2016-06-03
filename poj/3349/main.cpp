/**
判断n朵雪花中，是否有完全一样的雪花。一道比较简单的hash，我们将雪花的六个边的权值加
起来，记为sum，将sum相等的雪花归为一类，再在这里面根据题意找完全相同的，在同类中找到
一个角相同的，然后判断顺时针或者逆时针的所有角是否一模一样。
**/
#include <iostream>
#include <vector>
using namespace std;

const int prime = 1999;
vector<int> _hash[prime];
int snows[100000][6];

void hash_handle(int sum,int i){
	int pos = sum%prime;
	_hash[pos].push_back(i);
}

bool cmp(int x,int y){
	bool flag = false;
	for(int i=0;i<6;i++){
		if(snows[x][0]==snows[y][i]){
			//clock
			int m=1;
			for(m=1;m<6;m++) if(snows[x][m]!=snows[y][(m+i)%6]) break;
			if(m==6) flag = true;
			//counterclock
			int n=1;
			for(n=1;n<6;n++) if(snows[x][6-n]!=snows[y][(n+i)%6]) break;
			if(n==6) flag = true;
		}
	}
	return flag;
}

bool check(){
	for(int i=0;i<prime;i++){
		for(int m=0;m<_hash[i].size();m++){
			for(int n=m+1;n<_hash[i].size();n++){
				if(cmp(_hash[i][m],_hash[i][n]))
					return true;
			}
		}
	}
	return false;
}

int main(){
	//freopen("in.txt","r",stdin);
	int lines;	cin>>lines;
	int tmp=0;
	for(int i=0;i<lines;i++){
		int sum = 0;
		for(int p=0;p<6;p++){
			cin>>tmp;
			sum += tmp;
			snows[i][p] = tmp;
		}
		hash_handle(sum,i);
	}
	if(check()) cout<<"Twin snowflakes found."<<endl;
	else cout<<"No two snowflakes are alike."<<endl;
	return 0;
}
