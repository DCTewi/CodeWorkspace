#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXM = 2e5 + 5;
const ll INF = 1ll << 60;
int m, mod, top = 0;
long long t = 0;

class SegmentTree
{
public:
	SegmentTree(){}

	int l, r;
	long long int data, add_tag;
}se[4 * MAXM + 2];

inline int lson(int p){return p << 1;}
inline int rson(int p){return p << 1 | 1;}

void push_up(int p)
{
	se[p].data = max(se[lson(p)].data, se[rson(p)].data);
}

void build(int p, int l, int r)
{
	se[p].l = l; se[p].r = r;
	se[p].data = -INF;
	if (l == r) return;

	int mid = (l + r) >> 1;
	build(lson(p), l, mid);
	build(rson(p), mid + 1, r);
	push_up(p);
}

void change(int p, int x, ll k)
{
	if (se[p].l == se[p].r)
	{
		se[p].data = k;
		return ;
	}
	int mid = (se[p].l + se[p].r) >> 1;
	if (x <= mid) change(lson(p), x, k);
	if (x >  mid) change(rson(p), x, k);

	push_up(p);
}

long long query(int p, int l, int r)
{
	if (se[p].l == l && se[p].r == r) return se[p].data;

	int mid = (se[p].l + se[p].r) >> 1;
	if (mid >= r) return query(lson(p), l, r);
	else if (mid < l) return query(rson(p), l, r);
	else return max(query(lson(p), l, mid), query(rson(p), mid + 1, r));
}

int main(int argc, char const *argv[])
{
	scanf("%d %d", &m, &mod);
	build(1, 1, m);
	for (int i = 0; i < m; i++)
	{
		char cmd[10]; ll x;
		scanf("%s %lld", cmd, &x);
		switch (cmd[0])
		{
			case 'A':
			{
				x = (x + t) % mod;
				top++;
				change(1, top, x);

				break;
			}

			case 'Q':
			{
				if (x)
				{
					t = query(1, top - x + 1, top);
					t %= mod;
					printf("%lld\n", t);
				}
				else
				{
					puts("0");
				}
				break;
			}
		}
	}

	return 0;
}