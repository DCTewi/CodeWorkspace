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

int main()
{
    int _T = read<int>();
    while (_T--)
    {
        int n = read<int>(), maxn = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            a[i] = read<int>();
            maxn = max(maxn, a[i]);
        }
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            int now = maxn - a[i];
            if (now % 2)
            {
                puts("NO"); flag = 1; break;
            } 
        }
        if (!flag) puts("YES");
    }
    return 0;
}
