#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int read()
{
    int x = 0; char ch = getchar();
    while (!isdigit(ch)) ch = getchar();;
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

const int MAXN = 1E5 + 5;

struct Node
{
    int value = 0, pos = 0;
} dat[MAXN];
int n, m;
int top = -1;

int main()
{
    n = read(), m = read();
    for (int i = 0; i < n; i++)
    {
        int now = read();
        dat[now].value = now;
        dat[now].pos = i;
    }
    for (int i = 0; i < m; i++)
    {
        int now = read();
        dat[now].pos = top;
        top--;
    }

    sort(dat + 1, dat + n, [](Node a, Node b)
            {
                return a.pos < b.pos;
            });
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", dat[i].value);
    }
    return 0;
}

