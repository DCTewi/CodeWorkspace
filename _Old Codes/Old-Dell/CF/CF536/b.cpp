#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 50;
class Dish
{
public:
	Dish(int i = 0, int c = 0, int l = 0)
	{
		this->index = i;
		this->cost = c;
		this->left = l;
	}
	int index, cost, left;

	bool operator<(const Dish &other) const
	{
		return this.cost < other.cost;
	}
}dish[MAXN];
map<int, int> ind;
int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i = 1; i <= n; i++)
	{
		cin>>dish[i].left;
		dish[i].index = i;
	}
	for (int i = 1; i <= n; i++)
	{
		cin>>dish[i].cost;
	}

	sort(dish, dish + n, [](Dish a, Dish b)->bool{return a < b;});

	for (int i = 0; i < n; i++)
	{
		ind[dish[i].index] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int ordIndex, amount; cin>>ordIndex>>amount;
		int purch = 0;

		if (dish[ind[ordIndex]].left >= amount)
		{
			dish[ind[ordIndex]].left -= amount;
			purch += dish[ind[ordIndex]].cost * amount;
		}
		else
		{
			
		}
	}

	return 0;
}