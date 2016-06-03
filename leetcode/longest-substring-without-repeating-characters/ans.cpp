#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int ans=0;
		int cur=0;
		int start=0;
		if(s.length()<=1) return s.length();
		int imap[256];
		memset(imap,-1,sizeof(imap));
		for(int i=0;i<s.length();i++){
			if(imap[s[i]]==-1){
				imap[s[i]]=i;
				cur++;
			}
			else{
				if(imap[s[i]]>=start){
					start=imap[s[i]]+1;
					cur=i-start+1;
					imap[s[i]]=i;
				}
				else{
					imap[s[i]]=i;
					cur++;
				}
			}
			ans=max(ans,cur);
		}
		return ans;
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
