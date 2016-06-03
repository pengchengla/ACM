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

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> ans;
        memset(grade,0,sizeof(grade));
        graph.resize(numCourses);
        int size = prerequisites.size();
        for(int i=0;i<size;i++){
            pair<int,int> pp = prerequisites[i];
            graph[pp.second].push_back(pp.first);
            grade[pp.first]++;
        }
        bool flag = true;
        while(flag){
            flag = false;
            for(int i=0;i<numCourses;i++){
                if(grade[i]==0){
                    flag = true;
                    vector<int> tmp = graph[i];
                    for(int t=0;t<tmp.size();t++){
                        grade[tmp[t]]--;
                    }
                    grade[i]=-1;
                    ans.push_back(i);
                }
            }
        }
        if(ans.size()!=numCourses) ans.clear();
        return ans;
    }
private:
    vector<vector<int> > graph;
    int grade[2003];
};


int main(){
    return 0;
}
