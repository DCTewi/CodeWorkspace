#include <bits/stdc++.h>
using namespace std;

int main()
{
    double p, q; cin >> p >> q;

    cout << fixed << setprecision(8) 
    << (p * p + q * q) / (100 * (p + q)) << "\n";

    return 0;
}