#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main()
{
    //freopen("file","r",stdin);
    char str[260];
    memset(str,'\0',sizeof(char)*260);
    while(gets(str)&&str[0]!='#')
    {
        int sum=0;
        int len = strlen(str);
        for(int i=0;i<len;++i)
        {
            int temp=0;
            if(str[i]!=' ') temp = str[i]-'A'+1;
            sum += (i+1)*temp;
        }
        cout<<sum<<endl;
        memset(str,'\0',sizeof(char)*256);
    }
    return 0;
}
