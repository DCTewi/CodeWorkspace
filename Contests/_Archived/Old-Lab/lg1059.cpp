#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

int main(int argc, char const *argv[])
{
	int n; cin>>n;
	for (int i = 0; i < n; i++)
	{
		int tmp; cin>>tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	printf("%d\n", arr.size());
	for (auto i : arr)
	{
		printf("%d ", i);
	}
	printf("\n");

	return 0;
}
