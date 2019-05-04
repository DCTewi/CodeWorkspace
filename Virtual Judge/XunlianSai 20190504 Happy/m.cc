#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

vector<int> sto[MAXN];
int path[MAXN];

int main()
{
    ios::sync_with_stdio(0);

    int n; cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> path[i];
        sto[path[i]].push_back(i);
        //cout << sto[path[i]].size()<<"-"<<path[i]<<", ";
    }

    int ans = n - 1;
    for (int i = 1; i <= n; i++)
    {
        if (sto[path[i]].size() == 0) continue;

        int now = i - 1, siz = sto[path[i]].size() - 1;
        now += siz + n - sto[path[i]][siz];
        //cout << siz << " " << sto[path[i]][siz] << " " << now << "\n";
        ans = min(ans, now);
    }

    cout << ans << "\n";

    return 0;
}