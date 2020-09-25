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
    set<int> s;

    int n = read<int>();
    for (int i = 0; i < n; i++)
    {
        s.insert(read<int>());
    }
    int m = read<int>();
    for (int i = 0; i < m; i++)
    {
        puts(s.count(read<int>()) ? "Yes" : "No");
    }

    return 0;
}