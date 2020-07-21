#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T> T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w ? -x : x;
}

int main()
{
    int T = read<int>();
    while (T--)
    {
        int sum = 0, p = 0;
        int n = read<int>();
        string s; cin >> s;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                if (p) p--, sum++;
            }
            else if (s[i] == '1') p++;
            else if (s[i] == '2') sum++;
            else 
            {
                sum++;
            }
        }
        printf("%d\n", sum + p / 2);
    }
    return 0;
}