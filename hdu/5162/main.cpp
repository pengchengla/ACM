#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node
{
    int id;
    int dis;
    int rank;
    //node(int i,int d):id=i,dis=d{}
    node(int i,int d)
    {
        id = i;
        dis = d;
    }
};

bool cmp(const node & fir, const node & sec)
{
    return fir.dis>sec.dis;
}

bool cmp1(const node & fir, const node & sec)
{
    return fir.id<sec.id;
}

int main()
{
    //freopen("file","r",stdin);
    int tc = 0;
    cin>>tc;
    vector<node> ans;
    for(int t=1;t<=tc;t++)
    {
        ans.clear();
        int n=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int m_dis=INT_MIN;
            int dis=0;
            for(int k=1;k<=3;k++)
            {
                cin>>dis;
                if(dis>m_dis) m_dis = dis;
            }
            struct node tmp = node(i,m_dis);
            ans.push_back(tmp);
        }
        sort(ans.begin(),ans.end(),cmp);
        for(int i=0;i<n;i++)
        {
            ans[i].rank = i+1;
        }
        sort(ans.begin(),ans.end(),cmp1);
        for(int i=0;i<n;i++)
        {
            cout<<ans[i].rank;
            if(i!=n-1) cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
