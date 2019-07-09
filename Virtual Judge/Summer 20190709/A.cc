// A Yougurt Factory
#include <iostream>
using namespace std;
typedef long long ll;

const int MAXN = 1e4 + 5;

ll n, s, ans = 0;
ll y[MAXN], c[MAXN];

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i] >> y[i];
    }
    
    ll price = c[0];
    for (int i = 0; i < n; i++)
    {
        price = min(price + s, c[i]);
        ans += price * y[i];
    }

    cout << ans << "\n";

    return 0;
}