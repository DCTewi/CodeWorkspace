// WA2
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
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

        int l = -(1 << 30), r = 1 << 30, up = -(1 << 30), down = 1 << 30;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= 4; j++)
            {
                if (!rob[i].f[j])
                {
                    switch (j)
                    {
                    case 1:
                        up = max(up, rob[i].x);
                        break;
                    case 2:
                        l = max(l, rob[i].y);
                        break;
                    case 3:
                        down = min(down, rob[i].x);
                        break;
                    case 4:
                        r = min(r, rob[i].y);
                        break;
                    default:
                        break;
                    }
                }
            }
            // cout << "==>" << l <<" " << r << " " << up << " " << down << "\n";
        }
        if (l > r || up > down)
        {
            cout << "0\n";
        }
        else 
        {
            cout << "1 " << up << " " << l << "\n";
            // cout << "1 " << down << " " << r << "\n";
        }
    }

    return 0;
}
