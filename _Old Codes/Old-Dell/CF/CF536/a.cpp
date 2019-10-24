#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e2 + 5;
int n;
char ch[MAXN][MAXN];

bool check (int x, int y)
{
	if (ch[x][y] == 'X')
	if (ch[x - 1][y - 1] == 'X')
	if (ch[x + 1][y - 1] == 'X')
	if (ch[x + 1][y + 1] == 'X')
	if (ch[x - 1][y + 1] == 'X')
	{
		return true;
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin>>ch[i][j];
		}
	}

	int ans = 0;
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			if (check(i, j)) ans++;
		}
	}

	cout<<ans<<endl;
	return 0;
}