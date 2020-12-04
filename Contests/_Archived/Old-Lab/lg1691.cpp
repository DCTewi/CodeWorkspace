#include <bits/stdc++.h>
using namespace std;

int ans = 0;

void print_permutation(int n, char* P, char* A, int cur)
{
	if (cur == n)
	{
		for (int i = 0; i < n; i++)
		{
			printf("%c", A[i]);
		}
		printf("\n");
		ans++;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (P[i] != P[i - 1])
			{
				int cp = 0, ca = 0;
				for (int j = 0; j < cur; j++) if (A[j] == P[i]) ca++;
				for (int j = 0; j < n; j++) if (P[i] == P[j]) cp++;

				if (ca < cp)
				{
					A[cur] = P[i];
					print_permutation(n, P, A, cur + 1);
				}
			}
		}
	}
	return ;
}

int main(int argc, char const *argv[])
{
	int n; scanf("%d", &n);
	char A[n + 5], P[n + 5];
	for (int i = 0; i < n; i++)
	{
		cin>>P[i];
	}

	sort(P, P + n);

	print_permutation(n, P, A, 0);

	printf("%d\n", ans);

	return 0;
}