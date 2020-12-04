#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <deque>
#include <bitset>
using namespace std;
typedef long long ll;

int isfound = 0;
ll n;

void dfs(int len, ll now)
{
    if (len > 19 || isfound) return;
    if (now % n == 0)
    {
        isfound = 1;
        printf("%lld\n", now);
        return;
    }
    dfs(len + 1, now * 10);
    dfs(len + 1, now * 10 + 1);
}

int main()
{
    while (~scanf("%lld", &n))
    {
        if (!n) return 0;

        isfound = 0;
        dfs(1, 1l);
    }
    return 0;
}
