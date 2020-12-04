#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int read()
{
    int x = 0; char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch))
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x;
}

int main()
{
    int Q = read();
    while (Q--)
    {
        int n = read(), flag = 0;
        vector<int> a(n * 4);
        map<int, int> num;
        for (int i = 0; i < 4 * n; i++)
        {
            a[i] = read();
            num[a[i]]++;
        }
        for (auto it : num)
        {
            if (it.second & 1)
            {
                flag = 1; break;
            }
        }
        if (flag)
        {
            cout << "NO\n"; continue;
        }
        sort(a.begin(), a.end());

        int l = 0, r = 4 * n - 1, siz = -1;
        while (l < r)
        {
            if (a[l + 1] != a[l])
            {
                l++; continue;
            }
            else if (a[r - 1] != a[r])
            {
                r--; continue;
            }
            else
            {
                if (siz == -1) siz = a[l] * a[r];
                else if (siz != a[l] * a[r])
                {
                    flag = 1; break;
                }
                l += 2; r -= 2;
            }
        }
        if (flag)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}
