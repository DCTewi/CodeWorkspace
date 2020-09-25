// 读错题了，，语言不通还是难受
#include <bits/stdc++.h>
using namespace std;

vector<pair<string, int>> v;

int main()
{
    ios::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s; int t;
        cin >> s >> t;
        v.emplace_back(make_pair(s, t));
    }

    sort(v.begin(), v.end(), [](pair<string, int> a, pair<string, int> b)
    {
        return a.second > b.second;
    });

    for (int i = 0; i < v.size() && v[i].second == v[0].second; i++)
    {
        cout << v[i].first << "\n";
    }

    return 0;
}
