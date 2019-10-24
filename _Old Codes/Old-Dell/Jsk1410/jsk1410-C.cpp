#include <bits/stdc++.h>
using namespace std;

int ans = 0;
string in;

int main()
{
    getline(cin, in);
    for (int i = 0; i < in.size(); i += 3)
    {
        if (in[i + 2])
        {
            if (in[  i  ] != 'P') ans++;
            if (in[i + 1] != 'E') ans++;
            if (in[i + 2] != 'R') ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}
