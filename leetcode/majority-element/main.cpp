#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) 
    {
        sort(num.begin(),num.end());
        int mid = num.size()/2;
        return num[mid];
    }
};

int main()
{
    return 0;
}
