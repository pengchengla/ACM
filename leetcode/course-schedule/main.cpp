/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
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
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        if(numCourses==1) return true;
        int mark[1003][1003];
        memset(mark,0,sizeof(mark));
        int size = prerequisites.size();
        for(int i=0;i<size;i++){
            pair<int,int> pp = prerequisites[i];
            mark[pp.first][pp.second] = 1;
            if(mark[pp.second][pp.first]==1) return false;
        }
        return true;
    }
};

int main(){
    Solution * solution = new Solution();
    vector<pair<int, int> > prerequisites;
    //prerequisites.push_back(make_pair(1,0));
    //prerequisites.push_back(make_pair(1,2));
    solution->canFinish(1,prerequisites);
    return 0;
}
