//H
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
const int INF = 1 << 20;
int n, h, l;

struct Mov
{
    int ind, hor = INF;

    bool operator< (const Mov &o) const
    {
        if (this->hor == o.hor) return this->ind < o.ind;
        return this->hor > o.hor;
    }
}mov[MAXN];
vector<int> nex[MAXN];
int horr[MAXN], vis[MAXN];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>n>>h>>l;
    for (int i = 0; i < n; i++)
    {
        mov[i].ind = i;
    }
    for (int i = 0; i < h; i++)
    {
        cin>>horr[i];
    }
    for (int i = 0; i < l; i++)
    {
        int a, b; cin>>a>>b;
        nex[a].push_back(b);
        nex[b].push_back(a);
    }
    
    for (int i = 0; i < h; i++)
    {
        memset(vis, 0, sizeof(vis));
        queue<int> q; mov[horr[i]].hor = 0;
        q.push(horr[i]); vis[horr[i]] = 1;
        while (q.size())
        {
            int u = q.front();
            for (auto &v : nex[u])
            {
                if (mov[v].hor > mov[u].hor + 1)
                {
                    mov[v].hor = mov[u].hor + 1;
                    if (!vis[v])
                    {
                        q.push(v);
                        vis[v] = 1;
                    }
                }
            }
            q.pop(); vis[u] = 0;
        }
    }
    
    sort(mov, mov + n, [](Mov a, Mov b)->bool{return a < b;});
    
    cout<<mov[0].ind<<endl;
    
    return 0;
}
