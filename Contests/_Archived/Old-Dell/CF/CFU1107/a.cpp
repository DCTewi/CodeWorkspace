#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin>>t;
	while (t--)
	{
		int n; cin>>n;
		char s[n + 5];
		for (int i = 0; i < n; i++)
		{
			cin>>s[i];
		}

		if (n == 1)
		{
			puts("NO");
			continue;
		}
		else if (n == 2)
		{
			if (s[0] < s[1])
			{
				printf("YES\n2\n%c %c\n", s[0], s[1]);
			}
			else
			{
				puts("NO");
				continue;
			}
		}
		else
		{
			printf("YES\n2\n%c ", s[0]);
			for (int i = 1; i < n; i++)
			{
				printf("%c", s[i]);
			}
			printf("\n");
		}
	}
	return 0;
}