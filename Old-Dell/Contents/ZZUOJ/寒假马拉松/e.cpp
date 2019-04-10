#include <bits/stdc++.h>
using namespace std;

int dic[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int p, ans = 0;

int main(int argc, char const *argv[])
{
	cin>>p;
	do
	{
		if (dic[0] < dic[5] && dic[5] < dic[8])
		{
			if (dic[1] < dic[3] && dic[6] < dic[7] && dic[2] < dic[4])
			{
				if (dic[0] + dic[1] + dic[3] + dic[5] == p)
				if (dic[8] + dic[7] + dic[6] + dic[5] == p)
				if (dic[8] + dic[4] + dic[2] + dic[0] == p)
				{
					ans++;
				}
			}
		}
	}
	while (next_permutation(dic, dic + 9));

	(ans)? (printf("%d\n", ans)): puts("Not exist");
	return 0;
}
/**
 * abcdefghi
 * 012345678
 */