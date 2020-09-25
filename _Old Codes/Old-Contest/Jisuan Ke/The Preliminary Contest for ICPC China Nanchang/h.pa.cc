#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e9 + 5;

int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};

struct Path
{
    map<pair<int, int>, bool> paths;

    bool operator==(Path &o)
    {
        if (paths.size() != o.paths.size()) return false;

        int len = 0;
        for (auto &x : paths)
        {
            if (o.paths.count(x.first))
            {
                len++;
            }
        }
        if (len == paths.size()) return true;
        return false;
    }
};

vector<Path> path;
int vis[10][10];
int ans = 0;

int n = 0;
Path temppath;

void dfs(int x, int y)
{
    if (x == n && y == n)
    {
        int flag = 1;
        for (int i = 0; i < path.size(); i++)
        {
            if (path[i] == temppath) return;
        }
        for (auto &x : temppath.paths)
        {
            if (x.first == make_pair(1, 1))
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            path.push_back(temppath);
            ans++;
        }
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx > 0 && ny > 0 && nx <= n && ny <= n && !vis[nx][ny])
        {
            vis[nx][ny] = 1;
            temppath.paths[make_pair(nx, ny)] = true;
            dfs(nx, ny);
            temppath.paths.erase(make_pair(nx, ny));
            vis[nx][ny] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);

    puts("n:");
    cin>>n;

    dfs(1, 1);

    for (int i = 0; i < path.size(); i++)
    {
        for (auto &x : path[i].paths)
        {
            cout<<x.first.first<<","<<x.first.second<<" ";
        }
        cout<<endl;
    }

    cout<<ans<<endl;
    return 0;
}