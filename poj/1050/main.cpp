#include <stdio.h>
#define MAXSIZE 101

//求出一行中最大的子段和
int MaxArray( int n, int arr_[]){
    int i, sum_ = 0, max_ = 0;
    for (i=1; i<=n; i++){
        if (sum_>0)
            sum_ += arr_[i];
        else
            sum_ = arr_[i];
        if (sum_>max_)
            max_ = sum_;
    }
    return max_;
}

//求出最大子矩阵和。
int MaxMatrix( int n, int arr_[][MAXSIZE]){
    int max_ = arr_[1][1];
    int sum_;
    int i, j, k;
    int temp_arr[MAXSIZE]; 
    for (i=1; i<=n; i++){ //从第一行开始，直到第n行
        for (j=1; j<=n; j++) //只有起始行改变，temp_arr数组才初始化
            temp_arr[j] = 0;

        for (j=i; j<=n; j++){ //从i行到第n行
            for (k=1; k<=n; k++)  
                temp_arr[k] += arr_[j][k]; //temp_arr[k] 表示从第i行到第n行中第k列的总和。
            
            sum_ = MaxArray(n, temp_arr); //求出该行中最大的子段和
            if (sum_ > max_)
                max_ = sum_;
        }
    }
    
    return max_;
}

int main(){
    int n;
    int i, j;
    int arr_[MAXSIZE][MAXSIZE];
    int max_;
    while (~scanf("%d", &n)){ //多组测试。 相当于 scanf("%d", &n) != EOF
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                scanf("%d", &arr_[i][j]);
        max_ = MaxMatrix(n, arr_);
        printf("%d\n", max_);
    }
    return 0;
}
