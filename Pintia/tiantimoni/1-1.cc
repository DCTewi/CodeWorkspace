#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while (!isdigit(ch))
	{
		w |= ch == '-'; ch = getchar();
	}
	while (isdigit(ch))
	{
		x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();
	}
	return w? -x: x;
}

const int MAXN = 1e2 + 5;
map<int, int> s;
map<int, int> outed;

int main()
{
    int n; cin>>n;
    for (int i = 0; i < n; i++)
    {
        int k; cin>>k;
        map<int, bool> temp;
        for (int j = 0; j < k; j++)
        {
            int t; cin>>t;
            temp[t] = true;
        }
        if (temp.size() > 1)
        {
            for (auto it : temp)
            {
                s[it.first]++;
            }
        }
    }
    int m; cin>>m;
    int first = 1;
    for (int i = 0; i < m; i++)
    {
        int t; cin>>t;
        if (s.count(t) == 0)
        {
            if (outed.count(t) == 0)
            {
				if (!first) cout<<" ";
                cout<<t;
                outed[t] = 1;
            }
			if (first == 1)
            {
                first = 0;
            }

        }
    }
    if (first)
    {
        puts("No one is handsome");
    }
    return 0;
}
