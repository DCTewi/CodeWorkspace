//L WA
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e3 + 10;
const int DAY = 2e3 + 8;

int m, n, w, h;

struct People
{
    int ind = 0, sum = 0;

    People(int i = 0, int s = 0)
    {
        this->ind = i; this->sum = s;
    }

    bool operator<(const People &o) const
    {
        if (this->sum == o.sum) return this->ind < o.ind;
        return this->sum < o.sum;
    }
    bool operator>(const People &o) const
    {
        if (this->sum == o.sum) return this->ind < o.ind;
        return this->sum > o.sum;
    }
}worker[MAXN];

vector<int> ans[MAXN];

/* Tree array begin */

int c[MAXN][MAXN];

inline int lowbit(int i)
{
	return i & (-i);
}

void ADD(int per, int p, int delta)
{
	for (; p <= n; p += lowbit(p))
	{
		c[per][p] += delta;
	}
}

int query(int per, int p)
{
	int ans = 0;
	for (; p > 0; p -= lowbit(p))
	{
		ans += c[per][p];
	}
	return ans;
}

inline void add(int per, int l, int r, int delta)
{
    ADD(per, l, delta);
    ADD(per, r + 1, -delta);
}

/* Tree array end */

bool solve()
{
    for (int d = 1; d <= n; d++) // Per day
    {
        sort(worker + 1, worker + 1 + m, [](People a, People b)->bool{return a > b;});
        int day = query(DAY, d);
        add(DAY, d, d + w - 1, -day);
        while (0 < day--) // Select workers
        {
            // Select the worker who is free and have max sum left
            int u = -1;
            for (int i = 1; i <= m; i++)
            {
                if (!query(worker[i].ind, d) && worker[i].sum > 0)
                {
                    u = i; break;
                }
            }

            cout<<"Selected "<<worker[u].ind<<" to work at Day "<<d<<" left "<<worker[u].sum<<endl;

            // If no one selected
            if (u == -1) return false;

            // Mark the days which the worker used
            add(worker[u].ind, d, d + w + h - 1, 1);
            worker[u].sum -= w;
            ans[worker[u].ind].push_back(d);
        }
        
        cout<<"\t\tDays wanna: ";
        for (int i = 1; i <= n; i++)
        {
            cout<<query(DAY, i)<<" ";
        }
        cout<<endl;
        
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>m>>n>>w>>h;

    for (int i = 1; i <= m; i++)
    {
        worker[i].ind = i;
        cin>>worker[i].sum;
    }
    for (int i = 1; i <= n; i++)
    {
        int d; cin>>d;
        add(DAY, i, i, d);
    }

    if (solve())
    {
        puts("1");
        for (int i = 1; i <= m; i++)
        {
            for (auto &it : ans[i])
            {
                cout<<it<<((i == m)? "\n": " ");
            }
            cout<<endl;
        }
    }
    else
    {
        puts("-1");
    }

    return 0;
}
