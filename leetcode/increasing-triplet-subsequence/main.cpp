#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
		if(nums.size()<=2) return false;
		flag = new int[nums.size()];
		int len = lis(nums);
		if(len >= 3) return true;
		return false;
    }

	int lis(vector<int>& nums){
		int len = 1;
		flag[0]=nums[0];
		
		for(int i=1;i<nums.size();i++){
			if(flag[len-1]<nums[i]){
				flag[len] = nums[i];
				len++;
			}
			else{
				int pos = binary(nums[i],len);
				flag[pos] = nums[i];
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
private:
	int * flag;
};

int main(){
	vector<int> nums;
	//int total[9] = {2, 1, 6, 3, 5, 4, 8, 7, 9};
	//for(int i=0;i<9;i++){
	//	nums.push_back(total[i]);
	//}
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(2);
	Solution * solution = new Solution();
	if(solution->increasingTriplet(nums)) cout<<"true"<<endl;
	else cout<<"false"<<endl;
	return 0;
}
