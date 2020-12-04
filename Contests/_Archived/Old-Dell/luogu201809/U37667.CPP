#include <bits/stdc++.h>
using namespace std;
#define IMPOSSIBLE printf("Impossible!\n")
#define UNCERTAIN printf("Uncertain!\n")

const int MAXN = 5e5 + 10;
int n, m, s, q;
int a[MAXN], b[MAXN], len[MAXN];

int main(int argc, char const *argv[])
{
	scanf("%d%d%d%d", &n, &m, &s, &q);

	for (int i = 0; i < s; i++)
	{
		scanf("%d%d", &a[i], &b[i]);
		if (b[i] < a[i] || b[i] - a[i] >= m)
		{
			return 0 * IMPOSSIBLE;
		}
		//check
		len[i] = b[i] - a[i];
		for (int j = 0; j < i; j++)
		{
			if (b[j] >= a[i] || a[j] <= b[i])
			{
				len[i] = len[j] + len[i];
				len[j] = len[i];
				if (len[i] >= m) return 0 * IMPOSSIBLE;
			}
		}
	}

	for (int i = 0; i < s; i++)
	{
		if (len[i] == m - 1)
		{
			int row = a[i] / m + 1;
			int fir = a[i] - (row - 1) * m;
			for (int j = 0; j < q; j++)
			{
				a[i]
			}
		}
	}

	return 0;
}
///////////////////////mmmmmmmmmmmmmmmmmmmmmmmmpppppppppppp