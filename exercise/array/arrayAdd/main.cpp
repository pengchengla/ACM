#include <iostream>
using namespace std;

const int N=100;
int array[N];
int ans=0;

int handle(int n){
	//if(n==0) return array[0];
	//ans=ans+array[n]+handle(n-1);
	//return ans;
	return n==0?1:handle(n-1)+array[n];
}

int main(){
	for(int i=0;i<N;i++)
		array[i]=i+1;
	cout<<handle(N)<<endl;
	return 0;
}
