#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	double in; cin>>in;
	double nowspeed = 2.0;
	int ans = 0;
	while (in > 0)
	{
		in -= nowspeed;
		nowspeed *= 0.98;
		ans++;
	}
	printf("%d\n", ans);

	return 0;
}