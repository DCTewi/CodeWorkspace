#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
char ans[110][110];
int main()
{
    freopen("kotlin.in", "r", stdin);
    freopen("kotlin.out", "w", stdout);
    cin>>n>>m>>k;
    int cnt = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ans[i][j]='#';
    bool flag=0;
    int hs;
    for(int i=1;i<=n;i+=2)
    {
        if(!flag&&i==1)
            for(int j=1;j<=m;j+=2)
            {
                ans[i][j]='.';
                cnt++;
                if(k%cnt==0&&k/cnt<=(n+1)/2)
                {
                    flag=1;
                    hs = k/cnt;
                    break;
                }
            }
        else if(hs>=i/2)
        {
            for(int j=1;j<=m;j++)
                ans[i][j]=ans[1][j];
        }
    }
    if(!flag)   return 0*puts("Impossible");
    else
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                cout<<ans[i][j];
            cout<<endl;
        }
    }
    return 0;
}
