#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
int n, m;
struct Func
{
    int a, b, c;
}f[MAXN];
int flag[MAXN];

int get_func(int i, int x)
{
    return f[i].a * x * x + f[i].b * x + f[i].c;
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> f[i].a >> f[i].b >> f[i].c;
        flag[i] = 1;
    }
    
    sort(f, f + n, [](Func a, Func b)->bool
    {
        return (a.a != b.a)? a.a < b.a: (a.b != b.b)? a.b < b.b: a.c < b.c;
    });

    for (int i = 0; i < m; i++)
    {
        int out = 1 << 20, id = 1;
        for (int j = 0; j < n; j++)
        {
            int now = get_func(j, flag[j]);
            if (now < out)
            {
                out = now; id = j;
            }
        }
        flag[id]++;
        cout << out << " ";
    }

    return 0;
}
