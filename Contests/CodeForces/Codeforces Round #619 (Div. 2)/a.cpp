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
    int T = read<int>();
    while (T--)
    {
        string a, b, c; cin >> a >> b >> c;
        int f = 0;
        
        for (int i = 0; i < c.size(); i++)
        {
            if (a[i] == b[i] && c[i] != a[i])
            {
                puts("NO"); f = 1; break;
            }
            if (a[i] != b[i])
            {
                if (c[i] != a[i] && c[i] != b[i])
                {
                    puts("NO"); f=1; break;
                }
            }
        }
        if (f == 0) puts("YES");
    }
    return 0;
}