#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000;
int n, k;
int a[MAXN], rua[MAXN];
vector<int> index[MAXN];
int top[MAXN];

bool comp1(int a, int b)
{
    return a > b;
}
bool comp2(int a, int b)
{
    return a < b;
}

int main()
{
    memset(top, 0, sizeof(top));

    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        index[a[i]].push_back(i);
    }
    sort(a, a + n, comp1);

    int tot = 0;
    for (int i = 0; i < k; i++)
    {
        tot += a[i];
    }
    printf("%d\n", tot);
    if (k == 1) printf("%d\n", n);
    else
    {
        for (int i = 0; i < k; i++)
        {
            rua[i] = index[a[i]][top[a[i]]++];
            cout<<rua[i]<<" ";
        }
        cout<<endl;
        sort(rua, rua + k, comp2);

        printf("%d ", rua[1]);
        for (int i = 2; i < k - 1; i++)
        {
            printf("%d ", rua[i] - rua[i - 1]);
        }
        printf("%d\n", k - rua[k - 1]);
    }

    return 0;
}
