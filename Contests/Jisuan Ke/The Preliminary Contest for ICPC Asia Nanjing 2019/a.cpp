#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5;
const int MAXM = 1e5 + 5;

int n;

template <class T>
T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w? -x: x;
}

ll getxy(ll x, ll y)
{
    x = n - x + 1;
    y = n - y + 1;
    if(n==1) return 1;
    int left,right,top,bottom;
    left = y - 1;
    right = n - y;
    top = x - 1;
    bottom = n - x;
    int dist = min(min(min(left,right),top),bottom);
    ll anchor = n*n - (n-2*dist)*(n-2*dist);
    ll ans = anchor;
    int inner_n = n -2*dist;
    int inner_x = x - dist;
    int inner_y = y - dist;
    if(x - 1==dist || n - y== dist)
        return ans + inner_x + inner_y -1;
    return ans + 4*inner_n - inner_x - inner_y - 1;
}

struct Db
{
    vector<pair<int, int>> dat;

    void build()
    {
        sort(dat.begin(), dat.end());
    }

    void add(int x, int y)
    {
        dat.emplace_back(make_pair(x, y));
    }

    ll query(int x1, int y1, int x2, int y2)
    {
        int res = 0;
        auto l = lower_bound(dat.begin(), dat.end(), make_pair(x1, y1));

        for (auto i = l; i != dat.end(); i++)
        {
            if (i->first > x2) break;

            if (i->second >= y1 && i->second <= y2)
            {
                res += getxy(i->first, i->second);
            }
        }
        return res;
    }
};

int main()
{
    int T = read<int>();
    while (T--)
    {
        n = read<int>();
        int m = read<int>(), q = read<int>();
        Db db;
        for (int i = 0; i < m; i++)
        {
            int x = read<int>(), y = read<int>();
            db.add(x, y);
        }
        db.build();

        for (int i = 0; i < q; i++)
        {
            int x = read<int>(), y = read<int>();
            int a = read<int>(), b = read<int>();
            printf("%I64d\n", db.query(x, y, a, b));
        }
    }
}

