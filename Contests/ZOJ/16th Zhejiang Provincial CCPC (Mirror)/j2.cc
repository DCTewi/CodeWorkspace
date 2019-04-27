#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct P
{
    set<int> fs;
} ps[1000006];
int n, m;
set<int> s;
priority_queue<int, vector<int>, greater<int>> pq;
queue<int> q;

void cpq()
{
    priority_queue<int, vector<int>, greater<int>> nq;
    swap(nq, pq);
}
void cq()
{
    queue<int> nq;
    swap(nq, q);
}

void ofr(int inx)
{
    for (auto it : ps[inx].fs)
    {
        if (!s.count(it))
        {
            pq.emplace(it);
            s.insert(it);
            //cout << '<' << inx <<  '[' << it << ']';
            ofr(it);
        }
    }
}

void of(int inx)
{
    cpq();
    ofr(inx);
    while (!pq.empty())
    {
        q.emplace(pq.top());
        pq.pop();
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            ps[i].fs.clear();
        for (int i = 0; i < m; ++i)
        {
            int a, b;
            cin >> a >> b;
            ps[a].fs.emplace(b);
            ps[b].fs.emplace(a);
        }
        s.clear();
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (!s.count(i))
            {
                s.insert(i);
                q.emplace(i);
                ++ans;
                of(i);
            }
        }
        cout << ans << '\n';
        while (q.size() > 1)
            cout << q.front() << ' ', q.pop();
        cout << q.front() << '\n';
        q.pop();
    }
}