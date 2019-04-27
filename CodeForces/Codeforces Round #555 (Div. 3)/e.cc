#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int ha = 998244353;
const int N = 1e6 + 5;

int A[N];

int main()
{
    multiset<int> S;
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> A[i];
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        S.insert(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        auto it = S.lower_bound(n - A[i]);
        auto it2 = S.lower_bound(0);
        if (it == S.end())
        {
            printf("%d ", (A[i] + *it2) % n);
            S.erase(it2);
            continue;
        }
        else
        {
            printf("%d ", (A[i] + *it) % n);
            S.erase(it);
            continue;
        }
    }
    puts("");
    return 0;
}