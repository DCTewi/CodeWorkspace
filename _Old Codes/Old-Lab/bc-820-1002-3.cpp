#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
class Sub
{
public:
	Sub(){}
	Sub(char ch, int index)
	{
		this->ch = ch;
		this->index = index;
	}

	char ch;
	int index;

	bool operator<(const Sub &other)
	{
		if (this->ch == other.ch)
		{
			return this->index < other.index;
		}
		else return this->ch < other.ch;
	}
	
};

Sub sub[MAXN];

bool greaterr(Sub a, Sub b)
{
	return a < b;
}

int main(int argc, char const *argv[])
{
	int T; cin>>T;
	for (int t = 1; t <= T; t++)
	{
		memset(sub, 0, sizeof(sub));
		printf("Case #%d:\n", t);
		int n, q; scanf("%d%d", &n, &q);
		string a; cin>>a;
		for (int i = 0; i < n; i++)
		{
			sub[i] = Sub(a[i], i + 1);
		}
		sort(sub, sub + n, greaterr);

		for (int line = 0; line < q; line++)
		{
			int l, r, ans = 0; scanf("%d%d", &l, &r);

			for (int i = 0; i < n; i++)
			{
				if (sub[i].index >= l && sub[i].index <= r)
				{
					char ch = sub[i].ch;
					for (int j = i; j < n && sub[j].ch ==ch && sub[j].index <= r; j++)
					{
						ans++;
					}
					break;
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}