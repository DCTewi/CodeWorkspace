#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 35;

int l, r, c;
size_t tmp;
string tile[MAXN][MAXN];
struct Node
{
    int l = -1, r = -1, c = -1;
}s, e;

int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    while (cin >> l >> r >> c)
    {
        if (!(l || r || c)) return 0;
        s = e = (Node){-1, -1, -1};

        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                cin >> tile[i][j];
                if (!~(s.l) && ((tmp = tile[i][j].find_first_of('S')) != string::npos))
                {
                    s = (Node){i, j, (int)tmp};
                }
                if (!~(e.l) && ((tmp = tile[i][j].find_first_of('E')) != string::npos))
                {
                    e = (Node){i, j, (int)tmp};
                }
            }
        }

        cout << s.l <<","<<s.r<<","<<s.c<<" - "<<e.l << "," << e.r << "," << e.c << "\n";
    }
    return 0;
}
