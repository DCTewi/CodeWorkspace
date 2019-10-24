#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;

int read()
{
    int x = 0; char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{
    n = read(), m = read();
    list<int> q;
    for (int i = 0; i < n; i++)
    {
        int now = read();
        q.emplace_back(now);
    }

    for (int i = 0; i < m; i++)
    {
        int opt = read();
        auto it = q.begin();
        while (!((*it) == opt)) it++; 
        q.erase(it);
        q.emplace_front(opt);
    }
    for (auto it : q)
    {
        printf("%d ", it);
    }

    return 0;
}

