#include <bits/stdc++.h>
using namespace std;

const int MAX = 5e3 + 5;
class Farmer
{
public:
	Farmer(){}
	Farmer(int pi, int ai)
	{
		(*this).p = pi;
		(*this).a = ai;
	}
	int p, a;
	bool operator<(const Farmer &other)
	{
		return (*this).p < other.p;
	}
};

Farmer farmer[MAX];
int n, m;
int ans = 0;

inline bool greaterr(Farmer a, Farmer b)
{
	return a < b;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int p, a;
		scanf("%d%d", &p, &a);
		farmer[i] = Farmer(p, a);
	}

	sort(farmer, farmer + m, greaterr);

	for (int i = 0; i < m; i++)
	{
		if (farmer[i].a > n)
		{
			ans += n * farmer[i].p;
			break;
		}
		ans += farmer[i].a * farmer[i].p;
		n -= farmer[i].a;
	}

	printf("%d\n", ans);

	return 0;
}
