#include <iostream>
using namespace std;

int bubbleSort(int arr[], int n) {
	int ans = 0;
      bool swapped = true;
      int j = 0;
      int tmp;
      while (swapped) {
            swapped = false;
            j++;
            for (int i = 0; i < n - j; i++) {
                  if (arr[i] > arr[i + 1]) {
                        tmp = arr[i];
                        arr[i] = arr[i + 1];
                        arr[i + 1] = tmp;
                        swapped = true;
						ans++;
                  }
            }
      }
	  return ans;
}

int main(){
#ifdef ONLINE_JUDGE
#else
	freopen("in.txt","r",stdin);
#endif
	int count;
	int total[20];
	while(cin>>count && count){
		for(int i=0;i<count;i++) cin>>total[i];
		cout<<bubbleSort(total,count)<<endl;
	}
	return 0;
}
