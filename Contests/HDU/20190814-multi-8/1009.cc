#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read()
{
    ll x = 0; char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

struct Node
{
    ll x = 0, y = 0;
    bool operator<(const Node &o) const
    {
        return (x == o.x)? (y < o.y): (x < o.x);
    }
};

int main()
{
    int T = read();
    while (T--)
    {
        vector<Node> a(2), b(2);
        for (int i = 0; i < 2; i++) a[i].x = read(), a[i].y = read();
        for (int i = 0; i < 2; i++) b[i].x = read(), b[i].y = read();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }

    return 0;
}

