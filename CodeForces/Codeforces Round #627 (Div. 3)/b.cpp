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

const int MAXN = 5e3 + 5;
int a[MAXN];
map<int, vector<int>> p;

int main()
{
    int _T = read<int>();
    while (_T--)
    {
        p.clear();
        memset(a, 0, sizeof a);
        int n = read<int>();

        for (int i = 0; i < n; i++)
        {
            a[i] = read<int>();
            p[a[i]].emplace_back(i);
        }

        int flag = 0;
        for (auto iv : p)
        {
            auto &v = iv.second;
            if (v.size() >= 2)
            {
                if (v[v.size() - 1] - v[0] > 1)
                {
                    flag = 1;
                    puts("YES");
                    break;
                }
            }
        }
        if (!flag) puts("NO");
    }

    return 0;
}
