#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
int n;
struct Node
{
    int len, depth;
    vector<int> prev, next;
}node[MAXN];
queue<int> q;
int ans = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int id = 0;
        cin >> id >> node[i].len;
        while (cin >> id, id)
        {
            node[i].prev.emplace_back(id);
            node[id].next.emplace_back(i);
        }
        if (node[i].prev.size() == 0)
        {
            node[i].depth = 0; q.emplace(i);
        }
        else
        {
            node[i].depth = -1;
        }
    }

    while (q.size())
    {
        int now = q.front(), nowdep = node[now].depth + node[now].len;
        for (auto it : node[now].next)
        {
            if (node[it].depth == -1 || node[it].depth > nowdep)
            {
                node[it].depth = nowdep;
                q.emplace(it);
            }
        }
        q.pop();
    }

    for (int i = 0; i < n; i++)
    {
        if (ans < node[i].depth + node[i].len)
        {
            ans = node[i].depth + node[i].len;
        }
    }

    cout << ans << "\n";

    return 0;
}
