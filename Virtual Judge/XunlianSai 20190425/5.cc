// c
#include <bits/stdc++.h>
using namespace std;

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
int hurt[MAXN], f[MAXN][MAXN];
int ans = 1 << 20;

void dfs(int usec)
{
    if (usec > c)
    {
        ans = min(f[])
    }
}

int main()
{
    ios::sync_with_stdio(0); 

    cin >> n >> k >> c;;
    for (int i = 0; i < n; i++)
    {
        int d, x; cin >> monster[i].hp >> monster[i].atk;
    }

    sort(monster, monster + n, [](Monster a, Monster b) -> bool
    {
        if (a.atk == b.atk) return a.hp < b.hp;
        return a.atk > b.atk;
    });

    for (int i = 0; i < n; i++)
    {
        if (monster[i].hp > k)
        {
            int rnd = monster[i].hp / k + (monster[i].hp % k != 0);
            hurt[i] = (rnd - 1) * monster[i].atk;
        }
    }

    dfs(1);

    return 0;
}