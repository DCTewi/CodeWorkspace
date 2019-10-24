#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e2 + 5;

int h, w, n;
int hor[MAXN], ver[MAXN];

int main()
{   
    //freopen("kotlin.in", "r", stdin);
    //freopen("kotlin.out", "w", stdout);
    if (scanf("%d%d%d", &h, &w, &n));

    if (n > (h + 1) * (w + 1) / 4) return 0 * puts("Impossible");

    int nv = 1, nh = 1;
    for (int i = 1; i < w && nv < n; i += 2)
    {
        ver[i] = 1; if (i + 1 < w) nv++;
    }
    for (int i = 1; i < h && nv * nh < n; i += 2)
    {
        hor[i] = 1; if (i + 1 < h) nh++;
    }

    if (nh * nv != n)
    {
        nh = nv = 1;
        memset(hor, 0, sizeof(hor));
        memset(ver, 0, sizeof(ver));
        for (int i = 1; i < h && nv * nh < n; i += 2)
        {
            hor[i] = 1; if (i + 1 < h) nh++;
        }
        for (int i = 1; i < w && nv * nh < n; i += 2)
        {
            ver[i] = 1; if (i + 1 < w) nv++;
        }
    }

    if (nh * nv != n) return 0 * puts("Impossible");

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (hor[i] || ver[j]) printf("#");
            else printf(".");
        }
        puts("");
    }


    return 0;
}
