#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 5;
ll s[MAXN];
ll nxt[MAXN];
int n;

struct Index
{
	int ind;

	bool operator<(const Index &o) const
	{
		return s[this->ind] < s[o.ind];
	}
}ind[MAXN];

void getNext()
{
	nxt[0] = -1; // -1 表示前后缀不存在
	int k = -1; // 模式串的匹配游标
	for (int i = 1; i < n; i++)
	{
		while (k != -1 && s[k + 1] != s[i]) k = nxt[k];
		//下一个数失配则更新本位的失配指针，k == -1则触顶
		if (s[k + 1] == s[i]) k++;
		nxt[i] = k;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &s[i]);
		ind[i].ind = i;
	}

	getNext();

	if (nxt[n - 1] + 2 == n)
	{
		return 0 * puts("0");
	}

	sort(ind, ind + n, [](Index a, Index b)->bool{return a < b;});

for (int i = 0; i < n; i++)
{
	cout<<nxt[i] + 1<<" ";
}
cout<<endl;

	for (int i = 0; i < n - 1; i++)
	{
		//ind[i]
	}

	return 0;
}


