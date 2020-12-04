#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 4e4 + 5;
const int HASH = 31;

int m;
ll seed[MAXN], bhash[MAXN], hashl[MAXN];
int now[MAXN], top = 0;

int check(const int &sublen, const int &totlen)
{
    int cnt = 0, pos = -1; top = 0;
    for (int i = 0; i <= totlen - sublen; i++)
    {
        now[i] = i; top++;
        hashl[i] = bhash[i] - bhash[i + sublen] * seed[sublen];
    }
    sort(now, now + top, [](const int &a, const int &b)
    {
        return hashl[a] < hashl[b] || (hashl[a] == hashl[b] && a < b); // Right first
    });
    for (int i = 0; i <= totlen - sublen; i++)
    {
        if (i == 0 || hashl[now[i]] != hashl[now[i - 1]]) cnt = 0;
        if (++cnt >= m) pos = max(pos, now[i]); // Right first
    }
    return pos;

}

char s[MAXN];
int main()
{

    while (~scanf("%d", &m))
    {
        if (!m) return 0;

        scanf("%s", s);
        int len = strlen(s);
        // HASH
        bhash[len] = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            bhash[i] = bhash[i + 1] * HASH + (s[i] - 'a');
        }
        seed[0] = 1;
        for (int i = 1; i <= len; i++)
        {
            seed[i] = seed[i - 1] * HASH;
        }
        // CHECK
        if (check(1, len) < 0)
        {
            cout << "none\n";
        }
        else
        {
            int l = 1, r = len + 1;
            while (r - l > 1)
            {
                int mid = (l + r) >> 1;
                if (check(mid, len) >= 0) l = mid;
                else r = mid;
            }
            cout << l << " " << check(l, len) << "\n";
        }
    }
    return 0;
}
