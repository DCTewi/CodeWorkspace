#include <bits/stdc++.h>
using namespace std;

template <class T> T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w ? -x : x;
}

const int MAXN = 1e5 + 5;

int n;
string s;

int main()
{
    while (~scanf("%d", &n))
    {
        cin >> s;
        vector<int> plc[2];
        for (int i = 0; i < s.size(); i++)
        {
            plc[s[i] == 'b'].emplace_back(i);
        }

        
    }
}