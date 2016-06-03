#include <iostream>
using namespace std;

int main(){
	//freopen("in.txt","r",stdin);
	double n;
	while(cin>>n){
		int ans = 0;
		ans = (int)((1+n)*n)/2;
		cout<<ans<<endl<<endl;
	}
	return 0;
}
