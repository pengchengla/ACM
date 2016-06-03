#include<string>
#include<iostream>
using namespace std;

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    string s,s1,s2;
	string target="fjxmlhx";
    while(getline(cin,s)){
        for(int i=0;i<s.length();i++)
            if(isalpha(s[i])) s[i]=tolower(s[i]);
        int t=-1;
        t=s.find("marshtomp");
        while(t!=-1)
        {
			int k = 0;
            for(int i=t;i<t+9;i++)
				s[i]=target[k++];
            t=s.find("marshtomp");
        }
		cout<<s<<endl;
    }
    return 0;
}
