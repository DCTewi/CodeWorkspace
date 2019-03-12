#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
	Person(){}
	Person(int i, double t)
	{
		(*this).index = i;
		(*this).cost_time = t;
	}

	int index;
	double cost_time;

	bool operator<(const Person &other)
	{
		return (*this).cost_time < other.cost_time;
	}
	
};

const int MAX = 1e3 + 5;
int n;
Person person[MAX];

inline bool greaterr(Person a, Person b)
{
	return a < b;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		double t;
		scanf("%lf", &t);
		person[i] = Person(i + 1, t);
	}
	sort(person, person + n, greaterr);

	double left_time = 0, waiting_now = 0;
	for (int i = 0; i < n; i++)
	{
		if (i > 0)
		{
			waiting_now += person[i - 1].cost_time;
			left_time += waiting_now;
		}
		printf("%d ", person[i].index);
	}

	left_time /= (double) n;

	#ifdef TEWILOCAL
		cout<<endl<<left_time<<endl;
	#endif

	printf("\n%.2f\n", left_time);

	return 0;
}
