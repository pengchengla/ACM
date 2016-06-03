#include <iostream>
#include<vector>
using namespace std;

const int prime = 19999;
const int MAXN = 100100;
int sf[MAXN][6];
vector<int> hash[20000];

void HASH(int i, int sum){
    int j, key;
    key = sum % prime;
    hash[key].push_back(i);
}

bool cmp(int x, int y){
    bool flag = false;
    int i, j;
    for(i = 0; i < 6; i ++){
        if(sf[x][0] == sf[y][i]){
            for(j = 1; j < 6; j ++)
                if(sf[x][j] != sf[y][(i + j) % 6])
                    break;
            if(j == 6) flag = true;

            for(j = 1; j < 6; j ++)
                if(sf[x][6 - j] != sf[y][(i + j) % 6])
                    break;
            if(j == 6) flag = true;
        }
    }
    return flag;
}

bool check(){
    int i, j, k;
    for(i = 0; i < 20000; i ++){
        for(j = 0; j < hash[i].size(); j ++){
            for(k = j + 1; k < hash[i].size(); k ++){
                if(cmp(hash[i][j], hash[i][k]))
                    return true;
            }
        }
    }
    return false;
}

int main(){
    int n, i, j, sum;
    while(scanf("%d", &n) == 1){
        for(i = 0; i < n; i ++){
            sum = 0;
            for(j = 0; j < 6; j ++){
                scanf("%d", &sf[i][j]);
                sum += sf[i][j];
            }
            HASH(i, sum);
        }
        if(check())
            printf("Twin snowflakes found.\n");
        else
            printf("No two snowflakes are alike.\n");
    }
    return 0;
}
