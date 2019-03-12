#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50;
int n;
int s1[MAXN], s2[MAXN];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= 3; i++)
	{
		int nt; scanf("%d", &nt);
		for (int j = 1; j <= nt; j++)
		{
			int temp; scanf("%d", &temp);
			s1[temp] = i;
		}
	}
	for (int i = 1; i <= 3; i++)
	{
		int nt; scanf("%d", &nt);
		for (int j = 1; j <= nt; j++)
		{
			int temp; scanf("%d", &temp);
			s2[temp] = i;
		}
	}
	return 0;
}
