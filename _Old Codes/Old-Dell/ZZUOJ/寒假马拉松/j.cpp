#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;
int n;
int king = 0, win = 0;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		int temp; cin>>temp;
		if (i & 1) king += temp;
		else win += temp;
	}
	(win < king)? puts("KING"):
	(win > king)? puts("WIN"):
	puts("GOOD");
	return 0;
}