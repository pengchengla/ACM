#include <iostream>
using namespace std;

int partition(int * total, int start, int end){
	int left = start;
	int right = end;
	int key = total[start];
	while(left<right){
		while(left<right && total[right]>key) right--;
		if(left<right) total[left++] = total[right];
		while(left<right && total[left]<key) left++;
		if(left<right) total[right--] = total[left];
	}
	total[left] = key;
	return left;
}

void quick_sort(int * total, int start, int end){
	if(start<end){
		int par = partition(total,start,end);
		quick_sort(total,start,par-1);
		quick_sort(total,par+1,end);
	}
}

int main(){
	freopen("in.txt","r",stdin);
	int n;
	cin>>n;
	int * total = new int[n];
	for(int i=0;i<n;i++) cin>>total[i];
	quick_sort(total,0,n-1);
	for(int i=0;i<n;i++) cout<<total[i]<<" ";
	cout<<endl;
	return 0;
}
