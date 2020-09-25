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

typedef pair<int, bool> Time;

int main()
{
    int n = read<int>();
    vector<Time> v;

    for (int i = 0; i < n; i++)
    {
        v.emplace_back(make_pair(read<int>(), 1));
        v.emplace_back(make_pair(read<int>(), 0));
    }

    int ans = 0, now = 0;
    sort(v.begin(), v.end(), [](const Time &a, const Time &b)
    {
        return a.first < b.first;
    });

    for (int i = 0; i < (int)v.size(); i++)
    {
        now += v[i].second ? 1 : -1;

        if (i == v.size() - 1 || v[i].first < v[i + 1].first)
        {
            if (now > ans)
            {
                ans = now;
            }
        }
    }

    cout << ans;
    
    return 0;
}