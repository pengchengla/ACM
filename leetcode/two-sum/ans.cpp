#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        int length = numbers.size();
        map<int,int> mp;
        int find;
        for(int i = 0; i < length; ++i){
            find=mp[target - numbers[i]];
            if( find ){
                res.push_back(find);
                res.push_back(i+1);
                break;
            }
            mp[numbers[i]] = i+1;
        }
        return res;
    }
};

int main(){
    return 0;
}
