#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5;
int n;


template <class T>
T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w? -x: x;
}

struct SegTree
{
    ll st[MAXN << 2], add[MAXN << 2];
    int N = 1;

    inline void build(vector<ll> &raw)
    {
        for (; N < n + 1; N <<= 1); // Get raw data's place.5
        for (int i = N + 1; i <= N + n; i++) st[i] = raw[i - N]; // Raw data.
        for (int i = N - 1; i >= 1; i--) st[i] = st[i << 1] + st[i << 1 | 1]; // Build from leaves.
    }

    inline void update(int l, int r, ll k)
    {
        int s = N + l - 1, t = N + r + 1; // Left and Right.
        ll lNum = 0, rNum = 0, num = 1; // how many k left contained = lNum, how many k this plate contained = num.
        for (; s ^ t ^ 1; s >>= 1, t >>= 1, num <<= 1) // If s and t has same father, s ^ t == 1, 1 ^ 1 == 0
        {
            st[s] += k * lNum;
            st[t] += k * rNum;
            if (~s & 1) {add[s ^ 1] += k; st[s ^ 1] += k * num; lNum += num;} // If s is the left kid of its father, add its brother node.
            if ( t & 1) {add[t ^ 1] += k; st[t ^ 1] += k * num; rNum += num;} // If t is the right kid of its father, add its brother node.
        }
        for (; s; s >>= 1, t >>= 1) // Up to root
        {
            st[s] += k * lNum;
            st[t] += k * rNum;
        }
    }

    inline ll query(int l, int r)
    {
        int s = N + l - 1, t = N + r + 1; // Left and Right.
        ll lNum = 0, rNum = 0, num = 1, ans = 0; // Same as update()#lNum.
        for (; s ^ t ^ 1; s >>= 1, t >>= 1, num <<= 1)
        {
            if (add[s]) ans += add[s] * lNum; // Add the add lazy tag.
            if (add[t]) ans += add[t] * rNum;
            if (~s & 1) {ans += st[s ^ 1]; lNum += num;}
            if ( t & 1) {ans += st[t ^ 1]; rNum += num;}
        }
        for (; s; s >>= 1, t >>= 1) // Up to root
        {
            ans += add[s] * lNum;
            ans += add[t] * rNum;
        }
        return ans;
    }
};

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

struct Ques
{
    int top, bott;
    int index, ans = 0;
};

struct Edge
{
   int l, r;
   int from;
   int top;
}

int main()
{
    int T = read<int>();
    while (T--)
    {
        n = read<int>();
        int m = read<int>(), p = read<int>();
        vector<int> points[MAXN], raw(n + 1);
        for (int i = 0; i < m; i++)
        {
            int x = read<int>(), y = read<int>();
            points[x].emplace_back(y);
        }
        SegTree sg; sg.build(raw);

        vector<Ques> Q(p);
        for (int i = 0; i < p; i++)
        {
            Q[i].index = i;
            Q[i].l = read<int>(), Q[i].bott = read<int>();
            Q[i].r = read<int>(), Q[i].top = read<int>();
        }
        sort(Q.begin(), Q.end(), [](Ques a, Ques b)
                {
                    return a.bott < b.bott;
                });

        for (auto e : Q)
        {
            // RUA 
        }
    }
    return 0;
}
