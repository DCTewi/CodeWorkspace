#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5e4 + 5;

struct Job
{
    int index, time;
};

int main()
{
    ios::sync_with_stdio(0);

    int _T; cin >> _T;
    for (int T = 1; T <= _T; T++)
    {
        int n; cin >> n;
        vector<int> fa(n + 1, -1);
        vector<Job> job(n + 1, {-1, -1});

        for (int i = 1; i < n; i++)
        {
            int u, v; cin >> u >> v;
            fa[u] = v;
        }

        cout << "Case #" << T << ":\n";

        int m, cnt = 0; cin >> m;
        for (int i = 0; i < m; i++)
        {
            string opt; int x = 0, y = 0;
            cin >> opt >> x;
            if (opt == "C")
            {
                y = job[x].index;
                int nowtime = job[x].time;
                while (x != -1)
                {
                    if (job[x].time > nowtime)
                    {
                        y = job[x].index;
                        nowtime = job[x].time;
                    }
                    x = fa[x];
                }
                cout << y << "\n";
            }
            else
            {
                cin >> y;
                job[x].index = y;
                job[x].time = ++cnt;
            }
        }
    }
}

/**
1
5
4 3
3 2
1 3
5 2
5
C 3
T 2 1
C 3
T 3 2
C 3

*/