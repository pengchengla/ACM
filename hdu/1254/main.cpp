/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-08-05
*   描    述：
================================================================*/
#include <iostream>
#include <bitset>
using namespace std;

struct node{
    int x,y;
    node(){}
    node(int tx,int ty){x=tx;y=ty;}
};

int px,py,bx,by,ex,ey;
int map[10][10];
bitset<10> flag[10];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
queue<node> qu;

void bfs(){
}

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int tc; cin>>tc;
    while(tc--){
    }
    return 0;
}
