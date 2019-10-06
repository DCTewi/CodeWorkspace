#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T> T read()
{
    T x = 0; int ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

const int MAXN = 3e5 + 5;

int n, a[MAXN];
map<int. int> cnt;
int ans1[MAXN], ans2[MAXN];

int main()
{
    n = read<int>();
    for (int i = 0; i < n; i++)
    {
        a[i] = read<int>();
        cnt[a[i]]++;
    }

    return 0;
}

