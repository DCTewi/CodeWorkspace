#include <bits/stdc++.h>
using namespace std;

int n;
string ins, ous;
int vis[15], ind[15], out[15];

inline string toString(int p)
{
	string ans = "0";
	ans[0] += p;
	return ans;
}

int main(int argc, char const *argv[])
{
	cin>>n>>ins;

	if (ins[0] == 'A')
	{
		ous = "B=(0,";
		for (int i = 3, j = 0; i < ins.size() - 1; i += 2, j++)
		{
			ind[j] = ins[i] - '0';
		}
		for (int i = 1; i < n; i++)
		{
			int ansi = 0;
			for (int j = 0; j < i; j++)
			{
				if (ind[j] < ind[i])
				{
					ansi++;
				}
			}
			ous += toString(ansi);
			(i == n - 1)? ous += ")": ous += ",";
		}
	}
	else if (ins[0] == 'B')
	{
		ous = "A=(";
		for (int i = 3, j = 0; i < ins.size() - 1; i += 2, j++)
		{
			ind[j] = ins[i] - '0';
		}
		for (int i = n - 1; i >= 0; i--)
		{
			int cnt = 0;
			for (int j = 0; j < n; j++)
			{
				if (!vis[j])
				{
					if (cnt == ind[i])
					{
						vis[j] = 1;
						out[i] = j;
						break;
					}
					cnt++;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			ous += toString(out[i]);
			if (i != n - 1) ous += ",";
		}
		ous += ")";
	}
	cout<<ous<<endl;
	return 0;
}