/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-29
*   描    述：
================================================================*/
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        for(int i=0;i<len;i++){
            char ch = s[i];
            if(ch==' ') continue;
            if(ch>='0' && ch<='9'){
                int tmp = 0;
                while(ch>='0' && ch<='9'){
                    tmp = tmp*10 + (ch-'0');
                    i++;
                    if(i>=len) break;
                    ch = s[i];
                }
                num.push(tmp);
                i--;
            }else if(ch=='+'||ch=='-'){
                if(!op.empty() && op.top()!='('){
                    handle();
                }
                op.push(ch);
            }else if(ch=='('){
                op.push(ch);
            }else if(ch==')'){
                if(op.top()!='('){
                    handle();
                }
                op.pop();
            }
        }
        if(!op.empty()&&(op.top()=='+'||op.top()=='-')){
            handle();
        }
        return num.top();
    }
private:
    void handle(){
        int num1 = num.top(); num.pop();
        int num2 = num.top(); num.pop();
        char curOp = op.top(); op.pop();
        num.push(_cal(num2,curOp,num1));
    }
    int _cal(int num2,char op,int num1){
        int ans = 0;
        switch(op){
            case '+': ans = num2+num1; break;
            case '-': ans = num2-num1; break;
        }
        return ans;
    }
private:
    stack<int> num;
    stack<char> op;
};

int main(){
    Solution * solution = new Solution();
    cout<<solution->calculate(" 2-1 + 2 ")<<endl;
    return 0;
}
