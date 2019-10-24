#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 5;

int d, g;
struct Trash
{
    int time, full, height;

    Trash (int time = 0, int full = 0, int height = 0)
    {
        this->time = time; this->full = full; this->height = height;
    }

}food[MAXN];
int ans = 1 << 20, sur = 0;
int hp = 10;

void dfs(int now, int h)
{
    if (h >= d)
    {
        //cout<<"now = "<<now<<" h = "<<h<<endl;
        ans = min(ans, food[now - 1].time);
        return;
    }
    if (ans != 1 << 20) return;
    if (now >= g) return;
    if (hp < food[now].time)
    {
        sur = max(sur, hp);
        return;
    }

    // Eat this
    hp += food[now].full;

    dfs(now + 1, h);

    hp -= food[now].full;

    // Put this

    dfs(now + 1, h + food[now].height);

}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>d>>g;
    for (int i = 0; i < g; i++)
    {
        cin>>food[i].time>>food[i].full>>food[i].height;
    }

    sort(food, food + g, [](Trash a, Trash b)->bool
    {
        return a.time < b.time;
    });

    if (food[0].time > 10) return 0 * puts("10");
    else
    {
        sur = 10;
        dfs(0, 0);
    }

    if (ans == 1 << 20)
    {
        //puts("Dead");
        cout<<sur<<"\n";
    }
    else
    {
        //puts("Survived!");
        cout<<ans<<"\n";
    }

    return 0;
}