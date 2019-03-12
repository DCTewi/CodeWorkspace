#include <bits/stdc++.h>
using namespace std;

int n;

class Stu
{
public:
	Stu(){}
	Stu(int i, int chi, int math, int eng)
	{
		this->index = i;
		this->chi = chi;
		this->tot = chi + math + eng;
	}

	int index, chi, tot;

	bool operator>(const Stu &other) const
	{
		if (this->tot != other.tot) return this->tot > other.tot;
		else if (this->chi != other.chi) return this->chi > other.chi;
		else return this->index < other.index;
	}
};

vector<Stu> stu;

int main(int argc, char const *argv[])
{
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		int c, m, e;
		scanf("%d%d%d", &c, &m, &e);
		stu.push_back(Stu(i, c, m, e));
	}

	sort( stu.begin(), stu.end(), [](Stu a, Stu b) -> bool {return a > b;} );

	for (int i = 0; i < n && i < 5; i++)
	{
		printf("%d %d\n", stu[i].index, stu[i].tot);
	}
	return 0;
}