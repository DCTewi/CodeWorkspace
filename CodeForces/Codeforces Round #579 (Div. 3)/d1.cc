// WA
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string a, b;
    cin >> a >> b;
    int ans = -1, pos = 0;
    if ((pos = (int)a.find(b)) != (int)string::npos)
    {
        ans = max(max(pos, (int)a.size() - (int)b.size() - pos), ans);
    }
    if ((pos = (int)a.rfind(b)) != (int)string::npos)
    {
        ans = max(max(pos, (int)a.size() - (int)b.size() - pos), ans);
    }

    int l = a.find_first_of(b[0]), r = l;
    for (int i = 1, j = r; i < (int)b.size(); i++, j = r)
    {
        r = a.find_first_of(b[i], j + 1);
    }

    ans = max(max(l, (int)a.size() - r - 1), ans);

    cout << ans << "\n";

    return 0;
}
