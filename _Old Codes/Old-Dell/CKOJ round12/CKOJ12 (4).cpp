#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e5 + 1e3;
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
            for (int j = i + k; j < i + k + k; j++)
            {
                if (!isfish[j]) maxpower += speed[j];
                ans = max(ans, maxpower);
            }
            for (int j = i + k + 1; j < n - k + 1; j++)
            {
                if (!isfish[j - 1]) maxpower -= speed[j - 1];
                if (!isfish[j + k]) maxpower += speed[j + k];
            }
            #ifdef TEWILOCAL
                cout<<maxpower<<" "<<i<<" "<<i + k<<endl;
            #endif // TEWILOCAL

            if (!isfish[i]) fishpower_tot -= speed[i];
            if (!isfish[i + k]) fishpower_tot += speed[i + k];
        }
        printf("%lld\n", ans);

        memset(isfish, 0, sizeof(isfish));
        memset(speed, 0, sizeof(isfish));
    }
    return 0;
}
