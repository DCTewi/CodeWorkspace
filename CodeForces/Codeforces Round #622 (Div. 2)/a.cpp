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

const int x[] = {0, 0, 1, 0, 1, 1, 1};
const int y[] = {0, 1, 0, 1, 0, 1, 1};
const int z[] = {1, 0, 0, 1, 1, 0, 1};

int main()
{
    int T = read<int>();
    while (T--)
    {
        vector<int> v(3);
        for (int i = 0; i < 3; i++)
        {
            v[i] = read<int>();
        }
        sort(v.begin(), v.end());

        int &a = v[0], &b = v[1], &c = v[2];
        int ans = 0;

        for (int i = 0; i < 7; i++)
        {
            // cout << a << b << c << "\n";
            if (a >= x[i] && b >= y[i] && c >= z[i])
            {
                a -= x[i];
                b -= y[i];
                c -= z[i];
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
