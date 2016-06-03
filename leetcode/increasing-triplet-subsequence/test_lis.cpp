#include <iostream>
#include <vector>
using namespace std;

#define N 8
int total[N] = {1,2,1,2,1,2,1,2};
int flag[N] = {0};

int binary(int val,int len);
int BiSearch(int val,int len);

int lis(){
	flag[0] = total[0];
	int len = 1;

	for(int i=1;i<N;i++){
		if(total[i]>flag[len-1]){
			flag[len] = total[i];
			len++;
		}
		else{
			int pos = binary(total[i],len);
			flag[pos]=total[i];
		}
	}
	return len;
}

int binary(int val,int len){
	int left = 0;
	int right = len-1;
	while(left<=right){
		int mid = left + ((right-left)>>1);
		if(flag[mid]>val) right = mid-1;
		else if(flag[mid]<val) left = mid+1;
		else return mid;
	}
	return left;
}

int main(){
	int ans = lis();
	cout<<ans<<endl;
	for(int i=0;i<ans;i++){
		cout<<flag[i]<<" ";
	}
	cout<<endl;
	return 0;
}
