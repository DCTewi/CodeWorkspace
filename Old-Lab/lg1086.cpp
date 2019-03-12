#include <bits/stdc++.h>
using namespace std;

class Peanut
{
public:
	Peanut(){}
	Peanut(int x, int y, int value)
	{
		this->x = x;
		this->y = y;
		this->value = value;
	}
	
	int x, y, value;

	bool operator<(const Peanut &other) const
	{
		return this->value < other.value;
	}
};

priority_queue<Peanut> peanuts;

int main(int argc, char const *argv[])
{
	int m, n, k; scanf("%d%d%d", &m, &n, &k);

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int tmp; scanf("%d", &tmp);
			if (tmp != 0)
			{
				peanuts.push(Peanut(i, j, tmp));
			}
		}
	}

	int x = 0, y = (!peanuts.empty())? peanuts.top().y: 0, value_get = 0;
	while (!peanuts.empty())
	{
		Peanut max_now = peanuts.top();

		int mincost = abs(max_now.x - x) + abs(max_now.y - y) + max_now.x + 1;
		//printf("mincost of getting %d is %d, leftk = %d\n", max_now.value ,mincost, k);
		if (mincost > k)
		{
			break;
		}
		else
		{
			k -= mincost - max_now.x;
			value_get += max_now.value;
			x = max_now.x;
			y = max_now.y;
			peanuts.pop();
		}
	}

	printf("%d\n", value_get);

	return 0;
}