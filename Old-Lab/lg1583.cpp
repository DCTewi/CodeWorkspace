#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e4 + 5;
int n, k;
int e[15];

class Stu
{
public:
	Stu(){}
	Stu(int n, int w)
	{
		this->n = n;
		this->w = w;
	}
	
	int w, n, d;

	void addw(int a)
	{
		this->w += a;
	}

	bool operator<(const Stu &other) const
	{
		if (this->w != other.w) return this->w < other.w;
		else return this->n < other.n;
	}
	bool operator>(const Stu &other) const
	{
		if (this->w != other.w) return this->w > other.w;
		else return this->n < other.n;
	}
};

vector<Stu> stu;

int main(int argc, char const *argv[])
{
	cin>>n>>k;
	for (int i = 1; i <= 10; i++)
	{
		scanf("%d", &e[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		int w; scanf("%d", &w);
		stu.push_back(Stu(i, w));
	}
	sort(stu.begin(), stu.end(), [](Stu a, Stu b) -> bool {return a > b;});

	for (int i = 0; i < stu.size(); i++)
	{
		stu[i].d = i + 1;
		stu[i].addw(e[i % 10 + 1]);
	}

	sort(stu.begin(), stu.end(), [](Stu a, Stu b) -> bool {return a > b;});

	for (int i = 0; i < stu.size() && i < k; i++)
	{
		printf("%d ", stu[i].n);
	}
	printf("\n");
	return 0;
}