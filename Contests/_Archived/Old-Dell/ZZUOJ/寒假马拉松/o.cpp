#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e4 + 5;
const int dr[4] = {0, 0, 1, -1};
const int dc[4] = {1, -1, 0, 0};
int tile[MAXN][MAXN];
int n, indexx = 1, dir = 2;

inline void nextDir()
{
	switch (dir)
	{
		case 0:
		{
			dir = 2; return;
		}
		case 1:
		{
			dir = 3; return;
		}
		case 2:
		{
			dir = 1; return;
		}
		case 3:
		{
			dir = 0; return;
		}
	}
}

inline void dfs(int row, int col)
{
	if (indexx > n * n) return;

	tile[row][col] = indexx++;

	int nrow = row + dr[dir], ncol = col + dc[dir];
	if (tile[nrow][ncol] != 0 || nrow <= 0 || nrow > n || ncol <= 0 || ncol > n)
	{
		nextDir();
		nrow = row + dr[dir], ncol = col + dc[dir];
	}
	
	dfs(nrow, ncol);
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin>>n;
	dfs(1, n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout<<tile[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}