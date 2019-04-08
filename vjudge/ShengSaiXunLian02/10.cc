//H
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m,n;
int p[10004];
int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    int t;
    for (int i=0;i<n; ++i) {
        cin >> t;
        p[t]=i;
    }
    
    int ans = 0;
    for (int i=0; i<m;++i) {
        int a,b;
        cin >> a >> b;
        int d = abs(p[a]-p[b])-1;
        if (d%2 || (n-d+2)%2)++ans;
    
    }
    cout << ans;

}
