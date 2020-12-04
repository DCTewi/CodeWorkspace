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
    int _T = read<int>();
    while (_T--)
    {
        string s; cin >> s;
        vector<int> pat = {0};

        for (int i = 0, _i = s.size(); i < _i; i++)
        {
            if (s[i] == 'R') pat.emplace_back(i + 1);
        }
        pat.emplace_back(s.size() + 1);

        int ans = -1;
        for (int i = 1, _i = pat.size(); i < _i; i++)
        {
            ans = max(ans, pat[i] - pat[i - 1]);
        }

        printf("%d\n", ans);
    }
    return 0;
}
