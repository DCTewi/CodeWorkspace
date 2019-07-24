#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
const int INF = 1 << 30;
int n;
struct Robo
{
    int x, y;
    bool f[5];
} rob[MAXN];

int main()
{
    ios::sync_with_stdio(0);

    int T; cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> rob[i].x >> rob[i].y;
            for (int j = 1; j <= 4; j++)
            {
                cin >> rob[i].f[j];
            }
        }
        if (n == 1)
        {
            cout << "1 " << rob[1].x << " " << rob[1].y << "\n";
            continue;
        }

        int up = -INF, down = INF, l = -INF, r = INF;
        for (int i = 1; i <= n; i++)
        {
            Robo &now = rob[i];
            if (!now.f[1])
            {
                up = max(up, now.x);
            }
            if (!now.f[2])
            {
                r = min(r, now.y);
            }
            if (!now.f[3])
            {
                down = min(down, now.x);
            }
            if (!now.f[4])
            {
                l = max(l, now.y);
            }
        }
        if (up > down || l > r)
        {
            cout << "0\n";
        }
        else
        {
            cout << "1 " << ((up == -INF)? -100000: up) << " " << ((l == -INF)? -100000: l) << "\n";
        }
    }
    return 0;
}
