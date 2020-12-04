#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;

    int sum = 0;
    for (int i = 0; i < 15; i++)
    {
        if (a[i] == '1' && b[i] == '0')
        {
            sum++;
        }
    }

    if (sum > m || sum * n > 30)
    {
        cout << "Oh my God\n";
    }
    else
    {
        cout << 70 - (50 - sum * n) << "\n";
    }
    
    return 0;
}