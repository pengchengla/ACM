/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-08-04
*   描    述：
================================================================*/
#include <iostream>
#include <vector>
#include <string>
#include <bitset>
using namespace std;
#define MAX 1003

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        width = board[0].size();
        height = board.size();
        for(int i=0;i<MAX;i++) flag[i].reset();
        bool ans = false;
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(board[i][j]==word[0]){
                    flag[i][j] = 1;
                    ans = dfs(board,i,j,word,1);
                    for(int b=0;b<MAX;b++) flag[b].reset();
                }
                if(ans) return ans;
            }
        }
        return ans;
    }
private:
    bool dfs(vector<vector<char> >& board, int i, int j, string word, int pos){
        if(pos==word.length()) return true;
        for(int s=0;s<4;s++){
            int ti = i + dir[s][0];
            int tj = j + dir[s][1];
            if(isInArea(ti,tj) && board[ti][tj]==word[pos] && flag[ti][tj]==0){
                flag[ti][tj] = 1;
                if(dfs(board,ti,tj,word,pos+1)) return true;
                flag[ti][tj] = 0;//important
            }
        }
        return false;
    }

    bool isInArea(int ti,int tj){
        if(ti<height && ti>=0 && tj<width && tj>=0) return true;
        return false;
    }
private:
    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    bitset<MAX> flag[MAX];
    int width;
    int height;
};

int main(){
    vector<vector<char> > matrix;
    vector<char> vec;
    vec.push_back('A');
    vec.push_back('B');
    vec.push_back('C');
    vec.push_back('E');
    matrix.push_back(vec);

    vec.clear();
    vec.push_back('S');
    vec.push_back('F');
    vec.push_back('E');
    vec.push_back('S');
    matrix.push_back(vec);


    vec.clear();
    vec.push_back('A');
    vec.push_back('D');
    vec.push_back('E');
    vec.push_back('E');
    matrix.push_back(vec);

    Solution * solution = new Solution();
    //["ABCE","SFES","ADEE"], "ABCESEEEFS"
    cout<<solution->exist(matrix,"ABCESEEEFS")<<endl;
    return 0;
}
