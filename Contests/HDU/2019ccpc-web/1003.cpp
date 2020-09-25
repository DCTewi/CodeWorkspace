#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct State
{
    bool is_clone = 0;
    int first_pos;
    vector<int> inv_link;
    int len, link;
    map<char, int> next;
};

const int MAXLEN = 1e5;
State st[MAXLEN << 1];
int sz, last;
int cnt[MAXLEN << 1];

void sam_init()
{
    st[0].len = 0; st[0].link = -1;
    sz = 1; last = 0;
}

void sam_extend(char c)
{
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    st[cur].first_pos = st[cur].len - 1;
    int p = last;
    while (~p && !st[p].next.count(c))
    {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (!~p)
    {
        st[cur].link = 0;
    }
    else
    {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len)
        {
            st[cur].link = q;
        }
        else
        {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            st[clone].first_pos = st[q].first_pos;
            st[clone].is_clone = 1;
            while (~p && st[p].next[c] == q)
            {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
    for (int v = 1; v < sz; v++) st[st[v].link].inv_link.emplace_back(v);
}

void all_occur(int v, int P_len)
{
    if (!st[v].is_clone) cout << st[v].first_pos - P_len + 1 << "\n";
    for (int u : st[v].inv_link) all_occur(u, P_len);
}

int read()
{
    int x = 0; char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{
    int T = read();
    while (T--)
    {
        string s; cin >> s;
        sam_init();
        for (int i = 0; i < (int)s.size(); i++)
        {
            sam_extend(s[i]);
        }

        for (int i = 0; i < sz; i++)
        {
            printf("\t[%d]:%s- first:%d, len:%d, link:%d\n",i, st[i].is_clone?"clone":"orig", st[i].first_pos,
                    st[i].len, st[i].link);
            printf("\t\tInv_link: ");
            for (auto j : st[i].inv_link) printf("%d ", j); printf("\n");
            printf("\t\tNext: ");
            for (auto j : st[i].next) printf("%c->%d ", j.first, j.second); printf("\n");
        }
        //all_occur(1, 3);
    }
}



