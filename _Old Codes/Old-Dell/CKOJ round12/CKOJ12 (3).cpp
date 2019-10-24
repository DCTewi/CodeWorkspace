#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e5 + 5;
int n, k;
ll speed[MAXN];
bool isfish[MAXN];

int main()
{
    int T; cin>>T;
    while (T--)
    {
        ll fishpower_tot = 0, normpower = 0;
        cin>>n>>k;
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &speed[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &isfish[i]);
            if (i < k && !isfish[i])
            {
                fishpower_tot += speed[i];
            }
            if (isfish[i])
            {
                normpower += speed[i];
            }
        }

        ll maxpower, ans = 0;
        for (int i = 0; i < n - k + 1; i++)
        {
            maxpower = fishpower_tot + normpower;
            ans = max(ans, maxpower);
            #ifdef TEWILOCAL
                cout<<maxpower<<" "<<i<<" "<<i + k<<endl;
            #endif // TEWILOCAL

            if (!isfish[i]) fishpower_tot -= speed[i];
            if (!isfish[i + k]) fishpower_tot += speed[i + k];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
