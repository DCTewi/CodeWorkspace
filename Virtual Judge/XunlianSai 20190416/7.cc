#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int MAXN = 3E2 + 5;
int t, n;
int ans = 0, now = 0;

map<int, vector< pair<char, int> > > d;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>t>>n;
    for (int i = 0; i < n; i++)
    {
        char ch; int a, r;
        cin>>ch>>a>>r;
        d[a].push_back(make_pair(ch, r));
    }

    for (auto &x : d) // per time
    {
        if (x.second.size() > 1)
        {
            sort(x.second.begin(), x.second.end(), [](pair<char, int> a, pair<char, int> b)->bool
            {
                return a.second < b.second;
            });
        }
    }

    for (auto &x : d) // per time
    {
        
    }

    cout<<ans<<endl;

    return 0;
}