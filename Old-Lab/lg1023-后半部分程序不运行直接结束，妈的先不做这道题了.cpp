#include <bits/stdc++.h>
using namespace std;
#ifdef TEWILOCAL
	#include <windows.h>
#endif

int price, cost, cost_n, wanna_value, down_per;
map<int ,int> p_n;
int ans = 0;

int getN(int value)
{
	if (!p_n.count(value)) p_n[value] = getN(value - 1) - down_per;
	for (auto it : p_n)
	{
		cout<<it.first<<" "<<it.second<<endl;
	}
	Sleep(500);
	return p_n[value];
}

int getW(int value, int x, bool add)
{
	if (!p_n.count(value))
	{
		getN(value);
	}

	if (add)
	{
		return (value - cost + x) * p_n[value];
	}
	else return (value - cost - x) * p_n[value];
}

int getX(bool add)
{
	for (int i = 0; ; i++)//gov +i
	{
		int now = getW(price, i, add);//wanna w
		int now_w = 0, last_w = 0;
		bool found = 0;
		for (int j = 0; ; j++)//find max
		{
			now_w = getW(price + j, i, add);
			if (now_w > now && price + j != now) break;
			if (now_w < last_w)
			{
				found = 1;
				break;
			}
			last_w = now_w;
		}
		if (found)
		{
			return i;
		}
	}
}

int main(int argc, char const *argv[])
{
	//get data
	scanf("%d%d%d", &wanna_value, &cost, &cost_n);
	p_n[cost] = cost_n;
	for (int pp = 0, nn = 0; pp != -1 && nn != -1;)
	{
		scanf("%d%d", &pp, &nn);
		if (pp != -1) p_n[pp] = nn;
	}
	scanf("%d", &down_per);

	cout<<ans<<" ans1"<<endl;

	//check +
	ans = getX(1);
	cout<<ans<<" ans2"<<endl;
	//check -
	ans = getX(0);
	cout<<ans<<" ans3"<<endl;
	printf("%d\n", ans);
	cout<<ans<<endl;

	return 0;
}


/*	for (auto it : p_n)
	{
		cout<<it.first<<" "<<it.second<<endl;
	}
*/