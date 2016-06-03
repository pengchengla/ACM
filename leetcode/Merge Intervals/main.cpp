#include <iostream>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution 
{
private:
    bool cmp(const Interval & fir,const Interval & sec)
    {
        if(fir.start != sec.start)
            return fir.start < sec.start;
        else
            return fir.end < sec.end;
    }
public:
    vector<Interval> merge(vector<Interval> &intervals) 
    {
        sort(intervals.begin(),intervals.end(),cmp);
        int size = intervals.size();
        int i = 1;
        vector<Interval> v_tmp;
        Interval d_tmp;
        while(i<size)
        {
        }
    }
};

int main()
{
    return 0;
}
