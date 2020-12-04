#include <cstdio>

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d%d", &n, &m);

	int method[n * 4][3], ans = 0;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			for (int k = 0; k <= n; k++)
			{
				if ((i + j + k == n) && (i + j * 2 + k * 5 == m))
				{
					ans++;
					method[ans][0] = i;
					method[ans][1] = j;
					method[ans][2] = k;
				}
			}
		}
	}

	printf("一共有%d种结果：\n", ans);
	for (int i = 1; i <= ans; i++)
	{
		printf("5分%d个，2分%d个，1分%d个\n", method[i][2], method[i][1], method[i][0]);
	}

	return 0;
}