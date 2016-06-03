#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
		int * f = new int[amount+1];
		for(int i=0;i<=amount;i++) f[i] = -99;
		f[0] = 0;
		int count = 0;
		for(int i=0;i<coins.size();i++){
			for(int v=coins[i];v<=amount;v++){
				f[v]=max(f[v],f[v-coins[i]]+coins[i]);
				if(f[v]==f[v-coins[i]]+coins[i]) count++;
			}
		}
		if(f[amount]!=amount) count = -1;
		return count;
    }
};

int main(){
	vector<int> coins;
	coins.push_back(2);
	Solution * solution = new Solution();
	cout<<solution->coinChange(coins,2)<<endl;
	return 0;
}
