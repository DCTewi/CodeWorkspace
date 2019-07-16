// G - Circle
#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(0);
    while (cin >> n)
    {
        double s1 = n * sin(2 * M_PI / (double)n) / 2.0;
        double s2 = // (2.0 * sin(M_PI  / (2.0 * n))) * (1.0 - cos(M_PI / (2.0 * n)));
        cout << fixed << setprecision(6) << s1 + s2 << "\n";
    }
    return 0;
}
