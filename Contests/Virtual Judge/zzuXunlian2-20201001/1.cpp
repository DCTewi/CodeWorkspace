#include <bits/stdc++.h>
using namespace std;

template <class T> T read()
{
    T x = 0;
    int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while ( isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w ? -x : x;
}

int main()
{
    int n = read<int>();
    map<string, int> a;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        a[s]++;
    }

    for (auto p : a)
    {
        if (p.second > n - p.second)
        {
            return 0 * puts(p.first.c_str());
        }
    }

    puts("NONE");

    return 0;
}
