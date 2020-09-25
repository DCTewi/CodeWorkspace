#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

vector<int> sto[MAXN];
int path[MAXN], f[MAXN];
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> path[i];
        sto[path[i]].emplace_back(i);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < sto[path[i]].size(); j++)
        {
            if (sto[path[i]][j] > i) break;
            if (sto[path[i]][j] == i)
            {
                f[i] = j;
                if (f[i])
                {
                    f[i] += sto[path[i]][0];
                }
                break;
            }
        }

        if (sto[path[i]].size() == 1)
        {
            f[i] = i;
        }

        for (int j = 1; j < i; j++)
        {
            f[i] = min(f[i], f[j] + i - j);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << f[i] << " ";
    }
    cout << "\n";

    int ans = n - 1;
    for (int i = 1; i <= n; i++)
    {
        if (sto[path[i]].size() == 0)
        {
            ans = min(ans, f[i] + n - i);
            cout << ans << "\n";
        }
        else
        {
            int siz = sto[path[i]].size() - 1;
            ans = min(ans, f[i] + n - sto[path[i]][siz]);
            cout << ans << "\n";
        }
    }

    cout << ans << "\n";

    return 0;
}