// c wa3
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define INT int32_t

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
    int cost = min(lef, u.hp > k? u.hp / k + (u.hp % k != 0): 0);
    int dmgmax = (cost + 1) * k;
    u.hp -= dmgmax;
    lef -= cost;
    // cannot one turn kill
    if (u.hp > 0)
    {
        int rond = u.hp / k + (u.hp % k != 0);
        hurt += rond * u.atk;
    }

    dfs(now + 1);
}

INT main()
{
    ios::sync_with_stdio(0); 

    cin >> n >> k >> c; lef = c;
    for (int i = 0; i < n; i++)
    {
        int d, x; cin >> monster[i].hp >> monster[i].atk;
    }
/*
    sort(monster, monster + n, [](Monster a, Monster b) -> bool
    {
        if (a.atk == b.atk) return a.hp < b.hp;
        return a.atk > b.atk;
    });
*/
    dfs(0);

    cout<<ans<<"\n";

    return 0;
}
