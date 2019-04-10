#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e2 + 5;
int a[MAXN][MAXN];
int n, m;
int cnt = 0;

void debugPrint()
{
	cout<<endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

void solve1(int x, int y)
{
	int lt = x + 1; while (!a[lt++][y] && lt < n); lt--;
	int rt = y + 1; while (!a[x][rt++] && rt < m); rt--;

	a[x][y]? cnt--: cnt++; a[x][y] = !a[x][y];
	a[lt][y]? cnt--: cnt++; a[lt][y] = !a[lt][y];
	a[x][rt]? cnt--: cnt++; a[x][rt] = !a[x][rt];
	a[lt][rt]? cnt--: cnt++; a[lt][rt] = !a[lt][rt];

}

bool find()
{
	for (int x = 0; x < n - 1; x++)
	{
		for (int y = 0; y < m; y++)
		{
			if (!a[x][y]) continue;
			solve1(x, y);
			if (!cnt) return true;
		}
	}

	return !cnt;
}

int main()
{
	cin>>n>>m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		cin>>a[i][j];
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		int tem; cin>>tem;
		a[i][j] ^= tem;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j])
			{
				cnt++;
			}
		}
	}
	find()? puts("yes"): puts("no");

	return 0;
}