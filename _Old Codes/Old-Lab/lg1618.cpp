#include <bits/stdc++.h>
using namespace std;

int dic[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
double a, b, c;
bool flag = 0;
inline double get3(int hun, int ten, int one)
{
	return (double)(dic[hun] * 100 + dic[ten] * 10 + dic[one]);
}

int main(int argc, char const *argv[])
{
	scanf("%lf%lf%lf", &a, &b, &c);

	do
	{
		if (get3(0, 1, 2) / get3(3, 4, 5) == a / b)
		{
			if (get3(3, 4, 5) / get3(6, 7, 8) == b / c)
			{
				if (!flag) flag = 1;
				cout<<get3(0, 1, 2)<<" "<<get3(3, 4, 5)<<" "<<get3(6, 7, 8)<<endl;
			}
		}
	}while(next_permutation(dic, dic + 9));

	if (!flag) puts("No!!!");

	return 0;
}
