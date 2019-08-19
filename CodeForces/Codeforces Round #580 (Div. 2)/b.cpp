#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
ll n;
ll a[MAXN];
ll n0 = 0, nneg = 0, ans = 0;

int main()
{
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 0) n0++;
        else if (a[i] < 0) nneg++;
        ans += abs(1 - a[i]);
    }

    if (nneg != 0){
    if (nneg % 2 == 0)
    {
        ans -= nneg * 2;
    }
    else if (n0 > 0)
    {
        ans -= nneg * 2;
    }
    else
    {
        ans -= (nneg - 1) * 2;
    }}
    cout << ans << "\n";

    return 0;
}
