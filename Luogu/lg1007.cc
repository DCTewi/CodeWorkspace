#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e3 + 5;
int l, n;
int minans = 0, maxans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin >> l >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        minans = max(minans, min(l - tmp + 1, tmp));
        maxans = max(maxans, max(l - tmp + 1, tmp));
    }

    cout << minans << " " << maxans << "\n";

    return 0;
}
