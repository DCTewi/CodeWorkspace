// B - 	The World # WA
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string times, noon, c1, c2;
map<string, int> offset;

void get_time(int off)
{
    int h = (times[0] - '0');
    if (times[1] != ':') h = h * 10 + (times[1] - '0');
    string m = times.substr(2 + (times[1] != ':'), 2);

    if (noon == "PM") h += 12; 
    if (noon == "AM" && h == 12) h = 0;

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

    if (h >= 12)
    {
        h -= 12;
        cout << (h? h: 12) << ":" << m << " PM\n";
    }
    else
    {
        cout << (h? h: 12) << ":" << m << " AM\n";
    }
}

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
        int off = offset[c2] - offset[c1];

        cout << "Case " << t << ": ";
        get_time(off);
    }
    
    return 0;
}
