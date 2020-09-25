#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e4 + 5;

map<int, int> times;
map<int, priority_queue<int, vector<int>, less<int>>> vals;
int ans[MAXN];

inline void get_yinshu(int x)
{
    for (int i = 1; i <= int(sqrt(x)); i++)
    {
        if (x % i == 0)
        {
            times[i]++;
            if (x / i != i) times[x / i]++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);

    int n; cin>>n;

    for (int i = 0; i < n; i++)
    {
        int temp; cin>>temp;
        get_yinshu(temp);
    }

    for (auto &x : times)
    {
        vals[x.second].push(x.first);
    }

    for (int i = n; i >= 1; i--)
    {
        ans[i] = max(ans[i + 1], vals[i].empty()? 0: vals[i].top());
    }
    
    for (int i = 1; i <= n; i++)
    {
        cout<<ans[i]<<endl;
    }

    return 0;
}
