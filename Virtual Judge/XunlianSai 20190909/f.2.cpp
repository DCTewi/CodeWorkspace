#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int n, m;

template <class T> T read()
{
    T x = 0; int ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

int father[MAXN];
int getf(int p)
{
    if (father[p] == p) return p;
    
    return father[p] = getf(father[p]);
}

void merge(int u, int v)
{
    father[getf(u)] = getf(v);
}

int main()
{
    n = read<int>(), m = read<int>();

    for (int i = 1; i <= n; i++) father[i] = i;

    for (int i = 0; i < m; i++)
    {
        merge(read<int>(), read<int>());
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (getf(i) == i) cnt++;
    }

    printf("%d\n", m - n + cnt);

    return 0;
}


