//#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 5e5 + 5;
string s, t;
int f[MAXN];

void getF()
{
	f[0] = -1; int i = 0, j = -1;
	while (i < t.size())
	{
		if (j == -1 || t[i] == t[j])
		{
			f[++i] = ++j;
		}
		else j = f[j];
	}
}

int find()
{

	int i = 0, j = 0, count = 0;
	while (i < s.size() && j < t.size())
	{
		if (j == -1 || s[i] == t[j])
		{
			i++;j++;
		}
		else j = f[j];
		if (j == t.size())
		{
			count++;
			j = f[j];
		}
	}
	return count;
}

int main()
{
	int x; cin>>x;
	while (x--)
	{

		cin>>t>>s;
		getF();
		cout<<find()<<endl;
	}
}


