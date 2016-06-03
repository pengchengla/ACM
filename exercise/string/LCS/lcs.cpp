#include <iostream>
#include <string>
using namespace std;

void LCS_Print(int **LCS_Direction, string str, int row, int column){
    int nLen1 = str.length();
    if(nLen1 == 0 || row < 0 || column < 0)
        return;
    
    if(LCS_Direction[row][column] == 1){
        if(row > 0 && column > 0)
            LCS_Print(LCS_Direction, str, row - 1, column - 1);
		cout<<str[row]<<" ";
    }
    else if(LCS_Direction[row][column] == 2){
        if(row > 0)
            LCS_Print(LCS_Direction, str, row - 1, column);
    }
    else if(LCS_Direction[row][column] == 3){
        if(column > 0)
            LCS_Print(LCS_Direction, str, row, column - 1);
    }
}

int LCS(string str1, string str2){
    int nLen1 = str1.length();
    int nLen2 = str2.length();
    if(nLen1 <= 0 || nLen2 <= 0)
        return 0;
    // 申请一个二维数组，保存不同位置的LCS值
    int **LCS_Length = new int*[nLen1];
    // 申请一个二维数组，保存公共序列的位置
    int **LCS_Direction = new int*[nLen1];
    for(int i = 0; i < nLen1; i++){
        LCS_Length[i] = new int[nLen2];
        LCS_Direction[i] = new int[nLen2];
    }
    for(int i = 0; i < nLen1; i++){
        for(int j = 0; j < nLen2; j++){
            LCS_Direction[i][j] = 0;
			LCS_Length[i][j] = 0;
		}
	}
    
	for(int i = 0; i <nLen1; i++){
        for(int j = 0; j < nLen2; j++){
			if(i == 0 || j == 0){
                if(str1[i] == str2[j]){
                    LCS_Length[i][j] = 1;
                    LCS_Direction[i][j] = 1;
                }
                else
                    LCS_Length[i][j] = 0;
            }
            else if(str1[i] == str2[j]){
                LCS_Length[i][j] = LCS_Length[i - 1][j - 1] + 1;
                LCS_Direction[i][j] = 1;
            }
            else if(LCS_Length[i - 1][j] > LCS_Length[i][j - 1]){
                LCS_Length[i][j] = LCS_Length[i - 1][j];
                LCS_Direction[i][j] = 2;
            }
            else{
                LCS_Length[i][j] = LCS_Length[i][j - 1];
                LCS_Direction[i][j] = 3;
            }
        }
    }
    LCS_Print(LCS_Direction, str1, nLen1 - 1, nLen2 - 1);
    cout<<endl;
    int nLCS = LCS_Length[nLen1 - 1][nLen2 - 1];
    for(int i = 0; i < nLen1; i++){
        delete[] LCS_Length[i];
        delete[] LCS_Direction[i];
    }
    delete [] LCS_Length;
    delete [] LCS_Direction;
    return nLCS;
}

int main(){
	//最长公共子序列
    cout<<LCS("ABCBDAB", "BDCABA")<<endl;
    return 0;
}
