#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
const double PI = 3.14159265;
int n;
int x1, Y1, x2, y2;
int x[MAXN], y[MAXN], vis[MAXN];
double r[MAXN], ans;

inline int abs(int a, int b)
{
	return (a > b)? (a - b): (b - a);
}

void dfs(int p, double s)
{
	if (p == n)
	{
		ans = max(ans, s);
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			int flag = 0;
			for (int j = 0; j < n; j++)
			{
				if (vis[j] && r[j] >= sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])))
				{
					flag = 1;
					vis[i] = 1;
					dfs(p + 1, s);
					vis[i] = 0;
				}
			}
			if (flag)
			{
				continue;
			}

			vis[i] = 1;

			r[i] = min(abs(x[i], x1), abs(x[i], x2));
            r[i] = min(r[i], (double)min(abs(y[i], Y1), abs(y[i], y2)));

            for (int j = 0; j < n; j++)
            {
            	if (i != j && vis[j])
            	{
            		double d = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            		r[i] = min(r[i], d - r[j]);
            	}
            }
            dfs(p + 1, s + PI * r[i] * r[i]);

            r[i] = 0;
            vis[i] = 0;
		}
	}
}

inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while (!isdigit(ch))
	{
		w |= ch == '-'; ch = getchar();
	}
	while (isdigit(ch))
	{
		x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();
	}
	return (w? -x: x);
}

inline int readHigh()
{
	return read() + 1000;
}

int main()
{
	n = read();
	x1 = readHigh(); Y1 = readHigh();
	x2 = readHigh(); y2 = readHigh();
	for (int i = 0; i < n; i++)
	{
		x[i] = readHigh();
		y[i] = readHigh();
	}

	dfs(0, 0.0L);

	ans = abs(x1, x2) * abs(Y1, y2) - ans;

	cout<<(int)(ans + 0.5)<<endl;

	return 0;
}