#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> v;
int main()
{
	freopen("in.txt","r",stdin);
	string s;
    while(cin>>s && s!="#"){
        v.push_back(s);
    }
    while(cin>>s && s!="#"){
        cout<<s;
        int p = 0;
        int it = 0;
        for(int i = 0;i < v.size(); i++)
            if(v[i] == s) it = 1;
        if(it){
            cout<<" is correct"<<endl;
            continue;
        }
        cout<<": ";
        for(int i = 0; i < v.size(); i++){
            int minLen = v[i].length() - s.length();
            if(minLen < -1 || minLen > 1) continue;
            int di = 0;
            if(minLen == 0){
                for(int t = 0; t < s.length();t++)
                   if(v[i][t] != s[t])  di++;
               if(di == 1)  cout<<v[i]<<" ";
            }
            if(minLen == -1){
                int j = 0;
                for(int t = 0; t < s.size(); t++){
                    if(s[t] == v[i][j]){
                        j++;
                    }
                }
                if(j == v[i].size())
                    cout<<v[i]<<" ";
            }
            if(minLen == 1){
                int j = 0;
                for(int t = 0; t < v[i].size(); t++){
                    if(v[i][t] == s[j]){
                        j++;
                    }
                }
                if(j == s.size())
                    cout<<v[i]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
