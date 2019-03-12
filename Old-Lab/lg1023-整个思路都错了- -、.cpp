#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
double price_wanna, down_per, maxw;
double cost, cus_n;
map<double, double> p_n;
double price , n;

int main(int argc, char const *argv[])
{
	scanf("%lf%lf%lf", &price_wanna, &cost, &cus_n);
	p_n[cost] = cus_n;
	while (scanf("%lf%lf", &price, &n) == 2 && price != -1 && n != -1)
	{
		p_n[price] = n;
		if ((price - cost) * n > maxw) maxw = (price - cost) * n;
	}
	scanf("%lf", &down_per);

	auto it = p_n.end(); it--;
	#ifdef TEWILOCAL
		cout<<it->first<<" "<<it->second<<endl;
	#endif
	while ((it->first + 1 - cost) * (it->second - down_per) > maxw)
	{
		maxw = (it->first + 1 - cost) * (it->second - down_per);
		p_n[it->first + 1] = it->second - down_per;
		it++;
		#ifdef TEWILOCAL
			cout<<it->first<<" "<<it->second<<endl;
		#endif
	}
	cout<<maxw<<" "<<cus_n<<" "<<price_wanna<<" "<<cost<<endl;
	double delta = maxw / cus_n - price_wanna + cost;
	cout<<delta<<endl;

	return 0;
}

