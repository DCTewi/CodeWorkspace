// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
class SegmentTree
{
public:
	SegmentTree(){}

	int l, r;
	ll data, lazy_tag;
} st[4 * MAXN + 2];
int n, m;
ll raw_data[MAXN];

inline int lson(int p){return p << 1;}
inline int rson(int p){return p << 1 | 1;}

void push_up(int p)
{
	st[p].data = st[lson(p)].data + st[rson(p)].data;
}

void build(int p, int l, int r)
{
	st[p].l = l; st[p].r = r;

	if (l == r)
	{
		st[p].data = raw_data[l];
		return ;
	}

	int mid = (l + r) >> 1;
	build(lson(p), l, mid);
	build(rson(p), mid + 1, r);

	push_up(p);
}

void lazy_down(int p)
{
	if (st[p].lazy_tag)
	{
		st[lson(p)].data += st[p].lazy_tag * (st[lson(p)].r - st[lson(p)].l + 1);
		st[rson(p)].data += st[p].lazy_tag * (st[rson(p)].r - st[rson(p)].l + 1);
		st[lson(p)].lazy_tag += st[p].lazy_tag;
		st[rson(p)].lazy_tag += st[p].lazy_tag;

		st[p].lazy_tag = 0;
	}
}

void add(int p, int l, int r, ll n)
{
	if (st[p].l >= l && st[p].r <= r)
	{
		st[p].data += n * (st[p].r - st[p].l + 1);
		st[p].lazy_tag += n;
		return ;
	}

	lazy_down(p);

	int mid = (st[p].l + st[p].r) >> 1;
	if (mid >= l) add(lson(p), l, r, n);
	if (mid <  r) add(rson(p), l, r, n);

	push_up(p);
}

long long query(int p, int l, int r)
{
	if (st[p].l >= l && st[p].r <= r) return st[p].data;

	lazy_down(p);

	ll ans = 0;
	int mid = (st[p].l + st[p].r) >> 1;
	if (mid >= l) ans += query(lson(p), l, r);
	if (mid <  r) ans += query(rson(p), l, r);

	return ans;
}

int main(int argc, char const *argv[])
{

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &raw_data[i]);
	}
	build(1, 1, n);

	for (int i = 0; i < m; i++)
	{
		int cmd;
		scanf("%d", &cmd);
		switch (cmd)
		{
			case 1:
			{
				int x, y, k;
				scanf("%d%d%d", &x, &y, &k);
				add(1, x, y, k);
				break;
			}
			case 2:
			{
				int x, y;
				scanf("%d%d", &x, &y);
				printf("%lld\n", query(1, x, y));
				break;
			}
		}
	}
	
	return 0;
}
