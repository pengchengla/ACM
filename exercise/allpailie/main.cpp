#include <iostream>
#include <string>
using namespace std;

void swap(string &str,int i,int j){
	char ch = str[i]; str[i] = str[j]; str[j] = ch;
}

void arrange(string str,int pos){
	if(pos==str.length()){
		cout<<str<<endl;
		return;
	}
	for(int i=pos;i<str.length();i++){
		swap(str,i,pos);
		arrange(str,pos+1);
		swap(str,i,pos);
	}
}

int main(){
	string str="ABCD";
	arrange(str,0);
	return 0;
}
