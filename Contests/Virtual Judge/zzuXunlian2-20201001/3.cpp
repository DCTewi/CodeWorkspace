#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

string s;
bool hit[1000006];
int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> s;
        if (s.length() < 8)  {
            int x = stoi(s);
            if (x <= 1000003 && x >= 0) hit[x] = 1;
        }
        
    }
    for (int i=0; i<=n+1; ++i) {
        if (!hit[i]) {
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}