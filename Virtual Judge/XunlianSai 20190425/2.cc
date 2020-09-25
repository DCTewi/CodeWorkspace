// c tle
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
int n, k, c;
struct Monster
{
    int hp, atk;

    Monster(int d = 0, int x = 0)
    {
        this->hp = d; this->atk = x;
    }

}monster[MAXN];
int ans = 1 << 20, hurt = 0, lef = 0;

void dfs(int now)
{
    if (now >= n)
    {
        ans = min(ans, hurt);
        return;
    }

    auto &u = monster[now];
    while (u.hp > 0)
    { 
        int cost = min(lef, u.hp > k? u.hp / k + (u.hp % k != 0): 0);
        //cout<<u.hp<<" "<<cost<<"\n";

        u.hp -= (cost + 1) * k;
        lef -= cost;

        int thurt = u.hp > 0? u.atk: 0;
        hurt += thurt;
    }

    dfs(now + 1);
}

int main()
{
    ios::sync_with_stdio(0); 

    cin >> n >> k >> c; lef = c;
    for (int i = 0; i < n; i++)
    {
        int d, x; cin >> monster[i].hp >> monster[i].atk;
    }
    
    sort(monster, monster + n, [](Monster a, Monster b) -> bool
    {
        if (a.atk == b.atk) return a.hp < b.hp;
        return a.atk > b.atk;
    });

    dfs(0);

    cout<<ans<<"\n";

    return 0;
}
