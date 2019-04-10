#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
int mem[MAX];

int getans(int n)
{
	if (mem[n] != -1) return mem[n];
	int ans = 1;
	for (register int i = 1; i <= n / 2; i++)
	{
		ans += getans(i);
	}
	mem[n] = ans;
	return ans;
}

int main(int argc, char const *argv[])
{
	int n; cin>>n;
	for (register int i = 1; i <= n; i++)
	{
		mem[i] = -1;
	}
	mem[1] = 1;

	return !printf("%d\n", getans(n));
}