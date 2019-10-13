#include<bits/extc++.h>
#include<bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

struct team {
    int sol, p, inx;
} ts[100005];


struct cmp {
    bool operator()(team &t1, team &t2) {
        if (t1.sol!=t2.sol) return t1.sol>t2.sol;
        else if (t1.p != t2.p) return t1.p < t2.p;
        else return t1.inx < t2.inx;
    }
};


tree<team, null_type, cmp , rb_tree_tag, tree_order_statistics_node_update> rbt;
int n, m;
int t, p;

int main() {
    ios::sync_with_stdio(0);

    for (int i=1; i<=n; ++i) ts[i].inx = i;

    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        cin >> t >> p;

    }
}
