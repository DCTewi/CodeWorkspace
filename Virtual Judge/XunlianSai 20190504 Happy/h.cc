#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    ios::sync_with_stdio(0);
    
    ll maxn = 0, n = 0; cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll temp; cin >> temp;
        maxn = max(maxn, temp);
    }

    int now = 1;
    while (now < maxn)
    {
        now = 2 * now + 1;
    }

    now == maxn? cout << "Mike\n": cout << "Constantine\n";

    return 0;
}