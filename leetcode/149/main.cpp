#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Point 
{
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution 
{
private:
    map<int,vector<Point> > h_map;
    int ans;
public:
    static bool cmp(const Point & a, const Point & b)
    {
        return a.x<b.x;
    }
public:
    int maxPoints(vector<Point> &points) 
    {
        sort(points.begin(),points.end(),cmp);
        if(points.size()<=2) return 1;
        int i=0,j=0,k=0;
        for(;i<points.size();i++)
        {
            for(j=i+1;j<points.size();j++)
            {
                int d_x = points[i].x-points[j].x;
                int d_y = points[i].y-points[j].y;
                for(k=j+1;k<points.size();k++)
                {
                    int t_x = points[i].x-points[k].x;
                    int t_y = points[i].y-points[k].y;
                    if(t_x==d_x && t_y==d_y)
                    {
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution * solution = new Solution();
    vector<Point> points;
    points.push_back(Point(4,2));
    points.push_back(Point(3,4));
    points.push_back(Point(1,6));
    points.push_back(Point(6,5));
    points.push_back(Point(2,4));
    cout<<solution->maxPoints(points)<<endl;
    return 0;
}
