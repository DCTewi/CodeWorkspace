// B - The World
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string times, noon, c1, c2;
map<string, int> offset;

int main()
{
    ios::sync_with_stdio(0);

    offset["Beijing"] = 8;
    offset["Washington"] = -5;
    offset["London"] = 0;
    offset["Moscow"] = 3;

    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> times >> noon >> c1 >> c2;
        cout << "Case " << t << ": ";

        int h = times[0] - '0';
        if (times[1] != ':') h = h * 10 + times[1] - '0';
        if (h == 12) h -= 12;
        if (noon == "PM") h += 12;

        string m = times.substr(2 + (times[1] != ':'), 2);

        int off = offset[c2] - offset[c1];
        h += off;

        if (h < 0)
        {
            cout << "Yesterday "; h += 24;
        }
        else if (h >= 24)
        {
            cout << "Tomorrow "; h -= 24;
        }
        else
        {
            cout << "Today ";
        }

        bool pm = 0;
        if (h >= 12)
        {
            pm = 1;
            h -= 12;
        }
        if (h == 0) h = 12;

        cout << h << ":" + m << (pm? " PM\n": " AM\n");
    }
    
    return 0;
}
