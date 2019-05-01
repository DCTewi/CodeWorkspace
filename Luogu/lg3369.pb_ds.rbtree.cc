#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> rbtree;

const int Offset = 20;

rbtree tr;

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
                tr.insert((x << Offset) + i);
            }
            break;
            case 2:
            {
                // Del
                tr.erase(tr.lower_bound(x << Offset));
            }
            break;
            case 3:
            {
                // Get rank
                cout << tr.order_of_key(x << Offset) + 1 << "\n";
            }
            break;
            case 4:
            {
                //Get kth
                cout << (*tr.find_by_order(x - 1) >> Offset) << "\n";
            }
            break;
            case 5:
            {
                // Get Prev
                cout << (*--tr.lower_bound(x << Offset) >> Offset) << "\n";
            }
            break;
            case 6:
            {
                // Get Next
                cout << (*tr.lower_bound((x + 1) << Offset) >> Offset) << "\n";
            }
            break;
            default: break;
        }
    }
    return 0;
}