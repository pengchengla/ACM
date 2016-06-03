#include <iostream>
#include <algorithm>
using namespace std;

const int N=100;
int array[N];

void handle(int l,int r,int &maxv,int &minv){
	if(l==r){
		maxv=array[l];
		minv=array[r];
		return;
	}
	if(l+1==r){
		maxv=max(array[l],array[r]);
		minv=min(array[l],array[r]);
		return;
	}
	int maxl=0,minr=0;
	int mid=(l+r)/2;
	handle(l,mid,maxl,minr);

	int maxr=0,minr=0;
	handle(mid+1,r,maxr,minr);

	maxv=max(maxl,maxr);
	minv=min(minl,minr);
}

int main(){
	int maxv=0,minv=0;
	handle(0,N-1,maxv,minv);
	cout<<maxv<<"  "<<minv<<endl;
	return 0;
}
