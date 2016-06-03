/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：ans2.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-14
*   描    述：
================================================================*/
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

bool cmp(const pair<int,int> & a, const pair<int,int> & b ){
    if(a.first<b.first) return true;
    if(a.first==b.first && a.second<b.second) return true;
    return false;
}   

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> ans;
        int grade[2003];
        memset(grade,0,sizeof(grade));
        sort(prerequisites.begin(),prerequisites.end(),cmp);

        //count grade
        int size = prerequisites.size();
        for(int i=0;i<size;i++){
            pair<int,int> pp = prerequisites[i];
            grade[pp.second]++;
        }
        //first equal 0
        bool flag = true;
        while(flag){
            int i = 0;
            for(;i<numCourses;i++)  if(grade[i]==0) break;
            if(i==numCourses) break;
            grade[i] = -1;
            ans.push_back(i);

            for(int j=0;j<size;j++){
                pair<int,int> pp = prerequisites[j];
                if(pp.first==i) grade[pp.second]--;
            }
        }

        for(int i=0;i<numCourses;i++){
            if(grade[i]>0){
                ans.clear();
                return ans;
            }
        }
        return ans;
    }
};


int main(){
    Solution * solution = new Solution();
    vector<pair<int, int> > prerequisites;
    prerequisites.push_back(make_pair(1,0));
    prerequisites.push_back(make_pair(0,2));
    prerequisites.push_back(make_pair(2,1));
    cout<<solution->canFinish(3,prerequisites)<<endl;
    return 0;
}
