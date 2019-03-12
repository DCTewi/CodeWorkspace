#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        map<long long,int> mp;
        for(int i=1;i<=n;i++)
        {
            long long tmp;
            scanf("%lld",&tmp);
            mp[tmp]++;
        }
        for(int i=1;i<=m;i++)
        {
            long long tmp;
            scanf("%lld",&tmp);
            mp[tmp]--;
        }
        long long tmp=-1;
        for(auto j=mp.begin();j!=mp.end();j++)
        {
            if(j->first==1) continue;
            if(j->second ==0) continue;
            if(j->second ==1)
            {
                if(tmp==-1)
                    tmp=j->first;
                else{
                        tmp=-1;
                    break;
                }
            }
            if(j->second>1)
            {
                tmp=-1;
                break;
            }
        }
            for(int i=2;1ll*i*1ll*i<=tmp;i++)
            {
                if(tmp%i==0)
                {
                    tmp=-1;
                    break;
                }
            }
            if(tmp==-1)
            {
                puts("NO");
            }
            else
            {
                puts("YES");
            }
    }
}
