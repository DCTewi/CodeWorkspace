#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int n;
list<int> a;
string seq;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int tem; cin >> tem;
        a.push_back(tem);
    }
    int last = 0;

    while (a.size() && (a.front() > last || a.back() > last))
    {
        if (a.size() == 1 && a.front() > last)
        {
            seq += 'L';
            a.pop_back();
        }

        int l = a.front(), r = a.back();
        if (l < r)
        {
            if (l > last)
            {
                seq += 'L';
                last = l;
                a.pop_front();
            }
            else if (r > last)
            {
                seq += 'R';
                last = r;
                a.pop_back();
            }
        }
        else if (r < l)
        {
            if (r > last)
            {
                seq += 'R';
                last = r;
                a.pop_back();
            }
            else if (l > last)
            {
                seq += 'L';
                last = l;
                a.pop_front();
            }
        }
    }

    cout << seq.size() << "\n" << seq << "\n";

    return 0;
}