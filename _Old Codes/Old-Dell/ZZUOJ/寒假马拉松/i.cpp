#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
map<char, vector<char> > maps;
string n;
int k;
int ans[MAXN], cnt[MAXN];

void dfs(char x)
{
    cnt[x - '0'] = 1;
    for (int i = 0; i < maps[x].size(); i++)
    {
        if (!cnt[maps[x][i] - '0'])
        {
            dfs(maps[x][i]);
        }
    }
    return ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for (int i = 0; i < k; i++)
    {
        char x, y;
        cin>>x>>y;
        maps[x].push_back(y);
    }
    ans[0] = 1;

    for (int i = 0; i < n.size(); i++)
    {
        memset(cnt, 0, sizeof(cnt));
        dfs(n[i]);
        int sum = 0;
        for (int i = 0; i < 10; i++)
        {
            sum += cnt[i];
        }
        int add = 0;
        for (int i = 0; i < 100; i++)
        {
            ans[i] = ans[i] * sum + add;
            add = ans[i] / 10;
            ans[i] %= 10;
        }
    }

    int top = 99;
    while (top && !ans[top])top--;
    while (top >= 0)
    {
        cout<<ans[top--];
    }
    cout<<endl;

    return 0;
}