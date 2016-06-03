#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int map[4][4];
int flag,step;
int is_goal(){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
            if(map[i][j]!=map[0][0])
               return 0;
        }
    return 1;
}
void flip(int i,int j){
     map[i][j]=!map[i][j];
     if(i-1>=0) map[i-1][j]=!map[i-1][j];
     if(i+1<=3) map[i+1][j]=!map[i+1][j];
     if(j-1>=0) map[i][j-1]=!map[i][j-1];
     if(j+1<=3) map[i][j+1]=!map[i][j+1];
}

void dfs(int row,int col,int cnt){
     if(cnt==step){
         flag=is_goal();
         return ;
     }
     if(flag || row==4)
         return ;
     flip(row,col); //翻转点（row,col)
     if(col+1<=3)
          dfs(row,col+1,cnt+1);
     else
          dfs(row+1,0,cnt+1);
 
     flip(row,col); //不翻转点（row,col)，则将其还原
     if(col+1<=3)
          dfs(row,col+1,cnt);
     else
          dfs(row+1,0,cnt);
}

int main()
{
    freopen("in.txt","r",stdin);
    char s[5];
    for(int i=0;i<4;i++)
    {
        scanf("%s",s);
        for(int j=0;j<4;j++)
        {
            if(s[j]=='b')
                map[i][j]=1;
            else
                map[i][j]=0;
        }
    }
    flag=0;
    for(step=0;step<=16;step++)
    {
        dfs(0,0,0);
        if(flag)
           break;
    }
    if(!flag)
        puts("Impossible");
    else
        printf("%d\n",step);
 
    return 0;
}

