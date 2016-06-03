/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-28
*   描    述：
================================================================*/
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<char> op;
        stack<int> num;
        int len = s.length();
        for(int i=0;i<len;i++)
        {
            char ch = s[i];
            if(ch>='0' && ch<='9')
            {
                int tmp = 0;
                while(ch>='0' && ch<='9')
                {
                    tmp = tmp*10 + (ch-'0');
                    i++;
                    if(i>=len) break;
                    ch = s[i];
                }
                num.push(tmp);
                i--;
            }
            else if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
            {
                if(!op.empty()){
                    char top = op.top();
                    if(!judgePri(ch,top)){
                        int num1 = num.top(); num.pop();
                        int num2 = num.top(); num.pop();
                        op.pop();
                        num.push(_cal(num2,top,num1));
                    }
                }
                op.push(ch);
            }
        }
        while(!op.empty()){
            int num1 = num.top(); num.pop();
            int num2 = num.top(); num.pop();
            char top = op.top(); op.pop();
            num.push(_cal(num2,top,num1));
        }
        return num.top();
    }
private:
    bool judgePri(char cur,char top){
        if(cur=='/' && top !='/') return true;
        if(cur=='*' && (top=='+' || top=='-')) return true;
        return false;
    }

    int _cal(int num1,char op,int num2){
        int ans = 0;
        switch(op){
            case '+': ans = num1+num2;break;
            case '-': ans = num1-num2;break;
            case '*': ans = num1*num2;break;
            case '/': ans = num1/num2;break;
        }
        return ans;
    }
};

int main(){
    Solution * solution = new Solution();
    //cout<<solution->calculate("1*2-3/4+5*6-7*8+9/10")<<endl;
    cout<<solution->calculate("1*2-3/4+5*6")<<endl;
    return 0;
}
