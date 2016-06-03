#include <iostream>
#include <stack>
using namespace std;
//拆分
//取摸
//遍历?
int handle(int cur){

}

int main(){
	freopen("in.txt","r",stdin);
	int ans = 0;
	int start,end,target;
	cin>>start>>end>>target;
	for(int i=start;i<=end;i++){
		if(target==handle(i))
			ans=ans+(i%(power(10,9)+7))
	}
	cout<<ans<<endl;
	return 0;
}
