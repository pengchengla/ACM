#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int> > ans;
    vector<int> path;
    path.push_back(1);
    path.push_back(2);
    path.push_back(3);
    ans.push_back(path);

    path.clear();
    path.push_back(2);
    path.push_back(3);
    path.push_back(4);
    ans.push_back(path);

    path.clear();
    path.push_back(1);
    path.push_back(2);
    path.push_back(3);
    for(vector<vector<int> >::iterator iter = ans.begin();iter!=ans.end();iter++)
    {
        if(*iter == path)
        {
            for(vector<int>::iterator i = (*iter).begin();i!=(*iter).end();i++)
            {
                cout<<*i<<" ";
            }
            cout<<endl;
            cout<<"equal"<<endl;
        }
        else
        {
            cout<<"unequal"<<endl;
        }
    }
    return 0;
}
