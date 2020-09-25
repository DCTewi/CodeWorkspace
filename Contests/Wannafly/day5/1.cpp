#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T> T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w? -x: x;
}

const int MAXN = 301 + 5;

int rec[MAXN][MAXN];
int dp[MAXN][MAXN][10][10];
int dp1[MAXN][MAXN][10][10];
//dp-->max
//dp1-->min
int n,m;
inline int maxm(int a,int b,int c,int d){
    if(a<b)a=b; if(a<c)a=c; if(a<d)a=d;
    return a;
}
inline int minm(int a,int b,int c,int d){
    if(b<a)a=b; if(c<a)a=c; if(d<a)a=d;
    return a;
}
void st()
{
    for(int k=0;(1<<k)<=n;k++)
        for(int l=0;(1<<l)<=m;l++)
            for(int i=1;i+(1<<k)-1<=n;i++)
                for(int j=1;j+(1<<l)-1<=m;j++)
                {
                    if(!k&&!l){
                        dp1[i][j][k][l]=dp[i][j][k][l]=rec[i][j];
                    }
                    else if(k==0){
                        dp[i][j][k][l]=max(dp[i][j][k][l-1],dp[i][j+(1<<(l-1))][k][l-1]);
                        dp1[i][j][k][l]=min(dp1[i][j][k][l-1],dp1[i][j+(1<<(l-1))][k][l-1]);
                        //printf("%d %d\n",dp[i][j][k][l-1],dp[i][j+(1<<(l-1))][k][l-1]);
                    }
                    else if(l==0){
                        dp[i][j][k][l]=max(dp[i][j][k-1][l],dp[i+(1<<(k-1))][j][k-1][l]);
                        dp1[i][j][k][l]=min(dp1[i][j][k-1][l],dp1[i+(1<<(k-1))][j][k-1][l]);
                        //printf("%d %d\n",dp[i][j][k-1][l],dp[i+(1<<(k-1))][j][k-1][l]);
                    }
                    else {
                        dp[i][j][k][l]=maxm(dp[i][j][k-1][l-1],dp[i+(1<<(k-1))][j][k-1][l-1],
                                            dp[i][j+(1<<(l-1))][k-1][l-1],dp[i+(1<<(k-1))][j+(1<<(l-1))][k-1][l-1]);
                        dp1[i][j][k][l]=minm(dp1[i][j][k-1][l-1],dp1[i+(1<<(k-1))][j][k-1][l-1],
                                             dp1[i][j+(1<<(l-1))][k-1][l-1],dp1[i+(1<<(k-1))][j+(1<<(l-1))][k-1][l-1]);
                        //printf("%d %d %d %d\n",dp[i][j][k-1][l-1],dp[i+(1<<(k-1))][j][k-1][l-1],
                        //dp[i][j+(1<<(l-1))][k-1][l-1],dp[i+(1<<(k-1))][j+(1<<(l-1))][k-1][l-1]);
                    }
                    //printf("i:%d j:%d k:%d l:%d dp:%d\n",i,j,k,l,dp[i][j][k][l]);
                    //system("pause");
                }
}
int rmq2dmax(int x,int y,int x1,int y1){
    //if(x==x1&&y==y1)return dp[x][y][0][0];
    int k=log(x1-x+1)/log(2);
    int l=log(y1-y+1)/log(2);
    return maxm(dp[x][y][k][l],dp[x1-(1<<k)+1][y][k][l],
                dp[x][y1-(1<<l)+1][k][l],dp[x1-(1<<k)+1][y1-(1<<l)+1][k][l]);
}

int main()
{
    return 0;
}