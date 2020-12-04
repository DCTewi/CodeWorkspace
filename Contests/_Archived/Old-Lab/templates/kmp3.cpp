#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 5;
int nxt[MAXN];
int maxnext = -1;
void getNext(string s)
{
	nxt[0] = -1; // -1 表示前后缀不存在
	int k = -1; // 模式串的匹配游标
	for (int i = 1; i < s.size(); i++)
	{
		while (k != -1 && s[k + 1] != s[i]) k = nxt[k];
		if (s[k + 1] == s[i]) k++;
		nxt[i] = k;

		if (i != s.size() - 1) maxnext = max(maxnext, k);
	}
}

int main()
{
	string str, anss; cin>>str;
	getNext(str);

	int x = nxt[str.size() - 1];

	if (x == -1)
	{
		puts("Just a legend");
		return 0;
	}
	else
	{
		while (x > maxnext) x = nxt[x];

		if (x == -1)
		{
			puts("Just a legend");
			return 0;
		}
	}

	for (int i = 1; i < str.size() - 1; i++)
	{
		if (x == nxt[i])
		{
			for (int j = i - nxt[i]; j <= i; j++)
			{
				cout<<str[j];
			}
			cout<<endl;
			return 0;
		}
	}

	return 0;
}

