//D
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll s[200005];
ll sum = 0;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;
    int t;
    for (int i=1; i<=n; ++i) {
        cin >> t;
        sum += t;
        s[i] = sum;
    }
    //cout << sum << endl;
    ll sans = 0, ans = 0;
    for (int i=1; i<=n; ++i) {
        ans = 0;
        for (int j=i+1; j<=n; ++j) {
            ans +=min(s[j-1]-s[i-1], sum-s[j-1]+s[i-1]);
            //cout << i << ' ' << j << " " <<  min(s[j-1]-s[i-1], sum-s[j]+s[i-1]) << endl;
        }
        sans += ans;
        cout << ans << endl;
    }
    cout << sans;
    
    return 0;
}
