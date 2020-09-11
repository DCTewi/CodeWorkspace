#include <bits/stdc++.h>

#define NS (250005)
#define LGS (18)

using namespace std;

typedef long long LL;

template <typename _Tp>
inline void IN(_Tp& dig) {
    char c;
    bool flag = 0;
    dig = 0;
    while (c = getchar(), !isdigit(c))
        if (c == '-') flag = 1;
    while (isdigit(c)) dig = dig * 10 + c - '0', c = getchar();
    if (flag) dig = -dig;
}

struct graph {
    int head[NS], nxt[NS << 1], to[NS << 1], w[NS << 1], sz;
    void init() { memset(head, -1, sizeof(head)), sz = 0; }
    graph() { init(); }
    void push(int a, int b, int c) {
        nxt[sz] = head[a], to[sz] = b, w[sz] = c, head[a] = sz++;
    }
    int& operator[](const int a) { return to[a]; }
} g;

int n, pre[NS][LGS + 1], dep[NS], mx[NS][LGS + 1], id[NS], dfn;

int m, k, h[NS], sta[NS], top, MX;

LL f[NS];

bool book[NS];

void Init(int a, int fa) {
    pre[a][0] = fa, dep[a] = dep[fa] + 1, id[a] = ++dfn;
    for (int i = 1; i <= LGS; i += 1) {
        pre[a][i] = pre[pre[a][i - 1]][i - 1];
        mx[a][i] = min(mx[a][i - 1], mx[pre[a][i - 1]][i - 1]);
    }
    for (int i = g.head[a]; ~i; i = g.nxt[i])
        if (g[i] != fa) mx[g[i]][0] = g.w[i], Init(g[i], a);
}

int lca(int a, int b) {
    MX = INT_MAX;
    if (dep[a] > dep[b]) swap(a, b);
    for (int i = LGS; i >= 0; i -= 1)
        if (dep[pre[b][i]] >= dep[a]) MX = min(MX, mx[b][i]), b = pre[b][i];
    if (a == b) return a;
    for (int i = LGS; i >= 0; i -= 1)
        if (pre[a][i] != pre[b][i]) {
            MX = min(MX, min(mx[a][i], mx[b][i]));
            a = pre[a][i], b = pre[b][i];
        }
    return pre[a][0];
}

bool cmp(int a, int b) { return id[a] < id[b]; }

void Dp(int a) {
    f[a] = 0;
    for (int i = g.head[a]; ~i; i = g.nxt[i]) {
        Dp(g[i]);
        if (book[g[i]])
            f[a] += g.w[i];
        else
            f[a] += min((LL)g.w[i], f[g[i]]);
    }
}

int main(int argc, char const* argv[]) {
    IN(n);
    for (int i = 1, a, b, c; i < n; i += 1)
        IN(a), IN(b), IN(c), g.push(a, b, c), g.push(b, a, c);
    Init(1, 0), IN(m);
    while (m--) {
        IN(k);
        for (int i = 1; i <= k; i += 1) IN(h[i]), book[h[i]] = 1;
        sort(h + 1, h + 1 + k, cmp);
        sta[top = 1] = 1, g.sz = 0, g.head[1] = -1;
        for (int i = 1, l; i <= k; i += 1)
            if (h[i] != 1) {
                l = lca(sta[top], h[i]);
                if (l != sta[top]) {
                    while (id[l] < id[sta[top - 1]]) {
                        lca(sta[top - 1], sta[top]);
                        g.push(sta[top - 1], sta[top], MX);
                        top--;
                    }
                    if (id[l] > id[sta[top - 1]]) {
                        g.head[l] = -1, lca(l, sta[top]);
                        g.push(l, sta[top], MX), sta[top] = l;
                    } else
                        lca(l, sta[top]), g.push(l, sta[top--], MX);
                }
                g.head[h[i]] = -1, sta[++top] = h[i];
            }
        for (int i = 1; i < top; i += 1)
            lca(sta[i], sta[i + 1]), g.push(sta[i], sta[i + 1], MX);
        Dp(1), printf("%lld\n", f[1]);
        for (int i = 1; i <= k; i += 1) book[h[i]] = 0;
    }
    return 0;
}