#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T> T read()
{
    T x = 0; int ch = getchar(), w = 0;
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w ? -x : x;
}

const int MAXN = 1e2 + 5;
int vis[MAXN];

int main()
{
    int n = read<int>(), m = read<int>();
    vector<string> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
        
        reverse(b[i].begin(), b[i].end());
    }

    string ans, sna;

    for (int i = 0; i < n; i++)
    {
        if (vis[i]) continue;
        int flag = 1;
        for (int j = n - 1; j >= 0 && flag; j--)
        {
            if (j == i) continue;
            if (!vis[j] && a[i] == b[j])
            {
                vis[j] = vis[i] = 1;
                ans += a[i];
                flag = 0;
            }
        }
    }

    int maxn = -1, maxlen = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && a[i] == b[i] && a[i].size() > maxlen)
        {
            maxlen = a[i].size();
            maxn = i;
            vis[i] = 1;
        }
    }

    int anslen = ans.size() * 2 + (maxn == -1? 0: a[maxn].size());

    printf("%d\n", anslen);
    printf("%s", ans.c_str());
    if (maxn != -1) printf("%s", a[maxn].c_str());
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        printf("%c", ans[i]);
    }

    return 0;
}