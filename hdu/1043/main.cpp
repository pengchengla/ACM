#include <iostream>
#include <string>
using namespace std;

int main(){
	char total[3][3];
	freopen("in.txt","r",stdin);
	char ch;
	int count = 0;
	while(cin>>ch){
		cout<<ch<<endl;
		total[count/3][count%3] = ch;
		count++;
	}
	return 0;
}
