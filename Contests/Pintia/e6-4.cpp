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
    int n = read<int>(), len = read<int>();

    vector<int> l(n);
    for (int i = 0; i < n; i++)
    {
        l[i] = read<int>();
    }
    sort(l.begin(), l.end());

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (len < l[i]) break;

        len -= l[i]; ans++;
    }

    printf("%d\n", ans);
    return 0;
}