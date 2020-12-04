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
    vector<int> sons;
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

inline vector<int> get_new_root(int top)
{
    vector<int> res = node[top].sons;
    while (node[top].max_son)
    {
        top = node[top].max_son;
        for (int son : node[top].sons)
        {
            if (son == node[top].max_son) continue;
            res.emplace_back(son);
        }
    }
    return res;
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

    int ans = 0;
    priority_queue<int, vector<int>, nodecmp> q; q.push(1);
    for (int t = 0; t < k && q.size() && ans <= n; t++)
    {
        auto now = q.top(); q.pop();
        //printf("Kicked %d, ", node[now].id);
        ans += node[now].len;

        auto newroot = get_new_root(now);
        for (int son : newroot)
        {
            if (son == node[now].max_son) continue;
            q.push(son);
            //printf("%d ", son);
        }
        //printf("is new root.\n");
    }

    printf("%d\n", ans);

    return 0;
}
