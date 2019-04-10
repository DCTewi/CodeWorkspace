#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string t; cin>>t;
	string a[6];
	for (int i = 0; i < 5; i++)
	{
		cin>>a[i];
	}
	for (int i = 0; i < 5; i++)
	{
		if (a[i][0] == t[0] || a[i][1] == t[1])
		{
			
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}