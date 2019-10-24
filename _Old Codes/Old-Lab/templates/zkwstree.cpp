/*
	zkw's Segment Tree
	Range Summary Query Version
	zkw seg tree 代码少运行快 但是不能处理有运算优先级的问题(如加法乘法混合处理)
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6 + 5;
ll st[MAXN << 2]; //Segment Tree Array.
ll add[MAXN << 2]; //add[i] means node i was updated add[i] (lazy tag).
int n, N; //n <- actual length of data array, N <- amount of leave nodes.

inline void build()
{
	for (; N <= n + 1; N <<= 1);
	for (int i = N + 1; i <= N + n; i++) scanf("%lld", st + i);
	for (int i = N - 1; i >= 1; i--) st[i] = st[i << 1] + st[i << 1 | 1];
}

inline void pointUpdate(int x, int k)
{
	for (x += N; x; x >== 1) st[x] += k;
}

inline void update(int l, int r, int k)
{
	int s = N + l - 1, t = N + r + 1;
	ll sNum = 0, tNum = 0, num = 1;
	//sNum means the node amount which s contained. t same.
	//num means the node amount of current depth.
	for (; s ^ t ^ 1; s >>= 1, t >>= 1, num <<= 1)
	{
		//update the seg tree.
		st[s] += k * sNum;
		st[t] += k * tNum;
		//deal add.
		if (~s & 1){add[s ^ 1] += k; st[s ^ 1] += k * num; sNum += num;}
		if ( t & 1){add[t ^ 1] += k; st[t ^ 1] += k * num; tNum += num;}
	}
	//update higher nodes.
	for (; s; s >>= 1, t >>= 1)
	{
		st[s] += k * sNum;
		st[t] += k * tNum;
	}
}

inline ll query(int l, int r)
{
	int s = N + l - 1, t = N + r + 1; 
	ll sNum = 0, tNum = 0, num = 1;
	ll ans = 0;
	for (; s ^ t ^ 1; s >>= 1, t >>= 1, num <<= 1)
	{
		//if (father(s) == father(r)  =>  s ^ r == 1  =>  s ^ r ^ 1 == 0)

		if (add[s]) ans += add[s] * sNum;
		if (add[t]) ans += add[t] * tNum;

		if (~s & 1) {ans += st[s ^ 1]; sNum += num;}
		if ( t & 1) {ans += st[t ^ 1]; tNum += num;}
		//node ^ 1 is its brother node in binary tree.

		//if (~s & 1) means ~s is end with 1, therefore, s is the left node of its father node.
		//and then ans += st[s ^ 1], means add s's brother node's value.

		//t is same as s. but ans add when t is the right node.
		//update higher nodes.
		for (; s; s >>= 1, t >>= 1)
		{
			ans += add[s] * sNum;
			ans += add[t] * tNum;
		}
	}
	return ans;
}

int main()
{
	return 0;
}

