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
    int n = read<int>(), m = read<int>();
    set<int> a, b, intr, uion;

    for (int i = 0; i < n; i++) a.insert(read<int>());
    for (int i = 0; i < m; i++) b.insert(read<int>());

    set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(intr, intr.begin()));
    set_union       (a.begin(), a.end(), b.begin(), b.end(), inserter(uion, uion.begin()));

    cout << intr.size() << (intr.size() > 0 ? " " : "");
    for (auto it = intr.begin(); it != intr.end();)
    {
        printf("%d", *it);
        it++;
        if (it != intr.end()) printf(" ");
    }
    puts("");

    cout << uion.size() << (uion.size() > 0 ? " " : "");
    for (auto it = uion.begin(); it != uion.end();)
    {
        printf("%d", *it);
        it++;
        if (it != uion.end()) printf(" ");
    }

    return 0;
}
