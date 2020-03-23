#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T> T read()
{
    T x = 0; int ch = getchar(), w = 0;
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w ? -x : x;
}

const int FACT[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
long long cantor(const vector<int> &a)
{
    long long res (0);
    int len (a.size());
    for (int i = 0; i < len; i++)
    {
        int num = 0;
        for (int j = i + 1; j < len; j++)
        {
            if (a[j] < a[i]) num++;
        }
        res += FACT[len - i - 1] * num;
    }
    return res;
}
vector<int> decantor(int x, int n)
{
    vector<int> vis, res;
    for (int i = 0; i <= n; i++) vis.emplace_back(i + 1);
    for (int i = n - 1; i >= 0; i--)
    {
        int now = x / FACT[i];
        x %= FACT[i];

        res.emplace_back(vis[now]);
        vis.erase(vis.begin() + now);
    }
    return res;
}

const int MAXN = 362880 + 5; // hash of 876543210
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const char op[] = "udlr";

struct State
{
    string path; 
    int hash, pos0;
} now, net;
string path[MAXN];
int vis[MAXN];
vector<int> nowpath(9);
int ans = 46324; // hash of 123456780

void bfs()
{
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < 8; i++) nowpath[i] = i + 1;

    now.pos0 = 8; now.hash = ans; now.path = "";
    path[ans] = "";
    queue<State> q;
    vis[ans] = 1; q.push(now);
    while (q.size())
    {
        now = q.front(); q.pop();
        for (int i = 0; i < 4; i++)
        {
            int tx = now.pos0 / 3 + dx[i];
            int ty = now.pos0 % 3 + dy[i];
            if (tx >= 0 && tx <= 2 && ty >= 0 && ty <= 2)
            {
                net = now;
                net.pos0 = tx * 3 + ty;
                nowpath = decantor(now.hash, 9);
                swap(nowpath[now.pos0], nowpath[net.pos0]);
                net.hash = cantor(nowpath);

                if (!vis[net.hash])
                {
                    vis[net.hash] = 1;
                    net.path += op[i];
                    q.push(net);
                    path[net.hash] = net.path;
                }
            }
        }
    }
}

int main()
{
    bfs();
    char ch;
    while (cin >> ch)
    {
        if (ch == 'x')
        {
            now.pos0 = 0; nowpath[0] = 0;
        }
        else
        {
            nowpath[0] = ch - '0';
        }
        for (int i = 1; i <= 8; i++)
        {
            cin >> ch;
            if (ch == 'x')
            {
                now.pos0 = 0; nowpath[i] = 0;
            }
            else
            {
                nowpath[0] = ch - '0';
            }
        }
        now.hash = cantor(nowpath);
        if (!vis[now.hash]) puts("unsolvable");
        else printf("%s\n", path[now.hash].c_str());
    }
    return 0;
}
