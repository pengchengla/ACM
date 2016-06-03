#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int len=nums.size();
		if(len<=1) return len;
		int p=0;
		int twice=1;
		for(int i=1;i<len;i++){
			if(nums[i]!=nums[p] || (nums[i]==nums[p] && twice<2)){
				if(nums[p]==nums[i]) twice++;
				if(nums[p]!=nums[i]) twice=1;
				p++;
				nums[p]=nums[i];
			}
		}
		return p+1;
    }
};

int main(){
	return 0;
}
