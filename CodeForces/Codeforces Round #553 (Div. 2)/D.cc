#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
ll n;
struct Stu
{
    ll a, b, ind;

}stu[MAXN];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;

    for (int i = 0; i < n; i++)
    {
        cin>>stu[i].a>>stu[i].b;
        stu[i].ind = i;
    }

    sort(stu, stu + n, [](Stu a, Stu b)->bool
    {
        return (a.b - a.a) < (b.b - b.a);
    });

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += stu[i].a * i + stu[i].b * (n - i - 1);
    }
    cout<<ans<<"\n";

    return 0;
}
