//G
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);

    int T; cin >> T;
    while (T--)
    {
        int n; cin >> n;
        if (n % 4 == 0) n++;
        while ((n % 7))
        {
            n++;
            if (n % 4 == 0)
            {
                n++;
            }
        }
        cout<<n<<"\n";
    }

    return 0;
}