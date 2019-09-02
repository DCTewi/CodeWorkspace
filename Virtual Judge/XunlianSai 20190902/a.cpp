#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 35;
const int MAXQ = 55;

int x, y, q;

struct Tile
{
    char dir, value;
}tile[MAXN][MAXN];

string opt[MAXQ];

map<char, vector<char>> edge;

int main()
{
    ios::sync_with_stdio(0);
    cin >> x >> y;

    for (int i = 0; i < x; i++)
    {
        string tmp; cin >> tmp;
        for (int j = 0; j < y; j++)
        {
            tile[i][j].dir = tmp[j];
        }
    }
    for (int i = 0; i < x; i++)
    {
        string tmp; cin >> tmp;
        for (int j = 0; j < y; j++)
        {
            tile[i][j].value = tmp[j];
        }
    }
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        cin >> opt[i];
    }

    build_edges();

    return 0;
}
