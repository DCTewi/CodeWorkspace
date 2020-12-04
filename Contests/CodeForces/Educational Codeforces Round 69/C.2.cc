#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 3e6 + 5;
int n, k;
ll a[MAXN], ans = 0;

int main()
{
    ios::sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ans = a[n - 1] - a[0];

    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (int i = 0; i < n - 1; i++)
    {
        q.emplace(a[i] - a[i + 1]);
    }
    for (int i = 0; i < k - 1 && q.size(); i++)
    {
        ans += q.top(); q.pop();
    }
    cout << ans << "\n";

    return 0;
}
