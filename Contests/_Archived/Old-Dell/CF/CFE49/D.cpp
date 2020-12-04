#include <bits/stdc++.h>
using namespace std;
const int MAXN = 
int a[200002],b[200002],c[200002],d[200002],e[200002],p,x,y;

void dfs(int v,int g,int f)
{
    d[v]=g;
    e[f]=v;
    if(!d[a[v]]){dfs(a[v],g,f+1);return;}
    if(d[a[v]]==g)
    {
        y=f;p=1;
        for(int i=1;i<f;i++)if(a[v]==e[i]){x=i;break;}
        if(!x)x=f;
    }
}
int main()
{
    int n,t=1;
    long long gg=0;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++)cin>>a[i];

    for(int i=1;i<=n;i++)
    {
        if(d[i]||d[a[i]]){d[i]=1;continue;}
        if(a[i]==i)
        {
            d[i]=1,gg+=b[i];
            continue;
        }
        p=x=y=0;
        dfs(i,++t,1);
        int g=1e9;
        if(p)
        {
            for(int j=x;j<=y;j++)
            {
                g=std::min(g,b[e[j]]);
            }
            gg+=g;
        }
    }
   cout<<gg<<endl;
}