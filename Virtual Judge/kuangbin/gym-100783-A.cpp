#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 20;
int n;
vector<string> s;
map<char, int> chs;
map<int, char> ind;
set<char> used;
int vis[MAXN];
ll ans = 0;

inline ll toll(string s)
{
    if (chs[s[0]] == 0) return -1;

    ll res = 0;
    for (char ch : s)
    {
        res = (res << 3) + (res << 1) + (chs[ch]);
    }
    return res;
}

int check()
{
    ll sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ll now (toll(s[i]));
        if (now == -1) return 0;

        sum += now;
    }

    return (sum == toll(s[n - 1]));
}

ll dfs(int cnt)
{
    ll res = 0;
    if (cnt >= (int)used.size()) return check();

    for (int i = 0; i <= 9; i++)
    {
        if (vis[i]) continue;

        vis[i] = 1;
        chs[ind[cnt]] = i;
        res += dfs(cnt + 1);

        vis[i] = 0;
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    s = vector<string>(n);

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        for (char ch : s[i])
        {
            if (!used.count(ch))
            {
                used.insert(ch);
                ind[ind.size()] = ch;
            }
        }
    }

    printf("%lld\n", dfs(0));

    return 0;
}
