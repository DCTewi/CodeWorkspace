#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 5;
int n = 0, sum = 0, target = 0;
int a[MAXN];
int ans = 0;


int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	target = sum / n;

	sort(a, a + n, [](int a, int b) -> bool {return a > b;});

	for (int i = 0; i < n; i++)
	{
		if (a[i] == target) continue;
		for (int j = n - 1; j > i && a[i] > target; j--)
		{
			if (a[j] >= target) continue;
			int wanna = target - a[j];
			if (a[i] - wanna < target)
			{
				ans++;
				a[j] += a[i] - target;
				a[i] = target;
				break;
			}
			else
			{
				ans++;
				a[i] -= wanna;
				a[j] = target;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}

/*
*	9 8 17 6
*	17 9 8 6
*	13 9 8 10
*	11 9 10 10
*	10 10 10 10
*/