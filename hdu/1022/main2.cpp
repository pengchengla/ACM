#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

stack<char> seq;
queue<string> ans;

bool handle(int num,string str1,string str2){
	int p1 = 0;
	int p2 = 0;
	while(p2<num){
		while(p1<num && str1[p1]!=str2[p2]){
			ans.push("in");
			seq.push(str1[p1]);
			p1++;
		}
		if(p1<num){
			ans.push("in");
			seq.push(str1[p1]);
			p1++;
		}
		while(p2<num && !seq.empty() && seq.top()==str2[p2]){
			ans.push("out");
			seq.pop();
			p2++;
		}
		if(p1>=num && p2<num){
			return false;
		}
	}
	return true;
}

int main(){
	freopen("in.txt","r",stdin);
	int num;
	string str1,str2;
	while(cin>>num>>str1>>str2){
		while(!seq.empty()) seq.pop();
		while(!ans.empty()) ans.pop();
		int len1 = str1.length();
		int len2 = str2.length();
		if(len1!=len2 || len1!=num){
			cout<<"No."<<endl;
			continue;
		}
		bool flag = handle(num,str1,str2);
		if(!flag) cout<<"No."<<endl<<"FINISH"<<endl;
		else{
			cout<<"Yes."<<endl;
			while(!ans.empty()){
				cout<<ans.front()<<endl;
				ans.pop();
			}
			cout<<"FINISH"<<endl;
		}
	}
	return 0;
}
