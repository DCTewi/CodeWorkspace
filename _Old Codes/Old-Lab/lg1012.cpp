#include <bits/stdc++.h>
using namespace std;

int n;
string str[20 + 5];

bool custom(string a, string b)
{
	return a + b > b + a;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin>>str[i];
	}
	sort(str, str + n, custom);

	for (int i = 0; i < n; i++)
	{
		cout<<str[i];
	}
	cout<<endl;
	return 0;
}

