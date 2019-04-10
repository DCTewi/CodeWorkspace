#include <bits/stdc++.h>
using namespace std;


void print_permutation(int n, int* P, int* A, int cur)
{
	if (cur == n)
	{
		for (int i = 0; i < n; i++)
		{
			printf("%d ", A[i]);
		}
		printf("\n");
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
	int A[n + 5], P[n + 5];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &P[i]);
	}

	sort(P, P + n);

	print_permutation(n, P, A, 0);

	return 0;
}