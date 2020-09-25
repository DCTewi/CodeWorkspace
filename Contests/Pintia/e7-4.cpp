#include <bits/stdc++.h>
using namespace std;

template <class T>
T read()
{
    T x = 0;
    int ch = getchar(), w = 0;
    while (!isdigit(ch))
        w |= ch == '-', ch = getchar();
    while (isdigit(ch))
        x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w ? -x : x;
}

const int MAXN = 9 * 9 * 9 + 10; // all
const int MAXM = 9 * 9 * 4 + 10; // sub
const int MAXD = MAXN * 4 + MAXM + 10;

char tile[MAXN];

struct DLinks
{
    int n, m, size;
    int U[MAXD], D[MAXD], L[MAXD], R[MAXD], Row[MAXD], Col[MAXD];
    int H[MAXN], S[MAXM];
    int ansd, ans[MAXN];

    DLinks(int an, int am)
    {
        n = an, m = am;
        for (int i = 0; i <= m; i++)
        {
            S[i] = 0;
            U[i] = D[i] = i;
            L[i] = i - 1;
            R[i] = i + 1;
        }
        R[m] = 0; L[0] = m; size = m;
        for (int i = 1; i <= n; i++) H[i] = -1;
    }

    void link(int r, int c)
    {
        ++S[Col[++size] = c];
        Row[size] = r;
        D[size] = D[c]; U[D[c]] = size;
        D[c] = size; U[size] = c;
        
        if (H[r] < 0) H[r] = L[size] = R[size] = size;
        else
        {
            R[size] = R[H[r]]; L[R[H[r]]] = size;
            R[H[r]] = size; L[size] = H[r];
        }
    }
    void remove(int c)
    {
        L[R[c]] = L[c]; R[L[c]] = R[c];
        for (int i = D[c]; i != c; i = D[i])
        {
            for (int j = R[i]; j != i; j = R[j])
            {
                U[D[j]] = U[j]; D[U[j]] = D[j];
                --S[Col[j]];
            }
        }
    }
    void resume(int c)
    {
        for (int i = U[c]; i != c; i = U[i])
            for (int j = L[i]; j != i; j = L[j])
                ++S[Col[U[D[j]] = D[U[j]] = j]];
        L[R[c]] = R[L[c]] = c;
    }
    bool dance(int d)
    {
        if (R[0] == 0)
        {
            for (int i = 0; i < d; i++) 
                tile[(ans[i] - 1) / 9] = (ans[i] - 1) % 9 + '1';
            for (int i = 0; i < 9 * 9; i++)
                printf("%c", tile[i]);
            printf("\n");
            return true;
        }
        int c = R[0];
        for (int i = R[0]; i != 0; i = R[i])
            if (S[i] < S[c]) c = i;
        remove(c);
        for (int i = D[c]; i != c; i = D[i])
        {
            ans[d] = Row[i];
            for (int j = R[i]; j != i; j = R[j]) remove(Col[j]);

            if (dance(d + 1)) return true;

            for (int j = L[i]; j != i; j = L[j]) resume(Col[j]);
        }
        resume(c);
        return false;
    }
};

int main()
{
    while (~scanf("%s", tile))
    {
        if (tile[0] == 'e') return 0;

        DLinks dl(9 * 9 * 9, 9 * 9 * 4);
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                for (int k = 1; k <= 9; k++)
                {
                    int now = i * 9 + j;
                    if (tile[now] == '.' || tile[now] == '0' + k)
                    {
                        int p = now * 9 + k;
                        dl.link(p, i * 9 + j + 1);
                        dl.link(p, 9 * 9 + i * 9 + k);
                        dl.link(p, 9 * 9 * 2 + j * 9 + k);
                        dl.link(p, 9 * 9 * 3 + ((i / 3) * 3 + (j / 3)) * 9 + k);
                    }
                }
            }
        }
        dl.dance(0);
    }
    return 0;
}
