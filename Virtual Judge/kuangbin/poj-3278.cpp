#include <queue>
#include <cstdio>
#include <vector>
#include <cctype>
#include <iostream>
#include <memory.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int ans[MAXN];

int main()
{
    int n, k; cin >> n >> k;
    queue<int> q;
    q.push(n);
    while (q.size())
    {
        int u = q.front(); q.pop();
        if (u == k)
        {
            cout << ans[k] << "\n"; return 0;
        }

        vector<int> x({u * 2, u + 1, u - 1});
        for (int i : x)
        {
            if (i < MAXN && i >= 0 && !ans[i])
            {
                q.push(i); ans[i] = ans[u] + 1;
            }
        }
    }

    return 0;
}
