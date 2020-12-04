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

int main()
{
    freopen("kotlin.in", "r", stdin); freopen("kotlin.out", "w", stdout);
    int h = read<int>(), w = read<int>(), n = read<int>();

    if ((h + 1) * (w + 1) / 4 < n) return 0 * puts("Impossible");

    int hor = 0, ver = 0, flag = 1;

    for (int i = 1; i <= (w + 1) / 2; i++)
    {
        if (n % i == 0) 
        {
            if (n / i <= (h + 1) / 2)
            {
                flag = 0; ver = i; break;
            }
        }
    }
    
    if (flag) return 0 * puts("Impossible");

    hor = n / ver;

    // printf("Ver: %d, Hor: %d\n", ver, hor);

    for (int i = 0; i < h; i++)
    {
        int now = ver - 1;
        for (int j = 0; j < w; j++)
        {
            if ((j & 1) && now > 0)
            {
                printf("#"); now--;
            }
            else if ((i & 1) && (i / 2) < hor - 1) printf("#");
            else printf(".");
        }
        puts("");
    }
    fclose(stdin); fclose(stdout);

    return 0;
}
