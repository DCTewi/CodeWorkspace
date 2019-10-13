#include<bits/stdc++.h>
using namespace std;
const int maxn =505;
int w,h;
int m[maxn][maxn];
struct node{
    int x,y,val;
    bool operator<(const node &b) const
    {
        return val>b.val;
    }
};
const int dx[10]={0,0,-1,-1,-1,1,1,1};
const int dy[10]={1,-1,0,1,-1,0,1,-1};
bool flag[505][505];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>w>>h;

    for(int i=1;i<=w;i++)
    {
        for(int j=1;j<=h;j++){
            cin>>m[i][j];
            if(m[i][j]>=0){m[i][j]=0;flag[i][j]=1;}
        }
    }

    int x,y;
    cin>>x>>y;
    priority_queue<node>que;
    long long sum=0;
    if(m[x][y]>=0)return cout<<0<<endl,0;
    que.push((node){x,y,m[x][y]});
    flag[x][y]=1;sum+=m[x][y];
    while(!que.empty())
    {
        node now = que.top();
        que.pop();
        cout<<now.x<<' '<<now.y<<' '<<now.val<<endl;
        int val = now.val;
        for(int i=0;i<8;i++)
        {
            int x = now.x+dx[i];
            int y = now.y+dy[i];
            if(m[x][y]<0&&!flag[x][y])
            {
                flag[x][y]=1;
                int tmp = max(val,m[x][y]);
                que.push((node){x,y,tmp});
                sum+=tmp;

            }
        }
    }
    cout<<-sum<<endl;
    return 0;
}
