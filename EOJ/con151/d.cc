#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n, m; cin>>n>>m;

	int x, y, a, b; cin>>x>>y>>a>>b;

	int ans = abs(x - y) + abs(a - b);

	if (ans & 1) puts("Lose");
	else puts("Win");

	return 0;
}