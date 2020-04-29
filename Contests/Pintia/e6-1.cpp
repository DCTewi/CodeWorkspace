#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T> T read()
{
    T x = 0; int ch = getchar(), w = 0;
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w ? -x : x;
}

struct Cake
{
    float count, price, value;
};

int main()
{
    int n = read<int>(), req = read<int>();
    vector<Cake> cakes(n);

    for (int i = 0; i < n; i++)
    {
        scanf("%f", &cakes[i].count);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &cakes[i].price);
        cakes[i].value = cakes[i].price / cakes[i].count;
    }
    sort(cakes.begin(), cakes.end(), [](const Cake &a, const Cake &b)
    {
        return a.value > b.value;
    });

    float ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (cakes[i].count <= req)
        {
            ans += cakes[i].price;
        }
        else 
        {
            ans += cakes[i].value * req; break;
        }
        req -= cakes[i].count;
    }

    printf("%.2f", ans);

    return 0;
}