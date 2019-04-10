#include <cstdio>
#include <iostream>

using namespace std;
long long int n, l = 1, r = 1, m = 0;
long long int now;

bool check(long long int, long long int );
bool checkk(long long nk);

int main()
{
    scanf("%I64d", &n);
    r = n;

    while (l != r)
    {
        now = 0;

        m = (l + r) / 2;
        //cout<<"m = "<<m<<endl;
        if (checkk(m))
        {
            r = m;
        }
        else
        {
            if (r - l == 1)
            {
                break;
            }
            else l = m;
        }
    }

    printf("%I64d\n", r);

    return 0;
}

bool check(long long int leftn, long long int nk)
{
    if (leftn <= nk)
    {
        now += leftn;
        if (now >= n / 2)
        {
            //cout<<"m ok\n";
            return true;
        }
        //cout<<"m no\n";
        return false;
    }

    leftn -= nk;
    leftn -= leftn / 10;
    now += nk;

    if (check(leftn, nk)) return true;
    return false;
}

bool checkk(long long nk)
{
    long long int temp = n;
    long long int ans1 = 0, ans2 = 0;

    while (temp > 0)
    {
        ans1 += min(temp, nk);
        temp -= min(temp, nk);

        ans2 += temp / 10ll;
        temp -= (temp / 10ll);
    }

    return ans1 >= ans2;
}
