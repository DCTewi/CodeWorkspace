#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
int n;

int main()
{
    scanf("%d", &n);
    int N = 2 * n;
    
    vector<int> a(N);
    int cnt = 1, now = 0, dir = 1;

    while (cnt <= N && !a[now])
    {
        a[now] = cnt;
        cnt++;
        now += dir * n;
        if (now >= N)
        {
            dir = -1;
            now = N - 1 - (now - N + 1);
        } 
        else if (now < 0)
        {
            dir = 1;
            now = abs(now);
        }
    }
    if (cnt > N)
    {
        puts("YES");
        for (auto i : a)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
    else
    {
        puts("NO");
    }

    return 0;
}

