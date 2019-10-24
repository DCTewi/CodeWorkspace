#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int a[MAXN];
int n, m, seed;
int max = 0;
class Int
{
public:
	Int(){}
	Int(int x)
	{
		this->n = x;
	}
	
	int n;

	bool operator<(const Int &other)
	{
		return this->n > other.n;
	}
};
map<Int, int> a;

void generate_array(int n, int m, int seed) {
    unsigned x = seed;
    for (int i = 0; i < n; ++i) {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        a[Int(x % m + 1)]++;
        if (a[Int(x % m + 1)] > 1)
        {
        	a[Int((x % m + 1) * a[Int(x % m + 1)])]++;
        	a.erase(Int(x % m + 1));
        }
    }
}

bool greaterr(int a ,int b)
{
	return a > b;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d%d", &n, &m, &seed);
	generate_array(n, m, seed);

	for (auto it = a.begin(); it != a.end(); it++)
	{
		if (it->second > 1)
		{
			a[Int((it->first).n * it->second)]++;
			a.erase(it->first);
		}
	}

	return 0;
}
