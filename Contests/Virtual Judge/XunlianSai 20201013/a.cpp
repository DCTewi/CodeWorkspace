#include <bits/stdc++.h>
using namespace std;

template <class T> T read()
{
    T x = 0; int ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{
    int T = read<int>();
    while (T--)
    {
        int n = read<int>(), flag = 0;
        vector<int> a(n);
        map<int, int> times;
        map<int, vector<int>> plc;

        for (int i = 0; i < n; i++)
        {
            a[i] = read<int>();
            times[a[i]] ++;
            plc[a[i]].emplace_back(i);
            if (times[a[i]] >= 3)
            {
                flag = 1;
            }
        }

        if (!flag)
        {
            for (auto p : plc)
            {
                auto &v = p.second;
                for (int i = 1; i < v.size(); i++)
                {
                    if (v[i] - v[i - 1] > 1)
                    {
                        flag = 1; break;
                    }
                }

                if (flag) break;
            }
        }

        puts(flag ? "YES" : "NO");
    }
    return 0;
}
