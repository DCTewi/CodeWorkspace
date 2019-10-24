#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> tr;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll opt, x; cin >> opt >> x;
        switch (opt)
        {
            case 1:
            {
                // Add
                tr.insert(upper_bound(tr.begin(), tr.end(), x), x);
            }
            break;
            case 2:
            {
                // Del
                tr.erase(lower_bound(tr.begin(), tr.end(), x));
            }
            break;
            case 3:
            {
                // Get rank
                cout << lower_bound(tr.begin(), tr.end(), x) - tr.begin() + 1 << "\n";
            }
            break;
            case 4:
            {
                //Get kth
                cout << tr[x - 1] << "\n";
            }
            break;
            case 5:
            {
                // Get Prev
                cout << *--lower_bound(tr.begin(), tr.end(), x) << "\n";
            }
            break;
            case 6:
            {
                // Get Next
                cout << *upper_bound(tr.begin(), tr.end(), x) << "\n";
            }
            break;
            default: break;
        }
    }
    return 0;
}