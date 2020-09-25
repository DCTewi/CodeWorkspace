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
    int n = read<int>(), k = read<int>();
    vector<int> a(k + 1);
    for (int i = 0; i <= k; i++)
    {
        a[i] = read<int>();
    }

    int ans = 0;
    for (int i = 0; i <= k; i++)
    {
        if (a[i] > n)
        {
            return 0 * puts("No Solution!");
        }
    }
    for (int i = 0, now = 0; i <= k; i++)
    {
        now += a[i];
        if (now > n)
        {
            ans++;
            now = a[i];
        }
    }
    return 0 * printf("%d\n", ans);
}