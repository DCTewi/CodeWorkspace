#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;

template <typename T> T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return w? -x: x;
}

int main()
{
    n = read<int>(), k = read<int>();
    vector<int> a(n);
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        a[i] = read<int>();
        s.insert(a[i]);
    }

    if ()

    return 0;
}
