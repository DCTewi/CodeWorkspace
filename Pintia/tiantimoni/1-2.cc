#include <bits/stdc++.h>
using namespace std;

const string dang = "Dang";

int main()
{
	string s; cin>>s;
	
	int a = (s[0] - '0') * 10 + (s[1] - '0');
	int b = (s[3] - '0') * 10 + (s[4] - '0');

	if (a < 12 || (a == 12 && b == 0))
	{
		cout<<"Only "<<s<<". Too early to Dang.";
	}
	else
	{
		if (b > 0) a++;
		a -= 12;
		for (int i = 0; i < a; i++)
		{
			cout<<dang;
		}
	}

	return 0;
}
