#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);

	map<string, string> winn;
	winn["ChuiZi"] = "Bu";
	winn["JianDao"] = "ChuiZi";
	winn["Bu"] = "JianDao";

	int k, round = 1; cin>>k; k++;
	string now;
	while (now != "End")
	{
		cin>>now;

		if (now == "End") break;
		round++ % k? cout<<winn[now]<<endl: cout<<now<<endl;
	}

	return 0;
}