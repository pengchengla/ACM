/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-13
*   描    述：
================================================================*/
#include <iostream>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        row = grid.size();
        if(row==0) return 0;
        col = grid[0].size();
        cout<<row<<"   "<<col<<endl;
        memset(isscan,0,sizeof(isscan));
        
        int ans = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(isscan[i][j]==0 && grid[i][j]=='1'){
                    dfs(grid,i,j);
                    ans += 1;
                }
            }
        }
        return ans;
    }
private:
    int isscan[1003][1003];
    int row;
    int col;
private:
    void dfs(vector<vector<char> >& grid, int i, int j){
        if(i<0 || i>=row || j<0 || j>=col) return;
        if(isscan[i][j]==1) return;
        if(grid[i][j]=='0') return;
        isscan[i][j] = 1;
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
};

int main(){
    return 0;
}
