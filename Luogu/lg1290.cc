#include <bits/stdc++.h>
using namespace std;

bool sg(int n, int m)
{
    if (!m) return false;
    if (n / m == 1) return !sg(m, n % m);
    else return true;
}

int main()
{
    ios::sync_with_stdio(0);

    int T; cin >> T;
    while (T--)
    {
        int n, m; cin >> n >> m;

        if (sg(max(n, m), min(n, m)))
        {
            puts("Stan wins");
        }
        else
        {
            puts("Ollie wins");
        }
    }
    return 0;
}