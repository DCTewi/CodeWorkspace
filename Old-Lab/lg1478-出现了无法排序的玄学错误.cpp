#include <bits/stdc++.h>
using namespace std;

const int MAX = 5e3 + 5;
int n, s, a, b;
class Apple
{
public:
	Apple(){}
	Apple(int x, int y)
	{
		(*this).height = x;
		(*this).cost = y;
	}

	int height, cost;
	
	bool operator<(const Apple &other)
	{
		if ((*this).cost < other.cost)
		{
			return true;
		}
		else if ((*this).height < other.height)
		{
			return true;
		}
		return false;
	}
};

bool greaterr(Apple a, Apple b)
{
	return a < b;
}

vector<Apple> apple;
int height = 0, ans = 0;

int main(int argc, char const *argv[])
{
	scanf("%d%d", &n, &s);
	scanf("%d%d", &a, &b);
	height = a + b;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (x <= height)
		{
			apple.push_back(Apple(x, y));
		}
	}
	sort(apple.begin(), apple.end(), greaterr);
	#ifdef TEWILOCAL
	cout<<endl;
		for (auto app = apple.begin(); app != apple.end(); app++)
			cout<<app->height<<" "<<app->cost<<endl;
	#endif

	for (auto app = apple.begin(); app != apple.end(); app++)
	{
		if (s <= 0) break;
		if (app->height <= height)
		{
			#ifdef TEWILOCAL
				cout<<app->height<<" "<<app->cost<<" get"<<endl;
			#endif
			ans++;
			s -= app->cost;
		}
	}
	printf("%d\n", ans);
	return 0;
}
