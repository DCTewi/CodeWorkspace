#include<bits/stdc++.h>

using namespace std;
typedef long long LL;


int n;
LL l=1e7,t=1e7,r=-1e7,b=-1e7;
int x[1003], y[1003];
LL inc;
int main() {
    freopen("intel.in", "r", stdin);
    freopen("intel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> x[i] >> y[i];
        if (x[i]<l) l=x[i];
        if (x[i]>r) r=x[i];
        if (y[i]<t) t=y[i];
        if (y[i]>b) b=y[i];
    }
    for (int i=0; i<n-1; ++i) inc += abs(x[i]-x[i+1] + y[i]-y[i+1]);
    inc += abs(x[n-1]-x[0]+y[n-1]-y[0]);


    cout << inc-(r-l+b-t)*2;
}
