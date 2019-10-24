#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e2 + 5;

struct Query
{
    char dir;
    int arr_time, wait_lim;

    Query(char dir = 0, int a = 0, int w = 0)
    {
        this->dir = dir; this->arr_time = a; this->wait_lim = w;
    }

    bool operator< (const Query &o) const
    {
        if (this->arr_time == o.arr_time) return this->wait_lim < o.wait_lim;
        return this->arr_time < o.arr_time;
    }
}query[MAXN];

int t, n;
int ans = 0;
int vis[MAXN];

void dfs(int pid)
{
    if (pid == n)
    {
        return ;
    }


    
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>t>>n;

    for (int i = 0; i < n; i++)
    {
        char ch; int a, r;
        cin>>ch>>a>>r;
        query[i] = Query(ch, a, r);
    }

    sort(qv, qv + n);

    //dfs(0);

    cout<<ans<<endl;

    return 0;
}