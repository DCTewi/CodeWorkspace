#include <bits/stdc++.h>
using namespace std;

const int MAXD = 1e2 + 5;
const int MAXN = 3e3 + 5;

int d, g;
struct Trash
{
    int time, full, height;

    Trash (int time = 0, int full = 0, int height = 0)
    {
        this->time = time; this->full = full; this->height = height;
    }

}food[MAXD];
int f[MAXD][MAXN]; // f[ith food][height] = max hp

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>d>>g;
    for (int i = 1; i <= g; i++)
    {
        cin>>food[i].time>>food[i].full>>food[i].height;
    }

    sort(food + 1, food + g + 1, [](Trash a, Trash b)->bool
    {
        if (a.time == b.time) return a.height < b.height;
        return a.time < b.time;
    });

    //if (food[0].time > 10) return 0 * puts("10");

    f[0][0] = 10;

    for (int i = 1; i <= g; i++)
    {
        for (int j = 0; j <= d; j++)
        {
            // Eat this
            if (f[i - 1][j] >= food[i].time) // Can get food[i] alive
            {
                f[i][j] = max(f[i][j], f[i - 1][j] + food[i].full);
            }
            // Put this
            if (j - food[i].height >= 0 && f[i - 1][j - food[i].height] >= food[i].time) // Can alive
            {
                f[i][j] = max(f[i][j], f[i - 1][j - food[i].height]);
            }
        }
    }

    int maxh = 0, maxt = 0;

    for (int i = 1; i <= g; i++)
    { 
        for (int j = 0; j <= d; j++)
        {
            if (f[i][j] >= food[i].time)
            {
                maxh = max(maxh, j);
            }
            maxt = max(maxt, f[i][j]);
        }
        if (maxh == d)
        {
            cout<<food[i].time<<"\n";
            return 0;
        }
    }

    cout<<maxt<<"\n";

    return 0;
}
