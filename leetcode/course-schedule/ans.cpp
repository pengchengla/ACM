/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：ans.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-14
*   描    述：
================================================================*/
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        if(numCourses==1) return true;
        map<int,set<int> > hmap;
        int size = prerequisites.size();
        for(int i=0;i<size;i++){
            pair<int,int> pp = prerequisites[i];
            if(hmap.find(pp.first)!=hmap.end()){
                hmap[pp.first].insert(pp.second);
            }else{
                set<int> tmp;
                tmp.insert(pp.second);
                hmap.insert(pair<int,set<int> >(pp.first,tmp));
            }
            if(hmap.find(pp.second)!=hmap.end()){
                if(hmap[pp.second].find(pp.first)!=hmap[pp.second].end()){
                    return false;
                }
            }
        }
        return true;
    }   
};


int main(){
    Solution * solution = new Solution();
    vector<pair<int, int> > prerequisites;
    prerequisites.push_back(make_pair(1,0));
    prerequisites.push_back(make_pair(1,0));
    cout<<solution->canFinish(2,prerequisites)<<endl;
    return 0;
}
