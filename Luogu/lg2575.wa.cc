// wa 40
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);

    int T; cin >> T;
    while (T--)
    {
        int n, sum = 0; cin >> n;
        for (int i = 0; i < n; i++)
        {
            int num; cin >> num;
            for (int j = num - 1; j >= 0; j--)
            {
                int t; cin >> t;
                sum += 20 - t - j;
                //cout << j << " " << "added - "<<20 - t + j<<"\n";
            }
        }

        //cout << "sum = " << sum << "\n";

        if (sum & 1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}