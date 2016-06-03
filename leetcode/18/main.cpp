#include <iostream>
using namespace std;
//My idea is to sort num first, then build a hashtable with the key as the sum of the pair and the value as a vector storing all pairs of index of num that having the same sum. In this way, all elements stored in hashtable has a order that duplicate pairs are neighbors. Therefore scanning the vector in the hashtable we only put non duplicate elements into the final answer vvi.
class Solution
{ //using hashtable, avg O(n^2)
public:
    vector<vector<int> > fourSum(vector<int> &num, int target)
    {
        vector<vector<int> > vvi;
        int n = num.size();
        if(n < 4) return  vvi;

        sort(num.begin(), num.end());        
        unordered_map<int, vector<pair<int, int>> > mp;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                mp[num[i]+num[j]].push_back(make_pair(i,j));
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(i>0 && num[i] == num[i-1]) 
                continue;
            for(int j = i + 1; j < n; j++)
            {
                if(j > i + 1 && num[j] == num[j-1]) 
                    continue;
                int res = target - num[i] - num[j];
                if(mp.count(res))
                {
                    for(auto it = mp[res].begin(); it != mp[res].end(); it++)
                    {
                        int k = (*it).first, l = (*it).second;
                        if(k > j)
                        {//k>j make sure that the second pair has bigger values than the first pair.
                            if(!vvi.empty() && num[i]==vvi.back()[0] && num[j]==vvi.back()[1]
                            && num[k]==vvi.back()[2] && num[l] == vvi.back()[3])
                            {
                                continue; 
                        //if the obtained 4 elements are the same as previous one continue to next
                            }
                            vector<int> vi={num[i], num[j], num[k], num[l]};
                            vvi.push_back(vi);
                        } // if k>j
                    }//for it
                }//if
            }// forj
        }//for i
        return vvi;
    }
};
int main()
{
    return 0;
}
