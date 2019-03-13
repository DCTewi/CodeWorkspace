#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 5;
int kawaiijodoku[MAXN];
int ans[MAXN];

int main(int argc, char const *argv[])
{
	int n; cin>>n;

	for (int i = 0; i < n; i++)
	{
		cin>>kawaiijodoku[i];
		for (int j = 0; j < i; j++)
		{
			if (kawaiijodoku[j] < kawaiijodoku[i])
			{
				ans[i]++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}