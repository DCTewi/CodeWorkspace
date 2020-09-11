#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e6 + 5;

int check[MAXN];
int prim[MAXN], top = 0;
int n, k, maxx = 0, ans = 0;
int x[25], vis[25];

void getPrime(int upLimit)
{
	check[0] = check[1] = 1;
	for (int i = 2; i <= upLimit; i++)
	{
		if (!check[i])
		{
			prim[top++] = i;
		}

		for (int j = 0; j < top; j++)
		{
			if (i * prim[j] > upLimit) break;

			check[i * prim[j]] = 1;

			if (i % prim[j] == 0) break;
		}
	}
	return ;
}

void dfs(int num, int now, int res)
{
    if (num >= k)
    {
        if (!check[res])
        {
            //cout << res << "\n";
            ans++;
        }
        return;
    }

    for (int i = now; i < n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            dfs(num + 1, i, res + x[i]);
            vis[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        maxx += x[i];
    }

    getPrime(maxx + 5);

    dfs(0, 0, 0);

    cout << ans << "\n";

    return 0;
}