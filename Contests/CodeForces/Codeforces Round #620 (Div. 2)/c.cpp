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
        int n = read<int>(), inittmp = read<int>();
        vector<tuple<int, int, int>> a(n);

        for (int i = 0; i < n; i++)
        {
            int t = read<int>(), lw = read<int>(), hi = read<int>();
            a[i] = make_tuple(t, lw, hi);
        }

        int low = inittmp, hig = inittmp, t = 0;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            int now = get<0>(a[i]);
            low -= now - t;
            hig += now - t;
            t = now;

            // printf(" high = %d, low = %d  ", hig, low);

            if (get<1>(a[i]) > hig || get<2>(a[i]) < low)
            {
                flag = 1; break;
            }

            if (get<2>(a[i]) > hig) // a[i]'s top is higer
            {
                if (get<1>(a[i]) < low) // now belong to a[i] 
                {
                    continue;
                }
                else
                {
                    low = get<1>(a[i]);
                }
            }
            else
            {
                if (get<1>(a[i]) > low) // a[i] belong to now
                {
                    low = get<1>(a[i]); hig = get<2>(a[i]);
                }
                else
                {
                    hig = get<2>(a[i]);
                }
            }

            // printf(" => high = %d, low = %d\n", hig, low);
        }

        if (flag) puts("NO");
        else puts("YES");

    }
    return 0;
}
