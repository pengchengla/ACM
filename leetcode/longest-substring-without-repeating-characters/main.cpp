#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int count[256];
		int max=0;
		int tmp=0;
		for(int i=0;i<s.length();i++){
			memset(count,0,sizeof(count));
			count[s[i]]++;
			tmp=1;
			for(int j=i+1;j<s.length();j++){
				if(count[s[j]]!=0)
					break;
				count[s[j]]++;
				tmp++;
			}
			if(tmp>max) max=tmp;
		}
		return max;
    }
};

int main(){
	Solution * solution = new Solution();
	cout<<solution->lengthOfLongestSubstring("")<<endl;
	cout<<solution->lengthOfLongestSubstring("a")<<endl;
	cout<<solution->lengthOfLongestSubstring("abcabcbb")<<endl;
	cout<<solution->lengthOfLongestSubstring("bbbbb")<<endl;
	return 0;
}
