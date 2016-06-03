#include<string>
#include<iostream>
using namespace std;
int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    string s,s1,s2;
    while(getline(cin,s)){
        s1=s;
        for(int i=0;i<s.length();i++)
            if(isalpha(s[i])) s[i]=tolower(s[i]);
        int t=-1;
        t=s.find("marshtomp");
        while(t!=-1){
            for(int i=t;i<t+9;i++)
            s[i]='#';
            t=s.find("marshtomp");
        }
        s2="";
        for(int i=0;i<s.length();i++){
            if(s[i]!='#') s2+=s1[i];
            else if(s[i]=='#'){
                s2+="fjxmlhx";
                i+=8;
            }
        }
        cout<<s2<<endl;
    }
    return 0;
}
