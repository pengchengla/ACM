#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> s;
        int diff = 1;
        vector<string> temp;
        while(1)
        {
            if(preorder.find(',') == std::string::npos)
            {
                temp.push_back(preorder);
                break;
            }
            else
            {
                int position = preorder.find(',');
                temp.push_back(preorder.substr(0,position));
                preorder = preorder.substr(position+1);
            }
        }
		for(vector<string>::iterator it = temp.begin();it!=temp.end();it++)
        {
			string c = *it;
            if(--diff < 0)
                return false;
            if(c != "#")
                diff+=2;
        }
        return diff == 0;
    }
};

int main(){
	Solution * solution = new Solution();
	if(solution->isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#")==true) cout<<"true"<<endl;
	else cout<<"false"<<endl;
	return 0;
}
