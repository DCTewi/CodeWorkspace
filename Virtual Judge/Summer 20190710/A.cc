// A Calandar
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const string days[] = {"Friday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

string date;
ll yy1, yy2, m1, m2, d1, d2, offset;

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%lld%lld%lld", &yy1, &m1, &d1);
        cin >> date;
        scanf("%lld%lld%lld", &yy2, &m2, &d2);
        offset = (yy2 - yy1) *12 * 30 + (m2 - m1) * 30 + (d2 - d1);

        for (int i = 1; i < 6; i++)
        {
            if (date == days[i])
            {
                offset += i; break;
            }
        }
        offset = (offset % 5 + 5) % 5;
        puts(days[offset].c_str());
    }

    return 0;
}