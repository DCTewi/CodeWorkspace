#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T> T read()
{
    T x = 0; int ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
} 

const int MAXN = 1e5 + 5;

int n, k;

struct Node
{
    int id, father, len, max_son = 0, max_len = 0;
    vector<int> sons, newroots;
} node[MAXN] ;

struct nodecmp
{
    bool operator()(const int &a, const int &b)
    {
        return node[a].len < node[b].len;
    }
};

void add_len(int bot)
{
    while (bot)
    {
        node[bot].len++;
        if (node[node[bot].father].max_len >= node[bot].len) return;
        else
        {
            node[node[bot].father].max_len = node[bot].len;
            node[node[bot].father].max_son = bot;
            bot = node[bot].father;
        }
    }
}

void dfs(int now)
{
    if (!node[now].max_son) return;

    for (auto son : node[now].sons)
    {
        if (son == node[now].max_son)
        {
            dfs(son);
            for (auto root : node[son].newroots)
            {
                node[now].newroots.emplace_back(root);
            }
        }
        else
        {
            node[now].newroots.emplace_back(son);
        }
    }
}

int main()
{
    n = read<int>(), k = read<int>();

    for (int i = 2; i <= n; i++)
    {
        node[i].id = i;
        node[i].father = read<int>();
        node[node[i].father].sons.emplace_back(i);
    }
    for (int i = 2; i <= n; i++)
    {
        add_len(i);
    }
    node[1].id = 1; node[1].len++;

    dfs(1);

    int ans = 0;
    priority_queue<int, vector<int>, nodecmp> q; q.push(1);
    for (int t = 0; t < k && q.size() && ans <= n; t++)
    {
        auto now = q.top(); q.pop();
        //printf("Kicked %d, ", node[now].id);
        ans += node[now].len;

        for (int son : node[now].newroots)
        {
            q.push(son);
            //printf("%d ", son);
        }
        //printf("is new root.\n");
    }

    printf("%d\n", ans);

    return 0;
}

