#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e2 + 5;
int n, m;
int path[MAXN], meth[MAXN], vis[MAXN];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        cin>>path[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin>>meth[i];
    }
    
    return 0;
}
