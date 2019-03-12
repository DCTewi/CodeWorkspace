#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
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
	string s; cin>>s;
	getNext(s);
	for (int i = 0; i < s.size(); i++)
	{
		cout<<nxt[i]<<" ";
	}
	cout<<endl;
}
