#include <iostream>
#include <string>
using namespace std;

//全排列就是从第一个数字起每个数分别与它后面的数字交换
string src;
void swap(int i,int pos){
	char tmp = src[i];
	src[i] = src[pos];
	src[pos] = tmp;
}

void handle(int pos){
	if(pos==src.length()){
		cout<<src<<endl;
		return;
	}
	for(int i=pos;i<src.length();i++){
		swap(i,pos);
		handle(pos+1);
		swap(i,pos);
	}
}

int main(){
	freopen("in.txt","r",stdin);
	cin>>src;
	handle(0);
	return 0;
}
