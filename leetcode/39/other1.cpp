#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
   vector<vector<int> > combinationSum(vector<int> &candidates, int target) 
   {
     // Start typing your C/C++ solution below  
     // DO NOT write int main() function  
     vector<vector<int> > result;  
     vector<int> solution;  
     int sum=0;  
     std::sort(candidates.begin(), candidates.end());  
     GetCombinations(candidates,sum, 0, target, solution, result);  
     return result;  
    }  

    void GetCombinations(  
      vector<int>& candidates,  
      int& sum,  
      int level,  
      int target,  
      vector<int>& solution,  
      vector<vector<int> >& result)  
    {  
      if(sum > target) return;  
      if(sum == target)  
      {  
        result.push_back(solution);  
        return;  
      }  
      for(int i =level; i< candidates.size(); i++)  
      {  
        sum+=candidates[i];  
        solution.push_back(candidates[i]);  
        GetCombinations(candidates, sum, i, target, solution, result);  
        solution.pop_back();  
        sum-=candidates[i];        
      }  
    }  
};
int main()
{
    vector<int> candidates;
    candidates.push_back(2);
    candidates.push_back(3);
    candidates.push_back(6);
    candidates.push_back(7);
    Solution * solution = new Solution();
    vector<vector<int> > temp = solution->combinationSum(candidates,7);
    for(int i=0;i<temp.size();i++)
    {
        for(int j=0;j<temp[i].size();j++)
        {
            cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
