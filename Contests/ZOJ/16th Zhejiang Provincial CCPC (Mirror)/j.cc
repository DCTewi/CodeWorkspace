#include <bits/stdc++.h>
using namespace std;

struct P
{
    int id;
    set<int> fri;
    bool operator<(P p2)
    {
        if (fri.size() != p2.fri.size())
            return fri.size() > p2.fri.size();
        else
            return id < p2.id;
    }
} ps[1000005];
set<int> s;
queue<int> qa;

void clearq() {
    queue<int> nq;
    swap(qa,nq);
}


void outfri(int inx) {
    for (auto it:ps[inx].fri) {
        if (!s.count(it)) {
            s.emplace(it);
            qa.emplace(it);
            outfri(it);
        }
    }
}


int chkfri(int inx) {
    for (auto it : ps[inx].fri)
    {
        if (s.count(it))
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    //ios::sync_with_stdio(0);
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            ps[i].fri.clear(), ps[i].id = i;
        int a, b;
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b;
            ps[a].fri.emplace(b);
            ps[b].fri.emplace(a);
        }
        sort(ps + 1, ps + n + 1);
        int ans = 0;
        s.clear();
        for (int i = 1; i <= n; ++i)
        {
            if (!s.count(i)) {
                s.insert(ps[i].id);
                qa.emplace(ps[i].id);
                ans++;
                outfri(i);
            }
        }
        cout << ans << '\n';
        while(qa.size()>1) cout <<qa.front() << ' ', qa.pop();
        cout << qa.front() << '\n';qa.pop();

    }
    return 0;
}