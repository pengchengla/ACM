/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：ans.cpp
*   创 建 者：pengcheng
*   创建日期：2015-08-06
*   描    述：
================================================================*/
#include <iostream>
#include <string>
using namespace std;

int n,m,cnt;
char map[30][30];
int to[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

void dfs(int i,int j){
    map[i][j] = '#';
    for(int k = 0; k<4; k++){
        int x = i+to[k][0];
        int y = j+to[k][1];
        if(x<n && y<m && x>=0 && y>=0 && map[x][y] == '.'){
            cnt++;
            dfs(x,y);
        }
    }
    return;
}

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int i,j,si,sj;
    while(cin>>m>>n){
        if(m == 0 && n == 0)
            break;
        for(i = 0; i<n; i++){
            for(j = 0; j<m; j++){
                cin>>map[i][j];
                if(map[i][j] == '@'){
                    si = i;
                    sj = j;
                }
            }
        }
        cnt = 1;
        dfs(si,sj);
        cout<<cnt<<endl;
    }
    return 0;
}

