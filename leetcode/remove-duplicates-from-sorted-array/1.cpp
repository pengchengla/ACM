#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int len = nums.size();
		if(len<=1) return len;
		int p = 0;//p指向最后面一个有效数字
		for(int i=1;i<len;i++){
			if(nums[i]!=nums[p]){
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
