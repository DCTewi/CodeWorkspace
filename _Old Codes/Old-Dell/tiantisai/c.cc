#include <bits/stdc++.h>
using namespace std;

class Time
{
public:
	int hour, min;

	Time(int h = 0, int m = 0)
	{
		this->hour = h;
		this->min = m;
	}
	Time(string t)
	{
		this->hour = (t[0] - '0') * 10 + (t[1] - '0');
		this->min = (t[3] - '0') * 10 + (t[4] - '0');
	}

	int operator-(const Time &other) const
	{
		int ans = (this->hour - other.hour) * 60;
		ans += this->min - other.min;
		return ans;
	}
};

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n; cin>>n;
	for (int d = 0; d < n; d++)
	{
		int id = -1, totBook = 0, totTime = 0; string opt, tim;
		map<int, Time> lend;
		while (id != 0)
		{
		 	cin>>id>>opt>>tim;
			if (id == 0) break;

			if (opt == "S")
			{
				lend[id] = Time(tim);
			}
			else if (opt == "E" && lend.count(id))
			{

				totBook++;
				totTime += Time(tim) - lend[id];
				lend.erase(id);
			}
		}
		totBook? cout<<totBook<<" "<<round((double)totTime / (double)totBook)<<endl: cout<<"0 0\n";
	}
	return 0;
}