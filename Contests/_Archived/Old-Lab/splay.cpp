#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1E5 + 5;

class Splay
{
public:
	Splay(){}
	
	int fa, son[2];	//0 == left, 1 == right
	int val;
	int size, cnt;
}t[MAXN];
int root = 0, top = 0;

inline void update(int x)
{
	t[x].size = t[ t[x].son[0] ].size + t[ t[x].son[1] ].size + t[x].cnt;
} 

inline void connect(int son, int father, int place)
{
	t[son].fa = father;
	t[father].son[place] = son;
}

inline void rotate(int x)
{
	int f = t[x].fa, g = t[f].fa;	// f means x's father node, g means x's grandfather;
	int idx = (t[f].son[1] == x);	// idx means x is the left(0) or right(1) son of f;
	int idf = (t[g].son[1] == f);	// idf means f is the left(0) or right(1) son of g;
	connect(x, g, idf);			// x - g, the place of old f;
	connect(t[x].son[idx ^ 1], f, idx);	// ns - f, the place of old x in y;
	connect(f, x, idx ^ 1);		// f - x the place counter old x;

	update(f); update(x);
}

inline void splay(int x, int goal)
{
	while (t[x].fa != goal)
	{
		int f = t[x].fa, g = t[f].fa;
		if (g != goal)
		{
			(t[g].son[0] == f) ^ (t[f].son[0] == x) ? rotate(x): rotate(f);
		}
		rotate(x);
	}
	if (!goal) root = x;
}

inline void find(int x)
{
	int u = root;
	if (!u) return;

	while (t[u].son[ x > t[u].val ] && x != t[u].val)
	{
		u = t[u].son[ x > t[u].val];
	}
	splay(u, 0);
	// now root is x;
}

int getrank(int x)
{
	find(x);
	return t[ t[root].son[0] ].size + 1;
}

int prext(int x, int next)
{
	find(x);
	int u = root;
	if (t[u].val > x && next) return u;
	if (t[u].val < x && !next) return u;

	u = t[u].son[next];
	while (t[u].son[next ^ 1])
	{
		u = t[u].son[next ^ 1];
	}
	return u;
}

inline void insert(int x)
{
	int u = root, f = 0;
	while (u && t[u].val != x)
	{
		f = u;
		u = t[u].son[x > t[u].val];
	}

	if (u)
	{
		splay(u, 0);
		t[u].cnt++;
		update(u);
	}
	else
	{
		u = ++top;
		if (f)
		{
			t[f].son[x > t[f].val] = u;
		}
		t[u].son[0] = t[u].son[1] = 0;
		t[u].fa = f;
		t[u].val = x;
		t[u].cnt = 1;
		t[u].size = 1;
		splay(u, 0);
	}
}

inline void destroy(int x)
{
	int prev = prext(x, 0);
	int next = prext(x, 1);
	splay(prev, 0); splay(next, prev);

	int del = t[next].son[0];
	if (t[del].cnt > 1)
	{
		t[del].cnt--;
		splay(del, 0);
	}
	else
	{
		t[next].size -= 1;
		t[next].son[0] = 0;
		update(prev);
	}
}

int kth(int k)
{
	int u = root;
	if (t[u].size < k) return 0;
	while (true)
	{
		int lson = t[u].son[0];
		if (k > t[lson].size + t[u].cnt)
		{
			k -= t[lson].size + t[u].cnt;
			u = t[u].son[1];
		}
		else
		{
			if (t[lson].size >= k)
			{
				u = lson;
			}
			else
			{
				return t[u].val;
			}
		}
	}	
}

int main(int argc, char const *argv[])
{
	int n; cin>>n;
	while (n--)
	{
		int opt, x; scanf("%d%d", &opt, &x);
		switch (opt)
		{
			case 1:
			{
				insert(x);
				break;
			}
			case 2:
			{
				destroy(x);
				break;
			}
			case 3:
			{
				printf("%d\n", getrank(x));
				break;
			}
			case 4:
			{
				printf("%d\n", kth(x));
				break;
			}
			case 5:
			{
				printf("%d\n", t[prext(x, 0)].val);
				break;
			}
			case 6:
			{
				printf("%d\n", t[prext(x, 1)].val);
				break;
			}
			default: break;
		}
	}
	return 0;
}