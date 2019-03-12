#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int m; cin>>m;
	for (int l = 1; l  <= m; l++)
	{
		for (int r = l + 1; r  <= m; r++)
		{
			int im = (l + r) * (r - l + 1) / 2;
			if (im == m)
			{
				printf("%d %d\n", l, r);
				break;
			}
			else if (im > m)
			{
				break;
			}
		}
	}
	return 0;
}