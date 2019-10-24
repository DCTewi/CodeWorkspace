#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read()
{
    ll x = 0; char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

const int MAXN = 1e5 + 5;

struct Edge
{
    ll to;
    ll next;
} edge[MAXN << 2] ;
int head[MAXN], cnt = 0;
void addedge(int u, int v)
{
     cnt++;
     edge[cnt].to = v;
     edge[cnt].next = head[u];
     head[u] = cnt;
}

int main()
{
    ll T = read();
    while (T--)
    {
        cnt = 0;
        ll n = read();
        vector<int> zh(n + 1), ya(n + 1);
        for (int i = 1; i <= n; i++) zh[i] = read();
        for (int i = 1; i <= n; i++) ya[i] = read();
    }
    return 0;
}

