#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e3 + 5;
int n, m;
int sco_line, admitted_n;
class Stu
{
public:
	Stu(){}
	Stu(int id, int scr)
	{
		this->index = id;
		this->score = scr;
	}

	int index, score;
	
	bool operator<(const Stu &other) const
	{
		if (this->score == other.score) return this->index < other.index;
		else return this->score > other.score;
	}
};

vector<Stu> data;

int main(int argc, char const *argv[])
{
	cin>>n>>m;
	for (int i = 0; i < n; i++)
	{
		int id, src; cin>>id>>src;
		data.push_back(Stu(id, src));
	}

	sort(data.begin(), data.end());

	admitted_n = (m * 1.5 / 1.5 == m)? m * 1.5: m * 1.5 + 1;

	while (admitted_n != n && data[admitted_n].score == data[admitted_n - 1].score)
	{
		admitted_n++;
	}
	printf("%d %d\n", data[admitted_n - 1].score, admitted_n);
	for (int i = 0; i < admitted_n; i++)
	{
		printf("%d %d\n", data[i].index, data[i].score);
	}
	printf("\n");

	return 0;
}
