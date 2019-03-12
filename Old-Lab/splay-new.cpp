#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 1 << 30;

class Splay
{
	#define root e[0].ch[1]

private:
	class node
	{
	public:
		int val, father, ch[2];//left = 0, right = 1;
		int size, cnt;
	}e[MAXN];

	int n = 0, points;

	void update(int x)
	{
		e[x].size = e[ e[x].ch[0] ].size + e[ e[x].ch[1] ].size + e[x].cnt;
	}

	inline int id(int x)
	{
		return e[e[x].father].ch[1] == x;
	}

	void connect(int x, int f, int place)
	{
		e[x].father = f;
		e[f].ch[place] = x;
	}

	void rotate(int x)
	{
		int y = e[x].father;
		int z = e[y].father;
		connect(e[x].ch[id(y) ^ 1], y, id(x));
		connect(y, x, id(x) ^ 1);
		connect(x, z, id(y));
		update(y); update(x);
	}

	void splay(int at, int to)
	{
		to = e[to].father;
		while (e[at].father != to)
		{
			int f = e[at].father, g = e[f].father;
			if (g != to)
			{
				(e[g].ch[0] == f) ^ (e[f].ch[0] == at) ? rotate(at): rotate(f);				
			}
			rotate(at);
		}
		if (to == root)
		{
		 	root = at;
		}
	}

	int newnode(int v, int father)
	{
		n++;
		e[n].val = v;
		e[n].father = father;
		e[n].size = e[n].cnt = 1;

		return n;
	}
	void destroy(int x)
	{
		e[x].val = e[x].ch[0] = e[x].ch[1] = e[x].size = e[x].father = e[x].cnt = 0;
		if (x == n) n--;
	}

public:
	int getroot()
	{
		return root;
	}

	int find(int val)
	{
		int now = root;
		while(true)
		{
			if (e[now].val == val)
			{
				splay(now, root);
				return now;
			}
			int next = val > e[now].val;
			if (!e[now].ch[next]) return 0;
			now = e[now].ch[next];
		}
	}

	int insert(int val)
	{
		points++;
		if (!n)
		{
			root = 1;
			newnode(val, 0);
		}
		else 
		{
			int now = root;
			while (true)
			{
				e[now].size++;
				if (val == e[now].val)
				{
					e[now].cnt++;
					return now;
				}
				int next = val > e[now].val;
				if (!e[now].ch[next])
				{
					newnode(val, now);
					e[now].ch[next] = n;
					return n;
				}
				now = e[now].ch[next];
			}
		}
		return 0;
	}

	void erase(int val)
	{
		int deal = find(val);
		if (!deal) return;
		points--;

		if (e[deal].cnt > 1)
		{
			e[deal].cnt--;
			e[deal].size--;
			return;
		}
		else if (!e[deal].ch[0])
		{
			root = e[deal].ch[1];
			e[root].father = 0;
			destroy(deal);
			return;
		}
		else
		{
			int lson = e[deal].ch[0];
			while (e[lson].ch[1]) lson = e[lson].ch[1];
			splay(lson, e[deal].ch[0]);
			int rson = e[deal].ch[1];
			connect(rson, lson, 1); connect(lson, 0, 1);
			update(lson);
			destroy(deal);
			return;
		}
		return;
	}

	int rank(int val)
	{
		int ans = 0, now = root;
		while (true)
		{
			if (e[now].val = val) 
			{
				splay(now, root);
				return ans + e[e[now].ch[0]].size + 1;
			}
			if (now == 0) return 0;

			if (val < e[now].val) now = e[now].ch[0];
			else 
			{
				ans += e[e[now].ch[0]].size + e[now].cnt;
				now = e[now].ch[1];
			}
			return 0;
		}
	}

	int xth(int x)
	{
		if (x > points) return -INF;
		int now = root;
		while (true)
		{
			int this_size = e[now].size - e[e[now].ch[1]].size;//equal e[now].cnt + e[lson].size;
			if (x > e[e[now].ch[0]].size && x <= this_size) break;
			if (x < this_size) now = e[now].ch[0];
			else
			{
				x -= this_size;
				now = e[now].ch[1];
			}
		}
		splay(now, root);

		return e[now].val;
	}

	int next(int val)
	{
		int now = root, ans = INF;
		while (now)
		{
			if (e[now].val > val && e[now].val < ans) ans = e[now].val;
			if (val < e[now].val) now = e[now].ch[0];
			else now = e[now].ch[1];
		}
		return ans;
	}
	int prev(int val)
	{
		int now = root, ans = -INF;
		while (now)
		{
			if (e[now].val < val && e[now].val > ans) ans = e[now].val;
			if (val > e[now].val) now = e[now].ch[1];
			else now = e[now].ch[0];
		}
		return ans;
	}

	#undef root
}t;

int main(int argc, char const *argv[])
{
	int n; scanf("%d", &n);
	while (n--)
	{
		int opt, x; scanf("%d%d", &opt, &x);
		switch (opt)
		{
			case 1:
			{
				t.insert(x);
				break;
			}
			case 2:
			{
				t.erase(x);
				break;
			}
			case 3:
			{
				printf("%d\n", t.rank(x));
				break;
			}
			case 4:
			{
				printf("%d\n", t.xth(x));
				break;
			}
			case 5:
			{
				printf("%d\n", t.prev(x));
				break;
			}
			case 6:
			{
				printf("%d\n", t.next(x));
				break;
			}
			default:;
		}
	}

	return 0;
}