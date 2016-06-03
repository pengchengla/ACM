#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int> >& matrix) {
		if(matrix.size()==0) return 0;
		int ans = 1;
		vector<vector<int> > dp(matrix.size(),vector<int>(matrix[0].size(),-1));
		for(int i=0;i<matrix.size();++i){
			for(int j=0;j<matrix[0].size();++j){
				int tmp = helper(matrix,dp,matrix[i][j],i,j);
				ans = max(ans,tmp);
			}
		}
		return ans;
    }
private:
	int helper(vector<vector<int> >&matrix,vector<vector<int> >&dp,int cmp,int i,int j){
		if(dp[i][j]!=-1) return dp[i][j];
		int ans = 1;
		vector<pair<int,int> > dir = {make_pair(-1,0), make_pair(0,-1), make_pair(1,0), make_pair(0,1)};
		for(auto &x : dir){
			int row = i+x.first;
			int col = j+x.second;
			if(row>=0 && row<matrix.size() && col>=0 && col<matrix[0].size() && matrix[row][col]>cmp){
				int tmp = 1+helper(matrix,dp,matrix[row][col],row,col);
				ans = max(tmp,ans);
			}
		}
		dp[i][j] = ans;
		return ans;
	}
};

int main()
{
	return 0;
}
