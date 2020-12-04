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

int main()
{
    int T = read<int>();
    while (T--)
    {
        int n = read<int>();
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            a[i] = read<int>();
        }
        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != -1)
            {
                if ((i && a[i - 1] == -1) ||(i != n - 1 && a[i + 1] == -1))
                {
                    nums.emplace_back(a[i]);
                }
            }
        }
        if (nums.size() == 0) 
        {
            puts("0 0"); continue;
        }
        sort(nums.begin(), nums.end());
        int ans = (nums[0] + nums[nums.size() - 1]) / 2;
        int constans = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == -1) a[i] = ans;
        }
        for (int i = 0; i < n; i++)
        {
            if (i) constans = max(constans, abs(a[i] - a[i - 1]));
            if (i != n - 1) constans = max(constans, abs(a[i] - a[i + 1]));
        }
        printf("%d %d\n", constans, ans);
    }
    return 0;
}
