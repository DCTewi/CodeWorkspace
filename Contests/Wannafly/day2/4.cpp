#include <bits/stdc++.h>
using namespace std;

template <class T> T read()
{
    T x = 0; int ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

const int MAXN = 1e5 + 5;
int n = 0;
int p[MAXN];
vector<int> son[MAXN];
int kicked[MAXN];
map<int, int> lenof;

int main()
{
    n = read<int>();
    lenof[1] = n - 1;
    p[1] = 0; son[0].emplace_back(1);
    for (int i = 2; i <= n; i++)
    {
        p[i] = read<int>();
        son[p[i]].emplace_back(i);
    }
    int cnt = n;
    queue<int> q; q.push(1);
    while (q.size())
    {
        int u = q.front(); q.pop(); kicked[u] = 1;
    }

    return 0;
}