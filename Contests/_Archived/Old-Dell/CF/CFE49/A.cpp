#include <bits/stdc++.h>
using namespace std;

int t;
//abc  cde  efg;
int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--)
	{
		int n; scanf("%d", &n);
		string str; cin>>str;

		int uplimit = n / 2, flag = 1;
		for (int i = 0; i < uplimit; i++)
		{
			int j = n - 1 - i;
			if (str[i] == str[j]) continue;
			else if (abs(str[i] - str[j]) == 2) continue;
			else
			{
				flag = 0;
				break;
			}
		}

		flag? puts("YES"): puts("NO");
	}
	return 0;
}