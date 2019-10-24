#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e2 + 5;
int n, m;
int a[MAX], b[MAX];
int aa[MAX], bb[MAX];

bool check(int a[], int b[])
{
	for (int t = 0; t < 9; t++)
	{
		int tot1 = 0, tot2 = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] & 1) tot1++;
			a[i] >>= 1;
		}
		for (int i = 0; i < m; i++)
		{
			if (b[i] & 1) tot2++;
			b[i] >>= 1;
		}

		if (((tot1 & 1) && (!(tot2 & 1))) || ((!(tot1 & 1)) && (tot2 & 1))) return false;
	}
	return true;
}

int getnum()
{
	int num = bb[0];
	for (int i = 1; i < m - 1; i++)
	{
		num ^= bb[i];
	}
	num ^= aa[n - 1];
	return num;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		aa[i] = a[i];
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
		bb[i] = b[i];
	}
	if (!check(a, b)) return 0 * printf("NO\n");
	else 
	{
		printf("YES\n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (i == n - 1 && j == m - 1)
				{
					printf("%d ", getnum());
				}
				else if (i == n - 1)
				{
					printf("%d ", bb[j]);
				}
				else if (j == m - 1)
				{
					printf("%d ", aa[i]);
				}
				else
				{
					printf("0 ");
				}
			}
			printf("\n");
		}
	}

	return 0;
}