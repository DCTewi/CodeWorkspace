#include<bits/stdc++.h>
using namespace std;
char ans[110][110];
typedef long long ll;
ll n,m,k;
int main()
{
    //freopen("kotlin.in","r",stdin);
    //freopen("kotlin.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            ans[i][j]='*';
    }
    int cnt=0,hs=0x3f3f3f3f;
    bool flag=0;

    for(int i=1;i<=n;i+=2)
    {
        if(i==1)
            for(int j=1;j<=m;j+=2)
            {
                ans[i][j]='.';
                cnt++;
                if(k%cnt==0)
                {
                    int tmp = (m+1)/2;
                    if(tmp*cnt>=k)
                    {
                        flag=1;
                        hs=k/cnt;
                        break;
                    }
                }
            }
        else  if(hs>=i/2)
            for(int j=1;j<=m;j++)
            {
                ans[i][j]=ans[1][j];
            }
    }
    if(flag==0)
        return cout<<"Impossible"<<endl,0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cout<<ans[i][j];
        cout<<endl;
    }

}
