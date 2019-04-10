/*

-2 <<
-1
+2 <<
+2
+1 <
-1 <
-1

+1
+2
+3
0

0 <
0 <
())(()
)())
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int n, maxw = 0, tot = 0;
string str[MAXN];
map<int, int> weigh;

int getWei(string s)
{
	int ans = 0, flag = 0;
	stack<int> st;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(') st.push(1);
		if (s[i] == ')')
		{
			if (st.size() > 0)
			{
				st.pop();
			}
			else
			{
				flag = 1;
				ans--;
			}
		}
	}
	if (flag && st.size()) ans = 5e6;
	else
	{
		ans += st.size();
		if (ans >= maxw) maxw = ans;
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin>>str[i];
		weigh[getWei(str[i])]++;
	}

	tot += weigh[0] / 2;
	for (int i = 1; i <= maxw; i++)
	{
		while (weigh.count(-i) && weigh.count(i) && weigh[i] > 0 && weigh[-i] > 0)
		{
			weigh[i]--;
			weigh[-i]--;
			tot++;
		}
	}

	printf("%d\n", tot);
	return 0;
}