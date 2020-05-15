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
    int _T; scanf("%d", &_T);
    while (_T--)
    {
        map<string, int> a;
        int n = read<int>();
        for (int i = 0;i < n; i++)
        {
            string s; cin >> s;
            a[s] ++;
        }

        for (auto p : a)
        {
            printf("%s %d\n", p.first.c_str(), p.second);
        }
    }
    return 0;
}