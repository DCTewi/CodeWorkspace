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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = read<int>();
    }

    sort(a.begin(), a.end());

    printf("%d", a[k - 1]);

    return 0;
}