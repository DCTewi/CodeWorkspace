#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e4 + 5;
const int MAXI = 1e3 + 5;
int now[MAXN], sum[MAXN];
int ans[MAXN], add[MAXN];
struct Node {
    int a;
    int b;
    long long ab;
}node[MAXI];

int readInt()
{
	int ans = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-')
	{
		flag = -1; ch = getchar();
	}
	while (isdigit(ch))
	{
		ans = (ans << 1) + (ans << 3) + (ch ^ 48);
		ch = getchar();
	}
	return ans * flag;
}

void times(int n)
{
	memset(add, 0, sizeof(add));
	for (int i = 1; i <= ans[0]; i++)
	{
		ans[i] *= n;
		add[i + 1] += ans[i] / 10;
		ans[i] %= 10;
	}
	for (int i = 1; i <= ans[0] + 4; i++)
	{
		ans[i] += add[i];
		if (ans[i] >= 10)
		{
			ans[i + 1] += ans[i] / 10;
			ans[i] %= 10;
		}
		if (ans[i] != 0)
		{
			ans[0] = max(ans[0], i);
		}
	}
}
void div(int n)
{
	memset(add, 0, sizeof(add));
	int q = 0;
	for (int i = ans[0]; i >= 1; i--)
	{
		q *= 10;
		q += ans[i];
		add[i] = q / n;
		if (add[0] == 0 && add[i] != 0)
		{
			add[0] = i;
		}
		q %= n;
	}
}
bool check()
{
	if (sum[0] == add[0])
	{
		for (int i = add[0]; i >= 1; i--)
		{
			if (add[i] > sum[i]) return 1;
			else if (add[i] < sum[i]) return 0;
		}
	}
	if (add[0] > sum[0]) return 1;
	if (add[0] < sum[0]) return 0;
}
void copyy()
{
	memset(sum, 0, sizeof(sum));
	for (int i = add[0]; i >= 0; i--)
	{
		sum[i] = add[i];
	}
}

int main(int argc, char const *argv[])
{
	int n = readInt();
	for (int i = 0; i <= n; i++)
	{
		node[i].a = readInt();
		node[i].b = readInt();
        node[i].ab = node[i].a * node[i].b;
	}
	sort(node + 1, node + 1 + n, [](Node a, Node b) -> bool {return a.ab < b.ab;});

	ans[0] = ans[1] = 1;

	for (int i = 1; i <= n; i++)
	{
		times(node[i - 1].a);
		div(node[i].b);
		if (check()) copyy();
	}

	for (int i = sum[0]; i >= 1; i--)
	{
		printf("%d", sum[i]);
	}
	return 0;
}